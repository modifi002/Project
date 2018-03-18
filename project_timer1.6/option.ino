
void Beep2(){
  digitalWrite(Buzzer,HIGH);delay(50);
  digitalWrite(Buzzer,LOW);delay(50);
  digitalWrite(Buzzer,HIGH);delay(50);
  digitalWrite(Buzzer,LOW);
}
void Beep(){
  digitalWrite(Buzzer,HIGH);delay(50);
  digitalWrite(Buzzer,LOW);
}
void BeepESC(){
  digitalWrite(Buzzer,HIGH);delay(100);
  digitalWrite(Buzzer,LOW);delay(50);
  digitalWrite(Buzzer,HIGH);delay(50);
  digitalWrite(Buzzer,LOW);delay(50);
  digitalWrite(Buzzer,HIGH);delay(50);
  digitalWrite(Buzzer,LOW);
}
void BeepALM(){
  digitalWrite(Buzzer,HIGH);delay(200);
  digitalWrite(Buzzer,LOW);
}
void Save(){
  delay(50);
  lcd.clear();
  lcd.setCursor(3,0);lcd.print("Save data...!");
  lcd.setCursor(5,1);lcd.print("Success.");
  delay(1000);
  Beep2();
  lcd.clear();
  
}

