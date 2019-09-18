int pulsadorb = 0;
int pulsadorg = 0;
int pulsadorr = 0;
int pulsadory = 0;

int LedAzul = 2;
int LedVerde = 3;
int LedRojo = 4;
int LedAmarillo = 5;

int juego[] = {2,3,5,4};
int pulsacion [4];
int posicion = 0;

int randNumber;

void setup() {
  // put your setup code here, to run once:
  pinMode(LedAzul,OUTPUT);
  pinMode(LedVerde,OUTPUT);
  pinMode(LedRojo,OUTPUT);
  pinMode(LedAmarillo,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);

  digitalWrite(LedAzul,LOW);
  digitalWrite(LedVerde,LOW);
  digitalWrite(LedRojo,LOW);
  digitalWrite(LedAmarillo,LOW);

  Serial.begin(9600);
//cadena aleatoria
/*  for(int i=0;i<4;i++){
    randNumber = random(2,5);
    juego[i] = randNumber;
  }*/

//lucecitas
  for (int i=0;i<4;i++){
    digitalWrite(juego[i],HIGH);
    delay(300);
    digitalWrite(juego[i],LOW);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  pulsadorb = digitalRead(7);
  pulsadorg = digitalRead(8);
  pulsadorr = digitalRead(9);
  pulsadory = digitalRead(10);

  if (posicion>=4) {
    if(juego[0]==pulsacion[0]){
      if(juego[1]==pulsacion[1]){
        if(juego[2]==pulsacion[2]){
          if(juego[3]==pulsacion[3]){
          digitalWrite(LedAzul,HIGH);
          digitalWrite(LedVerde,HIGH);
          digitalWrite(LedRojo,HIGH);
          digitalWrite(LedAmarillo,HIGH);
          }
        }
      }
    }
    else{
    digitalWrite(LedAzul,HIGH);
    digitalWrite(LedVerde,HIGH);
    digitalWrite(LedRojo,HIGH);
    digitalWrite(LedAmarillo,HIGH);
    delay(500);
    digitalWrite(LedAzul,LOW);
    digitalWrite(LedVerde,LOW);
    digitalWrite(LedRojo,LOW);
    digitalWrite(LedAmarillo,LOW);
    Serial.print("fallo");
    }
  }
  
  if (pulsadorb==HIGH) {
    digitalWrite(LedAzul,HIGH);
    delay(500);
    pulsacion[posicion] = 2;
    posicion++;
  }
  if (pulsadorg==HIGH) {
    digitalWrite(LedVerde,HIGH);
    delay(500);
    pulsacion[posicion] = 3;
    posicion++;
  }
  if (pulsadorr==HIGH) {
    digitalWrite(LedRojo,HIGH);
    delay(500);
    pulsacion[posicion] = 4;
    posicion++;
  }
  if (pulsadory==HIGH) {
    digitalWrite(LedAmarillo,HIGH);
    delay(500);
    pulsacion[posicion] = 5;
    posicion++;
  }
  else {
    digitalWrite(LedAzul,LOW);
    digitalWrite(LedVerde,LOW);
    digitalWrite(LedRojo,LOW);
    digitalWrite(LedAmarillo,LOW);
  }
}
