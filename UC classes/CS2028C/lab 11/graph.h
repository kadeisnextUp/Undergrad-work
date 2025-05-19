#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Graph {
private:
    unordered_map<string, vector<string>> adjacency_list;

public:
    void addRoom(const string& room) {
        if (adjacency_list.find(room) == adjacency_list.end()) {
            adjacency_list[room] = {};
        }
    }

    void addTunnel(const string& from, const string& to) {
        
        adjacency_list[from].push_back(to);
        adjacency_list[to].push_back(from);
    }

    const vector<string>& getConnectedRooms(const string& room) const {
        return adjacency_list.at(room);
    }

    bool hasTunnel(const string& from, const string& to) const {
        if (adjacency_list.find(from) == adjacency_list.end()) return false;
        const auto& neighbors = adjacency_list.at(from);
        return find(neighbors.begin(), neighbors.end(), to) != neighbors.end();
    }

    void printGraph() const {
        for (const auto& pair : adjacency_list) {
            cout << pair.first << " -> ";
            for (const auto& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }

    vector<string> getAllRooms() const {
        vector<string> rooms;
        for (const auto& pair : adjacency_list) {
            rooms.push_back(pair.first);
        }
        return rooms;
    }
};

#endif
