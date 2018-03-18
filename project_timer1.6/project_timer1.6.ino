#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

ESP8266WiFiMulti WiFiMulti;
HTTPClient http;
/*
 * set LCD
 */
#include <LiquidCrystal_I2C.h>
#define I2CADDR 0x20 //keypad i2c address 0x27
LiquidCrystal_I2C lcd(0x3F,20,4);// PCF8574A =  0x3F
/*-------------------------------------
 * set keypad
 */
#include <Keypad_I2C.h>
#include <Keypad.h>
#include <Wire.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
// Digitran keypad, bit numbers of PCF8574 i/o port
byte rowPins[ROWS] = {7, 6, 5, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3, 2, 1, 0}; //connect to the column pinouts of the keypad

Keypad_I2C kpd( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574);
/*
 * set eeprom
 */
#include <I2CEEPROM.h>
I2CEEPROM eep(0x57);

//-----------set firebase----------------------
#include <FirebaseArduino.h>
// Config Firebase
#define FIREBASE_HOST "farmbase2-58b2d.firebaseio.com"
#define FIREBASE_AUTH "RbsqyBandXIJgwv8QzjsTk3Un0mchEvSNvxT5MkE"

//-------------date & time---------------//
#include <RTClib.h>
// ----------- DS3231 -------------------------------
RTC_DS3231 RTC;
DateTime Time;
char Year,Mon,Day,Hour,Min,Sec;
//----------------set byte ch1------------------------------------------//
//ch1 alarm1 (relay1)
byte t1on_H = 0, t1on_M = 0, t1on_S = 0;
byte t1off_H = 0, t1off_M = 0, t1off_S = 0;
//ch1 alarm2  (relay1)
byte t2on_H = 0, t2on_M = 0, t2on_S = 0;
byte t2off_H = 0, t2off_M = 0, t2off_S = 0;
//ch1 alarm3 (relay1)
byte t3on_H = 0, t3on_M = 0, t3on_S = 0;
byte t3off_H = 0, t3off_M = 0, t3off_S = 0;
//ch1 alarm4 (relay1)
byte t4on_H = 0, t4on_M = 0, t4on_S = 0;
byte t4off_H = 0, t4off_M = 0, t4off_S = 0;
//ch1 alarm5 (relay1)
byte t5on_H = 0, t5on_M = 0, t5on_S = 0;
byte t5off_H = 0, t5off_M = 0, t5off_S = 0;
//ch1 alarm6 (relay1)
byte t6on_H = 0, t6on_M = 0, t6on_S = 0;
byte t6off_H = 0, t6off_M = 0, t6off_S = 0;
//ch1 alarm7 (relay1)
byte t7on_H = 0, t7on_M = 0, t7on_S = 0;
byte t7off_H = 0, t7off_M = 0, t7off_S = 0;
//ch1 alarm8 (relay1)
byte t8on_H = 0, t8on_M = 0, t8on_S = 0;
byte t8off_H = 0, t8off_M = 0, t8off_S = 0;
//----------------END Alarm ch1-----------------------------------------//

byte Alarm1 = 0, Alarm2 = 0, Alarm3 = 0, Alarm4 = 0, 
     Alarm5 = 0, Alarm6 = 0, Alarm7 = 0, Alarm8 = 0,
     Alarm1_2 = 0, Alarm2_2 = 0, Alarm3_2 = 0, Alarm4_2 = 0, 
     Alarm5_2 = 0, Alarm6_2 = 0, Alarm7_2 = 0, Alarm8_2 = 0;
byte oldMin1 = 0, oldMin2 = 0, oldMin3 = 0, oldMin4 = 0, 
     oldMin5 = 0, oldMin6 = 0, oldMin7 = 0, oldMin8 = 0;
byte oldSec1 = 0, oldSec2 = 0, oldSec3 = 0, oldSec4 = 0, 
     oldSec5 = 0, oldSec6 = 0, oldSec7 = 0, oldSec8 = 0;
byte iChange1 = 0, iChange2 = 0, iChange3 = 0, iChange4 = 0,
     iChange5 = 0, iChange6 = 0, iChange7 = 0, iChange8 = 0;
String WL_Max, WL_Min ,WL_Max_2, WL_Min_2,status_net;
int Maximum = 0,Minimum = 0,Maximum_2 = 0,Minimum_2 = 0 ;
byte h = 0, r = 0,h_2 = 0, r_2 = 0;
byte n = 0 ,n2 =0,s = 0;
byte i_4 = 0;
int Manul_1 = 0,Manul_2 = 0;
String DeviceNumber = "SF-0006";
char getChar;

//Line
//ปั๊มน้ำตัวที่ 1 ทำงาน
String url_1_ok = "http://maker.ifttt.com/trigger/006_Pump_1ok/with/key/nuXF48SEms2-Ru8xXDIfN";
String url_1_no = "http://maker.ifttt.com/trigger/006_Pump_1no/with/key/nuXF48SEms2-Ru8xXDIfN";
//ปั๊มน้ำตัวที่ 2 ทำงาน
String url_2_ok = "http://maker.ifttt.com/trigger/006_Pump_2ok/with/key/nuXF48SEms2-Ru8xXDIfN";
String url_2_no = "http://maker.ifttt.com/trigger/006_Pump_2no/with/key/nuXF48SEms2-Ru8xXDIfN";
//Setup พร้อม
String url_5 = "http://maker.ifttt.com/trigger/006_Setup/with/key/nuXF48SEms2-Ru8xXDIfN";
//ปั๊มน้ำตัวที่ 1 และ 2 ทำงาน
String url_6_ok = "http://maker.ifttt.com/trigger/006_Pump_1_2_OK/with/key/nuXF48SEms2-Ru8xXDIfN";
String url_6_no = "http://maker.ifttt.com/trigger/006_Pump_1_2_NO/with/key/nuXF48SEms2-Ru8xXDIfN";
String url_6_1_ok = "http://maker.ifttt.com/trigger/006_Pump_1ok_2no/with/key/nuXF48SEms2-Ru8xXDIfN";
String url_6_2_ok = "http://maker.ifttt.com/trigger/006_Pump_1no_2ok/with/key/nuXF48SEms2-Ru8xXDIfN";
String url_off = "http://maker.ifttt.com/trigger/006_Pump_Off/with/key/nuXF48SEms2-Ru8xXDIfN";

//Warter
#include <NewPing.h>
#define TRIGGER_1_PIN  D7  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_1_PIN     D8
#define TRIGGER_2_PIN  D5  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_2_PIN     D6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400

NewPing sonar_1(TRIGGER_1_PIN, ECHO_1_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_2(TRIGGER_2_PIN, ECHO_2_PIN, MAX_DISTANCE);
//Current
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads;     /* Use thi for the 12-bit version */
float Current1,Current2,oldCurrent1,oldCurrent2; 

#define Relay1 D4
#define Relay2 D3
//#define LED_wifi  D7
#define Buzzer D0



void SetTimer(){
  delay(50);
  lcd.clear();
  lcd.setCursor(5,1);lcd.print("Set Timer.");
  lcd.setCursor(2,2);lcd.print("Press Key 1 - 8");

  while(1){
    delay(50);
    char key = kpd.getKey();
    switch(key){
      case '1':
      {
        SetTimer1();
        return;
        break; 
      }
      case '2':
      {
        SetTimer2();
        return;
        break; 
      }
      case '3':
      {
        SetTimer3();
        return;
        break; 
      }
      case '4':
      {
        SetTimer4();
        return;
        break; 
      }
      case '5':
      {
        SetTimer5();
        return;
        break; 
      }
      case '6':
      {
        SetTimer6();
        return;
        break; 
      }
      case '7':
      {
        SetTimer7();
        return;
        break; 
      }
      case '8':
      {
        SetTimer8();
        return;
        break; 
      }
      case '*':
      {
        lcd.clear();
        return;
        break;
      }
    }
  }
}
void setWL(){
  lcd.clear();
  delay(50);
  lcd.setCursor(2,0); lcd.print("Set Warter Manu");
  lcd.setCursor(0,1);lcd.print("1:Set Warter_1");
  lcd.setCursor(0,2);lcd.print("2:Set Warter_2");
  lcd.setCursor(0,3);lcd.print("*:Exit");

  while(1){
    delay(50);
    char key = kpd.getKey();
    switch(key){
      case '1' : {
       SetWL_1();
        return;
        break;
        
      }
      case '2' : {
        SetWL_2();
        return;
        break;
        
      }
      case '*' : {
        lcd.clear();
        return;
        break;
      }
   }
  }
  
}

void ShowALMPos(byte Time_H, byte Time_M,byte Time_S, char X, char Y){
  lcd.setCursor(X,Y);
  if(Time_H == 223 || Time_H == 255 || Time_H == 100){
    lcd.print("--");
  }else{
    if(Time_H < 10)lcd.print(0);
    lcd.print(Time_H);
  }
  
  lcd.setCursor(X+3,Y);
   if(Time_M == 223 || Time_M == 255 || Time_M == 100){
    lcd.print("--");
  }else{
    if(Time_M < 10)lcd.print(0);
    lcd.print(Time_M);
  }
  
  lcd.setCursor(X+6,Y);
   if(Time_S == 223 || Time_S == 255 || Time_S == 100){
    lcd.print("--");
  }else{
    if(Time_S < 10)lcd.print(0);
    lcd.print(Time_S);
  }
}
void showtime(char x,char y){
  lcd.setCursor(0,y);lcd.print("Time : ");
  lcd.setCursor(x,y);
  if(Time.hour() < 10){lcd.print(0);}
    lcd.print(Time.hour()); Serial.print(Time.hour());
    lcd.print(':'); Serial.print(':');
  if(Time.minute() < 10){lcd.print(0);}
    lcd.print(Time.minute()); Serial.print(Time.minute());
    lcd.print(':'); Serial.print(':');
  if(Time.second() < 10){lcd.print(0);}
    lcd.print(Time.second()); Serial.println(Time.second());
}

void showdate(char x,char y){
    lcd.setCursor(0,y);lcd.print("Date : "); 
    lcd.setCursor(x,y);
    if(Time.day() < 10){lcd.print(0);}
    lcd.print(Time.day()); Serial.print(Time.day());
    lcd.print('/'); Serial.print('/');
    if(Time.month() < 10){lcd.print(0);}
    lcd.print(Time.month()); Serial.print(Time.month());
    lcd.print('/');Serial.print('/'); 
    if(Time.year()%100 < 10){lcd.print(0);}
    lcd.print(Time.year()%100); Serial.println(Time.year()%100);
  
}

byte count_2 = 0;
void WarterLevel(){
  float pi = 3.141;
  float R1 = r/2,R2 = r_2/2;
  int high_1 = sonar_1.ping_cm();Serial.println(high_1);
  int high_2 = sonar_2.ping_cm();Serial.println(high_2);
  float distance_1 = ((h - (high_1-25))*(pi*R1*R1))/1000;
  lcd.setCursor(0,2);lcd.print("Water_1 :         ");
  lcd.setCursor(10,2);lcd.print(distance_1);
  lcd.setCursor(19,2);lcd.print("L");
  float distance_2 = ((h_2 - (high_2-25))*(pi*R2*R2))/1000;
  lcd.setCursor(0,3);lcd.print("Water_2 :         ");
  lcd.setCursor(10,3);lcd.print(distance_2);
  lcd.setCursor(19,3);lcd.print("L");
  if(s == 1){
    if(count_2 == 0){
      Firebase.setFloat(DeviceNumber + "/water/status1" , distance_1);
      Firebase.setFloat(DeviceNumber + "/water/status2" , distance_2);
      count_2 = 10;
    }
    count_2--;
  }
}

/*
void StatusPump(){
  lcd.setCursor(0,3);lcd.print("P1:     ");
  lcd.setCursor(3,3);lcd.print(Current1,2);
  lcd.setCursor(8,3);lcd.print("A");
  lcd.setCursor(9,3);lcd.print("::P2:     ");
  lcd.setCursor(14,3);lcd.print(Current2,2);
  lcd.setCursor(19,3);lcd.print("A");
}*/

void setup() {
  Wire.begin();
  kpd.begin( makeKeymap(keys) );
  lcd.init();
  RTC.begin();
  lcd.backlight();
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin();
  //pinMode(LED_wifi,OUTPUT);
  pinMode(Relay1,OUTPUT);
  pinMode(Relay2,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  digitalWrite(Relay1,HIGH);
  digitalWrite(Relay2,HIGH);
  Wifi_manege();
  CreatChar();
  Time_Server();
  Serial.println( "start" );
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  delay(100);
  Read1();Read2();Read3();Read4();Read5();Read6();Read7();Read8();ReadWL();
  calSensorValue();
  delay(100);
  Beep2();
  Line(url_5);
}

void loop() {
  Serial.println(n);
  Serial.println(n2);
 char key = kpd.getKey();
      Time = RTC.now();
      Wifi_re();
      Update_Time();
      showdate(8,0); 
      showtime(8,1);
      checkTimer();
      WarterLevel();
      
      GetFB_To_ESP();
    if (key == 'B')    //show mainmenu
    {
        Menu();
        return;
    }
    if (key == 'A')    //show mainmenu
    {
        SetDT();
        return;
    }
    if (key == 'D')    //show mainmenu
    {
      setWL();
      return;

    }
    if (key == 'C')    //show mainmenu
    {
      SetTimer();
      return;
    }
    if(key == '1'){
      if(Manul_1 == 1 || s == 1){
        BeepALM();
        digitalWrite(Relay1,HIGH);
        //Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
        iChange1 = 0, iChange2 = 0, iChange3 = 0, iChange4 = 0,
        iChange5 = 0, iChange6 = 0, iChange7 = 0, iChange8 = 0;
        s = 0;
      }else{
        BeepALM();
        digitalWrite(Relay1,LOW);
        //Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      }
      Manul_1 = !Manul_1;
      return;
    }
    if(key == '2'){
      if(Manul_2 == 1 || s == 1){
        BeepALM();
        digitalWrite(Relay2,HIGH);
        //Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
        iChange1 = 0, iChange2 = 0, iChange3 = 0, iChange4 = 0,
        iChange5 = 0, iChange6 = 0, iChange7 = 0, iChange8 = 0;
        s = 0;
      }else{
        BeepALM();
        digitalWrite(Relay2,LOW);
        //Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      }
      Manul_2 = !Manul_2;
      return;
    }
    if(key == '3'){
      if(Manul_2 == 1 && Manul_1 == 1 || s == 1){
        BeepALM();
        digitalWrite(Relay2,HIGH);
        digitalWrite(Relay1,HIGH);
        //Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
        //Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
        iChange1 = 0, iChange2 = 0, iChange3 = 0, iChange4 = 0,
        iChange5 = 0, iChange6 = 0, iChange7 = 0, iChange8 = 0;
        s = 0;
      }else if(Manul_2 != 1 && Manul_1 != 1){
        BeepALM();
        digitalWrite(Relay2,LOW);
        digitalWrite(Relay1,LOW);
        //Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
        //Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      }
      Manul_2 = !Manul_2;
      Manul_1 = !Manul_1;
      return;
    }
}

void Menu(){
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("A : Reboot");
  lcd.setCursor(0,1); lcd.print("B : Recovery");
  lcd.setCursor(0,2); lcd.print("C : Infomation");
  lcd.setCursor(0,3); lcd.print("* : Exit");
  while(1){
    delay(50);
    char key = kpd.getKey();
    switch(key){
      case '*' : {
       lcd.clear();
        return;
        break;
        
      }
      case 'A' : {
        byte iget = Confirm("Reboot?");
        if (iget == 1) {
          lcd.clear();lcd.setCursor(4,1);lcd.print("Rebooting...");
          delay(2000);
          ESP.reset();
          return;
        } else {
          lcd.clear();
        return;
        }
        break;
      }
      case 'B' : {
        byte iget = Confirm("Recovery?");
        if (iget == 1) {
          lcd.clear();lcd.setCursor(4,1);lcd.print("Recovery...");
          delay(2000);
          Recovery();
          ESP.eraseConfig();
          ESP.reset();
          return;
        } else {
          lcd.clear();
          return;
        }
        break;
        
      }
      case 'C' : {
        Info();
        return;
        break;
      }
   }
  }  
}
void Wifi_manege(){
  //digitalWrite(LED_wifi,HIGH);
  WiFiManager wifiManager;
  //wifiManager.setMinimumSignalQuality(10);
  wifiManager.setTimeout(180);
  //digitalWrite(LED_wifi,LOW);
  lcd.setCursor(2,0);lcd.print("No Connect Wi-Fi");
  lcd.setCursor(0,1);lcd.print("Pleass Connect...!");
  lcd.setCursor(0,2);lcd.print("Wifi: ");lcd.print("SF-0006"); 
  if(!wifiManager.autoConnect("SF-0006","123456789")) { 
    ESP.reset();
    delay(5000);
  } 
  lcd.clear();
}

byte count = 0;
void Wifi_re(){
  if(WiFi.status() != WL_CONNECTED){
    WiFi.begin();
      while (WiFi.status() != WL_CONNECTED) {
        //offline mode
        //digitalWrite(LED_wifi,LOW);
        char key = kpd.getKey();
        if (key != NO_KEY)Beep();
          Time = RTC.now();
          showdate(8,0); 
          showtime(8,1);
          checkTimer();
          WarterLevel();
          //StatusPump();
      //CheckTime();
        if (key == 'B')    //show mainmenu
        {
          Menu();
          return;
        }
        //Beep();
        Serial.println("Disconnect..");
        lcd.setCursor(19,0);lcd.print(" ");
        delay(50);
        count = 1;
      }
    }
    //digitalWrite(LED_wifi,HIGH);
    Serial.println("connect..");
    lcd.setCursor(19,0);lcd.print(char(5));
    if(count == 1){
      lcd.clear();
      Read1();Read2();Read3();Read4();Read5();Read6();Read7();Read8();ReadWL();
       count = 0;
       lcd.clear();
       return;
    }
}

byte Confirm(char a[]){
  delay(50);
  lcd.clear();
  lcd.setCursor(0,0);lcd.print("CONFIRM : ");lcd.print(a);
  lcd.setCursor(0,1);lcd.print("<1> Yes");
  lcd.setCursor(0,2);lcd.print("<2> No");
  lcd.setCursor(0,3);lcd.print("Press NUM 1 or 2");

  delay(50);
  while (1) {
    delay(50);
    char key = kpd.getKey();
    switch (key)
    {
      case '1':
        {
          return 1;
          break;
        }
      case '2':
        {
          return 0;
          break;
        }
      case '*':
        {
          return 0 ;
          break;
        }
    }
  }
}
void Info(){
  lcd.clear();
  lcd.setCursor(4,0); lcd.print("Information.");
  lcd.setCursor(0,1); lcd.print("Number : "); lcd.print(DeviceNumber);
  lcd.setCursor(0,2); lcd.print("IP : "); lcd.print(WiFi.localIP());
  lcd.setCursor(0,3); lcd.print("Version : 1.0 (bata)");
  while(1){
    delay(50);
    char key = kpd.getKey();
    //if(key != NO_KEY)Beep();
    switch(key){
      case '*' : {
        BeepESC();
        Menu();
        return;
        break;
      }
    }
  }
}
void SetDT(){
  Time = RTC.now();
  char key = kpd.getKey();
  lcd.clear();
  lcd.setCursor(5,0); lcd.print("Date&Time");
  while(1){
    delay(50);
    showdate(8,1); 
    showtime(8,2);
        Day = SetDateTime(2,8,1);
        if(Day == 255) goto bailout;
        Mon = SetDateTime(2,11,1);
        if(Mon == 255) goto bailout;
        Year = SetDateTime(2,14,1);
        if(Year == 255) goto bailout;

        Hour = SetDateTime(2,8,2);
        if(Hour == 255) goto bailout;
        Min = SetDateTime(2,11,2);
        if(Min == 255) goto bailout;
        Sec = SetDateTime(2,14,2);
        if(Sec == 255) goto bailout;
        RTC.adjust(DateTime(Year, Mon, Day, Hour, Min, Sec));
        
        bailout:
         lcd.clear();
         return;
         
      if (key == '*')    //show mainmenu
      {
        BeepESC();
        lcd.clear();
        return;
      }
  }
}


void Control_1(){
  delay(100);
  FirebaseObject data = Firebase.get(DeviceNumber + "/control");
 
  int status_1 = data.getInt("pump1/status");
  if(status_1 == 1){
    digitalWrite(Relay1,LOW);
      //Line(url_1);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      n = 1;
      n2 = 0;
      chackCurrent();
  }
  if(status_1 == 0){
    digitalWrite(Relay1,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Line(url_off);
      iChange1 = 0, iChange2 = 0, iChange3 = 0, iChange4 = 0,
      iChange5 = 0, iChange6 = 0, iChange7 = 0, iChange8 = 0;
      n = 0;
      n2 = 0;
      s = 0;
  }
  Firebase.setInt(DeviceNumber + "/Timer/Status/Status", 0);
}

void Control_2(){  
  delay(100);
  FirebaseObject data = Firebase.get(DeviceNumber + "/control");
  
  int status_2 = data.getInt("pump2/status"); 
  if(status_2 == 1){
    digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_3);
      n = 0;
      n2 = 1;
      chackCurrent();
  }
  if(status_2 == 0){
    digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
      iChange1 = 0, iChange2 = 0, iChange3 = 0, iChange4 = 0,
      iChange5 = 0, iChange6 = 0, iChange7 = 0, iChange8 = 0;
      n = 0;
      n2 = 0;
      s = 0;
  }
  Firebase.setInt(DeviceNumber + "/Timer/Status/Status", 0);
}

void SetWL_1(){
  lcd.clear();
  delay(50);
  lcd.setCursor(1,0); lcd.print("Set Warter Level_1");
  /*lcd.setCursor(0,1); lcd.print("Max:");
  lcd.setCursor(4,1); lcd.print(Maximum);
  lcd.setCursor(8,1); lcd.print("L");
  lcd.setCursor(11,1); lcd.print("Min:");
  lcd.setCursor(15,1); lcd.print(Minimum);
  lcd.setCursor(19,1); lcd.print("L");
*/
  lcd.setCursor(0,1); lcd.print("High:");
  lcd.setCursor(10,1); lcd.print(h);
  lcd.setCursor(18,1); lcd.print("cm");
  lcd.setCursor(0,2); lcd.print("Radius:");
  lcd.setCursor(10,2); lcd.print(r);
  lcd.setCursor(18,2); lcd.print("cm");
  
  lcd.setCursor(0,3); lcd.print("A:Set *:EXIT #:Save");
  while(1){
    delay(50);
    char key = kpd.getKey();
    if(key == 'A'){
      h = SetDateTime(3,10,1);
      if (h == 255) goto bailout;

      eep.write(92,h);
      delay(50);
      
      bailout:
        SetWL_1();
        return;
    }
    if(key == 'B'){
      
      r = SetDateTime(3,10,2);
      if (r == 255) goto bailout2;

      eep.write(93,r);
      delay(50);
      SetWL_1();
      
      bailout2:
        SetWL_1();
        return;
    }
    if (key == '*'){
        setWL();
        return;
    }
  }
}
void SetWL_2(){
  lcd.clear();
  delay(50);
  lcd.setCursor(1,0); lcd.print("Set Warter Level_2");
  /*lcd.setCursor(0,1); lcd.print("Max:");
  lcd.setCursor(4,1); lcd.print(Maximum_2);
  lcd.setCursor(8,1); lcd.print("L");
  lcd.setCursor(11,1); lcd.print("Min:");
  lcd.setCursor(15,1); lcd.print(Minimum_2);
  lcd.setCursor(19,1); lcd.print("L");
*/
  lcd.setCursor(0,1); lcd.print("High:");
  lcd.setCursor(10,1); lcd.print(h_2);
  lcd.setCursor(18,1); lcd.print("cm");
  lcd.setCursor(0,2); lcd.print("Radius:");
  lcd.setCursor(10,2); lcd.print(r_2);
  lcd.setCursor(18,2); lcd.print("cm");
  
  lcd.setCursor(0,3); lcd.print("A:Set *:EXIT #:Save");
  while(1){
    delay(50);
    char key = kpd.getKey();
    
    if(key == 'A'){
      h_2 = SetDateTime(3,10,1);
      if (h_2 == 255) goto bailout;

      eep.write(90,h_2);
      delay(50);
      
      bailout:
        SetWL_2();
        return;
    }
    if(key == 'B'){
      r_2 = SetDateTime(3,10,2);
      if (r_2 == 255) goto bailout2;
      
      eep.write(91,r_2);
      delay(50);
      
      bailout2:
        SetWL_2();
        return;
    }
    if (key == '*'){
        setWL();
        return;
    }
  }
}

int SetDateTime(char Num, char X, char Y){
  char xx,yy,xx_bk;
  xx = X;
  xx_bk = xx; //use for key *
  yy = Y  ;  //height cur pos  (top left
  char key, iNum = 0;
  int Sum = 0;
  lcd.blink();
  lcd.setCursor(xx,yy); //lcd.print(' ');
  while(1){
    delay(50);
     key = kpd.getKey();
     //if(key != NO_KEY)Beep();
     if(key == 'C'){
       xx = xx_bk;
       iNum = 0;
       Sum = 0;
       lcd.setCursor(xx,yy); //lcd.print(' ');
     }
     if ( (key == '#') && (iNum >= Num)) {
      Beep2();
      return (Sum);
      }
      if (key == '*') {
      BeepESC();
      lcd.noCursor();
      lcd.noBlink();
      return(255);
      }
      if(key >= '0' && key <= '9' && iNum < Num || key == 'D' && iNum < Num){
        if(key == 'D') key = '-';
        Sum = Sum * 10 + (key - '0');
        lcd.setCursor(xx,yy); lcd.print(key);
        iNum++;

        if(iNum < Num){
          xx++;
          lcd.setCursor(xx,yy); //lcd.print(' ');
        }
      }
      if(iNum >= Num){
        lcd.noCursor();
        lcd.noBlink();
      }
  }
}

int getMaxValue1(){
  int16_t adc0;
  int sensorValue1; 
  int sensorMax1 = 0;
  uint32_t start_time = millis();
  while((millis()-start_time) < 200){
    sensorValue1 = ads.readADC_SingleEnded(0);
    if (sensorValue1 > sensorMax1){
      sensorMax1 = sensorValue1;
    }
  }
  return sensorMax1;
}
int getMaxValue2(){
  int16_t adc1;
  int sensorValue2; 
  int sensorMax2 = 0;
  uint32_t start_time = millis();
  while((millis()-start_time) < 200) {
    sensorValue2 = ads.readADC_SingleEnded(1);
    if (sensorValue2 > sensorMax2){
      sensorMax2 = sensorValue2;
    }
  }
  return sensorMax2;
}

int sensor_max_1,sensor_max_2,a1,a2;
void calSensorValue(){
  ads.begin();
  int sensor_Read1,sensor_Read2;
  lcd.setCursor(2,0);lcd.print("Read Value Sensor");
  for(int i = 1; i<=30 ; i++){
    sensor_Read1 = getMaxValue1();
    a1 += sensor_Read1;
    sensor_Read2 = getMaxValue2();
    a2 += sensor_Read2; 
    lcd.setCursor(0,1);lcd.print("sensor_max1 = "); lcd.print(a1); 
    lcd.setCursor(0,2);lcd.print("sensor_max2 = "); lcd.print(a2);
  }
  lcd.setCursor(5,3);lcd.print("Success..!"); Serial.println("Success..!");
  sensor_max_1 = a1/30;
  lcd.setCursor(0,1);lcd.print("sensor_max1 = "); lcd.print(sensor_max_1);lcd.print("  ");
  Serial.print("sensor_max1 = "); Serial.println(sensor_max_1);
  sensor_max_2 = a2/30;
  lcd.setCursor(0,2);lcd.print("sensor_max2 = "); lcd.print(sensor_max_2);lcd.print("  ");
  Serial.print("sensor_max2 = "); Serial.println(sensor_max_2);
  delay(1000);
  lcd.clear();
}
void chackCurrent(){
  delay(100);
  int sensor_max1,sensor_max2;
  sensor_max1 = getMaxValue1();
  Current1=(float)(sensor_max1-sensor_max_1)*5/65535/0.1/1.141;
  sensor_max2 = getMaxValue2();
  Current2=(float)(sensor_max2-sensor_max_2)*5/65535/0.1/1.141;
  
  if(n == 1 && n2 == 0 && s == 0){
    if(Current1 > oldCurrent1)
      Line(url_1_ok);
    else
      Line(url_1_no);
    s = 1;
    count_2 = 0;
  } 
  if(n == 0 && n2 == 1 && s == 0){
    if(Current2 > oldCurrent2)
      Line(url_2_ok);
    else
      Line(url_2_no);
    s = 1;
    count_2 = 0;
  }
  if(n == 1 && n2 == 1 && s == 0){
    if(Current1 > oldCurrent1 && Current2 > oldCurrent2 )
      Line(url_6_ok);
    else if(Current1 > oldCurrent1 && Current2 <= oldCurrent2)
      Line(url_6_1_ok);
    else if(Current1 <= oldCurrent1 && Current2 > oldCurrent2)
      Line(url_6_2_ok);
    else
      Line(url_6_no);
    s = 1;
    count_2 = 0;
  }
  oldCurrent1 = Current1; 
  oldCurrent2 = Current2;
  //StatusPump();
}

void Line(String url){
  http.begin(url); //HTTP
  int httpCode = http.GET();
 
  
  if (httpCode > 0) {
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
    http.end();
}

