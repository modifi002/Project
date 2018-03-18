void SetTimer1(){
  String Pump_1,Pump_2;
  delay(100);
  Pump_1 = (Alarm1 == 1) ? "ON" : "OFF";
  Pump_2 = (Alarm1_2 == 1) ? "ON" : "OFF";
  lcd.clear();
  Time = RTC.now();
  char key = kpd.getKey();
  lcd.setCursor(0,0);lcd.print("   ON        OFF  ");
  lcd.setCursor(0,1);lcd.print("  :  :      :  :  ");
  ShowALMPos(t1on_H, t1on_M, t1on_S, 0, 1); ShowALMPos(t1off_H, t1off_M, t1off_S, 10, 1);
  lcd.setCursor(0,2);lcd.print("Pump 1 : ");lcd.print(Pump_1);
  lcd.setCursor(0,3);lcd.print("Pump 2 : ");lcd.print(Pump_2);
  while(1){
    delay(100);
    char key = kpd.getKey();
    switch(key){
        case '1':
        {
          if(Alarm1 == 1){
            lcd.setCursor(9,2);lcd.print("OFF");
            Alarm1 = 0;
          }else{
            lcd.setCursor(9,2);lcd.print("ON ");
            Alarm1 = 1;
          }
          eep.write(48, Alarm1);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus1/Pump_1/status", Alarm1);
          Save(); 
          SetTimer1(); 
          break; 
       }
       case '2':
        {
          if(Alarm1_2 == 1){
            lcd.setCursor(9,3);lcd.print("OFF");
            Alarm1_2 = 0;
          }else{
            lcd.setCursor(9,3);lcd.print("ON ");
            Alarm1_2 = 1;
          }
          eep.write(68, Alarm1_2);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus1/Pump_2/status", Alarm1_2);
          Save();  
          SetTimer1();
          break; 
       }
    }
    if(key == 'A'){
        t1on_H = SetDateTime(2,0,1);
        if(t1on_H == 255) goto bailout;
        t1on_M = SetDateTime(2,3,1);
        if(t1on_M == 255) goto bailout;
        t1on_S = SetDateTime(2,6,1);
        if(t1on_M == 255) goto bailout;
        t1off_H = SetDateTime(2,10,1);
        if(t1off_H == 255) goto bailout;
        t1off_M = SetDateTime(2,13,1);
        if(t1off_M == 255) goto bailout;
        t1off_S = SetDateTime(2,16,1);
        if(t1off_S == 255) goto bailout;
        
        eep.write(0, t1on_H); delay(10);
        eep.write(1, t1on_M); delay(10);
        eep.write(2, t1on_S); delay(10);
        eep.write(3, t1off_H); delay(10);
        eep.write(4, t1off_M); delay(10);
        eep.write(5, t1off_S); delay(10);
      
        bailout:
          StaticJsonBuffer<200> jsonBuffer;
          JsonObject& Timer_1 = jsonBuffer.createObject();
          Timer_1["ON_HH"] = t1on_H;
          Timer_1["ON_MM"] = t1on_M;
          Timer_1["ON_SS"] = t1on_S;
          Timer_1["OFF_HH"] = t1off_H;
          Timer_1["OFF_MM"] = t1off_M;
          Timer_1["OFF_SS"] = t1off_S;
          Firebase.set(DeviceNumber + "/Timer/Time_1/" , Timer_1);
          Save();
         SetTimer1();
         return;
    }
    if (key == '*')    //show mainmenu
    {
        //BeepESC();
        SetTimer();
        return;
    }
  }
}
void SetTimer2(){
  String Pump_1,Pump_2;
  delay(100);
  Pump_1 = (Alarm2 == 1) ? "ON" : "OFF";
  Pump_2 = (Alarm2_2 == 1) ? "ON" : "OFF";
  lcd.clear();
  Time = RTC.now();
  lcd.setCursor(0,0);lcd.print("   ON        OFF  ");
  lcd.setCursor(0,1);lcd.print("  :  :      :  :  ");
  ShowALMPos(t2on_H, t2on_M, t2on_S, 0, 1); ShowALMPos(t2off_H, t2off_M, t2off_S, 10, 1);
  lcd.setCursor(0,2);lcd.print("Pump 1 : ");lcd.print(Pump_1);
  lcd.setCursor(0,3);lcd.print("Pump 2 : ");lcd.print(Pump_2);
  while(1){
    delay(100);
    char key = kpd.getKey();
     switch(key){
        case '1':
        {
          if(Alarm2 == 1){
            lcd.setCursor(9,2);lcd.print("OFF");
            Alarm2 = 0;
          }else{
            lcd.setCursor(9,2);lcd.print("ON ");
            Alarm2 = 1;
          }
          eep.write(49, Alarm2);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus2/Pump_1/status", Alarm2);
          Save(); 
          SetTimer2();  
          break; 
       }
       case '2':
        {
          if(Alarm2_2 == 1){
            lcd.setCursor(9,3);lcd.print("OFF");
            Alarm2_2 = 0;
          }else{
            lcd.setCursor(9,3);lcd.print("ON ");
            Alarm2_2 = 1;
          }
          eep.write(69, Alarm2_2);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus2/Pump_2/status", Alarm2_2); 
          Save(); 
          SetTimer2();
          break; 
       }
    }
    if(key == 'A'){
        t2on_H = SetDateTime(2,0,1);
        if(t2on_H == 255) goto bailout;
        t2on_M = SetDateTime(2,3,1);
        if(t2on_M == 255) goto bailout;
        t2on_S = SetDateTime(2,6,1);
        if(t2on_M == 255) goto bailout;
        t2off_H = SetDateTime(2,10,1);
        if(t2off_H == 255) goto bailout;
        t2off_M = SetDateTime(2,13,1);
        if(t2off_M == 255) goto bailout;
        t2off_S = SetDateTime(2,16,1);
        if(t2off_S == 255) goto bailout;
        
        eep.write(6, t2on_H); delay(10);
        eep.write(7, t2on_M); delay(10);
        eep.write(8, t2on_S); delay(10);
        eep.write(9, t2off_H); delay(10);
        eep.write(10, t2off_M); delay(10);
        eep.write(11, t2off_S); delay(10);
      
        bailout:
          StaticJsonBuffer<200> jsonBuffer;
          JsonObject& Timer_1 = jsonBuffer.createObject();
          Timer_1["ON_HH"] = t2on_H;
          Timer_1["ON_MM"] = t2on_M;
          Timer_1["ON_SS"] = t2on_S;
          Timer_1["OFF_HH"] = t2off_H;
          Timer_1["OFF_MM"] = t2off_M;
          Timer_1["OFF_SS"] = t2off_S;
          Firebase.set(DeviceNumber + "/Timer/Time_2/" , Timer_1);
          Save();
         SetTimer2();
         return;
    }
      if (key == '*')    //show mainmenu
      {
        SetTimer();
        return;
      }
  }
}
void SetTimer3(){
  delay(100);
  String Pump_1,Pump_2;
  Pump_1 = (Alarm3 == 1) ? "ON" : "OFF";
  Pump_2 = (Alarm3_2 == 1) ? "ON" : "OFF";
  lcd.clear();
  Time = RTC.now();
  lcd.setCursor(0,0);lcd.print("   ON        OFF  ");
  lcd.setCursor(0,1);lcd.print("  :  :      :  :  ");
  ShowALMPos(t3on_H, t3on_M, t3on_S, 0, 1); ShowALMPos(t3off_H, t3off_M, t3off_S, 10, 1);
  lcd.setCursor(0,2);lcd.print("Pump 1 : ");lcd.print(Pump_1);
  lcd.setCursor(0,3);lcd.print("Pump 2 : ");lcd.print(Pump_2);
  while(1){
    delay(100);
    char key = kpd.getKey();
    switch(key){
        case '1':
        {
          if(Alarm3 == 1){
            lcd.setCursor(9,2);lcd.print("OFF");
            Alarm3 = 0;
          }else{
            lcd.setCursor(9,2);lcd.print("ON ");
            Alarm3 = 1;
          }
          eep.write(50, Alarm3);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus3/Pump_1/status", Alarm3);
          Save(); 
          SetTimer3();  
          break; 
       }
       case '2':
        {
          if(Alarm3_2 == 1){
            lcd.setCursor(9,3);lcd.print("OFF");
            Alarm3_2 = 0;
          }else{
            lcd.setCursor(9,3);lcd.print("ON ");
            Alarm3_2 = 1;
          }
          eep.write(70, Alarm3_2);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus3/Pump_2/status", Alarm3_2); 
          Save(); 
          SetTimer3(); 
          break; 
       }
    }
    if(key == 'A'){
        t3on_H = SetDateTime(2,0,1);
        if(t3on_H == 255) goto bailout;
        t3on_M = SetDateTime(2,3,1);
        if(t3on_M == 255) goto bailout;
        t3on_S = SetDateTime(2,6,1);
        if(t3on_M == 255) goto bailout;
        t3off_H = SetDateTime(2,10,1);
        if(t3off_H == 255) goto bailout;
        t3off_M = SetDateTime(2,13,1);
        if(t3off_M == 255) goto bailout;
        t3off_S = SetDateTime(2,16,1);
        if(t3off_S == 255) goto bailout;
        
        eep.write(12, t3on_H); delay(10);
        eep.write(13, t3on_M); delay(10);
        eep.write(14, t3on_S); delay(10);
        eep.write(15, t3off_H); delay(10);
        eep.write(16, t3off_M); delay(10);
        eep.write(17, t3off_S); delay(10);
      
        bailout:
          StaticJsonBuffer<200> jsonBuffer;
          JsonObject& Timer_1 = jsonBuffer.createObject();
          Timer_1["ON_HH"] = t3on_H;
          Timer_1["ON_MM"] = t3on_M;
          Timer_1["ON_SS"] = t3on_S;
          Timer_1["OFF_HH"] = t3off_H;
          Timer_1["OFF_MM"] = t3off_M;
          Timer_1["OFF_SS"] = t3off_S;
          Firebase.set(DeviceNumber + "/Timer/Time_3/" , Timer_1);
          Save();
         SetTimer3();
         return;
    }  
      if (key == '*')    //show mainmenu
      {
        SetTimer();
        return;
      }
  }
}
void SetTimer4(){
  delay(100);
  String Pump_1,Pump_2;
  Pump_1 = (Alarm4 == 1) ? "ON" : "OFF";
  Pump_2 = (Alarm4_2 == 1) ? "ON" : "OFF";
  lcd.clear();
  Time = RTC.now();
  lcd.setCursor(0,0);lcd.print("   ON        OFF  ");
  lcd.setCursor(0,1);lcd.print("  :  :      :  :  ");
  ShowALMPos(t4on_H, t4on_M, t4on_S, 0, 1); ShowALMPos(t4off_H, t4off_M, t4off_S, 10, 1);
  lcd.setCursor(0,2);lcd.print("Pump 1 : ");lcd.print(Pump_1);
  lcd.setCursor(0,3);lcd.print("Pump 2 : ");lcd.print(Pump_2);
  while(1){
    delay(100);
    char key = kpd.getKey();
    switch(key){
        case '1':
        {
          if(Alarm4 == 1){
            lcd.setCursor(9,2);lcd.print("OFF");
            Alarm4 = 0;
          }else{
            lcd.setCursor(9,2);lcd.print("ON ");
            Alarm4 = 1;
          }
          eep.write(51, Alarm4);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus4/Pump_1/status", Alarm4);
          Save();  
          SetTimer4(); 
          break; 
       }
       case '2':
        {
          if(Alarm4_2 == 1){
            lcd.setCursor(9,3);lcd.print("OFF");
            Alarm4_2 = 0;
          }else{
            lcd.setCursor(9,3);lcd.print("ON ");
            Alarm4_2 = 1;
          }
          eep.write(71, Alarm4_2);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus4/Pump_2/status", Alarm4_2); 
          Save(); 
          SetTimer4(); 
          break; 
       }
    }
    if(key == 'A'){
        t4on_H = SetDateTime(2,0,1);
        if(t4on_H == 255) goto bailout;
        t4on_M = SetDateTime(2,3,1);
        if(t4on_M == 255) goto bailout;
        t4on_S = SetDateTime(2,6,1);
        if(t4on_M == 255) goto bailout;
        t4off_H = SetDateTime(2,10,1);
        if(t4off_H == 255) goto bailout;
        t4off_M = SetDateTime(2,13,1);
        if(t4off_M == 255) goto bailout;
        t4off_S = SetDateTime(2,16,1);
        if(t4off_S == 255) goto bailout;
        
        eep.write(18, t4on_H); delay(10);
        eep.write(19, t4on_M); delay(10);
        eep.write(20, t4on_S); delay(10);
        eep.write(21, t4off_H); delay(10);
        eep.write(22, t4off_M); delay(10);
        eep.write(23, t4off_S); delay(10);
      
        bailout:
          StaticJsonBuffer<200> jsonBuffer;
          JsonObject& Timer_1 = jsonBuffer.createObject();
          Timer_1["ON_HH"] = t4on_H;
          Timer_1["ON_MM"] = t4on_M;
          Timer_1["ON_SS"] = t4on_S;
          Timer_1["OFF_HH"] = t4off_H;
          Timer_1["OFF_MM"] = t4off_M;
          Timer_1["OFF_SS"] = t4off_S;
          Firebase.set(DeviceNumber + "/Timer/Time_4/" , Timer_1);
          Save();
         SetTimer4();
         return;
    } 
      if (key == '*')    //show mainmenu
      {
        SetTimer();
        return;
      }
  }
}
void SetTimer5(){
  delay(100);
  String Pump_1,Pump_2;
  Pump_1 = (Alarm5 == 1) ? "ON" : "OFF";
  Pump_2 = (Alarm5_2 == 1) ? "ON" : "OFF";
  lcd.clear();
  Time = RTC.now();
  lcd.setCursor(0,0);lcd.print("   ON        OFF  ");
  lcd.setCursor(0,1);lcd.print("  :  :      :  :  ");
  ShowALMPos(t5on_H, t5on_M, t5on_S, 0, 1); ShowALMPos(t5off_H, t5off_M, t5off_S, 10, 1);
  lcd.setCursor(0,2);lcd.print("Pump 1 : ");lcd.print(Pump_1);
  lcd.setCursor(0,3);lcd.print("Pump 2 : ");lcd.print(Pump_2);
  while(1){
    delay(100);
    char key = kpd.getKey();
    switch(key){
        case '1':
        {
          if(Alarm5 == 1){
            lcd.setCursor(9,2);lcd.print("OFF");
            Alarm5 = 0;
          }else{
            lcd.setCursor(9,2);lcd.print("ON ");
            Alarm5 = 1;
          }
          eep.write(52, Alarm5);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus5/Pump_1/status", Alarm5);
          Save();
          SetTimer5();   
          break; 
       }
       case '2':
        {
          if(Alarm5_2 == 1){
            lcd.setCursor(9,3);lcd.print("OFF");
            Alarm5_2 = 0;
          }else{
            lcd.setCursor(9,3);lcd.print("ON ");
            Alarm5_2 = 1;
          }
          eep.write(72, Alarm5_2);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus5/Pump_2/status", Alarm5_2); 
          Save();  
          SetTimer5();
          break; 
       }
    }
    if(key == 'A'){
        t5on_H = SetDateTime(2,0,1);
        if(t5on_H == 255) goto bailout;
        t5on_M = SetDateTime(2,3,1);
        if(t5on_M == 255) goto bailout;
        t5on_S = SetDateTime(2,6,1);
        if(t5on_M == 255) goto bailout;
        t5off_H = SetDateTime(2,10,1);
        if(t5off_H == 255) goto bailout;
        t5off_M = SetDateTime(2,13,1);
        if(t5off_M == 255) goto bailout;
        t5off_S = SetDateTime(2,16,1);
        if(t5off_S == 255) goto bailout;
        
        eep.write(24, t5on_H); delay(10);
        eep.write(25, t5on_M); delay(10);
        eep.write(26, t5on_S); delay(10);
        eep.write(27, t5off_H); delay(10);
        eep.write(28, t5off_M); delay(10);
        eep.write(29, t5off_S); delay(10);
      
        bailout:
          StaticJsonBuffer<200> jsonBuffer;
          JsonObject& Timer_1 = jsonBuffer.createObject();
          Timer_1["ON_HH"] = t5on_H;
          Timer_1["ON_MM"] = t5on_M;
          Timer_1["ON_SS"] = t5on_S;
          Timer_1["OFF_HH"] = t5off_H;
          Timer_1["OFF_MM"] = t5off_M;
          Timer_1["OFF_SS"] = t5off_S;
          Firebase.set(DeviceNumber + "/Timer/Time_5/" , Timer_1);
          Save();
         SetTimer5();
         return;
    }
      if (key == '*')    //show mainmenu
      {
        SetTimer();
        return;
      }
  }
}
void SetTimer6(){
  delay(100);
  String Pump_1,Pump_2;
  Pump_1 = (Alarm6 == 1) ? "ON" : "OFF";
  Pump_2 = (Alarm6_2 == 1) ? "ON" : "OFF";
  lcd.clear();
  Time = RTC.now();
  lcd.setCursor(0,0);lcd.print("   ON        OFF  ");
  lcd.setCursor(0,1);lcd.print("  :  :      :  :  ");
  ShowALMPos(t6on_H, t6on_M, t6on_S, 0, 1); ShowALMPos(t6off_H, t6off_M, t6off_S, 10, 1);
  lcd.setCursor(0,2);lcd.print("Pump 1 : ");lcd.print(Pump_1);
  lcd.setCursor(0,3);lcd.print("Pump 2 : ");lcd.print(Pump_2);
  while(1){
    delay(100);
    char key = kpd.getKey();
    switch(key){
        case '1':
        {
          if(Alarm6 == 1){
            lcd.setCursor(9,2);lcd.print("OFF");
            Alarm6 = 0;
          }else{
            lcd.setCursor(9,2);lcd.print("ON ");
            Alarm6 = 1;
          }
          eep.write(53, Alarm6);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus6/Pump_1/status", Alarm6);
          Save();  
          SetTimer6(); 
          break; 
       }
       case '2':
        {
          if(Alarm6_2 == 1){
            lcd.setCursor(9,3);lcd.print("OFF");
            Alarm6_2 = 0;
          }else{
            lcd.setCursor(9,3);lcd.print("ON ");
            Alarm6_2 = 1;
          }
          eep.write(73, Alarm6_2);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus6/Pump_2/status", Alarm6_2); 
          Save();  
          SetTimer6();
          break; 
       }
    }
    if(key == 'A'){
        t6on_H = SetDateTime(2,0,1);
        if(t6on_H == 255) goto bailout;
        t6on_M = SetDateTime(2,3,1);
        if(t6on_M == 255) goto bailout;
        t6on_S = SetDateTime(2,6,1);
        if(t6on_M == 255) goto bailout;
        t6off_H = SetDateTime(2,10,1);
        if(t6off_H == 255) goto bailout;
        t6off_M = SetDateTime(2,13,1);
        if(t6off_M == 255) goto bailout;
        t6off_S = SetDateTime(2,16,1);
        if(t6off_S == 255) goto bailout;
        
        eep.write(30, t6on_H); delay(10);
        eep.write(31, t6on_M); delay(10);
        eep.write(32, t6on_S); delay(10);
        eep.write(33, t6off_H); delay(10);
        eep.write(34, t6off_M); delay(10);
        eep.write(35, t6off_S); delay(10);
      
        bailout:
          StaticJsonBuffer<200> jsonBuffer;
          JsonObject& Timer_1 = jsonBuffer.createObject();
          Timer_1["ON_HH"] = t6on_H;
          Timer_1["ON_MM"] = t6on_M;
          Timer_1["ON_SS"] = t6on_S;
          Timer_1["OFF_HH"] = t6off_H;
          Timer_1["OFF_MM"] = t6off_M;
          Timer_1["OFF_SS"] = t6off_S;
          Firebase.set(DeviceNumber + "/Timer/Time_6/" , Timer_1);
          Save();
         SetTimer6();
         return;
    }
      if (key == '*')    //show mainmenu
      {
        SetTimer();
        return;
      }
  }
}
void SetTimer7(){
  delay(50);
  String Pump_1,Pump_2;
  Pump_1 = (Alarm7 == 1) ? "ON" : "OFF";
  Pump_2 = (Alarm7_2 == 1) ? "ON" : "OFF";
  lcd.clear();
  Time = RTC.now();
  lcd.setCursor(0,0);lcd.print("   ON        OFF  ");
  lcd.setCursor(0,1);lcd.print("  :  :      :  :  ");
  ShowALMPos(t7on_H, t7on_M, t7on_S, 0, 1); ShowALMPos(t7off_H, t7off_M, t7off_S, 10, 1);
  lcd.setCursor(0,2);lcd.print("Pump 1 : ");lcd.print(Pump_1);
  lcd.setCursor(0,3);lcd.print("Pump 2 : ");lcd.print(Pump_2);
  while(1){
    delay(100);
    char key = kpd.getKey();
    switch(key){
        case '1':
        {
          if(Alarm7 == 1){
            lcd.setCursor(9,2);lcd.print("OFF");
            Alarm7 = 0;
          }else{
            lcd.setCursor(9,2);lcd.print("ON ");
            Alarm7 = 1;
          }
          eep.write(54, Alarm7);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus7/Pump_1/status", Alarm7);
          Save();
          SetTimer7();   
          break; 
       }
       case '2':
        {
          if(Alarm7_2 == 1){
            lcd.setCursor(9,3);lcd.print("OFF");
            Alarm7_2 = 0;
          }else{
            lcd.setCursor(9,3);lcd.print("ON ");
            Alarm7_2 = 1;
          }
          eep.write(74, Alarm7_2);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus7/Pump_2/status", Alarm7_2); 
          Save();
          SetTimer7();  
          break; 
       }
    }
    if(key == 'A'){
        t7on_H = SetDateTime(2,0,1);
        if(t7on_H == 255) goto bailout;
        t7on_M = SetDateTime(2,3,1);
        if(t7on_M == 255) goto bailout;
        t7on_S = SetDateTime(2,6,1);
        if(t7on_M == 255) goto bailout;
        t7off_H = SetDateTime(2,10,1);
        if(t7off_H == 255) goto bailout;
        t7off_M = SetDateTime(2,13,1);
        if(t7off_M == 255) goto bailout;
        t7off_S = SetDateTime(2,16,1);
        if(t7off_S == 255) goto bailout;
        
        eep.write(36, t7on_H); delay(10);
        eep.write(37, t7on_M); delay(10);
        eep.write(38, t7on_S); delay(10);
        eep.write(39, t7off_H); delay(10);
        eep.write(40, t7off_M); delay(10);
        eep.write(41, t7off_S); delay(10);
      
        bailout:
          StaticJsonBuffer<200> jsonBuffer;
          JsonObject& Timer_1 = jsonBuffer.createObject();
          Timer_1["ON_HH"] = t7on_H;
          Timer_1["ON_MM"] = t7on_M;
          Timer_1["ON_SS"] = t7on_S;
          Timer_1["OFF_HH"] = t7off_H;
          Timer_1["OFF_MM"] = t7off_M;
          Timer_1["OFF_SS"] = t7off_S;
          Firebase.set(DeviceNumber + "/Timer/Time_7/" , Timer_1);
          Save();
         SetTimer7();
         return;
    }
      if (key == '*')    //show mainmenu
      {
        SetTimer();
        return;
      }
  }
}
void SetTimer8(){
  delay(100);
  String Pump_1,Pump_2;
  Pump_1 = (Alarm8 == 1) ? "ON" : "OFF";
  Pump_2 = (Alarm8_2 == 1) ? "ON" : "OFF";
  lcd.clear();
  Time = RTC.now();
  lcd.setCursor(0,0);lcd.print("   ON        OFF  ");
  lcd.setCursor(0,1);lcd.print("  :  :      :  :  ");
  ShowALMPos(t8on_H, t8on_M, t8on_S, 0, 1); ShowALMPos(t8off_H, t8off_M, t8off_S, 10, 1);
  lcd.setCursor(0,2);lcd.print("Pump 1 : ");lcd.print(Pump_1);
  lcd.setCursor(0,3);lcd.print("Pump 2 : ");lcd.print(Pump_2);
  while(1){
    delay(100);
    char key = kpd.getKey();
    switch(key){
        case '1':
        {
          if(Alarm8 == 1){
            lcd.setCursor(9,2);lcd.print("OFF");
            Alarm8 = 0;
          }else{
            lcd.setCursor(9,2);lcd.print("ON ");
            Alarm8 = 1;
          }
          eep.write(55, Alarm8);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus8/Pump_1/status", Alarm8);
          Save();  
          SetTimer8(); 
          break; 
       }
       case '2':
        {
          if(Alarm8_2 == 1){
            lcd.setCursor(9,3);lcd.print("OFF");
            Alarm8_2 = 0;
          }else{
            lcd.setCursor(9,3);lcd.print("ON ");
            Alarm8_2 = 1;
          }
          eep.write(75, Alarm8_2);
          delay(50);
          Firebase.setInt(DeviceNumber + "/Timer/TimeStatus8/Pump_2/status", Alarm8_2); 
          Save();  
          SetTimer8();
          break; 
       }
    }
    if(key == 'A'){
        t8on_H = SetDateTime(2,0,1);
        if(t8on_H == 255) goto bailout;
        t8on_M = SetDateTime(2,3,1);
        if(t8on_M == 255) goto bailout;
        t8on_S = SetDateTime(2,6,1);
        if(t8on_M == 255) goto bailout;
        t8off_H = SetDateTime(2,10,1);
        if(t8off_H == 255) goto bailout;
        t8off_M = SetDateTime(2,13,1);
        if(t8off_M == 255) goto bailout;
        t8off_S = SetDateTime(2,16,1);
        if(t8off_S == 255) goto bailout;
        
        eep.write(42, t8on_H); delay(10);
        eep.write(43, t8on_M); delay(10);
        eep.write(44, t8on_S); delay(10);
        eep.write(45, t8off_H); delay(10);
        eep.write(46, t8off_M); delay(10);
        eep.write(47, t8off_S); delay(10);
      
        bailout:
          StaticJsonBuffer<200> jsonBuffer;
          JsonObject& Timer_1 = jsonBuffer.createObject();
          Timer_1["ON_HH"] = t8on_H;
          Timer_1["ON_MM"] = t8on_M;
          Timer_1["ON_SS"] = t8on_S;
          Timer_1["OFF_HH"] = t8off_H;
          Timer_1["OFF_MM"] = t8off_M;
          Timer_1["OFF_SS"] = t8off_S;
          Firebase.set(DeviceNumber + "/Timer/Time_8/" , Timer_1);
          Save();
         SetTimer8();
         return;
    }
      if (key == '*')    //show mainmenu
      {
        SetTimer();
        return;
      }
  }
}

