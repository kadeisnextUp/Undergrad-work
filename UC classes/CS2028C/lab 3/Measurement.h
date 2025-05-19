#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <iostream>
#include <string>

//All code was developed by Javon Kimbrough, Kira Brown Johnson, and Kaden Sawyer
class Measurement {
private:
    int littles;
    int lots;
    int heaps;

public:
    Measurement();
    Measurement(int l, int lo, int h);
    Measurement(int totalLittles);

    // getters and setters
    int getLittles() const;
    int getLots() const;
    int getHeaps() const;

    void setLittles(int l);
    void setLots(int lo);
    void setHeaps(int h);

    void printMeasurement() const;

    //operator overload
    operator std::string() const;
    void operator- (const Measurement&);
    void operator+ (const Measurement&);
    void operator* (const Measurement&);
    void operator/ (const Measurement&);
    bool operator== (const Measurement&);

    // special functions
    void simplify();
    int inMeters();
};

#endif  // MEASUREMENT_H
