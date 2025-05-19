#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
  int model_year{0};
  std::cout << "What is the model year of the car? ";
  std::cin >> model_year;
  return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
  int accidents{0};
  std::cout << "How many accidents has the car been in? ";
  std::cin >> accidents;
  return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
  double msrp{0.0};
  std::cout << "How much did you pay for the car? ";
  std::cin >> msrp;
  return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 *
 * returns: whether the car has premium option as entered by the user (`bool`).
 */
bool car_has_premium_options() {
  std::string has_options_string{""};
  std::cout << "Does your car have premium options (yes/no)? ";
  std::cin >> has_options_string;
  if (has_options_string == "yes") {
    return true;
  } else {
    return false;
  }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
  std::cout << std::fixed << std::setprecision(2)
            << "dappreciation will list your car for $" << resale_price
            << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
  std::cout << "Unfortunately your car is ineligible for the dappreciation "
               "platform.\n";
}

int main() {
    //variables & constants
    int year, accidents ;
    double msrp, finalPrice, percent;
    bool premium = false;

    double const TIER_ONE_BASE = 85.00;
    double const TIER_TWO_BASE = 63.00;
    double const TIER_THREE_BASE = 45.00;
    double const ONE_ACCIDENT = 2.00;
    double const TWO_ACCIDENT = 10.00;
    double const THREE_ACCIDENT = 20.00;
    double const HAS_PREMIUM = 5.00;




    //inputs
    percent = 0.0;
    year = car_model_year();
    accidents = car_accidents();
    //asking the user if there are premium options and assigning the correct bool value to premium
    premium = car_has_premium_options();
    msrp = car_msrp();

    //calculation to determine resale if eligible
    if ((2023 - year) < 11 && accidents <= 3) {
        //age
        if ((2023 - year) < 5) {
            percent = TIER_ONE_BASE;
        }
        else if ((2023 - year >= 5) && (2023 - year <= 8)) {
            percent = TIER_TWO_BASE;
        }
        else if ((2023 - year == 9) || (2023 - year == 10)) {
            percent = TIER_THREE_BASE;
        }
        
        //number of accidents
        if (accidents == 1) {
            percent -= ONE_ACCIDENT;
        }
        else if (accidents == 2) {
            percent -= TWO_ACCIDENT;
        }
        else if (accidents == 3) {
            percent -= THREE_ACCIDENT;
        }

        //premium option
        if (premium) {
            percent += HAS_PREMIUM;
        }

        //resale price
        finalPrice = msrp * (percent / 100.0);

        print_eligible_message(finalPrice);
    }
    else {
        print_ineligible_message();
    }


    return 0;
}
