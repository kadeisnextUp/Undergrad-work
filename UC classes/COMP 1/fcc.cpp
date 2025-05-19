#include <fstream>
#include <iostream>
#include <vector>


// declaring helper functions first
std::vector<std::string> file_to_vector(std::ifstream& file);
int find_matching_string(std::string check, std::vector<std::string>checkVector);

bool more_to_read(std::ifstream &file) {
  file >> std::noskipws;
  while (file.peek() == ' ') {
    char discard;
    file >> discard;
  }
  return !(file.eof() || std::iscntrl(file.peek()));
}

int fcc(const std::string &fixme_filename, const std::string &typo_filename,
        const std::string &fixo_filename, std::string &fixed_sentence) {
    //variables
    std::ifstream typoFile,fixoFile,fixmeFile;
    std::vector<std::string> typos;
    std::vector<std::string> fixos;
    std::vector<std::string> fixme;
    //varible to count the corrections
    int count = 0;

    //open and read files
    typoFile.open(typo_filename);
    fixoFile.open(fixo_filename);
    fixmeFile.open(fixme_filename);
    


    while (more_to_read(typoFile)) {
        typos = file_to_vector(typoFile);
    }

    while (more_to_read(fixoFile)) {
        fixos = file_to_vector(fixoFile);
    }
    while (more_to_read(fixmeFile)) {
        fixme = file_to_vector(fixmeFile);
    }

    //the typo and corrections part
    if (typos.size() == fixos.size()) {
        //find typos and correct them
        for (int x = 0; x < typos.size(); x++) {
            if (find_matching_string(typos[x], fixme) != -1) {
                std::string replacement = fixos[x];
                fixme[find_matching_string(typos[x], fixme)] = replacement;
                count++;
            }
        }
        //make the updated sentence
        for (int x = 0; x < fixme.size(); x++) {
            fixed_sentence += fixme[x];
            if (x < fixme.size() - 1) {
                fixed_sentence += " ";
            }
            else {
                fixed_sentence += ".";
            }
        }
    }
    else {
        return -1;
    }


  return count;
}

/*
*  file_to_vector
* 
*  This function will take the a file and copy the data into a vector and output it.
* 
*  input: a ifstream file passed by reference 
*  output: a vector with the data from the file in it
* 
*/

std::vector<std::string> file_to_vector(std::ifstream &file) {
    std::vector<std::string> words;
    while (more_to_read(file)) {
        std::string next_word;
        file >> next_word;
        words.push_back(next_word);
    }
    return words;
}

/*
* 
*  find_matching_string
* 
*   This function will attepmt to find a matching string in a given vector
* 
*   input: a string that you want to find the match of and the vector where the match could potentially be
*   output: a int that will be the index of a match if found and will be -1 if a match was not found
*/

int find_matching_string(std::string check, std::vector<std::string>checkVector) {
    int index = -1;

    for (int x = 0; x < checkVector.size(); x++) {
        if (checkVector[x] == check) {
            index = x;
            break;
        }
    }
    return index;
}

