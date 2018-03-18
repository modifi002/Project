void Read1(){
  lcd.setCursor(3,0);lcd.print("Please wait...");
  lcd.setCursor(0,1);lcd.print("  Loading data : ");
  
    /*----------
     ch1(relay1) timer1
  */
  delay(50);
  t1on_H = eep.read(0);delay(100);
  t1on_M = eep.read(1);delay(100);
  t1on_S = eep.read(2);delay(100);
  t1off_H = eep.read(3);delay(100);
  t1off_M = eep.read(4);delay(100);
  t1off_S = eep.read(5);delay(100);
  Alarm1 = eep.read(48);delay(100);
  Alarm1_2 = eep.read(68);delay(100);
  lcd.setCursor(15,1);lcd.print("  1");
  lcd.setCursor(7,2);lcd.print("12.5 %");
  
   StaticJsonBuffer<200> jsonBuffer;
   JsonObject& Timer_1 = jsonBuffer.createObject();
   Timer_1["ON_HH"] = t1on_H;
   Timer_1["ON_MM"] = t1on_M;
   Timer_1["ON_SS"] = t1on_S;
   Timer_1["OFF_HH"] = t1off_H;
   Timer_1["OFF_MM"] = t1off_M;
   Timer_1["OFF_SS"] = t1off_S;

   Firebase.set(DeviceNumber + "/Timer/Time_1/" , Timer_1);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus1/Pump_1/status" , Alarm1);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus1/Pump_2/status" , Alarm1_2);
   Serial.println("set on 1");
   delay(100);
  if (Firebase.failed()) {
      Serial.print("failed:1");
      Serial.println(Firebase.error());            
      return;
  }
  delay(500);
}
void Read2(){
  /*----------
    ch1(relay1) timer2
  */
  t2on_H = eep.read(6);delay(100);
  t2on_M = eep.read(7);delay(100);
  t2on_S = eep.read(8);delay(100);
  t2off_H = eep.read(9);delay(100);
  t2off_M = eep.read(10);delay(100);
  t2off_S = eep.read(11);delay(100);
  Alarm2 = eep.read(49);delay(100);
  Alarm2_2 = eep.read(69);delay(100);
  lcd.setCursor(15,1);lcd.print("  2");
  lcd.setCursor(7,2);lcd.print("25.0 %");
   StaticJsonBuffer<200> jsonBuffer;
   JsonObject& Timer_1 = jsonBuffer.createObject();
   Timer_1["ON_HH"] = t2on_H;
   Timer_1["ON_MM"] = t2on_M;
   Timer_1["ON_SS"] = t2on_S;
   Timer_1["OFF_HH"] = t2off_H;
   Timer_1["OFF_MM"] = t2off_M;
   Timer_1["OFF_SS"] = t2off_S;

   Firebase.set(DeviceNumber + "/Timer/Time_2/" , Timer_1);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus2/Pump_1/status" , Alarm2);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus2/Pump_2/status" , Alarm2_2);
   Serial.println("set on 2");
   delay(100);
   if (Firebase.failed()) {
      Serial.print("failed:2");
      Serial.println(Firebase.error());            
      return;
  }
  
  delay(500);
}
void Read3(){
  /*----------
    ch1(relay1) timer3
  */
  t3on_H = eep.read(12);delay(100);
  t3on_M = eep.read(13);delay(100);
  t3on_S = eep.read(14);delay(100);
  t3off_H = eep.read(15);delay(100);
  t3off_M = eep.read(16);delay(100);
  t3off_S = eep.read(17);delay(100);
  Alarm3 = eep.read(50);delay(100);
  Alarm3_2 = eep.read(70);delay(100);
  lcd.setCursor(15,1);lcd.print("  3");
  lcd.setCursor(7,2);lcd.print("37.5 %");
   StaticJsonBuffer<200> jsonBuffer;
   JsonObject& Timer_1 = jsonBuffer.createObject();
   Timer_1["ON_HH"] = t3on_H;
   Timer_1["ON_MM"] = t3on_M;
   Timer_1["ON_SS"] = t3on_S;
   Timer_1["OFF_HH"] = t3off_H;
   Timer_1["OFF_MM"] = t3off_M;
   Timer_1["OFF_SS"] = t3off_S;

   Firebase.set(DeviceNumber + "/Timer/Time_3/" , Timer_1);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus3/Pump_1/status" , Alarm3);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus3/Pump_2/status" , Alarm3_2);
   Serial.println("set on 3");
   delay(100);
   if (Firebase.failed()) {
      Serial.print("failed:3");
      Serial.println(Firebase.error());            
      return;
  }
  delay(500);
}
void Read4(){
  /*----------
    ch1(relay1) timer4
  */
  t4on_H = eep.read(18);delay(100);
  t4on_M = eep.read(19);delay(100);
  t4on_S = eep.read(20);delay(100);
  t4off_H = eep.read(21);delay(100);
  t4off_M = eep.read(22);delay(100);
  t4off_S = eep.read(23);delay(100);
  Alarm4 = eep.read(51);delay(100);
  Alarm4_2 = eep.read(71);delay(100);
  lcd.setCursor(15,1);lcd.print("  4");
  lcd.setCursor(7,2);lcd.print("50.0 %");
     StaticJsonBuffer<200> jsonBuffer;
   JsonObject& Timer_1 = jsonBuffer.createObject();
   Timer_1["ON_HH"] = t4on_H;
   Timer_1["ON_MM"] = t4on_M;
   Timer_1["ON_SS"] = t4on_S;
   Timer_1["OFF_HH"] = t4off_H;
   Timer_1["OFF_MM"] = t4off_M;
   Timer_1["OFF_SS"] = t4off_S;

   Firebase.set(DeviceNumber + "/Timer/Time_4/" , Timer_1);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus4/Pump_1/status" , Alarm4);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus4/Pump_2/status" , Alarm4_2);
   Serial.println("set on 4");
   delay(100);
   if (Firebase.failed()) {
      Serial.print("failed:4");
      Serial.println(Firebase.error());            
      return;
  }
  delay(500);
}
void Read5(){
  /*----------
    ch1(relay1) timer5
  */
  t5on_H = eep.read(24);delay(100);
  t5on_M = eep.read(25);delay(100);
  t5on_S = eep.read(26);delay(100);
  t5off_H = eep.read(27);delay(100);
  t5off_M = eep.read(28);delay(100);
  t5off_S = eep.read(29);delay(100);
  Alarm5 = eep.read(52);delay(100);
  Alarm5_2 = eep.read(72);delay(100);
  lcd.setCursor(15,1);lcd.print("  5");
  lcd.setCursor(7,2);lcd.print("62.5 %");
     StaticJsonBuffer<200> jsonBuffer;
   JsonObject& Timer_1 = jsonBuffer.createObject();
   Timer_1["ON_HH"] = t5on_H;
   Timer_1["ON_MM"] = t5on_M;
   Timer_1["ON_SS"] = t5on_S;
   Timer_1["OFF_HH"] = t5off_H;
   Timer_1["OFF_MM"] = t5off_M;
   Timer_1["OFF_SS"] = t5off_S;

   Firebase.set(DeviceNumber + "/Timer/Time_5/" , Timer_1);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus5/Pump_1/status" , Alarm5);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus5/Pump_2/status" , Alarm5_2);
   Serial.println("set on 5");
   delay(100);
   if (Firebase.failed()) {
      Serial.print("failed:5");
      Serial.println(Firebase.error());            
      return;
  }
  delay(500);
}
void Read6(){
  /*----------
    ch1(relay1) timer6
  */
  t6on_H = eep.read(30);delay(100);
  t6on_M = eep.read(31);delay(100);
  t6on_S = eep.read(32);delay(100);
  t6off_H = eep.read(33);delay(100);
  t6off_M = eep.read(34);delay(100);
  t6off_S = eep.read(35);delay(100);
  Alarm6 = eep.read(53);delay(100);
  Alarm6_2 = eep.read(73);delay(100);
  lcd.setCursor(15,1);lcd.print("  6");
  lcd.setCursor(7,2);lcd.print("75.0 %");
     StaticJsonBuffer<200> jsonBuffer;
   JsonObject& Timer_1 = jsonBuffer.createObject();
   Timer_1["ON_HH"] = t6on_H;
   Timer_1["ON_MM"] = t6on_M;
   Timer_1["ON_SS"] = t6on_S;
   Timer_1["OFF_HH"] = t6off_H;
   Timer_1["OFF_MM"] = t6off_M;
   Timer_1["OFF_SS"] = t6off_S;

   Firebase.set(DeviceNumber + "/Timer/Time_6/" , Timer_1);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus6/Pump_1/status" , Alarm6);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus6/Pump_2/status" , Alarm6_2);
   Serial.println("set on 6");
   delay(100);
   if (Firebase.failed()) {
      Serial.print("failed:6");
      Serial.println(Firebase.error());            
      return;
  }
  delay(500);
}
void Read7(){
  /*----------
    ch1(relay1) timer7
  */
  t7on_H = eep.read(36);delay(100);
  t7on_M = eep.read(37);delay(100);
  t7on_S = eep.read(38);delay(100);
  t7off_H = eep.read(39);delay(100);
  t7off_M = eep.read(40);delay(100);
  t7off_S = eep.read(41);delay(100);
  Alarm7 = eep.read(54);delay(100);
  Alarm7_2 = eep.read(74);delay(100);
  lcd.setCursor(15,1);lcd.print("  7");
  lcd.setCursor(7,2);lcd.print("87.5 %");
     StaticJsonBuffer<200> jsonBuffer;
   JsonObject& Timer_1 = jsonBuffer.createObject();
   Timer_1["ON_HH"] = t7on_H;
   Timer_1["ON_MM"] = t7on_M;
   Timer_1["ON_SS"] = t7on_S;
   Timer_1["OFF_HH"] = t7off_H;
   Timer_1["OFF_MM"] = t7off_M;
   Timer_1["OFF_SS"] = t7off_S;

   Firebase.set(DeviceNumber + "/Timer/Time_7/" , Timer_1);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus7/Pump_1/status" , Alarm7);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus7/Pump_2/status" , Alarm7_2);
   Serial.println("set on 7");
   delay(100);
   if (Firebase.failed()) {
      Serial.print("failed:7");
      Serial.println(Firebase.error());            
      return;
  }
  delay(500);
}
void Read8(){
  /*----------
    ch1(relay1) timer8
  */
  t8on_H = eep.read(42);delay(100);
  t8on_M = eep.read(43);delay(100);
  t8on_S = eep.read(44);delay(100);
  t8off_H = eep.read(45);delay(100);
  t8off_M = eep.read(46);delay(100);
  t8off_S = eep.read(47);delay(100);
  Alarm8 = eep.read(55);delay(100);
  Alarm8_2 = eep.read(75);delay(100);
  lcd.setCursor(15,1);lcd.print("  8");
  lcd.setCursor(7,2);lcd.print(" 100 %");
     StaticJsonBuffer<200> jsonBuffer;
   JsonObject& Timer_1 = jsonBuffer.createObject();
   Timer_1["ON_HH"] = t8on_H;
   Timer_1["ON_MM"] = t8on_M;
   Timer_1["ON_SS"] = t8on_S;
   Timer_1["OFF_HH"] = t8off_H;
   Timer_1["OFF_MM"] = t8off_M;
    Timer_1["OFF_SS"] = t8off_S;

   Firebase.set(DeviceNumber + "/Timer/Time_8/" , Timer_1);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus8/Pump_1/status" , Alarm8);
   Firebase.setInt(DeviceNumber + "/Timer/TimeStatus8/Pump_2/status" , Alarm8_2);
   Serial.println("set on 8");
   delay(100);
   if (Firebase.failed()) {
      Serial.print("failed:8");
      Serial.println(Firebase.error());            
      return;
  }
  lcd.setCursor(5,2);lcd.print("Success...");
  delay(500);
  lcd.clear(); 
}
void ReadWL(){
  WL_Max = eep.readString(56);
  WL_Min = eep.readString(62);
  h = eep.read(92);
  r = eep.read(93);
  WL_Max_2 = eep.readString(78);
  WL_Min_2 = eep.readString(84);
  h_2 = eep.read(90);
  r_2 = eep.read(91);
  Maximum = WL_Max.toInt();
  Minimum = WL_Min.toInt();
  Maximum_2 = WL_Max_2.toInt();
  Minimum_2 = WL_Min_2.toInt();
}

