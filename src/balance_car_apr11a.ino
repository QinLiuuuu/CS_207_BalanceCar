*/
int STBY = 8; 
  
//Motor A
int PWMA = 9; // Left motor PWM output control pin
int AIN1 = 7; //Left motor positive pole
int AIN2 = 6; //Left motor negative pole
  
//Motor B  
int PWMB = 10; //Right motor PMW output control pin
int BIN1 = 13; //Right motor positive pole
int BIN2 = 12; //Right motor negative pole 
  
void setup(){  
  pinMode(STBY, OUTPUT);  
  
  pinMode(PWMA, OUTPUT);  
  pinMode(AIN1, OUTPUT);  
  pinMode(AIN2, OUTPUT);  
  
  pinMode(PWMB, OUTPUT);  
  pinMode(BIN1, OUTPUT);  
  pinMode(BIN2, OUTPUT);  
}  

void runset(int motor, int speed, int direction){  
  
  digitalWrite(STBY, HIGH); //使能驱动模块脚 
  
  boolean Pin1 = LOW;  
  boolean Pin2 = HIGH;  
  
  if(direction == 1){  
    Pin1 = HIGH;  
    Pin2 = LOW;  
  }  
  
  if(motor == 1){  
    digitalWrite(AIN1, Pin1);  
    digitalWrite(AIN2, Pin2);  
    analogWrite(PWMA, speed);  
  }else{  
    digitalWrite(BIN1, Pin1);  
    digitalWrite(BIN2, Pin2);  
    analogWrite(PWMB, speed);  
  }  
}  
  
void loop(){  
  runset(1, 255, 1);  
  runset(2, 255, 1); 
  
  delay(1000); // 1 second
  stop(); // stop
  delay(250); //continue 
  
  runset(1, 128, 0);   
  runset(2, 128, 0); 
  
  delay(1000);  
  stop();  
  delay(250);  
}  
   
void stop(){  
  digitalWrite(STBY, LOW);   
}  
