#include <stdio.h>
#include <assert.h>

// Defining the thresholds as global variable, why? --> if different customer need  different threshold
#define TEMP_LIMIT_LOW 0
#define TEMP_LIMIT_HIGH 45

#define SOC_LIMIT_LOW 20
#define SOC_LIMIT_HIGH 80

#define CHARGERATE_LIMIT_LOW 0
#define CHARGERATE_LIMIT_HIGH 0.8

int compareBatteryParameter(float value,float lower_limit,float upper_limit)
{
	return (!(value<lower_limit || value>upper_limit));
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
	return (compareBatteryParameter(temperature,TEMP_LIMIT_LOW,TEMP_LIMIT_HIGH)&&
		    compareBatteryParameter(soc,SOC_LIMIT_LOW,SOC_LIMIT_HIGH)&&
		    compareBatteryParameter(chargeRate,CHARGERATE_LIMIT_LOW,CHARGERATE_LIMIT_HIGH));

}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(50,50,0.5));
  assert(!batteryIsOk(40,85,0.5));
  assert(!batteryIsOk(40,85,1.0));
}
