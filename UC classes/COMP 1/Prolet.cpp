#include <iostream>

int get_int();
double calculate_per_capita_gdp_estimate(int quarters_from_epoch);
std::string format_money(double money);
std::string quarter_to_ordinal(int quarter);

/* This program is going to give the expected (working-age) per-capita GDP based on the year and
	quarter that is inputted.

*/
int main() {
	// variables and constants
	int eYear, eQuarter;
	const int QUATER_IN_YEAR = 4;
	const int EPOCH = 1977 ;
	const int EPOCH_QUATER = EPOCH * 4;
	double forGdp, calcQuarters, gdp;

	// input
	std::cout << "Please enter the year for the calculation: ";
	eYear = get_int();
	std::cout << "Please enter the quarter for the calculation: ";
	eQuarter = get_int();

	//calculation
	calcQuarters = eYear * QUATER_IN_YEAR + (eQuarter - 1);
	forGdp = calcQuarters - EPOCH_QUATER;
	gdp = calculate_per_capita_gdp_estimate(forGdp);

	//output
	std::cout << "In the " << quarter_to_ordinal(eQuarter) << " quarter of " << eYear;
	std::cout << ", the projected contribution to GDP per working-age person is $" << format_money(gdp) << ".\n";


	return 0;
}