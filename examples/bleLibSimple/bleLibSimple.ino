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
  myDevice = ble.startDeviceScanName("test");
  Serial.println("device found");
  myService = myDeivce.startServiceScanUUID(SERVICE_UUID);
  Serial.println("service found");
  charInput = myService.startCharacteristicScanUUID(CHAR_INPUT_UUID);
  charOutput = myService.startCharacteristicScanUUID(CHAR_OUTPUT_UUID);
  charSensorValue = myService.startCharacteristicScanUUID(CHAR_SENSOR_VALUE_UUID);
  charValueFormat = myService.startCharacteristicScanUUID(CHAR_VALUE_FORMAT_UUID);
  Serial.println("found characteristics");
}

void Loop(){
  uint8_t command[] = {0x00,0x00,0x00}
  charInput.write(command,[](uint8_t* result,int len){

  });
  uint8_t command[] = {0x00,0x00,0x00}
  charInput.read([](uint8_t* result,int len){

  });
  charSensorValue.setNotifier([](uint8_t* result,int len){

  });
}
