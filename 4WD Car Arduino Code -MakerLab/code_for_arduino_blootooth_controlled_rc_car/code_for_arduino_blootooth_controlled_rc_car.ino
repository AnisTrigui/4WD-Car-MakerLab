#include <Servo.h>
Servo myservo;
int pos = 0;
char t ; 
void setup() {

pinMode(2,OUTPUT);
pinMode(A3,OUTPUT);
pinMode(A0,OUTPUT);
pinMode(7,OUTPUT);  
pinMode(A1,OUTPUT);
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
myservo.attach(9);
myservo.write(90);
Serial.begin(9600);
 
}
 
void loop() {
 
if(Serial.available()){
  t = Serial.read();
 }
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}

else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
 
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
 
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  }

 
else if(t == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
 
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
 
}
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
else if(t == 'W'){     
  digitalWrite(7,HIGH);
  digitalWrite(A0,HIGH);
}
else if(t == 'w'){     
  digitalWrite(7,LOW);
  digitalWrite(A0,LOW);
}
else if(t == 'U'){     
  digitalWrite(2,HIGH);
  digitalWrite(A3,HIGH);
}
else if(t == 'u'){     
  digitalWrite(2,LOW);
  digitalWrite(A3,LOW);
}

else if(t == 'X'){

 myservo.write(0);
 delay(15);
  

}
else if(t == 'x'){

 myservo.write(90);
 delay(15);
  

}
 


}
