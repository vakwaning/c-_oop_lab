#include "lot.hpp"
#include "lot.cpp"
#pragma once

namespace developed_lot
{
    class DevelopedLot : public Lot
    {
    private:
        double floor_area;
        double num_floors;

    public:
        DevelopedLot();
        DevelopedLot(double, double, double, double, double, int);
        virtual ~DevelopedLot();
        double virtual value() const;

    protected:
        double floor_area_ratio() const;
    };
    class Office : public DevelopedLot
    {
    private:
        int num_of_floors;

    public:
        Office(double, double, double, double, double, int, int);
        double virtual value() const;
    }
};
