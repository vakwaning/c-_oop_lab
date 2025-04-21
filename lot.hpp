#pragma once

namespace lot {
class Lot{
private:
    double latitude;
    double longitude;
    double width;
    double length;

public:
    Lot();
    Lot(double, double, double, double);
    virtual ~Lot();
    double get_latitude();
    double get_longitude();
    double virtual value() const;

protected:
    double land_area() const;
};
};