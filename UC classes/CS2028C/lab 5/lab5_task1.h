#include <iostream>
#include <string>
using namespace std;

const int MAX_MOVIES = 10; // global constant 

class Movie {
public:
    string title;
    Movie(string t) : title(t) {}
    // Function to get movie title
    string getTitle() const {
        return title;
    }
};

class Shelf {
private:
    Movie* movies[MAX_MOVIES]; // array to hold pointers to Movie objects
    int movies_num;           // # movies currently in the shelf

public:
    // constructor
    Shelf() : movies_num(0) {
        for (int i = 0; i < MAX_MOVIES; ++i) {
            movies[i] = nullptr; // initialize array elements to nullptr
        }
    }

    // adds a movie to the shelf
    void add(Movie* movie) {
        if (movies_num < MAX_MOVIES) {
            movies[movies_num] = movie;
            movies_num++;
        }
        else {
            cout << "Shelf is full. Cannot add more movies." << endl;
        }
    }

    // removes a movie from the shelf
    Movie* remove() {
        if (movies_num > 0) {
            Movie* removedMovie = movies[movies_num - 1]; // gets the last movie
            movies[movies_num - 1] = nullptr;             // clears the reference
            movies_num--;
            return removedMovie;                             // returns the removed movie
        }
        else {
            cout << "Shelf is empty. No movies to remove." << endl;
            return nullptr; // returns nullptr if no movies are available
        }
    }

    // gets the current number of movies
    int getMovies_num() const {
        return movies_num;
    }

    void displayMovies() const {
        if (movies_num == 0) {
            cout << "The shelf is empty.\n";
            return;
        }
        cout << "Movies on the shelf:\n";
        for (int i = 0; i < movies_num; ++i) {
            cout << "- " << movies[i]->getTitle() << endl;
        }
    }
};