#ifndef __LIBIOT_H__
#define __LIBIOT_H__

int iotgeti(const char* device_path);
int iotgets(const char* device_path, char* result);
int iotputi(const char* device_path, int   value);
int iotputs(const char* device_path, char* value);

#endif
