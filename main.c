#include <stdio.h>
#include "libiot.h"

int main( int argc, char *argv[]) {
  // iotgeti()
  for(int i = 0; i < 100; i++) {
    int accel_x = iotgeti( "device/accel/x" );
    printf( "device/accel/x: %d\n", accel_x );
  }
  printf("hit any key\n");
  int c = getchar();
  /* iotgets() */
  char ip[32];
  int ret = iotgets("host/ip", ip);
  printf("host/ip:%s\n", ip);
  /* iotputi() */
  int vol = iotgeti("conf/sound/volume");
  printf("conf/sound/volume:%d\n", vol);
  vol = (vol + 1) % 10;
  vol = iotputi("conf/sound/volume", vol);
  vol = iotgeti("conf/sound/volume");
  printf("conf/sound/volume:%d\n", vol);
  /* iotputs() */
  char pass[16];
  ret = iotgets("conf/wifi/list/3/pass", pass);
  printf("conf/wifi/list/3/pass:%s\n", pass);
  ret = iotputs("conf/wifi/list/3/pass", "4290FFFF");
  ret = iotputi("conf/save", 1);
  ret = iotgets("conf/wifi/list/3/pass", pass);
  printf("conf/wifi/list/3/pass:%s\n", pass);
  return 0;
}
