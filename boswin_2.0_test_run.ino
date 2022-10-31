
/*
         --------------- 
        |     O   O     |
        |---------------|
sr 2==> |               | <== sr 1
         --------------- 
            ||     ||
            ||     ||
sr 3==>   -----   ------  <== sr 4
         |-----   ------|

servo 1 = 180 (foot forward), 0 (foot backward)
servo 2 = 0 (foot backward), 180 (foort forward)
servo 3 = 0 (down), 180 (up)
servo 4 = 180 (down), 0 (up)
*/
#include <Servo.h>
Servo s1;
Servo s2;
Servo s3;
Servo s4;

int pos = 90;
int s1_set;
int s2_set;
int s3_set;
int s4_set;

void servo_collect_set(int s1_set, int s2_set, int s3_set, int s4_set){
  s1.write(s1_set);
  s2.write(s2_set);
  s3.write(s3_set);
  s4.write(s4_set);
  Serial.write("servo locating complete");
}

void setup(){
  s1.attach(2);
  s2.attach(3);
  s3.attach(4);
  s4.attach(5);
  Serial.begin(9600);
}

void loop(){
  
servo_collect_set(pos,pos,pos,pos);
delay(1000);
servo_collect_set(90,90,20,60);
delay(1000);
servo_collect_set(120,120,20,60);
delay(1000);
servo_collect_set(90,90,120,170);
delay(1000);
servo_collect_set(60,60,120,170);
delay(1000);
servo_collect_set(90,90,90,90);
delay(1000);
}
