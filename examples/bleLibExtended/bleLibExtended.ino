typedef error int;
bleDevice myDevice;
bleService myService;
#define SERVICE_UUID = {0x00,0x00};
#define CHAR_OUTPUT_UUID = {};
#define CHAR_INPUT_UUID = {};
#define CHAR_SENSOR_VALUE_UUID = {};
#define CHAR_VALUE_FORMAT_UUID

bleCharacteristic charOutput, charInput, charSensorValue, charValueFormat;

void Setup(){
  ble.startDeviceScan(bleDevice checkDevice,error errorHandler);
  Serial.println("Searching devices");
  while(!ble.foundDevice()){
    printf(".");
    delay(10);
  }
  Serial.println();

  myDevice.startServiceScan(bleService checkService,error errorHandler);
  Serial.println("Searching services");
  while(!myDevice.foundService()){
    printf(".");
    delay(10);
  }
  Serial.println();

  myService.startCharacteristicScan(cleCharacteristic checkCharacteristic,error errorHandler);
  Serial.println("Searching services");
  while(!myDevice.foundCharacteristic()){
    printf(".");
    delay(10);
  }
  Serial.println();
}
void Loop(){
  uint8_t command[] = {0x00,0x00,0x00}
  charInput.write(command,[](uint8_t* result){

  });
  uint8_t command[] = {0x00,0x00,0x00}
  charInput.read([](uint8_t* result){

  });
  charSensorValue.setNotifier([](uint8_t* result){

  })
}
boolean checkDevice(bleDevice currentDevice){
  if (bleDevice.name == "test"){
    myDevice = currentDevice;
    //stop searching
    return true;

  }else{
    //keep on searching
    return false;
  }
}

boolean checkService(bleDevice currentDevice){
  if (bleDevice.UUID16 == SERVICE_UUID){
    myDevice = currentDevice;
    //stop searching
    return true;

  }else{
    //keep on searching
    return false;
  }
}
boolean checkCharacteristic(bleDevice currentDevice){
  if (bleDevice.UUID16 == CHAR_INPUT_UUID){
    charInput = currentDevice;
  }else if (bleDevice.UUID16 == CHAR_OUTPUT_UUID){
    charOutput = currentDevice;
  }else if (bleDevice.UUID16 == CHAR_SENSOR_VALUE_UUID){
    charSensorValue = currentDevice;
  }else if (bleDevice.UUID16 == CHAR_VALUE_FORMAT_UUID){
    charValueFormat = currentDevice;
  }
  return false;
}
void errorHandler(error currentError){
  printf("Error number: %i",error);
}
