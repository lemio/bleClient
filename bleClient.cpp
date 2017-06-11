
/*Ble::Ble(){
}*/
#include "bleClient.h"
void Ble::startDeviceScan(boolean (*searchDeviceFunction)(bleDevice)){
  for(int i=0;i<10;i++){
    bleDevice myDevice;
    if (i == 5){
      myDevice.setName(TEST_NAME_CORRECT,4);
      myDevice.setUUID(TEST_UUID_CORRECT);
    }else{
      myDevice.setName(TEST_NAME_WRONG,4);
      myDevice.setUUID(TEST_UUID_WRONG);
    }
    if (searchDeviceFunction(myDevice)){
      break;
    }
  }
}
bleDevice Ble::startDeviceScanName(char* name,int len){
  //startDeviceScan(
}

void bleDevice::setName(char* name, int len){
  _name = name;
  _nameLen = len;
}
void bleDevice::setUUID(uuidType uuid){
  _uuid = uuid;
}
boolean bleDevice::hasName(char* name, int len){
  if (len == _nameLen){
    for(int i=0;i<_nameLen;i++){
      if (_name[i] != name[i]){
        return false;
      }

    }
    return true;
  }
}
boolean Ble::deviceScanNameFunction(bleDevice currentDevice){
    if (currentDevice.hasName(_search_name,_search_name_len)){
      //return currentDevice;
    }
}
uuidType bleDevice::getUUID(){
  return _uuid;
}
