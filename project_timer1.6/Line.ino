void Recovery(){
  Recovery_1();
  Recovery_2();
  Recovery_3();
  Recovery_4();
  Recovery_5();
  Recovery_6();
  Recovery_7();
  Recovery_8();
}

void Recovery_1(){
  eep.write(0, 255); delay(10);
  eep.write(1, 255); delay(10);
  eep.write(2, 255); delay(10);
  eep.write(3, 255); delay(10);
  eep.write(4, 255); delay(10);
  eep.write(5, 255); delay(10);
      
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& Timer_1 = jsonBuffer.createObject();
  Timer_1["ON_HH"] = 255;
  Timer_1["ON_MM"] = 255;
  Timer_1["ON_SS"] = 255;
  Timer_1["OFF_HH"] = 255;
  Timer_1["OFF_MM"] = 255;
  Timer_1["OFF_SS"] = 255;
  Firebase.set(DeviceNumber + "/Timer/Time_1/" , Timer_1);

  
  eep.write(48, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus1/Pump_1/status", 0);
  eep.write(68, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus1/Pump_2/status", 0);
}

void Recovery_2(){
  eep.write(6, 255); delay(10);
  eep.write(7, 255); delay(10);
  eep.write(8, 255); delay(10);
  eep.write(9, 255); delay(10);
  eep.write(10, 255); delay(10);
  eep.write(11, 255); delay(10);
      
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& Timer_1 = jsonBuffer.createObject();
  Timer_1["ON_HH"] = 255;
  Timer_1["ON_MM"] = 255;
  Timer_1["ON_SS"] = 255;
  Timer_1["OFF_HH"] = 255;
  Timer_1["OFF_MM"] = 255;
  Timer_1["OFF_SS"] = 255;
  Firebase.set(DeviceNumber + "/Timer/Time_2/" , Timer_1);

  
  eep.write(49, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus2/Pump_1/status", 0);
  eep.write(69, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus2/Pump_2/status", 0);
}

void Recovery_3(){
  eep.write(12, 255); delay(10);
  eep.write(13, 255); delay(10);
  eep.write(14, 255); delay(10);
  eep.write(15, 255); delay(10);
  eep.write(16, 255); delay(10);
  eep.write(17, 255); delay(10);
      
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& Timer_1 = jsonBuffer.createObject();
  Timer_1["ON_HH"] = 255;
  Timer_1["ON_MM"] = 255;
  Timer_1["ON_SS"] = 255;
  Timer_1["OFF_HH"] = 255;
  Timer_1["OFF_MM"] = 255;
  Timer_1["OFF_SS"] = 255;
  Firebase.set(DeviceNumber + "/Timer/Time_3/" , Timer_1);

  
  eep.write(50, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus3/Pump_1/status", 0);
  eep.write(70, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus3/Pump_2/status", 0);
}

void Recovery_4(){
  eep.write(18, 255); delay(10);
  eep.write(19, 255); delay(10);
  eep.write(20, 255); delay(10);
  eep.write(21, 255); delay(10);
  eep.write(22, 255); delay(10);
  eep.write(23, 255); delay(10);
      
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& Timer_1 = jsonBuffer.createObject();
  Timer_1["ON_HH"] = 255;
  Timer_1["ON_MM"] = 255;
  Timer_1["ON_SS"] = 255;
  Timer_1["OFF_HH"] = 255;
  Timer_1["OFF_MM"] = 255;
  Timer_1["OFF_SS"] = 255;
  Firebase.set(DeviceNumber + "/Timer/Time_4/" , Timer_1);

  
  eep.write(51, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus4/Pump_1/status", 0);
  eep.write(71, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus4/Pump_2/status", 0);
}

void Recovery_5(){
  eep.write(24, 255); delay(10);
  eep.write(25, 255); delay(10);
  eep.write(26, 255); delay(10);
  eep.write(27, 255); delay(10);
  eep.write(28, 255); delay(10);
  eep.write(29, 255); delay(10);
      
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& Timer_1 = jsonBuffer.createObject();
  Timer_1["ON_HH"] = 255;
  Timer_1["ON_MM"] = 255;
  Timer_1["ON_SS"] = 255;
  Timer_1["OFF_HH"] = 255;
  Timer_1["OFF_MM"] = 255;
  Timer_1["OFF_SS"] = 255;
  Firebase.set(DeviceNumber + "/Timer/Time_5/" , Timer_1);

  
  eep.write(52, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus5/Pump_1/status", 0);
  eep.write(72, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus5/Pump_2/status", 0);
}

void Recovery_6(){
  eep.write(30, 255); delay(10);
  eep.write(31, 255); delay(10);
  eep.write(32, 255); delay(10);
  eep.write(33, 255); delay(10);
  eep.write(34, 255); delay(10);
  eep.write(35, 255); delay(10);
      
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& Timer_1 = jsonBuffer.createObject();
  Timer_1["ON_HH"] = 255;
  Timer_1["ON_MM"] = 255;
  Timer_1["ON_SS"] = 255;
  Timer_1["OFF_HH"] = 255;
  Timer_1["OFF_MM"] = 255;
  Timer_1["OFF_SS"] = 255;
  Firebase.set(DeviceNumber + "/Timer/Time_6/" , Timer_1);

  
  eep.write(53, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus6/Pump_1/status", 0);
  eep.write(73, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus6/Pump_2/status", 0);
}

void Recovery_7(){
  eep.write(36, 255); delay(10);
  eep.write(37, 255); delay(10);
  eep.write(38, 255); delay(10);
  eep.write(39, 255); delay(10);
  eep.write(40, 255); delay(10);
  eep.write(41, 255); delay(10);
      
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& Timer_1 = jsonBuffer.createObject();
  Timer_1["ON_HH"] = 255;
  Timer_1["ON_MM"] = 255;
  Timer_1["ON_SS"] = 255;
  Timer_1["OFF_HH"] = 255;
  Timer_1["OFF_MM"] = 255;
  Timer_1["OFF_SS"] = 255;
  Firebase.set(DeviceNumber + "/Timer/Time_7/" , Timer_1);

  
  eep.write(54, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus7/Pump_1/status", 0);
  eep.write(74, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus7/Pump_2/status", 0);
}

void Recovery_8(){
  eep.write(42, 255); delay(10);
  eep.write(43, 255); delay(10);
  eep.write(44, 255); delay(10);
  eep.write(45, 255); delay(10);
  eep.write(46, 255); delay(10);
  eep.write(47, 255); delay(10);
      
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& Timer_1 = jsonBuffer.createObject();
  Timer_1["ON_HH"] = 255;
  Timer_1["ON_MM"] = 255;
  Timer_1["ON_SS"] = 255;
  Timer_1["OFF_HH"] = 255;
  Timer_1["OFF_MM"] = 255;
  Timer_1["OFF_SS"] = 255;
  Firebase.set(DeviceNumber + "/Timer/Time_8/" , Timer_1);

  
  eep.write(55, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus8/Pump_1/status", 0);
  eep.write(75, 0);
  delay(50);
  Firebase.setInt(DeviceNumber + "/Timer/TimeStatus8/Pump_2/status", 0);
}
