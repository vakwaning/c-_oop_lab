#include <cmath>
#include <iostream>
#include "lot.hpp"
#include <cstdio>
using namespace lot;

Lot::Lot(){
    this->latitude = 0;
    this->longitude = 0;
    this->width = 0;
    this->length = 0;
};

Lot::Lot(double latitude, double longitude, double width, double length){
    this->latitude = latitude;
    this->longitude = longitude;
    this->width = width;
    this->length = length;
};

Lot::~Lot() = default;

double Lot::get_latitude(){
    return this->latitude;
};

double Lot::get_longitude(){
    return this->longitude;
}

double Lot::land_area() const{
    return this->length * this->width;
};

double Lot::value() const{
    return 16 * this->land_area();
};

void lot_test() {
    lot::Lot lot1 = lot::Lot(0, 0, 0, 0);
    lot::Lot lot2 = lot::Lot(18.776, 108.5, 122.8, 19.1);
    lot::Lot lot3 = lot::Lot(-90.909090, 180.364, 6.8, 4.4);

    double val1 = lot1.value();
    double val2 = lot2.value();
    double val3 = lot3.value();

    assert(val1 == 0);
    assert(val2 == 37527.68);
    assert(val3 == 478.72);
};

//int main() {
//    lot_test();
//};