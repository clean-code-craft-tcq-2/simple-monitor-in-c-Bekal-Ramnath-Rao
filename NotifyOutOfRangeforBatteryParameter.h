#ifndef NOTIFYOUTOFRANGEFORBATTERYPARAMETER_H__
#define NOTIFYOUTOFRANGEFORBATTERYPARAMETER_H__

extern void notifyTemperatureOutofRange(float, void (*)(float, char*,char*));
extern void notifySOCOutofRange(float, void (*)(float, char*,char*));
extern void notifyChargeRateOutofRange(float, void (*)(float, char*,char*));

#endif