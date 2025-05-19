#include "metaverse.h"
#include "display.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <istream>
#include <vector>

int count_neighbors(const metaverse_t &board, int row, int column) {
    int count = 0;
    //the relative locations are similar to a tic tac toe board
    std::vector<std::pair<int, int>> directions = {
       {-1, -1}, {-1, 0}, {-1, 1},
       {0, -1},           {0, 1},
       {1, -1},  {1, 0},  {1, 1}
    };

    for (const auto& dir : directions) {
        int newRow = row + dir.first;
        int newColumn = column + dir.second;

        if (newRow >= 0 && newRow < board.size() && newColumn >= 0 && newColumn < board[newRow].size()) {
            if (board[newRow][newColumn]) {
                count++;
            }
        }
    }

  return count;
}


bool occupied_in_next_tick(bool currently_occupied, int neighbor_count) {
    bool occupied = false;
    if (currently_occupied = true) {
        if (neighbor_count == 2 || neighbor_count == 3) {
            occupied = true;
        }

    }
    else {
        if (neighbor_count == 3) {
            occupied = true;
        }
    }
  return occupied;
}

metaverse_t tick(const metaverse_t &board) {

    metaverse_t nextGeneration(board.size(), std::vector<bool>(board[0].size(), false));

    for (int row = 0; row < board.size(); ++row) {
        for (int col = 0; col < board[row].size(); ++col) {
            int neighborCount = count_neighbors(board, row, col);

            bool occupied = occupied_in_next_tick(board[row][col], neighborCount);

            nextGeneration[row][col] = occupied;
        }
    }

    return nextGeneration;
}

bool resize_metaverse(int rows, metaverse_t &board) {
    board.resize(rows,board[rows]);
  return true;
}

bool citizenship_row_to_metaverse_row(const std::string &input_row, int row,
                                      metaverse_t &board) {
    if (input_row.size() == board[row].size()) {
        for (int x = 0; x < input_row.size(); x++) {
            board[row][x] = input_row[x];
        }
        return true;
    }
    else {

        return false;
    }
}

bool read_metaverse_configuration_line_from_file(std::ifstream &metaverse_file,
                                                 int &size, int &generations) {
    std::string line;
    bool read = false;

    if (getline(metaverse_file, line)) {
        // since line[0] returns a char i can subtract the ascii value of 0 to get a int
        size = line[0] - '0';
        generations = line[2] - '0';
        read = true;
    }
    else {
        return read;
    }
    
   
  return read;
}
bool initialize_metaverse_from_file(std::ifstream &metaverse_file,
                                    metaverse_t &metaverse,
                                    int &generations) {
  int size{};
  int actual_row{};

  generations = 0;

  if (!read_metaverse_configuration_line_from_file(metaverse_file, size,
                                                   generations)) {
    return false;
  }

  if (!resize_metaverse(size, metaverse)) {
    return false;
  }

  metaverse_file >> std::ws;
  while (!metaverse_file.eof()) {
    std::string line{};
    if (!std::getline(metaverse_file, line)) {
      return false;
    }
    if (!citizenship_row_to_metaverse_row(line, actual_row, metaverse)) {
      return false;
    }
    actual_row++;
    metaverse_file >> std::ws;
  }
  return actual_row == size;
}

void model_metaverse(const metaverse_t &starting_metaverse, int generations) {
    metaverse_t current = starting_metaverse;

    for (int gen = 0; gen < generations; ++gen) {
        metaverse_t nextMetaverse = current;
        for (int row = 0; row < current.size(); ++row) {
            for (int col = 0; col < current[row].size(); ++col) {
                int neighborCount = count_neighbors(current, row, col);

                bool occupied = occupied_in_next_tick(current[row][col], neighborCount);

                nextMetaverse[row][col] = occupied;
            }
        }

        display_metaverse(std::cout, nextMetaverse);

        current = nextMetaverse;
    }

}
