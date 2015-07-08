#ifndef Pot_H
#define Pot_H

#include "Arduino.h"
#include "mixer.h"
#include <math.h>

#define LOGARITHMIC 1
#define LINEAR 0

class Pot
{
public:
  unsigned long int val, lastVal;
  float valF;
  int pin, id, multiplex;
  boolean isLog;
  
  Pot(int _pin, int _id, boolean _isLog, int _multiplex);
  boolean changed();
};

Pot::Pot(int _pin, int _id, boolean _isLog, int _multiplex)
{
  pin = _pin;
  id = _id;
  multiplex = _multiplex;
  isLog = _isLog;
  pinMode(pin, INPUT);
}

boolean Pot::changed()
{
  if(!isLog)
  {
    val = analogRead(pin)/8;
  } 
  else
  {
    valF = analogRead(pin)/128.0;
    val = pow(2, valF)/2;
  }

  if(val != lastVal)
  {
    lastVal = val;
    return true;
  } 
  else return false;
}

#endif

