#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>


using namespace std;


class Student {

private:
	string firstName;
	string lastName;
	int mNumber;
	string major;

public:
	//constructors
	Student() {
		firstName = "none";
		lastName = "none";
		mNumber = 0;
		major = "undecided";
	}

	Student(string name1, string name2, int number, string study) {
		firstName = name1;
		lastName = name2;
		mNumber = number;
		major = study;
	}

	//getter for mNumber
	int getMnumber() const;

	//used to print information of said student
	void Display() const;
	string getName() const;

	//getters for lab 12
	string getFirstName() const { return firstName; }
	string getLastName() const { return lastName; }
	string getMajor() const { return major; }

	//overload
	operator std::string() const {
		return "M" + to_string(mNumber);
	}

	bool operator==(const Student& other) const {
		return mNumber == other.mNumber;
	}
	bool operator<(const Student& other) const {
		return mNumber < other.mNumber;
	}
	bool operator!=(const Student& other) const {
		return !(*this == other);
	}

};

	


#endif
