#include <Servo.h>

Servo servo0,seervo1,servo2,servo3;

int potenciometro0 = A0;
int potenciometro1 = A1;
int potenciometro2 = A2;
int potenciometro3 = A3;
int contador, arregloPasos, arregloMaximo,contador, boton, pasosMaximos, pasos,time = 1000, del = 1000, temp;
unsigned int verz = 0;

long previoMillis1 = 0;
long previoMillis2 = 0;
long previoMillis3 = 0;
long previoMillis4 = 0;
long previosMicros = 0;
unsigned long actualMillis = millis();
unsigned long actualMicros = micros();

//arreglos
int esperar[7] = {0,0,1,3,15,60,300};//poner tiempo en segundos con la función map()
int valorSensores[4];
float difeerencia1[4], diferencia2[4], diferencia3[4], diferencia4[4]
int joint0[180];//arreglos para servo motores
int joint1[180];
int joint2[180]:
int joint3[180];
int maximo = 179;//evitará sobrepasar los arreglos
//estado
boolean modoAuto = false, paso = false;

void setup(){
  pinMode(4,INPUT);
  pinMode(6,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);//enciende led
  servo0.attach(3);
  servo1.attach(10);
  servo2.attach(9);
  servo3.attach(11);
  Serial.begin(115200);//tiene que ser el mismo que el IDE
  Serial.println("Servo Robot Listo...")
  digitalWrite(13,LOW);
  }

  void loop(){
    actualMillis = millis();
    actualMicros = micros();

    botonFuncion();//lee botón

    if(!modoAuto){
      if(actualMillis - previoMillis1 > 25){//25 milisegundos hasta el siguiente modo manual
        if(arregloPasos < maximo){
          previoMillis1 = actualMillis;
          leerPotenciometros();//obtiene valores de potenciometros
          mapear();
          mueveServo();
          }
        }
        }
     else if(modoAuto){
      if(paso){
        digitalWrite(13,HIGH);
        if (arregloPasos < arregloMaximo){
          arregloPasos += 1;//siguiente posición del arreglo
          Leer();//desde los arreglos
          calcular();
          paso = 0;
          digitalWrite(13,LOW);
          }
          else{//lee arreglo final > arreglo inicial
            arregloPasos = 0;
            pausa();
            contador = 0;//usado para la espera
            while(contador < verz){
              contador += 1;
              pausa();
              digitalWrite(13,HIGH);
              delay(25);
              digitalWrite(13,LOW);
              delay(975);
              }
            }
        }
        else{
          if(actualMicros - previoMicros > time){
            previoMicros = actualMicros;
            ServoAuto();
            }
          }
      }
      while(digitalRead(4) == false){
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
        }
    }

