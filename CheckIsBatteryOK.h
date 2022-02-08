#ifndef CHECKISBATTERYOK_H__
#define CHECKISBATTERYOK_H__

extern int batteryIsOk(float , float , float, 
	                   int (*[])(float,void (*[])(float,void (*)(float, char*,char*)),void (*)(float, char*,char*)),
	                   void (*[])(float, void (*)(float, char*,char*)),
	                   void (*)(float, char*,char*));

#endif