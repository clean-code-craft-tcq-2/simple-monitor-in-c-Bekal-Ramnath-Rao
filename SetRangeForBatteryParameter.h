#ifndef SETRANGEFORBATTERYPARAMETER_H__
#define SETRANGEFORBATTERYPARAMETER_H__

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

extern void setSafetyRangeforTemperature(float,float);
extern void setSafetyRangeforStateOfCharge(float,float);
extern void setThresholdforChargeRate(float);

#endif