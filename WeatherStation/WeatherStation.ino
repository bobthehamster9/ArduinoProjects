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

void setup(void)
{
  sensors.begin();
  lcd.begin(16,2);
}

void loop(void)
{ 
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
  lcd.print("Humidity:");
  lcd.setCursor(9, 1);
  lcd.print(DHT.humidity);
  lcd.setCursor(14, 1);
  lcd.print("%");
  delay(50);
}
