#include <cmath>
#include <iostream>
#include "developed_lot.hpp"
#include <cstdio>
#include <cassert>
using namespace developed_lot;

DevelopedLot::DevelopedLot() : Lot(0.0, 0.0, 0.0, 0.0),
                               floor_area(0),
                               num_floors(0) {};

DevelopedLot::DevelopedLot(double latitude, double longitude, double width, double length, double floor_area, int num_floors) : Lot(latitude, longitude, width, length),
                                                                                                                                floor_area(floor_area),
                                                                                                                                num_floors(num_floors) {};

DevelopedLot::~DevelopedLot() = default;

double DevelopedLot::value() const
{
    return Lot::value() + (100 * this->floor_area * this->num_floors);
};

double DevelopedLot::floor_area_ratio() const
{
    return (this->floor_area * this->num_floors) / this->land_area();
};

void developed_lot_test()
{
    developed_lot::DevelopedLot dlot1 =
        developed_lot::DevelopedLot(18.776, 108.5, 122.8, 19.1, 0, 0);

    developed_lot::DevelopedLot dlot2 =
        developed_lot::DevelopedLot(-90.909090, 180.364, 6.8, 4.4, 60.1, 10);

    double val1 = dlot1.value();
    std::cout << "Val1:" << val1 << std::endl;
    double val2 = dlot2.value();
    std::cout << "Val2:" << val2 << std::endl;

    assert(val1 == 37527.68);
    assert(val2 == 60578.72);
};

Office::Office(double a, double b, double c, double d, double e, int f, int g) : DevelopedLot(a, b, c, d, e, f), num_of_offices(g) {}
double Office::value() const
{
    return DevelopedLot::value() + 200 * num_of_offices;
}

int main()
{
    developed_lot_test();
};
