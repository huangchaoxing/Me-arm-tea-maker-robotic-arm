//int incomingByte = 0;   // for incoming serial data
//int led = 13;
void setup()
{
  Serial.begin(9600); // // opens serial port, sets data rate to 9600 bps
 
  //pinMode(led, OUTPUT);
}
 
void loop()
{ //digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
 
/*  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();//not using this
   Serial.print(incomingByte);
   if(incomingByte=='2')
     { digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(500);
      digitalWrite(led, LOW); 
      delay(200);
      digitalWrite(led,HIGH);
      delay(1000);
      }
   else{
        for(int i=0;i<=9;i++)
        {digitalWrite(led,HIGH);
        delay(1000);
        digitalWrite(led,LOW);
        delay(1000);}
         }
  }*/
  char serialCmd;
  serialCmd=Serial.read();
  Serial.print("serialCmd = ");
  Serial.print(serialCmd);  
  int X;
  int Y;
  int coordinate = Serial.parseInt(); 
  switch(serialCmd){
    case 'x':  
     X=coordinate;
      Serial.print(" x: ");
      Serial.println(X);
      break;
    case 'y':  
         
      Y=coordinate;
      Serial.print(" y: ");
      Serial.println(Y);
      break;
    default:
      Serial.println(" Unknown Command.");
  }

  
}
