 int bp=5;
 int reservoir_principal=9;
 int moteur = 12;
 int vanne_doseur = 8;
 int vanne_mangeoir = 7;
 int dose_servie = 4;
 int dose_at1  = 2; 
 int dose_at2  = 3; 
bool dose_atteint1  ;
bool dose_atteint2   ;
int i=0;
int j=0;
bool demarre;

void setup() {
  // put your setup code here, to run once:
pinMode(reservoir_principal,OUTPUT);
pinMode(moteur,OUTPUT);
pinMode(vanne_doseur,OUTPUT);
pinMode(vanne_mangeoir,OUTPUT);
pinMode(dose_servie,OUTPUT);
pinMode(dose_at1,INPUT_PULLUP);
pinMode(dose_at2,INPUT_PULLUP);
pinMode(bp,INPUT_PULLUP);
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   demarre=digitalRead(bp);
  if(demarre==LOW){
  digitalWrite(vanne_mangeoir,LOW);
  digitalWrite(dose_servie,LOW);
  dose_atteint1=digitalRead(dose_at1);
  dose_atteint2=digitalRead(dose_at2);
  digitalWrite(reservoir_principal,HIGH);
  delay(500);
  digitalWrite(moteur,HIGH);
   delay(500);
  digitalWrite(vanne_doseur,HIGH);
  delay(500); 
  
  
    while(i<=10){
      dose_atteint1=digitalRead(dose_at1);
      dose_atteint2=digitalRead(dose_at2);
       Serial.println ("i");
       Serial.println (i);
      digitalWrite(vanne_mangeoir,LOW); 
      digitalWrite(reservoir_principal,HIGH);
      digitalWrite(moteur,HIGH);
      digitalWrite(vanne_doseur,HIGH);
      if (dose_atteint1 == LOW){
         Serial.print ("dos1");
         Serial.println (dose_atteint1);
         delay(1000);
         if (dose_atteint2 == HIGH){
        Serial.println ("dos2");
        Serial.println (dose_atteint2);
        digitalWrite(reservoir_principal,LOW);  
        digitalWrite(moteur,LOW);
        digitalWrite(vanne_doseur,LOW);
        digitalWrite(vanne_mangeoir,HIGH);
        delay(5000);
         i++;
      }
      }
     
      }
      i=0;
       while(j<=19){
         dose_atteint1=digitalRead(dose_at1);
         dose_atteint2=digitalRead(dose_at2);
         Serial.println ("j");
         Serial.println (j);
         digitalWrite(vanne_mangeoir,LOW); 
         digitalWrite(dose_servie,LOW);
         digitalWrite(reservoir_principal,HIGH);
         digitalWrite(moteur,HIGH);
         digitalWrite(vanne_doseur,HIGH);
         if (dose_atteint1 == LOW){
           Serial.println ("GFDS");
         Serial.println (dose_atteint1);
            delay(1000);
            if (dose_atteint2 == LOW){ 
            digitalWrite(reservoir_principal,LOW);
            digitalWrite(moteur,LOW);
            digitalWrite(vanne_doseur,LOW);
            digitalWrite(vanne_mangeoir,HIGH);
            delay(500);
            digitalWrite(dose_servie,HIGH);
            delay(500);
         }
         }
       j++;
       } 
       j=0;
     }
     }
