#ifndef SETRANGEFORBATTERYPARAMETER_H__
#define SETRANGEFORBATTERYPARAMETER_H__

struct 
{
	float low;
	float high;
	float highAlert;
	float lowAlert;
}Temperature;

struct  
{
	float low;
	float high;
	float highAlert;
	float lowAlert;
}StateOfCharge;

struct 
{
	float limit;
	float limitAlert;
}ChargeRate;

extern void setSafetyRangeforTemperature(float,float);
extern void setSafetyRangeforStateOfCharge(float,float);
extern void setThresholdforChargeRate(float);

#endif