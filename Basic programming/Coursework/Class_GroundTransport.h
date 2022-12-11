#pragma once

#include "Class_Transport.h"

class GroundTransport : public Transport
{
protected:
    int travelTimeToRest;
    double restTime1;
public:
    GroundTransport();
    virtual double resultCalculation(int distance) const override;
};