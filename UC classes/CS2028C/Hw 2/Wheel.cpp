#include "Wheel.h"
using namespace std;

//Pass min and max into range_min and range_max


Wheel::Wheel(int min, int max) : range_min(min), range_max(max) {
    value = 0;
}


//The value is calculated by using a random number in the wheel's range
void Wheel::spin() {
    value = range_min + rand() % (range_max - range_min + 1);
}

//Get the value of the wheel from the private member 
int Wheel::getValue() const {
    return value;
}

//Update the max and min value in the private member to match the inputed values
void Wheel::setRange(int min, int max) {
    range_min = min;
    range_max = max;
}



//hardmode
int HardModeWheel::getRangeMax() const { 
    return getValue();
}

void HardModeWheel::spin(int playerResult) {

    Wheel::spin();
    int houseResult = getValue();


    if (houseResult > playerResult) {
        HouseWins++;
        HouseLosses = 0;
    }
    else {
        HouseLosses++;
        HouseWins = 0;
    }


    if (HouseLosses == 2) {
        int newMax = getRangeMax() * 2;
        setRange(1, newMax);
        HouseLosses = 0;
    }


    if (HouseWins == 2) {
        int newMax = getRangeMax() / 2;
        if (newMax < 10) newMax = 10;
        setRange(1, newMax);
        HouseWins = 0;
    }
}


