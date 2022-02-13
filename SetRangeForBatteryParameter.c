#include "SetRangeForBatteryParameter.h"
#include "WarningBatteryParmeternearOutofRange.h"

//  why defining seperate set functions for different parameters? --> if different customer need  different range and limit
void setSafetyRangeforTemperature(float low, float high)
{
	Temperature.low = low;
	Temperature.high = high;
	Temperature.highAlert = Temperature.high - WARNING_TOLERANCE_TEMPERATURE*Temperature.high;
	Temperature.lowAlert = Temperature.low + WARNING_TOLERANCE_TEMPERATURE*Temperature.low;
}

void setSafetyRangeforStateOfCharge(float low, float high)
{
	StateOfCharge.low = low;
	StateOfCharge.high = high;
	StateOfCharge.highAlert = StateOfCharge.high - WARNING_TOLERANCE_SOC*StateOfCharge.high;
	StateOfCharge.lowAlert = StateOfCharge.low + WARNING_TOLERANCE_SOC*StateOfCharge.low;
}

void setThresholdforChargeRate(float limit)
{
	ChargeRate.limit = limit;
	ChargeRate.limitAlert = limit - WARNING_TOLERANCE_CHARGERATE*ChargeRate.limit;
}