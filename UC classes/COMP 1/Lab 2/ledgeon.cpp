#include <iostream>

/* This program will take the years and number of patients in a hospital
* for those years as input and output the percent change between the years
* and the total charity charges in those years
*
*/
int main() {
	// variables
	int year1, year2, numPateints1, numPateints2;
	double change, charity1, charity2;
	double ratio = 1008.97;

	//inputs
	std::cout << "Enter the first year: ";
	std::cin >> year1;
	std::cout << "Enter the number of patients we saw that year: ";
	std::cin >> numPateints1;
	std::cout << "Enter the second year: ";
	std::cin >> year2;
	std::cout << "Enter the number of patients we saw that year: ";
	std::cin >> numPateints2;

	//calculations
	change = 1.0*(numPateints2 - numPateints1) / numPateints1;
	change = change * 100.0;
	charity1 = ratio * numPateints1;
	charity2 = ratio * numPateints2;

	//outputs
	std::cout << "In year " << year1 << ", our hospital issued " << charity1 << " dollars of charity charges.\n";
	std::cout << "In year " << year2 << ", our hospital issued " << charity2 << " dollars of charity charges.\n";
	std::cout << "Between " << year1 << " and " << year2 << ", there was a " << change;
	std::cout << "% increase in patients seen at our hospital.\n";









	return 0;
}