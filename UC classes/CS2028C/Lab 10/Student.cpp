#include "Student.h"
#include <iostream>
using namespace std;



int Student::getMnumber() const {
	return mNumber;
}


void Student::getInfo() const {
	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "M Number: " << mNumber << endl;
	cout << "Major: " << major << endl;
}

string Student::getName() const {
	return firstName + " " + lastName;
}