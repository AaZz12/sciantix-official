#ifndef FUELELEMENT_H
#define FUELELEMENT_H

#include "Entity.h"

class FuelElement : virtual public Entity
{
protected:
    double length;
    double defect_type; //1 if mid lenght, 0.5 if end rod, ...
    double free_volume;
    double sheath_surface;
    double sheath_temperature;

public:
    void setLength(double y)
    {
        length = y;
    }

    double getLenght()
    {
        return length;
    }

    void setDefectType(double y)
    {
        defect_type = y;
    }

    double getDefectType()
    {
        return defect_type;
    }

    void setFreeVolume(double y)
    {
        free_volume = y;
    }

    double getFreeVolume()
    {
        return free_volume;
    }

    void setSheathSurface(double y)
    {
        sheath_surface = y;
    }

    double getSheathSurface()
    {
        return sheath_surface;
    }

    void setSheathTemperature(double y)
    {
        sheath_temperature = y;
    }

    double getSheathTemperature()
    {
        return sheath_temperature;
    }

    FuelElement(){ }
    ~FuelElement(){ }


};

#endif