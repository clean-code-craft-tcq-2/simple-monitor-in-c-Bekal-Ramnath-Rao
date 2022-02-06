#include <stdio.h>
#include <assert.h>

struct 
{
	float low;
	float high;
}Temperature;

struct  
{
	float low;
	float high;
}StateOfCharge;

struct 
{
	float limit;
}ChargeRate;

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

int monitorBatteryTemperature(float temperature)
{
	return (!(temperature<Temperature.low || temperature>Temperature.high));
}


int monitorStateOfCharge(float soc)
{
	return (!(soc<StateOfCharge.low || soc>StateOfCharge.high));
}

int monitorChargeRate(float chargeRate)
{
	return (!(chargeRate>ChargeRate.limit));
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
	return (monitorBatteryTemperature(temperature)&&
		    monitorStateOfCharge(soc)&&
		    monitorChargeRate(chargeRate));

}

int main() {
  setSafetyRangeforTemperature(0,45);
  setSafetyRangeforStateOfCharge(20,80);
  setThresholdforChargeRate(0.8);
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(50,50,0.5));
  assert(!batteryIsOk(40,85,0.5));
  assert(!batteryIsOk(40,85,1.0));
}
