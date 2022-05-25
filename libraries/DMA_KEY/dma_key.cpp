#include "dma_key.h"
#if(ARDUINO>100)
#include "Arduino.h"
#else
#include "WConstants.h"
#endif
extern "C" 
{
#include <stdio.h>  
#include <string.h> 
#include <inttypes.h>
}


int Key1Pin = 5;
int Key2Pin = 2;
int Key3Pin = 3;
int Key4Pin = 67;
int Key5Pin = 13;


DMA_KEY::DMA_KEY()
{
}



void DMA_KEY::KeyInit(void)
{
	pinMode(Key1Pin, INPUT);
	pinMode(Key2Pin, INPUT);
	pinMode(Key3Pin, INPUT);
	pinMode(Key4Pin, INPUT);
	pinMode(Key5Pin, INPUT);
}

int DMA_KEY::CheckKey(int keynum)
{
	int keystate = 1;
	
	if(keynum == 1)
	{
		keystate = digitalRead(Key1Pin);
		delay(2);
		if(keystate == 0)
		{
			while(!digitalRead(Key1Pin));
			return 1;
		}	
	}
	else if(keynum == 2)
	{
		keystate = digitalRead(Key2Pin);
		delay(2);
		if(keystate == 0)
		{
			while(!digitalRead(Key2Pin));
			return 1;
		}	
	}
	else if(keynum == 3)
	{
		keystate = digitalRead(Key3Pin);
		delay(2);
		if(keystate == 0)
		{
			while(!digitalRead(Key3Pin));
			return 1;
		}	
	}
	else if(keynum == 4)
	{
		keystate = digitalRead(Key4Pin);
		delay(2);
		if(keystate == 0)
		{
			while(!digitalRead(Key4Pin));
			return 1;
		}	
	}
	else if(keynum == 5)
	{
		keystate = digitalRead(Key5Pin);
		delay(2);
		if(keystate == 0)
		{
			while(!digitalRead(Key5Pin));
			return 1;
		}	
	}

	return 0;
}





