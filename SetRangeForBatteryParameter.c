#include "SetRangeForBatteryParameter.h"

//  why defining seperate set functions for different parameters? --> if different customer need  different range and limit
void setSafetyRangeforTemperature(float low, float high)
{
	Temperature.low = low;
	Temperature.high = high;
}

void setSafetyRangeforStateOfCharge(float low, float high)
{
	StateOfCharge.low = low;
	StateOfCharge.high = high;
}

void setThresholdforChargeRate(float limit)
{
	ChargeRate.limit = limit;
}