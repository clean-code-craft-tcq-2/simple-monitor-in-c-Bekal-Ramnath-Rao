#ifndef WARNINGBATTERYPARAMETEROUTOFRANGE_H__
#define WARNINGBATTERYPARAMETEROUTOFRANGE_H__

#define WARNING_TOLERANCE_TEMPERATURE 0.05 //can set to 0 if tolearance is not required for any of the parameter
#define WARNING_TOLERANCE_SOC 0.05
#define WARNING_TOLERANCE_CHARGERATE 0.05

extern void warningBatteryTempnearOutofRange(float , void (*)(float, char*, char*));
extern void warningBatterySOCnearOutofRange(float, void (*)(float, char*,char*));
extern void warningBatteryChargeRatenearOutofRange(float, void (*)(float, char*,char*));

#endif