#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <DHT.h>
#define dhtPin 5
#define dhtType DHT11
//Create a DHT object of DHT type
DHT dht(dhtPin, dhtType);

//Need a WiFi hotspot to connect NodeMCU with
//Create char type pointer to store name and password of mobile hotspot
const char* ssid = "i";
const char* password = "testing123";

//Create a WiFi client to test the connection
WiFiClient client;
//Use channel ID
unsigned long myChannel = 1638700;
//Write key
const char* myKey = "3TUJD72OPB2VFMOD";

int count = 0;

void setup() {
  //Initiate WiFi communication with buad rate of 9600
  Serial.begin(9600);
  //Initiate WiFi communication
  WiFi.begin(ssid, password);
  //Initiate communication with ThingSpeak platform
  ThingSpeak.begin(client);
  //Initiate DHT
  dht.begin();
}

void loop() {
  int temp = dht.readTemperature();
  int humidity - dht.readHumidity();
  //Send data to ThingSpeak platform every 15secs
  if (count == 0)
  {
    //Temp data stored in field 1 
    ThingSpeak.writeField(myChannel, 1, temp, myKey);
    count = 1;
  }
  else if (count == 1)
  {
    //Humidity data stored in field 2
    ThingSpeak.writeField(myChannel, 2, hum, myKey);
    count = 0;
  }
  delay(16000);
}
