#include <time.h>

int timezone = 7 * 3600;                    //ตั้งค่า TimeZone ตามเวลาประเทศไทย
int dst = 0;                                //กำหนดค่า Date Swing Time

int c = 0;
void Time_Server(){
  configTime(timezone, dst, "pool.ntp.org", "time.nist.gov"); //ดึงเวลาจาก Server
  Serial.println("\nLoading time");
  while (!time(nullptr)) {
    Serial.print("*");
    delay(500);
    c++;
    if(c == 20) break;
  }
  
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  

  Year = p_tm->tm_year;
  Mon = p_tm->tm_mon;
  Day = p_tm->tm_mday;
  Hour = p_tm->tm_hour;
  Min = p_tm->tm_min;
  Sec = p_tm->tm_sec;

  RTC.adjust(DateTime(Year, Mon+1, Day, Hour, Min, Sec));
  delay(200);
  Serial.println("Update Time Success.");
}

void Update_Time(){
  delay(50);
  if(Time.hour() == 0 && Time.minute() == 0 && t1off_S == 0) {
    Time_Server();
    calSensorValue();
  }
}
/*
 * creat char
 */
byte Down[8] = {
        B00100,
        B00100,
        B00100,
        B00100,
        B11111,
        B01110,
        B00100,
        B00000
};
byte Up[8] = {
        B00100,
        B01110,
        B11111,
        B00100,
        B00100,
        B00100,
        B00100,
        B00000
};
byte UpDown[8] = {
        B00100,
        B01110,
        B11111,
        B00100,
        B00100,
        B11111,
        B01110,
        B00100
};
byte Scoll_1[8] = {
        B00100,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B00100
};
byte Scoll_2[8] = {
        B00100,
        B00100,
        B00100,
        B00100,
        B00100,
        B00100,
        B00100,
        B00100
};
byte Wifi[8] = {
        B11111,
        B10001,
        B01110,
        B01010,
        B00000,
        B00100,
        B00000,
        B00000
};
byte WifiNo[8] = {
        B11111,
        B10001,
        B01110,
        B01011,
        B00001,
        B00101,
        B00000,
        B00001
};
/*--------------------------------------
 * End creat char
 ---------------------------------------*/
void CreatChar(){
  lcd.createChar(0, Down);
  lcd.createChar(1, Up);
  lcd.createChar(2, UpDown);
  lcd.createChar(3, Scoll_1);
  lcd.createChar(4, Scoll_2);
  lcd.createChar(5, Wifi);
  lcd.createChar(6, WifiNo);
}


