#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);


//0023:00:0055EF
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(38400);
 
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
  char c=Serial.read();
  mySerial.write(c);
}
  if(mySerial.available())
{
  char c=mySerial.read();
  Serial.write(c);
}
}
