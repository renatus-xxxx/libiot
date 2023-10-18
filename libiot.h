#ifndef __LIBIOT_H__
#define __LIBIOT_H__

int iotgeti(const char* device_path);
int iotgets(const char* device_path, char* result);
int iotputi(const char* device_path, int   value);
int iotputs(const char* device_path, char* value);
int iotfindi(const char* device_path);
int iotfinds(const char* device_path, char** result, int num);

#endif
