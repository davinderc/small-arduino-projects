/*
  Open door Alarm

 Makes an annoying alarm sound when door is open

 circuit:
 * Buzzer on digital pin 9
 * Switch between ground and digital pin 7

 created 02 May 2016
 modified 02 May 2016
 by Davinder Chandhok

This code is published under a CC-BY-SA 3.0 License

 */

int ledPin = 13;
int buzzer = 9;
int doorSensor = 7;
int buzzerDuration = 250;
int statePin = LOW;
int doorOpen = LOW;
int timeOn = 0;
int pauseBetweenNotes = 800; // Alarme leve 
int freqMedia = 400; // Freq media
int freqAlta = 100; // Freq alta
int intervaloMedio = 5000;
int intervaloLongo = 10000;

void setup() {
 pinMode(ledPin, OUTPUT); //door closed LED
 pinMode(7, INPUT_PULLUP); //door sensor button
 digitalWrite(buzzer, LOW);
}

void loop() {

    statePin = !statePin; // pisca em quanto porta esta fechada.
    digitalWrite(ledPin, statePin);
    doorOpen = digitalRead(doorSensor); // leia sensor (botao) da porta
    while(doorOpen){
        digitalWrite(buzzer,HIGH); //Barulho do buzzer
        delay(buzzerDuration); 
        digitalWrite(buzzer,LOW);
        if(timeOn > intervaloMedio) { //Aumentar a frequencia do barulho
            pauseBetweenNotes = freqMedia; 
        }
        if(timeOn > intervaloLongo) {
            pauseBetweenNotes = freqAlta;
        }
        delay(pauseBetweenNotes); //intervalo entre barulho
        timeOn = timeOn + pauseBetweenNotes+buzzerDuration; //contador do tempo do buzzer
        doorOpen = digitalRead(doorSensor); // checar se a porta fechou e reseta o contador e frequencia
        if(!doorOpen){
          pauseBetweenNotes = 1000;
          timeOn = 0;
        }
      }
    }
