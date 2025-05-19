#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>

class Word {
public:
    std::string word;
    int count;

    Word(std::string w = "") : word(w), count(1) {}

    bool operator<(const Word& other) const {
        return word < other.word;
    }

    bool operator>(const Word& other) const {
        return word > other.word;
    }

    bool operator==(const Word& other) const {
        return word == other.word;
    }

    friend std::ostream& operator<<(std::ostream& os, const Word& w) {
        os << w.word << " (" << w.count << ")";
        return os;
    }
};

#endif
