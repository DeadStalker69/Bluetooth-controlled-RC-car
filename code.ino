char t;             // defines the chracter which will be used for communication between bluetooth device and bluetooth module.
 
void setup() {
pinMode(11,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(13,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse 
Serial.begin(9600);   //start the Bluetooth communication
 
} 
 
void loop() {
if(Serial.available()){   //checks ifany input is availible by the Bluetooth module.
  t = Serial.read();      //reads the input from Bluetooth module.
  Serial.println(t);      //prints the input to Arduino
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH); //Right forward motor set as high or given command to move
  digitalWrite(11,HIGH); //Left forward motor set as high or given command to move
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH); //Right backward motor set as high or given command to move
  digitalWrite(10,HIGH); //Left backward motor set as high or given command to move
}
 
else if(t == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH); //Right forward motor set as high or given command to move
}
 
else if(t == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(11,HIGH); //Left forward motor set as high or given command to move
}


 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW); //Right forward motor set as low or given command to stop
  digitalWrite(12,LOW); //Right backward motor set as low or given command to stop
  digitalWrite(11,LOW); //Left forward motor set as low or given command to stop
  digitalWrite(10,LOW); //Left backward motor set as low or given command to stop
}


delay(100);
}
