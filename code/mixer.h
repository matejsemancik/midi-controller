#ifndef Mixer_H
#define Mixer_H

#include "Arduino.h"

int s0 = 0;
int s1 = 0;
int s2 = 0;

void MidiTX(unsigned char CC, unsigned char ID, unsigned char VAL)
{
  Serial.write(CC);
  Serial.write(ID);
  Serial.write(VAL);
}

void multiplex(int ch)
{
  // Nastavi jednotlive bitove vahy pinov pre vstup. hodnotu 'ch', napr. pri ch=3 -> s3 = 0, s2=1, s0=1
  s0 = bitRead(ch, 0);
  s1 = bitRead(ch, 1);
  s2 = bitRead(ch, 2);
  
  digitalWrite(2, s0);
  digitalWrite(3, s1);
  digitalWrite(4, s2);
}

#endif
