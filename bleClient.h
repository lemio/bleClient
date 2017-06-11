typedef int boolean;
typedef int uuidType;

#define TEST_NAME_CORRECT "test"
#define TEST_UUID_CORRECT 20
#define TEST_UUID_WRONG 15
#define TEST_NAME_WRONG "null"

class bleDevice{
  public:
    //bleDevice();
    //void startServiceScan(void (*searchServiceFunction)(bleService&));
    uuidType getUUID();
    //String getName();
    //bleDevice startDeviceScanName(char* name);
    boolean hasName(char* name,int len);
    void setName(char* name,int len);
    void setUUID(uuidType uuid);
    //foundService();
    //bleService serviceArray[];
  private:
    const char* _name;
    int _nameLen;
    uuidType _uuid;
};

class Ble{
  public:
    //Ble();
    boolean deviceScanNameFunction(bleDevice currentDevice);
    void startDeviceScan(boolean (*searchDeviceFunction)(bleDevice));
    bleDevice startDeviceScanName(char* name, int len);
  private:
    char* _search_name;
    int _search_name_len;
    //bleDevice deviceArray[];
};
class bleCharacteristic{
  public:
    bleCharacteristic();
    /*getUUID();
    read();
    write();
    setNotifier();*/
};

class bleService{
  //static esp_gatt_srvc_id_t service_id
  public:
    bleService();
    startCharacteristicScan(void (*searchCharacteristicFunction)(bleCharacteristic));
    foundCharacteristic();
    //bleCharacteristic characteristicArray[];
};
