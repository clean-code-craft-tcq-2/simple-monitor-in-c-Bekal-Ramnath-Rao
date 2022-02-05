#include <stdio.h>
#include <assert.h>

int compareBatteryParameter(float value,float lower_limit,float upper_limit)
{
	if( value<lower_limit || value>upper_limit)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
	return (compareBatteryParameter(temperature,0,45)&&
		    compareBatteryParameter(soc,20,80)&&
		    compareBatteryParameter(chargeRate,0,0.8));

}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
