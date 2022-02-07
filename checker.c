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

//Adding the Notification Inteface for User to Take Safety Actions
void printOnConsole(float parameterValue, char* parameter,char* nonsafeCondition)
{
	printf("%s is %s than %f\n",parameter,nonsafeCondition,parameterValue);
}

void notifyTemperatureOutofRange(float temperature)
{
	if(temperature > Temperature.high)
	{
		printOnConsole(temperature,"Temperature","Higher than");
	}
	else
	{
		printOnConsole(temperature,"Temperature","Lower than");
	}
}

void notifySOCOutofRange(float soc)
{
	if(soc > StateOfCharge.high)
	{
		printOnConsole(soc,"SOC","Higher than");
	}
	else
	{
		printOnConsole(soc,"SOC","Lower than");
	}
}

void notifyChargeRateOutofRange(float chargeRate)
{
	printOnConsole(chargeRate,"ChargeRate","is above threshold");
}

int monitorBatteryTemperature(float temperature)
{
	if(temperature<Temperature.low || temperature>Temperature.high)
	{
		notifyTemperatureOutofRange(temperature);
		return 0;
	}
	else
	{
		return 1;
	}
}


int monitorStateOfCharge(float soc)
{
	if(soc<StateOfCharge.low || soc>StateOfCharge.high)
	{
		notifySOCOutofRange(soc);
		return 0;
	}
	else
	{
		return 1;
	}
}

int monitorChargeRate(float chargeRate)
{
	if(chargeRate>ChargeRate.limit)
	{
		notifyChargeRateOutofRange(chargeRate);
		return 0;
	}
	else
	{
		return 1;
	}
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
