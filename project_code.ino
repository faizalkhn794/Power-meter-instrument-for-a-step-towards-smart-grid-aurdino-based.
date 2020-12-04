#define dht_apin A3
#include <SoftwareSerial.h>
#include <LiquidCrystal.h> 
#include <dht.h> 
#define Read_Current  = A0;

pinMode(3,OUTPUT);

float adcvaluve,adcvolatage,power = 0.0;
float powerfactor = 0.85;
float Current = 0.0;
float Power = 0.0;
float humidity = 0.0;
float temprature = 0.0;
float volatge = 230;

char RECIVED_SMS [] 

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

char mobileNumber; 
SoftwareSerial SIM900(9, 10);

void setup() 
{
  digitalWrite(6,HIGH);
  Serial.begin(19200); // this is for coomunication with LCD screen
  mySerial.begin(19200); // this is for communication with arduino board and sim900 board
  lcd.begin(16, 2); 
  lcd.print("     Arduino    "); 
  lcd.setCursor(0, 1);
  
  lcd.print("      "); 

  delay(2000);
  lcd.clear();
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  mySerial.println("AT+CNMI=0"); // Decides how newly arrived SMS messages should be handled,this command will only read text recived to the sim
  updateSerial();
}
  
void loop() 
{
 Serial.println("DHT11 Humidity & temperature Sensor\n\n");
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    humidity = DHT.humidity;
    Serial.print(humidity);
    Serial.print("%  ");
    Serial.print(\n);
    Serial.print("temperature = ");
    temprature = DHT.temprature;
    Serial.print(temprature); 
    Serial.println("C  ");
    
    delay(5000);
 
 adcValue = analogRead(Read_Current);
 adcVoltage = (adcValue / 1024.0) * 5000;
 current = ((adcVoltage - offsetVoltage) / sensitivity);
 Serial.println(current value is = );
 Serial.println(current);/// this is the rms value of the current

 

 lcd.setCursor(0, 0);
 lcd.print(" "); 
 lcd.print("I=");
 lcd.print(Current); 
 lcd.setCursor(0, 1);
 power = current*voltage*0.85;
 lcd.print("P="); 
 lcd.print(Power); 
 delay(1000);
 void updateSerial();
}

void updateSerial()
{
  delay(500);
  
  while(mySerial.available()) 
  {
    RECIVED_SMS = (mySerial.read());//stores the recived sms in the variable
  }
  if(RECIVED_SMS == POWER)
  {
    mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
    mySerial.println("AT+CMGS=\"+917007925936\"");//i have put my own phone number in this 
    mySerial.print("POWER CONSUMED = %f /n,CURRENT CONSUMED = %f',power,current); 
  }//send back info to the mobile
  else if(RECIVED_SMS == HUMIDITY)
  { 
    mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
    mySerial.println("AT+CMGS=\"+917007925936\""); //i have put my own phone number in this 
    mySerial.print("temprature = %f /n,temprature = %f',humidity,temprature);  //text that the board will send to the number
  }// send back requested info to mobile
  else if(RECIVED_SMS == DECREASE_LOAD)
  {
   digitalRight(6,LOW); // this will disable the high loaded connected load
    mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
    mySerial.println("AT+CMGS=\"+917007925936\""); //i have put my own phone number in this 
    mySerial.print("high load has been disable");  
  } 
  else 
  {
    if(
    lcd.print(RECIVED_SMS);
  }
}
