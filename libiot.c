#include <stdlib.h>
#include <string.h>

#define IOT_PORT	8

int iotgeti(const char* device_path) {
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x53);
  outp(IOT_PORT, 0xC0);
  int l = strlen(device_path);
  outp(IOT_PORT, l);
  for(int i = 0; i < l; i++) {
    outp(IOT_PORT, device_path[i]);
  }
  outp(IOT_PORT, 0x00);
  unsigned char r[2];
  r[0] = inp(IOT_PORT);
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x80);
  r[0] = inp(IOT_PORT);
  r[0] = inp(IOT_PORT);
  r[1] = inp(IOT_PORT);
  return *((int*)r);
}

int iotgets(const char* device_path, char* result) {
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x53);
  outp(IOT_PORT, 0xC0);
  int l = strlen(device_path);
  outp(IOT_PORT, l);
  for(int i = 0; i < l; i++) {
    outp(IOT_PORT, device_path[i]);
  }
  outp(IOT_PORT, 0x00);
  result[0] = inp(IOT_PORT);
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x03);
  outp(IOT_PORT, 0x80);
  l = inp(IOT_PORT);
  for(int i = 0; i < l; i++) {
    result[i] = inp(IOT_PORT);
  }
  result[l] = 0; // add null terminator
  return l;
}

int iotputi(const char* device_path, int value) {
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x53);
  outp(IOT_PORT, 0xC0);
  int l = strlen(device_path);
  outp(IOT_PORT, l);
  for(int i = 0; i < l; i++) {
    outp(IOT_PORT, *device_path);
    device_path++;
  }
  outp(IOT_PORT, 0x00);
  int r = inp(IOT_PORT);
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x41);
  outp(IOT_PORT, 0xC0);
  outp(IOT_PORT, 0x02);
  outp(IOT_PORT, value & 0x00ff);
  outp(IOT_PORT, value & 0xff00);
  return 0;
}

int iotputs(const char* device_path, char* value) {
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x53);
  outp(IOT_PORT, 0xC0);
  int l = strlen(device_path);
  outp(IOT_PORT, l);
  for(int i = 0; i < l; i++) {
    outp(IOT_PORT, *device_path);
    device_path++;
  }
  outp(IOT_PORT, 0x00);
  int r = inp(IOT_PORT);
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x43);
  outp(IOT_PORT, 0xC0);
  l = strlen(value);
  outp(IOT_PORT, l);
  for(int i = 0; i < l; i++) {
    outp(IOT_PORT, *value);
    value++;
  }
  outp(IOT_PORT, 0x00);
  r = inp(IOT_PORT);
}

int iotfindi(const char* device_path) {
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x53);
  outp(IOT_PORT, 0xC0);
  int l = strlen(device_path);
  outp(IOT_PORT, l);
  for(int i = 0; i < l; i++) {
    outp(IOT_PORT, *device_path);
    device_path++;
  }
  outp(IOT_PORT, 0x00);
  unsigned char r[2];
  r[0] = inp(IOT_PORT);
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x11);
  outp(IOT_PORT, 0x80);
  r[0] = inp(IOT_PORT);
  r[0] = inp(IOT_PORT);
  r[1] = inp(IOT_PORT);
  return *((int*)r);
}

int iotfinds(const char* device_path, char** result, int num) {
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x53);
  outp(IOT_PORT, 0xC0);
  int l = strlen(device_path);
  outp(IOT_PORT, l);
  for(int i = 0; i < l; i++) {
    outp(IOT_PORT, *device_path);
    device_path++;
  }
  outp(IOT_PORT, 0x00);
  int ret = inp(IOT_PORT);
  outp(IOT_PORT, 0xE0);
  outp(IOT_PORT, 0x01);
  outp(IOT_PORT, 0x13);
  outp(IOT_PORT, 0x80);
  for(int i = 0; i < num; i++) {
    l = inp(IOT_PORT);
    for(int j = 0; j < l; j++) {
      result[i][j] = inp(IOT_PORT);
    }
    result[i][l] = 0;
  }
  return 0;
}