#include <stdio.h>
#include "bleClient.h"

Ble myBle;
bleDevice myDevice;
int checkDevice(bleDevice currentDevice);
int foundDevice = false;
int main(){

  //ble myBle();
  //myBle.startDeviceScanName("test",4);
myBle.startDeviceScan(checkDevice);
  while(!foundDevice){

  }

  printf("found Device\n");

  printf("The value is %i",myDevice.getUUID());
}

boolean checkDevice(bleDevice currentDevice){
  printf("checkDevice\n");
  if (currentDevice.hasName("test",4)){
    printf("name is correct, UUID %i",currentDevice.getUUID());
    myDevice = currentDevice;
    foundDevice = true;
    return true;
  }else{
    //keep on searching
    return false;

  }
}
