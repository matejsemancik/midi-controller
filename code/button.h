#ifndef Button_H
#define Button_H

#include "Arduino.h"

#define TOGGLE 1
#define HOLD 0

#define NOTEON 144
#define NOTEOFF 128
#define CTRLCHANGE 176

class Button
{
public:
  int val, lastVal, pin, id, multiplex, statusmsg;
  boolean ena, toggleable;

  Button(int _pin, int _id, int _multiplex, boolean _toggleable);
  boolean changed();
};

Button::Button(int _pin, int _id, int _multiplex, boolean _toggleable)
{
  pin = _pin;
  id = _id;
  multiplex = _multiplex;
  toggleable = _toggleable;
  statusmsg = 176;
  pinMode(pin, INPUT);
  ena = true;
}

boolean Button::changed()
{
  val = digitalRead(pin);

  if(toggleable)
  {
    if(ena == true && val == 1)
    {
      ena = false;
      return true;
    } 
    else
    {
      ena = !val;
      return false;
    }
  } 
  else if(!toggleable)
  {
    if(lastVal == val)
    {
      return false;
    } 
    else if(val == 1 && ena == true)
    {
      ena = false;
      statusmsg = 144;
      return true;
    } 
    else if(val == 0 && ena == false)
    {
      ena = true;
      statusmsg = 128;
      return true;
    }
    lastVal = val;
  }
}

#endif



