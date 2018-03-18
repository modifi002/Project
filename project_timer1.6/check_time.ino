void checkTimer(){
  Time = RTC.now();
  /*------------------------
     ch1(relay1) , alarmtime1 (peroid1)
  */
  //if(oldSec1 != Time.second() || oldMin1 != Time.minute())iChangeMin1 = 0; //make once in a min, oldmin and iChangeMin1  avoid obtrusive, annoy.
  //time On HH:MM
  if(t1on_H == Time.hour() && t1on_M == Time.minute() && t1on_S <= Time.second() && iChange1 == 0){
    BeepALM();
    if(Alarm1_2 == 0 && Alarm1 == 1){
      digitalWrite(Relay1,LOW);
      //Line(Pump1_on + Pump1_on_ok);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      n = 1;
      n2 = 0;
    }
    if(Alarm1_2 == 1 && Alarm1 == 0){
      digitalWrite(Relay2,LOW);
      //Line(url_3);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      n = 0;
      n2 = 1;
    }
    if(Alarm1_2 == 1 && Alarm1 == 1){
      digitalWrite(Relay1,LOW);
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_6);
      n = 1;
      n2 = 1;
    }
    chackCurrent();
    iChange1 = 1;
    delay(100);
  }
  //time off HH:MM
  if(t1off_H == Time.hour() && t1off_M == Time.minute() && t1off_S <= Time.second() && iChange1 == 1){
    BeepALM();
    if(Alarm1_2 == 0 && Alarm1 == 1){
      digitalWrite(Relay1,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Line(url_off);
    }
    if(Alarm1_2 == 1 && Alarm1 == 0){
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    if(Alarm1_2 == 1 && Alarm1 == 1){
      digitalWrite(Relay1,HIGH);
      digitalWrite(Relay2,HIGH);
      Line(url_off);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
    }
    //Serial.print("OFF");
    iChange1 = 0;
    n = 0;
    n2 = 0;
    s = 0;
    delay(100);
  }

  /*------------------------
     ch1(relay1) , alarmtime2 (peroid2)
  */
  //if(oldSec2 != Time.second() || oldMin2 != Time.minute())iChangeMin2 = 0; //make once in a min, oldmin and iChangeMin1  avoid obtrusive, annoy.
  //time On HH:MM
  if(t2on_H == Time.hour() && t2on_M == Time.minute() && t2on_S <= Time.second() && iChange2 == 0){
    BeepALM();
    if(Alarm2_2 == 0 && Alarm2 == 1){
      digitalWrite(Relay1,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      //Line(url_1);
      n = 1;
      n2 = 0;
    }
    if(Alarm2_2 == 1 && Alarm2 == 0){
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_3);
      n = 0;
      n2 = 1;
    }
    if(Alarm2_2 == 1 && Alarm2 == 1){
      digitalWrite(Relay1,LOW);
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_6);
      n = 1;
      n2 = 1;
    }
    chackCurrent();
    iChange2 = 1;
    delay(100);
  }
  //time off HH:MM
  if(t2off_H == Time.hour() && t2off_M == Time.minute() && t2off_S <= Time.second() && iChange2 == 1 ){
    BeepALM();
    if(Alarm2_2 == 0 && Alarm2 == 1){
      digitalWrite(Relay1,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Line(url_off);
    }
    if(Alarm2_2 == 1 && Alarm2 == 0){
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    if(Alarm2_2 == 1 && Alarm2 == 1){
      digitalWrite(Relay1,HIGH);
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    iChange2 = 0;
    n = 0;
    n2 = 0;
    s = 0;
    delay(100);
  }
  /*------------------------
     ch1(relay1) , alarmtime3 (peroid2)
  */
  //if(oldSec3 != Time.second() || oldMin3 != Time.minute())iChangeMin3 = 0; //make once in a min, oldmin and iChangeMin1  avoid obtrusive, annoy.
  //time On HH:MM
  if(t3on_H == Time.hour() && t3on_M == Time.minute() && t3on_S <= Time.second() && iChange3 == 0 ){
    BeepALM();
    if(Alarm3_2 == 0 && Alarm3 == 1){
      digitalWrite(Relay1,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      //Line(url_1);
      n = 1;
      n2 = 0;
    }
    if(Alarm3_2 == 1 && Alarm3 == 0){
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_3);
      n = 0;
      n2 = 1;
    }
    if(Alarm3_2 == 1 && Alarm3 == 1){
      digitalWrite(Relay1,LOW);
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_6);
      n = 1;
      n2 = 1;
    }
    chackCurrent();
    iChange3 = 1;
    delay(100);
  }
  //time off HH:MM
  if(t3off_H == Time.hour() && t3off_M == Time.minute() && t3off_S <= Time.second() && iChange3 == 1 ){
    BeepALM();
    if(Alarm3_2 == 0 && Alarm3 == 1){
      digitalWrite(Relay1,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Line(url_off);
    }
    if(Alarm3_2 == 1 && Alarm3 == 0){
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    if(Alarm3_2 == 1 && Alarm3 == 1){
      digitalWrite(Relay1,HIGH);
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    iChange3 = 0;
    n = 0;
    n2 = 0;
    s = 0;
    delay(100);
  }
   /*------------------------
     ch1(relay1) , alarmtime4 (peroid4)
  */
  //if(oldSec4 != Time.second() || oldMin4 != Time.minute())iChangeMin4 = 0; //make once in a min, oldmin and iChangeMin1  avoid obtrusive, annoy.
  //time On HH:MM
  if(t4on_H == Time.hour() && t4on_M == Time.minute() && t4on_S <= Time.second() && iChange4 == 0){
    BeepALM();
    if(Alarm4_2 == 0 && Alarm4 == 1){
      digitalWrite(Relay1,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      //Line(url_1);
      n = 1;
      n2 = 0;
    }
    if(Alarm4_2 == 1 && Alarm4 == 0){
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_3);
      n = 0;
      n2 = 1;
    }
    if(Alarm4_2 == 1 && Alarm4 == 1){
      digitalWrite(Relay1,LOW);
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_6);
      n = 1;
      n2 = 1;
    }
    chackCurrent();
    iChange4 = 1;
    delay(100);
  }
  //time off HH:MM
  if(t4off_H == Time.hour() && t4off_M == Time.minute() && iChange4 == 1 && t4off_S <= Time.second()){
    BeepALM();
    if(Alarm4_2 == 0 && Alarm4 == 1){
      digitalWrite(Relay1,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Line(url_off);
    }
    if(Alarm4_2 == 1 && Alarm4 == 0){
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    if(Alarm4_2 == 1 && Alarm4 == 1){
      digitalWrite(Relay1,HIGH);
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    iChange4 = 0;
    n = 0;
    n2 = 0;
    s = 0;
    delay(100);
  }
   /*------------------------
     ch1(relay1) , alarmtime5 (peroid5)
  */
  //if(oldSec5 != Time.second() || oldMin5 != Time.minute())iChangeMin5 = 0; //make once in a min, oldmin and iChangeMin1  avoid obtrusive, annoy.
  //time On HH:MM
  if(t5on_H == Time.hour() && t5on_M == Time.minute() && t5on_S <= Time.second() && iChange5 == 0){
    BeepALM();
    if(Alarm5_2 == 0 && Alarm5 == 1){
      digitalWrite(Relay1,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      //Line(url_1);
      n = 1;
      n2 = 0;
    }
    if(Alarm5_2 == 1 && Alarm5 == 0){
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_3);
      n = 0;
      n2 = 1;
    }
    if(Alarm5_2 == 1 && Alarm5 == 1){
      digitalWrite(Relay1,LOW);
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_6);
      n = 1;
      n2 = 1;
    }
    chackCurrent();
    iChange5 = 1;
    delay(100);
  }
  //time off HH:MM
  if(t5off_H == Time.hour() && t5off_M == Time.minute() && t5off_S <= Time.second() && iChange5 == 1){
    BeepALM();
    if(Alarm5_2 == 0 && Alarm5 == 1){
      digitalWrite(Relay1,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Line(url_off);
    }
    if(Alarm5_2 == 1 && Alarm5 == 0){
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    if(Alarm5_2 == 1 && Alarm5 == 1){
      digitalWrite(Relay1,HIGH);
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    iChange5 = 0;
    n = 0;
    n2 = 0;
    s = 0;
    delay(100);
  }
   /*------------------------
     ch1(relay1) , alarmtime6 (peroid6)
  */
  //if(oldSec6 != Time.second() || oldMin6 != Time.minute())iChangeMin6 = 0; //make once in a min, oldmin and iChangeMin1  avoid obtrusive, annoy.
  //time On HH:MM
  if(t6on_H == Time.hour() && t6on_M == Time.minute() && t6on_S <= Time.second() && iChange6 == 0){
    BeepALM();
    if(Alarm6_2 == 0 && Alarm6 == 1){
      digitalWrite(Relay1,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      //Line(url_1);
      n = 1;
      n2 = 0;
    }
    if(Alarm6_2 == 1 && Alarm6 == 0){
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_3);
      n = 0;
      n2 = 1;
    }
    if(Alarm6_2 == 1 && Alarm6 == 1){
      digitalWrite(Relay1,LOW);
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_6);
      n = 1;
      n2 = 1;
    }
    chackCurrent();
    iChange6 = 1;
    delay(100);
  }
  //time off HH:MM
  if(t6off_H == Time.hour() && t6off_M == Time.minute() && iChange6 == 1 && t6off_S <= Time.second()){
    BeepALM();
    if(Alarm6_2 == 0 && Alarm6 == 1){
      digitalWrite(Relay1,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Line(url_off);
    }
    if(Alarm6_2 == 1 && Alarm6 == 0){
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    if(Alarm6_2 == 1 && Alarm6 == 1){
      digitalWrite(Relay1,HIGH);
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    iChange6 = 0;
    n = 0;
    n2 = 0;
    s = 0;
    delay(100);
  }
   /*------------------------
     ch1(relay1) , alarmtime7 (peroid7)
  */
  //if(oldSec7 != Time.second() || oldMin7 != Time.minute())iChangeMin7 = 0; //make once in a min, oldmin and iChangeMin1  avoid obtrusive, annoy.
  //time On HH:MM
  if(t7on_H == Time.hour() && t7on_M == Time.minute() && t7on_S <= Time.second() && iChange7 == 0){
    BeepALM();
    if(Alarm7_2 == 0 && Alarm7 == 1){
      digitalWrite(Relay1,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      //Line(url_1);
      n = 1;
      n2 = 0;
    }
    if(Alarm7_2 == 1 && Alarm7 == 0){
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_3);
      n = 0;
      n2 = 1;
    }
    if(Alarm7_2 == 1 && Alarm7 == 1){
      digitalWrite(Relay1,LOW);
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_6);
      n = 1;
      n2 = 1;
    }
    chackCurrent();
    iChange7 = 1;
    delay(100);
  }
  //time off HH:MM
  if(t7off_H == Time.hour() && t7off_M == Time.minute() && iChange7 == 1 && t7off_S <= Time.second()){
    BeepALM();
    if(Alarm7_2 == 0 && Alarm7 == 1){
      digitalWrite(Relay1,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Line(url_off);
    }
    if(Alarm7_2 == 1 && Alarm7 == 0){
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    if(Alarm7_2 == 1 && Alarm7 == 1){
      digitalWrite(Relay1,HIGH);
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    iChange7 = 0;
    n = 0;
    n2 = 0;
    s = 0;
    delay(100);
  }
   /*------------------------
     ch1(relay1) , alarmtime8 (peroid8)
  */
  //if(oldSec8 != Time.second() || oldMin8 != Time.minute())iChangeMin8 = 0; //make once in a min, oldmin and iChangeMin1  avoid obtrusive, annoy.
  //time On HH:MM
  if(t8on_H == Time.hour() && t8on_M == Time.minute() && t8on_S <= Time.second() && iChange8 == 0){
    BeepALM();
    if(Alarm8_2 == 0 && Alarm8 == 1){
      digitalWrite(Relay1,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      //Line(url_1);
      n = 1;
      n2 = 0;
    }
    if(Alarm8_2 == 1 && Alarm8 == 0 ){
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_3);
      n = 0;
      n2 = 1;
    }
    if(Alarm8_2 == 1 && Alarm8 == 1){
      digitalWrite(Relay1,LOW);
      digitalWrite(Relay2,LOW);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "ON");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "ON");
      //Line(url_6);
      n = 1;
      n2 = 1;
    }
    chackCurrent();
    iChange8 = 1;
    delay(100);
  }
  //time off HH:MM
  if(t8off_H == Time.hour() && t8off_M == Time.minute() && iChange8 == 1 && t8off_S <= Time.second()){
    BeepALM();
    if(Alarm8 == 1 && Alarm8_2 == 0){
      digitalWrite(Relay1,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Line(url_off);
    }
    if(Alarm8_2 == 1 && Alarm8 == 0){
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    if(Alarm8_2 == 1 && Alarm8 == 1){
      digitalWrite(Relay1,HIGH);
      digitalWrite(Relay2,HIGH);
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_1", "OFF");
      Firebase.setString(DeviceNumber + "/Timer/PumpStatus/Pump_2", "OFF");
      Line(url_off);
    }
    iChange8 = 0;
    n = 0;
    n2 = 0;
    s = 0;
    delay(100);
  }
  //eep.write(60, n); delay(10);
}

