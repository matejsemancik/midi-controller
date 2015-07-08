/*
  Created by Matej Semančík.
  All rights reserved
*/

#include <math.h>
#include "button.h"
#include "pot.h"
#include "mixer.h"

// Definicia tlacitiek
int numButtons = 8; // CISLA MUSIA BYT ROVNAKE
Button *buttons[8]; // CISLA MUSIA BYT ROVNAKE

// Definicia potenciometrov
int numPots = 0;
Pot *pots[0];

void setup()
{
  Serial.begin(57600);
  
  // Adresovacie piny pre multiplexor
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
  // Prvy multiplexor, A0 /////////////////////////////////////////////////////////////////////////////////////////////
  
  //Potenciometre ////////////////////////////////////////////////////////////////////
  /*
  
  for(int i=0; i<numPots; i++)
  {
    pots[i] = new Pot(A0, i, LINEAR, i); //pin, id, je linearny, multiplex
  }
  */
  //Tlacitka /////////////////////////////////////////////////////////////////////////
  
  for(int i=0; i<numButtons; i++)
  {
    buttons[i] = new Button(A0, numPots+i+56, numPots+i, HOLD);
  }
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void loop()
{
  //Potenciometre
  /*
  for(int i=0; i<numPots; i++)
  {
    multiplex(pots[i]->multiplex);
    if(pots[i]->changed())
    {
      MidiTX(176, pots[i]->id, pots[i]->val);
    }
  }
  */
  
  //Tlacitka
  for(int i=0; i<numButtons; i++)
  {
    multiplex(buttons[i]->multiplex);
    if(buttons[i]->changed())
    {
      MidiTX(buttons[i]->statusmsg, buttons[i]->id, buttons[i]->val*127);
    }
  }
  // --------------------------------------------
  
  delay(10);
}
