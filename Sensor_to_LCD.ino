#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11 
DHT dht11(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  float temp = 0.0;
  float humid = 0.0;
  Serial.begin(9600);
  dht11.begin();
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("Humid:");
  lcd.setCursor(0, 1);
  lcd.print("Temp:");
}

void loop() {
  float humid = dht11.readHumidity();
  float temp = dht11.readTemperature();
  lcd.setCursor(7, 0);
  lcd.print(humid);
  lcd.print(" %");
  lcd.setCursor(6, 1);
  lcd.print(temp);
  lcd.print(" C");
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("\t");
  Serial.print("Humid: ");
  Serial.println(humid);
  delay(1000);
}
