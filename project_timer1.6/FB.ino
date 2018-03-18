void GetFB_To_ESP(){
  delay(50);
  FirebaseObject Status = Firebase.get(DeviceNumber + "/Timer/Status");
  int data = Status.getInt("Status");
  if (Firebase.failed()) {
      Serial.print("disconnect firebase");
      lcd.setCursor(19,0);lcd.print(char(6));
      return;
  }
  if(data > 0){
    switch(data){
      case 1 :
      {
        GetFB_To_ESP1();
        return;
        break; 
      }
       case 2 :
      {
        GetFB_To_ESP2();
        return;
        break; 
      }
       case 3 :
      {
        GetFB_To_ESP3();
        return;
        break; 
      }
       case 4 :
      {
        GetFB_To_ESP4();
        return;
        break; 
      }
       case 5 :
      {
        GetFB_To_ESP5();
        return;
        break; 
      }
       case 6 :
      {
        GetFB_To_ESP6();
        return;
        break; 
      }
       case 7 :
      {
        GetFB_To_ESP7();
        return;
        break; 
      }
       case 8 :
      {
        GetFB_To_ESP8();
        return;
        break; 
      }
      case 9 :
      {
        Control_1();
        return;
        break; 
      }
      case 10 :
      {
        Control_2();
        return;
        break; 
      }
    }
  }
}
void GetFB_To_ESP1(){ 
  delay(100);
  FirebaseObject data = Firebase.get(DeviceNumber + "/Timer/Time_1");
 
  int FB_onH1 = data.getInt("ON_HH");
  int FB_onM1 = data.getInt("ON_MM"); 
  int FB_onS1 = data.getInt("ON_SS"); 
  int FB_offH1 = data.getInt("OFF_HH");
  int FB_offM1 = data.getInt("OFF_MM");
  int FB_offS1 = data.getInt("OFF_SS");

  if (Firebase.failed()) {
      Serial.print("dis1on");
      BeepESC();
      return;
  }
  if(FB_onH1 != t1on_H || FB_onM1 != t1on_M || FB_onS1 != t1on_S){
    t1on_H = (byte)FB_onH1;
    eep.write(0, t1on_H);
    delay(50);
    t1on_M = (byte)FB_onM1;
    eep.write(1, t1on_M);
    delay(50);
    t1on_S = (byte)FB_onS1;
    eep.write(2, t1on_S);
    delay(50);
    Beep2(); 
  }
  if(FB_offH1 != t1off_H || FB_offM1 != t1off_M || FB_offS1 != t1off_S){
    t1off_H = (byte)FB_offH1;
    eep.write(3, t1off_H);
    delay(50);
    t1off_M = (byte)FB_offM1;
    eep.write(4, t1off_M);
    delay(50);
    t1off_S = (byte)FB_offS1;
    eep.write(5, t1off_S);
    delay(50);
    Beep2();
  }
  
  FirebaseObject data2 = Firebase.get(DeviceNumber + "/Timer/TimeStatus1");
  int Status1 = data2.getInt("Pump_1/status");
  int Status2 = data2.getInt("Pump_2/status");
  if(Status1 != Alarm1 || Status2 != Alarm1_2){
     Alarm1 = (byte)Status1;
     eep.write(48, Alarm1);
     delay(50);
     Beep2();
  }
  if(Status2 != Alarm1_2){
     Alarm1_2 = (byte)Status2;
     eep.write(68, Alarm1_2);
     delay(50);
     Beep2();
  }
  Firebase.setInt(DeviceNumber + "/Timer/Status/Status", 0);
  //Line(url_5);//ส่งข้อความไปที่ Line ว่าอัพเดทข้อมูลเรียบร้อย
}
void GetFB_To_ESP2(){
  delay(100);
  FirebaseObject data = Firebase.get(DeviceNumber + "/Timer/Time_2");
 
  int FB_onH2 = data.getInt("ON_HH");
  int FB_onM2 = data.getInt("ON_MM"); 
  int FB_onS2 = data.getInt("ON_SS"); 
  int FB_offH2 = data.getInt("OFF_HH");
  int FB_offM2 = data.getInt("OFF_MM");
  int FB_offS2 = data.getInt("OFF_SS");

  if (Firebase.failed()) {
      Serial.print("dis2on");
      BeepESC();
      return;
  }
  if(FB_onH2 != t2on_H || FB_onM2 != t2on_M || FB_onS2 != t2on_S){
    t2on_H = (byte)FB_onH2;
    eep.write(6, t2on_H);
    delay(50);
    t2on_M = (byte)FB_onM2;
    eep.write(7, t2on_M);
    delay(50);
    t2on_S = (byte)FB_onS2;
    eep.write(8, t2on_S);
    delay(50);
    Beep2(); 
  }
  if(FB_offH2 != t2off_H || FB_offM2 != t2off_M || FB_offS2 != t2off_S){
    t2off_H = (byte)FB_offH2;
    eep.write(9, t2off_H);
    delay(50);
    t2off_M = (byte)FB_offM2;
    eep.write(10, t2off_M);
    delay(50);
    t2off_S = (byte)FB_offS2;
    eep.write(11, t2off_S);
    delay(50);
    Beep2();
  }
  
  FirebaseObject data2 = Firebase.get(DeviceNumber + "/Timer/TimeStatus2");
  int Status1 = data2.getInt("Pump_1/status");
  int Status2 = data2.getInt("Pump_2/status");
  if(Status1 != Alarm2){
     Alarm2 = (byte)Status1;
     eep.write(49, Alarm2);
     delay(50);
     Beep2();
  }
  if(Status2 != Alarm2_2){
     Alarm2_2 = (byte)Status2;
     eep.write(69, Alarm2_2);
     delay(50);
     Beep2();
  }
  Firebase.setInt(DeviceNumber + "/Timer/Status/Status", 0);
  //Line(url_5);//ส่งข้อความไปที่ Line ว่าอัพเดทข้อมูลเรียบร้อย
}
void GetFB_To_ESP3(){
  delay(100);
  FirebaseObject data = Firebase.get(DeviceNumber + "/Timer/Time_3");
 
  int FB_onH3 = data.getInt("ON_HH");
  int FB_onM3 = data.getInt("ON_MM"); 
  int FB_onS3 = data.getInt("ON_SS"); 
  int FB_offH3 = data.getInt("OFF_HH");
  int FB_offM3 = data.getInt("OFF_MM");
  int FB_offS3 = data.getInt("OFF_SS");

  if (Firebase.failed()) {
      Serial.print("dis3on");
      BeepESC();
      return;
  }
  if(FB_onH3 != t3on_H || FB_onM3 != t3on_M || FB_onS3 != t3on_S){
    t3on_H = (byte)FB_onH3;
    eep.write(12, t3on_H);
    delay(50);
    t3on_M = (byte)FB_onM3;
    eep.write(13, t3on_M);
    delay(50);
    t3on_S = (byte)FB_onS3;
    eep.write(14, t3on_S);
    delay(50);
    Beep2(); 
  }
  if(FB_offH3 != t3off_H || FB_offM3 != t3off_M || FB_offS3 != t3off_S){
    t3off_H = (byte)FB_offH3;
    eep.write(15, t3off_H);
    delay(50);
    t3off_M = (byte)FB_offM3;
    eep.write(16, t3off_M);
    delay(50);
    t3off_S = (byte)FB_offS3;
    eep.write(17, t3off_S);
    delay(50);
    Beep2();
  }
  
  FirebaseObject data2 = Firebase.get(DeviceNumber + "/Timer/TimeStatus3");
  int Status1 = data2.getInt("Pump_1/status");
  int Status2 = data2.getInt("Pump_2/status");
  if(Status1 != Alarm3){
     Alarm3 = (byte)Status1;
     eep.write(50, Alarm3);
     delay(50);
     Beep2();
  }
  if(Status2 != Alarm3_2){
     Alarm3_2 = (byte)Status2;
     eep.write(70, Alarm3_2);
     delay(50);
     Beep2();
  }
  Firebase.setInt(DeviceNumber + "/Timer/Status/Status", 0);
  //Line(url_5);//ส่งข้อความไปที่ Line ว่าอัพเดทข้อมูลเรียบร้อย  
}
void GetFB_To_ESP4(){
  delay(100);
  FirebaseObject data = Firebase.get(DeviceNumber + "/Timer/Time_4");
 
  int FB_onH4 = data.getInt("ON_HH");
  int FB_onM4 = data.getInt("ON_MM"); 
  int FB_onS4 = data.getInt("ON_SS"); 
  int FB_offH4 = data.getInt("OFF_HH");
  int FB_offM4 = data.getInt("OFF_MM");
  int FB_offS4 = data.getInt("OFF_SS");

  if (Firebase.failed()) {
      Serial.print("dis4on");
      BeepESC();
      return;
  }
  if(FB_onH4 != t4on_H || FB_onM4 != t4on_M || FB_onS4 != t4on_S){
    t4on_H = (byte)FB_onH4;
    eep.write(18, t4on_H);
    delay(50);
    t4on_M = (byte)FB_onM4;
    eep.write(19, t4on_M);
    delay(50);
    t4on_S = (byte)FB_onS4;
    eep.write(20, t4on_S);
    delay(50);
    Beep2(); 
  }
  if(FB_offH4 != t4off_H || FB_offM4 != t4off_M || FB_offS4 != t4off_S){
    t4off_H = (byte)FB_offH4;
    eep.write(21, t4off_H);
    delay(50);
    t4off_M = (byte)FB_offM4;
    eep.write(22, t4off_M);
    delay(50);
    t4off_S = (byte)FB_offS4;
    eep.write(23, t4off_S);
    delay(50);
    Beep2();
  }
  
  FirebaseObject data2 = Firebase.get(DeviceNumber + "/Timer/TimeStatus4");
  int Status1 = data2.getInt("Pump_1/status");
  int Status2 = data2.getInt("Pump_2/status");
  if(Status1 != Alarm4){
     Alarm4 = (byte)Status1;
     eep.write(51, Alarm4);
     delay(50);
     Beep2();
  }
  if(Status2 != Alarm4_2){
     Alarm4_2 = (byte)Status2;
     eep.write(71, Alarm4_2);
     delay(50);
     Beep2();
  }
  Firebase.setInt(DeviceNumber + "/Timer/Status/Status", 0);
  //Line(url_5);//ส่งข้อความไปที่ Line ว่าอัพเดทข้อมูลเรียบร้อย
}
void GetFB_To_ESP5(){
  delay(100);
  FirebaseObject data = Firebase.get(DeviceNumber + "/Timer/Time_5");
 
  int FB_onH5 = data.getInt("ON_HH");
  int FB_onM5 = data.getInt("ON_MM"); 
  int FB_onS5 = data.getInt("ON_SS"); 
  int FB_offH5 = data.getInt("OFF_HH");
  int FB_offM5 = data.getInt("OFF_MM");
  int FB_offS5 = data.getInt("OFF_SS");

  if (Firebase.failed()) {
      Serial.print("dis5on");
      BeepESC();
      return;
  }
  if(FB_onH5 != t5on_H || FB_onM5 != t5on_M || FB_onS5 != t5on_S){
    t5on_H = (byte)FB_onH5;
    eep.write(24, t5on_H);
    delay(50);
    t5on_M = (byte)FB_onM5;
    eep.write(25, t5on_M);
    delay(50);
    t5on_S = (byte)FB_onS5;
    eep.write(26, t5on_S);
    delay(50);
    Beep2(); 
  }
  if(FB_offH5 != t5off_H || FB_offM5 != t5off_M || FB_offS5 != t5off_S){
    t5off_H = (byte)FB_offH5;
    eep.write(27, t5off_H);
    delay(50);
    t5off_M = (byte)FB_offM5;
    eep.write(28, t5off_M);
    delay(50);
    t5off_S = (byte)FB_offS5;
    eep.write(29, t5off_S);
    delay(50);
    Beep2();
  }
  
  FirebaseObject data2 = Firebase.get(DeviceNumber + "/Timer/TimeStatus5");
  int Status1 = data2.getInt("Pump_1/status");
  int Status2 = data2.getInt("Pump_2/status");
  if(Status1 != Alarm5){
     Alarm5 = (byte)Status1;
     eep.write(52, Alarm5);
     delay(50);
     Beep2();
  }
  if(Status2 != Alarm5_2){
     Alarm5_2 = (byte)Status2;
     eep.write(72, Alarm5_2);
     delay(50);
     Beep2();
  }
  Firebase.setInt(DeviceNumber + "/Timer/Status/Status", 0);
  //Line(url_5);//ส่งข้อความไปที่ Line ว่าอัพเดทข้อมูลเรียบร้อยอย
}
void GetFB_To_ESP6(){
  delay(100);
  FirebaseObject data = Firebase.get(DeviceNumber + "/Timer/Time_6");
 
  int FB_onH6 = data.getInt("ON_HH");
  int FB_onM6 = data.getInt("ON_MM"); 
  int FB_onS6 = data.getInt("ON_SS"); 
  int FB_offH6 = data.getInt("OFF_HH");
  int FB_offM6 = data.getInt("OFF_MM");
  int FB_offS6 = data.getInt("OFF_SS");

  if (Firebase.failed()) {
      Serial.print("dis6on");
      BeepESC();
      return;
  }
  if(FB_onH6 != t6on_H || FB_onM6 != t6on_M || FB_onS6 != t6on_S){
    t6on_H = (byte)FB_onH6;
    eep.write(30, t6on_H);
    delay(50);
    t6on_M = (byte)FB_onM6;
    eep.write(31, t6on_M);
    delay(50);
    t6on_S = (byte)FB_onS6;
    eep.write(32, t6on_S);
    delay(50);
    Beep2(); 
  }
  if(FB_offH6 != t6off_H || FB_offM6 != t6off_M || FB_offS6 != t6off_S){
    t6off_H = (byte)FB_offH6;
    eep.write(33, t6off_H);
    delay(50);
    t6off_M = (byte)FB_offM6;
    eep.write(34, t6off_M);
    delay(50);
    t6off_S = (byte)FB_offS6;
    eep.write(35, t6off_S);
    delay(50);
    Beep2();
  }
  
  FirebaseObject data2 = Firebase.get(DeviceNumber + "/Timer/TimeStatus6");
  int Status1 = data2.getInt("Pump_1/status");
  int Status2 = data2.getInt("Pump_2/status");
  if(Status1 != Alarm6){
     Alarm6 = (byte)Status1;
     eep.write(53, Alarm6);
     delay(50);
     Beep2();
  }
  if(Status2 != Alarm6_2){
     Alarm6_2 = (byte)Status2;
     eep.write(73, Alarm6_2);
     delay(50);
     Beep2();
  }
  Firebase.setInt(DeviceNumber + "/Timer/Status/Status", 0);
  //Line(url_5);//ส่งข้อความไปที่ Line ว่าอัพเดทข้อมูลเรียบร้อย
}
void GetFB_To_ESP7(){
  delay(100);
  FirebaseObject data = Firebase.get(DeviceNumber + "/Timer/Time_7");
 
  int FB_onH7 = data.getInt("ON_HH");
  int FB_onM7 = data.getInt("ON_MM"); 
  int FB_onS7 = data.getInt("ON_SS"); 
  int FB_offH7 = data.getInt("OFF_HH");
  int FB_offM7 = data.getInt("OFF_MM");
  int FB_offS7 = data.getInt("OFF_SS");

  if (Firebase.failed()) {
      Serial.print("dis7on");
      BeepESC();
      return;
  }
  if(FB_onH7 != t7on_H || FB_onM7 != t7on_M || FB_onS7 != t7on_S){
    t7on_H = (byte)FB_onH7;
    eep.write(36, t7on_H);
    delay(50);
    t7on_M = (byte)FB_onM7;
    eep.write(37, t7on_M);
    delay(50);
    t7on_S = (byte)FB_onS7;
    eep.write(38, t7on_S);
    delay(50);
    Beep2(); 
  }
  if(FB_offH7 != t7off_H || FB_offM7 != t7off_M || FB_offS7 != t7off_S){
    t7off_H = (byte)FB_offH7;
    eep.write(39, t7off_H);
    delay(50);
    t7off_M = (byte)FB_offM7;
    eep.write(40, t7off_M);
    delay(50);
    t7off_S = (byte)FB_offS7;
    eep.write(41, t7off_S);
    delay(50);
    Beep2();
  }
  
  FirebaseObject data2 = Firebase.get(DeviceNumber + "/Timer/TimeStatus7");
  int Status1 = data2.getInt("Pump_1/status");
  int Status2 = data2.getInt("Pump_2/status");
  if(Status1 != Alarm7){
     Alarm7 = (byte)Status1;
     eep.write(54, Alarm7);
     delay(50);
     Beep2();
  }
  if(Status2 != Alarm7_2){
     Alarm7_2 = (byte)Status2;
     eep.write(74, Alarm7_2);
     delay(50);
     Beep2();
  }
  Firebase.setInt(DeviceNumber + "/Timer/Status/Status", 0);
  //Line(url_5);//ส่งข้อความไปที่ Line ว่าอัพเดทข้อมูลเรียบร้อย
}
void GetFB_To_ESP8(){
  delay(100);
  FirebaseObject data = Firebase.get(DeviceNumber + "/Timer/Time_8");
 
  int FB_onH8 = data.getInt("ON_HH");
  int FB_onM8 = data.getInt("ON_MM"); 
  int FB_onS8 = data.getInt("ON_SS"); 
  int FB_offH8 = data.getInt("OFF_HH");
  int FB_offM8 = data.getInt("OFF_MM");
  int FB_offS8 = data.getInt("OFF_SS");

  if (Firebase.failed()) {
      Serial.print("dis8on");
      BeepESC();
      return;
  }
  if(FB_onH8 != t8on_H || FB_onM8 != t8on_M || FB_onS8 != t8on_S){
    t8on_H = (byte)FB_onH8;
    eep.write(42, t8on_H);
    delay(50);
    t8on_M = (byte)FB_onM8;
    eep.write(43, t8on_M);
    delay(50);
    t8on_S = (byte)FB_onS8;
    eep.write(44, t8on_S);
    delay(50);
    Beep2(); 
  }
  if(FB_offH8 != t8off_H || FB_offM8 != t8off_M || FB_offS8 != t8off_S){
    t8off_H = (byte)FB_offH8;
    eep.write(45, t8off_H);
    delay(50);
    t8off_M = (byte)FB_offM8;
    eep.write(46, t8off_M);
    delay(50);
    t8off_S = (byte)FB_offS8;
    eep.write(47, t8off_S);
    delay(50);
    Beep2();
  }
  
  FirebaseObject data2 = Firebase.get(DeviceNumber + "/Timer/TimeStatus8");
  int Status1 = data2.getInt("Pump_1/status");
  int Status2 = data2.getInt("Pump_2/status");
  if(Status1 != Alarm8){
     Alarm8 = (byte)Status1;
     eep.write(55, Alarm8);
     delay(50);
     Beep2();
  }
  if(Status2 != Alarm8_2){
     Alarm8_2 = (byte)Status2;
     eep.write(75, Alarm8_2);
     delay(50);
     Beep2();
  }
  Firebase.setInt(DeviceNumber + "/Timer/Status/Status", 0);
  //Line(url_5);//ส่งข้อความไปที่ Line ว่าอัพเดทข้อมูลเรียบร้อย
}

