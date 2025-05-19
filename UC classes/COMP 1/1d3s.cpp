#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{26};

int number_from_letter(char letter) {
  int offset = letter - (int)'a';
  if (offset < 0 || offset >= ALPHABET_LENGTH) {
    std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
    assert(false);
  }
  return offset;
}

char letter_from_number(int number) {

  if (number < 0 || number >= ALPHABET_LENGTH) {
    std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
    assert(false);
  }

  const char alphabet[] = { 'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'};
  return alphabet[number];
}

int main() {
    // varibles 
    char shift_direction{ ' ' };
    int shift_number = 0;
    char plaintext{ ' ' };
    int plaintext_position, actual_shift, encrypted_position;
    char encrypted;
    std::string cipher ="";

    // inputs and checking for erros
    std::ifstream inFile;
    inFile.open("input.txt");
        if (inFile >> shift_direction) {
            if (shift_direction == 'l' || shift_direction == 'r') {
                if (inFile >> shift_number) {
                    // active encryption
                    while (inFile >> plaintext) {
                        plaintext_position = number_from_letter(plaintext);
                        actual_shift = shift_number;
                        if (shift_direction != 'r') {
                            actual_shift *= -1;
                        }

                        encrypted_position = plaintext_position + actual_shift;
                        encrypted_position = encrypted_position % 26;
                        if (encrypted_position < 0) {
                            encrypted_position += 26;
                        }

                        encrypted = letter_from_number(encrypted_position);
                        cipher += encrypted;
                    }
                    std::cout << cipher + "\n";
                }
                else {
                    std::cout << "Oops: Could not read the shift number from the input file.\n";
                }
            }
            else {
                std::cout << "Oops: Invalid direction in the input file.\n";
            }
        }
        else {
            std::cout << "Oops: Invalid direction in the input file.\n";
        }

    inFile.close();


    

}