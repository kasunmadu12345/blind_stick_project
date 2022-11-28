int trigger_pin = 2;// Ultra sonic sensor 1 
int echo_pin = 3;// Ultra sonic sensor 1 
int trigger_pin_2 = 5;// Ultra sonic sensor 2 
int echo_pin_2 = 6;// Ultra sonic sensor 2 
int trigger_pin_3 = 7 ;// Ultra sonic sensor 3 
int echo_pin_3 = 8 ;// Ultra sonic sensor 31 int buzzer_pin = 4; 

#include "SD.h"  
#include "TMRpcm.h" 
#include "SPI.h" 
#define SD_ChipSelectPin 10

TMRpcm tmrpcm; 

void setup () { 
    Serial.begin (9600);

    pinMode (trigger_pin, OUTPUT);// Ultra sonic sensor 1 
    pinMode (echo_pin, INPUT);// Ultra sonic sensor 1 
    pinMode (trigger_pin_2, OUTPUT);// Ultra sonic sensor 2 
    pinMode (echo_pin_2, INPUT);// Ultra sonic sensor 2 
    pinMode (trigger_pin_3, OUTPUT);// Ultra sonic sensor 3 
    pinMode (echo_pin_3, INPUT);// Ultra sonic sensor 3 
    pinMode (buzzer_pin, OUTPUT); 
} 

tmrpcm.speakerPin = 9;
Serial.begin(9600);

  if (!SD.begin(SD_ChipSelectPin)){ 

    Serial.println("SD fail"); 
    return; 
} 

void loop () { 
    digitalWrite (trigger_pin, LOW); 
    delayMicroseconds (2); 
    digitalWrite (trigger_pin, HIGH); 
    delayMicroseconds (10); 
    digitalWrite (trigger_pin, LOW); 
    long t = pulseIn (echo_pin, HIGH); 
    long distance = t / 29 / 2; 
    digitalWrite (trigger_pin_2, LOW); 
    delayMicroseconds (2); 
    digitalWrite (trigger_pin_2, HIGH); 
    delayMicroseconds (10); 
    digitalWrite (trigger_pin_2, LOW); 
    long tl = pulseIn (echo_pin_2, HIGH); 
    long distancel = tl / 29 / 2; 
    digitalWrite (triggeryin_3, LOW); 
    delayMicroseconds (2); 
    digitalWrite (triggeryin_3, HIGH); 
    delayMicroseconds (10); digitalWrite (trigger_pin_3, LOW); 
    long t2 = pulseln (echo_pin_3, HIGH); 
    long distance3 = t2 / 29 / 2; 

}

if(distance > 30){ 
    Serial.println(distance); go_audio(); delay(4000); 
    } if (distance <= 30) { 
        Serial.println(distance); stop_audio(); clelav(4000); 
    } 
    if (distance<30 && distancel<50 ) {
        Serial.println(distance); 
        goup_audio(); 
        delay(4000); 
    if(distance3<50 && distance3>33){
        goDown_audio(); 
        delay(4000); 
    } 
}

void goup_audio() {// Goup audio input 
    tmrpcm.setVolume(6); 
    tmrpcm.play("GOUP.wav"); 
} 
void go_audio() {// Go audio audio input 
    tmrpcm.setVolume(6); 
    tmrpcm.play("GO.wav"); 
}

void stop_audio() {// Stop audio input 
    tmrpcm.setVolume(6); 
    tmrpcm.play("STOP.wav"); 
} 
void goDown audio() {// Go down audio input. 
    tmrpcm.setVolume(6); 
    tmrpcm.play("GODOWN.wav"); 
}

