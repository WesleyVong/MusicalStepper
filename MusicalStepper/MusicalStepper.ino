
#include <LiquidCrystal.h>

const int rs = 10;
const int g0 = 16;
const int a1 = 19;
const int a1s = 20;
const int b1 = 21;
const int c1 = 23;
const int c1s = 24;
const int d1 = 26;
const int e1 = 29;
const int f1 = 31;
const int f1s = 32;
const int g1 = 35;
const int g1s = 37;
const int a2 = 39;
const int a2s = 40;
const int b2 = 43;
const int c2 = 46;
const int c2s = 48;
const int d2 = 52;
const int e2 = 57;
const int f2 = 63;
const int f2s = 67;
const int g2 = 70;
const int a3 = 77;
const int b3 = 83;

int noteSize = 0;
int count = 0;
int note = 0;
double noteLength = 0.0;
double tempo = 1.5;

LiquidCrystal lcd(12, 11, 8, 4, 3, 2);

//Scale
//int notes[] = {c1,d1,e1,f1,g1,a2,b2,c2,d2,e2,f2,g2,a3,b3};
//int lengths[] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};

//Soviet Anthem Tempo 1.5
int notes[] =   {c2,rs,g1,c2,g1,a2,b2,e1,e1,a2,
                 g1,f1,g1,c1,c1,d1,d1,e1,f1,f1,
                 g1,a2,b2,c2,d2,g1,e2,d2,c2,d2,
                 b2,g1,c2,b2,a2,b2,e1,e1,a2,g1,
                 f1,g1,c1,c1,c2,b2,a2,g1,b2,c2,
                 d2,e2,d2,c2,b2,c2,d2,g1,g1,b2,
                 c2,d2,c2,b2,a2,g1,a2,b2,e1,e1,
                 g1,a2,b2,c2,a2,b2,c2,a2,b2,c2,
                 a2,c2,f2,rs,f2,e2,d2,c2,d2,e2,
                 c2,c2,d2,c2,b2,a2,b2,c2,a2,a2,//100
                 c2,b2,a2,g1,c1,c1,c2,b2,a2,g1,
                 rs,g1,c2,g1,a2,b2,e1,e1,a2,g1,
                 f1,g1,c1,c1,d1,d1,e1,f1,f1,g1,
                 a2,b2,c2,d2,g1,e2,d2,c2,d2,b2,
                 g1,c2,b2,a2,b2,e1,e1,a2,g1,f1,
                 g1,c1,c1,c2,b2,a2,g1,b2,c2,d2,
                 e2,d2,c2,b2,c2,d2,g1,g1,b2,c2,
                 d2,c2,b2,a2,g1,a2,b2,e1,e1,g1,
                 a2,b2,c2,a2,b2,c2,a2,b2,c2,a2,
                 c2,f2,rs,f2,e2,d2,c2,d2,e2,c2,
                 c2,d2,c2,b2,a2,b2,c2,a2,a2,c2,
                 b2,a2,g1,c1,c1,g1,a2,b2,c2};
double lengths[] = {6,1,1,2,1.5,0.5,2,1,1,2,
                 1.5,0.5,2,1,1,2,1.5,0.5,2,1.5,
                 0.5,2,1,1,3,1,2,1.5,0.5,2,
                 1,1,2,1.5,0.5,2,1,1,2,1.5,
                 0.5,2,1,1,2,1.5,0.5,1,1,1,
                 1,4,1,1,1,1,3,1,1,1,
                 1,1,4,1,1,1,1,3,1,1,
                 1,1,1,2,1.5,0.5,2,1.5,0.5,2,
                 1,1,3,1,4,1,1,1,1,3,
                 1,4,4,1,1,1,1,3,1,4,//100
                 2,1.5,0.5,2,1.5,0.5,2,1.5,0.5,2,
                 1,1,2,1.5,0.5,2,1,1,2,1.5,
                 0.5,2,1,1,2,1.5,0.5,2,1.5,0.5,
                 2,1,1,3,1,2,1.5,0.5,2,1,
                 1,2,1.5,0.5,2,1,1,2,1.5,0.5,
                 2,1,1,2,1.5,0.5,1,1,1,1,
                 4,1,1,1,1,3,1,1,1,1,
                 1,4,1,1,1,1,3,1,1,1,
                 1,1,2,1.5,0.5,2,1.5,0.5,2,1,
                 1,3,1,4,1,1,1,1,3,1,
                 4,4,1,1,1,1,3,1,4,2,
                 1.5,0.5,2,1.5,0.5,4,2,2,5};

//Hall of the Mountain King Tempo 0.6
//int notes[] =   {b1,c1s,d1,e1,f1s,d1,f1s,f1,c1,f1,
//                 e1,c1,e1,b1,c1s,d1,e1,f1s,d1,f1s,
//                 b2,a2,f1s,d1,f1s,a2,
//                 // Repeat Above
//                 b1,c1s,d1,e1,f1s,d1,f1s,f1,c1,f1,
//                 e1,c1,e1,b1,c1s,d1,e1,f1s,d1,f1s,
//                 b2,a2,f1s,d1,f1s,a2,
//                 // Next Stanza
//                 f1s,g1s,a2s,b2,c2s,a2s,c2s,d2,a2s,d2,
//                 c2s,a2s,c2s,f1s,g1s,a2s,b2,c2s,a2s,c2s,
//                 d2,a2s,d2,c2s,
//                 // Repeat Above
//                 f1s,g1s,a2s,b2,c2s,a2s,c2s,d2,a2s,d2,
//                 c2s,a2s,c2s,f1s,g1s,a2s,b2,c2s,a2s,c2s,
//                 d2,a2s,d2,c2s,
//                 // Next Stanza
//                 b2,c2s,d2,e2,f2s,d2,f2s,f2,c2s,f2,
//                 e2,c2,e2,b2,c2s,d2,e2,f2s,d2,f2s,
//                 b2,a2,f1s,d1,f1s,a2,
//                 // Rests
//                 rs,a2s,b2,rs,a2s,b2,rs,
//                 // Next Stanza
//                 b1,c1s,d1,e1,f1s,d1,f1s,b2,a2s,f1s,
//                 a2s,c2s,b2,
//                 // Rests
//                 rs,a2s,b2,rs,a2s,b2,rs,
//                 // Next Stanza
//                 b1,c1s,d1,e1,f1s,d1,f1s,b2,a2s,f1s,
//                 a2s,c2s,b2};
//                 
//double lengths[] = {1,1,1,1,1,1,2,1,1,2,
//                    1,1,2,1,1,1,1,1,1,1,
//                    1,1,1,1,1,4,
//                    // Repeat Above
//                    1,1,1,1,1,1,2,1,1,2,
//                    1,1,2,1,1,1,1,1,1,1,
//                    1,1,1,1,1,4,
//                    // Next Stanza
//                    1,1,1,1,1,1,2,1,1,2,
//                    1,1,2,1,1,1,1,1,1,2,
//                    1,1,2,4,
//                    // Repeat Above
//                    1,1,1,1,1,1,2,1,1,2,
//                    1,1,2,1,1,1,1,1,1,2,
//                    1,1,2,4,
//                    // Next Stanza
//                    1,1,1,1,1,1,2,1,1,2,
//                    1,1,2,1,1,1,1,1,1,1,
//                    1,1,1,1,1,4,
//                    // Rests
//                    1.5,0.2,2.5,5.5,0.2,2.5,4,
//                    // Next Stanza
//                    1,1,1,1,1,1,1,1,1,1,
//                    1,1,4,
//                    // Rests
//                    1.5,0.2,2.5,5.5,0.2,2.5,4,
//                    // Next Stanza
//                    1,1,1,1,1,1,1,1,1,1,
//                    1,1,4};

// Ode to Joy Tempo = 0.75
//int notes[] = {e1,e1,f1,g1,g1,f1,e1,d1,c1,c1,d1,e1,e1,d1,d1,e1,e1,f1,g1,g1,f1,e1,d1,c1,c1,d1,e1,d1,c1,c1,d1,d1,e1,c1,d1,e1,f1,e1,c1,d1,e1,f1,e1,d1,c1,d1,g0,e1,e1,f1,g1,g1,f1,e1,d1,c1,c1,d1,e1,d1,c1,c1};
//int lengths[] = {2,2,2,2,2,2,2,2,2,2,2,2,3,1,4,2,2,2,2,2,2,2,2,2,2,2,2,3,1,4,2,2,2,2,2,1,1,2,2,2,1,1,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,3,1,4};

//Katyusha
//int notes[] = {a2,d2,c2,d2,c2,a2s,a2,g1,a2,d1,
//               rs,a2s,g1,a2,f1,e1,a1,f1,e1,d1,
//               // Next Stanza
//               d1,e1,f1,d1,f1,f1,e1,d1,e1,a1,
//               e1,f1,g1,e1,g1,g1,f1,e1,d1,a2,
//               d2,c2,d2,c2,a2s,a2,g1,a1,d1,rs,
//               a2s,g2,a2,f1,e1,a1,f1,e1,d1,
//               // Repeat Above
//               d1,e1,f1,d1,f1,f1,e1,d1,e1,a1,
//               e1,f1,g1,e1,g1,g1,f1,e1,d1,a2,
//               d2,c2,d2,c2,a2s,a2,g1,a1,d1,rs,
//               a2s,g2,a2,f1,e1,a1,f1,e1,d1};
//
//double lengths[] = {2,2,2,1,1,2,1,1,2,2,
//                    1,2,1,3,1,1,1,1,1,4,
//                    // Next Stanza
//                    3,1,3,1,1,1,1,1,2,2,
//                    3,1,3,1,1,1,1,1,4,2,
//                    2,2,1,1,2,1,1,2,2,1,
//                    2,1,3,1,1,1,1,1,4,
//                    // Repeat Above
//                    3,1,3,1,1,1,1,1,2,2,
//                    3,1,3,1,1,1,1,1,4,2,
//                    2,2,1,1,2,1,1,2,2,1,
//                    2,1,3,1,1,1,1,1,4};

const int stepPin = 7; 
const int dirPin = 6; 
const int enPin = 5;

void setup() {
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  lcd.setCursor(0,0);
  lcd.print("Hall of the ");
  lcd.setCursor(0,1);
  lcd.print("Mountain King");
  
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
  delay(5000);
}

void loop() { 
//  if (speed < 80){
//    speed ++;
//    motor.setSpeed(speed);
//    Serial.println(speed);
//  }
  if (notes[count] > 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(notes[count]);
    //Serial.println(notes[count]);
    note = notes[count];
    noteLength = lengths[count];
    moveStep(note * noteLength * tempo, note);
    moveStep(1,10);
    count++;
  }else {
    digitalWrite(enPin,HIGH);
    lcd.clear();
  }
  
 
}

void moveStep(int stepNum, int rpm){
  digitalWrite(dirPin,HIGH);
    for(int x = 0; x < stepNum; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(150000.0/rpm); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(150000.0/rpm); 
    }
}
