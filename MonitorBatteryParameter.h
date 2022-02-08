#ifndef MONITORBATTERYPARAMETER_H__
#define MONITORBATTERYPARAMETER_H__

extern int monitorBatteryTemperature(float, 
	                                 void (*[])(float,void (*)(float, char*,char*)),
	                                 void (*)(float, char*,char*));
extern int monitorStateOfCharge(float, 
	                            void (*[])(float,void (*)(float, char*,char*)),
	                            void (*)(float, char*,char*));
extern int monitorChargeRate(float, 
	                         void (*[])(float,void (*)(float, char*,char*)),
	                         void (*)(float, char*,char*));

#endif