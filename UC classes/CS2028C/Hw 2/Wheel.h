
#ifndef WHEEL_H
#define WHEEL_H

#include <cstdlib>
#include <ctime>
class Wheel
{
private:
	int range_max;
	int range_min;
	int value;
public:

    Wheel(int min = 1, int max = 10 );
	void spin();
	int getValue() const;
	void setRange(int min, int max);


};

class HardModeWheel : public Wheel {
private:
    int HouseWins; 
    int HouseLosses; 
public:
    //hard mode constructor
    HardModeWheel(int min = 1, int max = 10) : Wheel(min, max), HouseWins(0), HouseLosses(0) {}

	void spin(int playerResult);
	int getRangeMax() const;
    
};

#endif