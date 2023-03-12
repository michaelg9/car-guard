#include <SoftwareSerial.h>

SoftwareSerial BTSerial(6,7);

const int redLED = 10;
const int blueLED = 11;
const int greenLED = 12;

char switchstate;

void setup(){
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop(){
  if(BTSerial.available() > 0){
    switchstate = BTSerial.read();
    
    // write to bluetooth communication, eg. app terminal
    BTSerial.println(switchstate);
    // write to serial communication, eg. serial monitor
    Serial.println(switchstate);

    if(switchstate == '5'){
      digitalWrite(redLED, HIGH);
    }
    else if (switchstate == '4'){
      digitalWrite(redLED, LOW);
    }

    if(switchstate == '6'){
      digitalWrite(blueLED, HIGH);
    }
    else if (switchstate == '3'){
      digitalWrite(blueLED, LOW);
    }
    
    if(switchstate == '7'){
      digitalWrite(greenLED, HIGH);
    }
    else if (switchstate == '2'){
      digitalWrite(greenLED, LOW);
    }
    
    if(switchstate == '9'){
      digitalWrite(redLED, HIGH);
      digitalWrite(blueLED, HIGH);
      digitalWrite(greenLED, HIGH);
    }
    else if (switchstate == '0'){
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(greenLED, LOW);
    }    
  }
  delay(50);
}
