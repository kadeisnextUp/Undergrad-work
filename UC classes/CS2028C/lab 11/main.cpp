
#include "graph.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;
//gameplay stuff
class WumpusGame {
private:
    Graph& cave;
    string currentRoom;
    string wumpusRoom;
    string pitRoom;
    string batsRoom;
    int arrows;
    bool gameOver;
    vector<string> fallenArrows;
    vector<string> visitedRooms;

    void placeHazards(const string& startRoom) {
        vector<string> rooms = cave.getAllRooms();
        rooms.erase(remove(rooms.begin(), rooms.end(), startRoom), rooms.end());

        // randomly placed hazards
        random_shuffle(rooms.begin(), rooms.end());
        wumpusRoom = rooms[0];
        pitRoom = rooms[1];
        batsRoom = rooms[2];
    }

    void getObservations() {
        vector<string> adjacent = cave.getConnectedRooms(currentRoom);
        bool smell = false, breeze = false, screech = false;

        for (const string& room : adjacent) {
            if (room == wumpusRoom) smell = true;
            if (room == pitRoom) breeze = true;
            if (room == batsRoom) screech = true;
        }

        cout << "You observe the tunnels...\n";
        if (smell) cout << "You smell a terrible stench.\n";
        if (breeze) cout << "You feel a draft.\n";
        if (screech) cout << "You hear screeching.\n";
        if (!smell && !breeze && !screech) cout << "You hear nothing unusual.\n";
    }

    void movePlayer(const string& newRoom) {
        if (find(cave.getConnectedRooms(currentRoom).begin(),
            cave.getConnectedRooms(currentRoom).end(), newRoom) == cave.getConnectedRooms(currentRoom).end()) {
            cout << "You can't move there directly!\n";
            return;
        }

        currentRoom = newRoom;
        visitedRooms.push_back(currentRoom);
        cout << "You move to room " << currentRoom << ".\n";

        // check room contents
        if (currentRoom == pitRoom) {
            cout << "You fell into a bottomless pit! Game over.\n";
            gameOver = true;
        }
        else if (currentRoom == batsRoom) {
            cout << "You've disturbed a colony of bats! They carry you to another room.\n";
            vector<string> adjacent = cave.getConnectedRooms(currentRoom);
            currentRoom = adjacent[rand() % adjacent.size()];
            visitedRooms.push_back(currentRoom);
            cout << "The bats drop you in room " << currentRoom << ".\n";
            movePlayer(currentRoom); // Check new room
        }
        else if (currentRoom == wumpusRoom) {
            if (arrows > 0) {
                cout << "The Wumpus attacks! You lose an arrow defending yourself.\n";
                arrows--;
                // wumpus moves
                vector<string> allRooms = cave.getAllRooms();
                allRooms.erase(remove(allRooms.begin(), allRooms.end(), currentRoom), allRooms.end());
                wumpusRoom = allRooms[rand() % allRooms.size()];
                cout << "You hear the Wumpus moving to another room.\n";
            }
            else {
                cout << "The Wumpus attacks and you have no arrows left! Game over.\n";
                gameOver = true;
            }
        }
        else {
            // check for fallen arrows
            auto it = find(fallenArrows.begin(), fallenArrows.end(), currentRoom);
            if (it != fallenArrows.end()) {
                cout << "You find an arrow on the floor!\n";
                arrows++;
                fallenArrows.erase(it);
            }
        }
    }

    void shootArrow(const vector<string>& path) {
        if (arrows <= 0) {
            cout << "You have no arrows left!\n";
            return;
        }

        arrows--;
        cout << "You shoot an arrow through rooms: ";
        for (const string& room : path) cout << room << " ";
        cout << "\n";

        // check if arrow hits Wumpus
        for (const string& room : path) {
            if (room == wumpusRoom) {
                cout << "You hear a terrible scream! You've killed the Wumpus!\n";
                cout << "Congratulations! You win!\n";
                gameOver = true;
                return;
            }
        }

        cout << "The arrow misses and falls to the floor.\n";

        // arrow falls in last room if it's not hazardous
        if (path.back() != pitRoom && path.back() != batsRoom) {
            fallenArrows.push_back(path.back());
        }

        // wumpus moves after missed shot
        vector<string> allRooms = cave.getAllRooms();
        allRooms.erase(remove(allRooms.begin(), allRooms.end(), currentRoom), allRooms.end());
        wumpusRoom = allRooms[rand() % allRooms.size()];
        cout << "You hear the Wumpus moving to another room.\n";
    }

    vector<vector<string>> generatePossiblePaths(const string& start, int depth) {
        vector<vector<string>> paths;
        if (depth <= 0) return paths;

        for (const string& neighbor : cave.getConnectedRooms(start)) {
            vector<string> path = { neighbor };
            if (depth == 1) {
                paths.push_back(path);
            }
            else {
                vector<vector<string>> subpaths = generatePossiblePaths(neighbor, depth - 1);
                for (vector<string>& subpath : subpaths) {
                    vector<string> fullpath = path;
                    fullpath.insert(fullpath.end(), subpath.begin(), subpath.end());
                    paths.push_back(fullpath);
                }
            }
        }

        return paths;
    }

public:
    WumpusGame(Graph& graph, const string& startRoom) : cave(graph), currentRoom(startRoom), arrows(3), gameOver(false) {
        srand(time(0));
        placeHazards(startRoom);
        visitedRooms.push_back(startRoom);
    }

    void play() {
        cout << "Welcome to Hunt the Wumpus!\n";
        cout << "You are in room " << currentRoom << ".\n";
        cout << "You have " << arrows << " arrows.\n";

        while (!gameOver) {
            cout << "\nOptions:\n";
            cout << "1. Move to another room\n";
            cout << "2. Shoot an arrow\n";
            cout << "3. Observe tunnels\n";
            cout << "4. Quit game\n";
            cout << "Choose an option (1-4): ";

            int choice;
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
            case 1: {
                cout << "Connected rooms: ";
                vector<string> adjacent = cave.getConnectedRooms(currentRoom);
                for (const string& room : adjacent) cout << room << " ";
                cout << "\nEnter room to move to: ";
                string room;
                cin >> room;
                //capatilizing input just in case
                if (!room.empty()) {
                    room[0] = toupper(room[0]);
                }
                movePlayer(room);
                break;
            }
            case 2: {
                cout << "Enter arrow path (2-4 rooms, space separated): ";
                vector<string> path;
                string room;

                // read until we get 3 rooms OR user presses enter
                while (path.size() < 3 && cin >> room) {
                    // capitalize input
                    if (!room.empty()) room[0] = toupper(room[0]);

                    // validate first room is adjacent
                    if (path.empty()) {
                        vector<string> adjacent = cave.getConnectedRooms(currentRoom);
                        if (find(adjacent.begin(), adjacent.end(), room) == adjacent.end()) {
                            cout << room << " is not adjacent to " << currentRoom << "!\n";
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                    }
                    //validate subsequent rooms are connected
                    else if (!cave.hasTunnel(path.back(), room)) {
                        cout << room << " is not connected to " << path.back() << "!\n";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }

                    path.push_back(room);

                    // we have at least 1 room (2 total)
                    if (path.size() >= 1) {
                        // check if enter was pressed
                        if (cin.peek() == '\n') {
                            break;
                        }
                    }
                }

                // clear any remaining input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // validate we got at least 1 room (2 total)
                if (path.size() < 1) {
                    cout << "Arrow path too short. Enter 2-4 rooms.\n";
                }
                else {
                    shootArrow(path);
                }
                break;
            }
            case 3:
                getObservations();
                break;
            case 4:
                gameOver = true;
                cout << "Thanks for playing!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }

            if (!gameOver) {
                cout << "\nYou are in room " << currentRoom << ".\n";
                cout << "You have " << arrows << " arrows remaining.\n";
            }
        }
    }
};

int main() {
    srand(time(0));

    // create cave structure
    Graph cave;

    // adding rooms and using A-T to represent 20 rooms
    for (char c = 'A'; c <= 'T'; c++) {
        cave.addRoom(string(1, c));
    }

    // connect rooms (this creates a traditional dodecahedron structure )
    // connect each room to 3 others
    vector<pair<string, string>> tunnels = {
        {"A", "B"}, {"A", "E"}, {"A", "F"},
        {"B", "A"}, {"B", "C"}, {"B", "J"},
        {"C", "B"}, {"C", "D"}, {"C", "L"},
        {"D", "C"}, {"D", "E"}, {"D", "N"},
        {"E", "A"}, {"E", "D"}, {"E", "O"},
        {"F", "A"}, {"F", "G"}, {"F", "O"},
        {"G", "F"}, {"G", "H"}, {"G", "P"},
        {"H", "G"}, {"H", "I"}, {"H", "J"},
        {"I", "H"}, {"I", "J"}, {"I", "K"},
        {"J", "B"}, {"J", "H"}, {"J", "I"},
        {"K", "I"}, {"K", "L"}, {"K", "S"},
        {"L", "C"}, {"L", "K"}, {"L", "M"},
        {"M", "L"}, {"M", "N"}, {"M", "Q"},
        {"N", "D"}, {"N", "M"}, {"N", "O"},
        {"O", "E"}, {"O", "F"}, {"O", "N"},
        {"P", "G"}, {"P", "Q"}, {"P", "R"},
        {"Q", "M"}, {"Q", "P"}, {"Q", "T"},
        {"R", "P"}, {"R", "S"}, {"R", "T"},
        {"S", "K"}, {"S", "R"}, {"S", "T"},
        {"T", "Q"}, {"T", "R"}, {"T", "S"}
    };

    for (const auto& tunnel : tunnels) {
        cave.addTunnel(tunnel.first, tunnel.second);
    }

    // start game in room A obviously
    WumpusGame game(cave, "A");
    game.play();

    return 0;
}