#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
void setup()
{
   Serial.begin(9600); 
pinMode(13, OUTPUT);  
   if(!accel.begin())
   {
      Serial.println("No valid sensor found");
      while(1);
   }
}
void loop() 
{
sensors_event_t event; 
accel.getEvent(&event);
const int x= event.acceleration.x;
const int y= event.acceleration.y;
Serial.print("X=");
Serial.print(x);
Serial.print("  ");
Serial.print("Y=");
Serial.println(y);
//Serial.print(analogRead(x));

//Serial.print(analogRead(y));

if (x>7 || x<-7){
  digitalWrite(13, HIGH); 
  delay(3400);
  digitalWrite(13,LOW);
  sendAlert();
}
if (y>7 || y<-7){
  digitalWrite(13, HIGH); 
  delay(3400);
  digitalWrite(13,LOW);
  sendAlert();
}
delay(300);
}
void sendAlert()
{
  Serial.println("Fall Detected");
}
