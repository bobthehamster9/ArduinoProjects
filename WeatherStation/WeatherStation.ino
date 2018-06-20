//Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include <dht.h>


// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 8
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

dht DHT;

#define DHT11_PIN 9

const int hallPin=12;
const unsigned long sampleTime=1000;
const int maxRPM = 10200; 

void setup(void)
{
  sensors.begin();
  lcd.begin(16,2);
  pinMode(hallPin,INPUT);
}

void loop(void)
{ 
  int rpm=getRPM();
  int chk = DHT.read11(DHT11_PIN);
  // Send the command to get temperatures
  sensors.requestTemperatures();  
  //Serial.print("Temperature is: ");
  //Serial.println(sensors.getTempCByIndex(0));
  
  //Update value every 1 sec.
  delay(10);
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(6, 0);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.setCursor(4, 1);
  lcd.print(DHT.humidity);
  lcd.setCursor(8, 1);
  lcd.print("%");
  lcd.setCursor(10, 1);
  lcd.print("km:");
  lcd.setCursor(13, 1);
  lcd.print(10 * rpm * 0.001885);
  delay(100);
}

int getRPM()
{
  // sample for sampleTime in millisecs
  int kount=0;
  boolean kflag=LOW;
  unsigned long currentTime=0;
  unsigned long startTime=millis();
  while (currentTime<=sampleTime)
  {
    if (digitalRead(hallPin)==HIGH)
    {
      kflag=HIGH;
    }
    if (digitalRead(hallPin)==LOW && kflag==HIGH)
    {
      kount++;
      kflag=LOW;
    }
    currentTime=millis()-startTime;
  }
  int kount2rpm = int(60000./float(sampleTime))*kount;
  //int rpm2km = int(1 * kount2rpm * 0.001885);
  return kount2rpm;
}
