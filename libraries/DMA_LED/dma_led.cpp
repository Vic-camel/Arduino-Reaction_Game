#include "dma_led.h"
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


int LED1RedPin   = 54;
int LED1GreenPin = 55;
int LED1BluePin  = 56;
int LED2RedPin   = 57;
int LED2GreenPin = 58;
int LED2BluePin  = 59;
int LED3RedPin   = 60;
int LED3GreenPin = 61;
int LED3BluePin  = 62;

int LED1RedFlag   = 0;
int LED1GreenFlag = 0;
int LED1BlueFlag  = 0;
int LED2RedFlag   = 0;
int LED2GreenFlag = 0;
int LED2BlueFlag  = 0;
int LED3RedFlag   = 0;
int LED3GreenFlag = 0;
int LED3BlueFlag  = 0;




DMA_LED::DMA_LED()
{

}



void DMA_LED::LedInit(void)
{
	pinMode(LED1RedPin,  OUTPUT);
	pinMode(LED1GreenPin,OUTPUT);
	pinMode(LED1BluePin, OUTPUT);
	pinMode(LED2RedPin,  OUTPUT);
	pinMode(LED2GreenPin,OUTPUT);
	pinMode(LED2BluePin, OUTPUT);
	pinMode(LED3RedPin,  OUTPUT);
	pinMode(LED3GreenPin,OUTPUT);
	pinMode(LED3BluePin, OUTPUT);
	digitalWrite(LED1RedPin,   HIGH);
	digitalWrite(LED1GreenPin, HIGH);
	digitalWrite(LED1BluePin,  HIGH);
	digitalWrite(LED2RedPin,   HIGH);
	digitalWrite(LED2GreenPin, HIGH);
	digitalWrite(LED2BluePin,  HIGH);
	digitalWrite(LED3RedPin,   HIGH);
	digitalWrite(LED3GreenPin, HIGH);
	digitalWrite(LED3BluePin,  HIGH);
}


void DMA_LED::LedOn(int lednum, int ledcolor)
{
	if(lednum == 1)
	{
		switch(ledcolor)
		{
			case 0 :  
				digitalWrite(LED1RedPin, LOW);
				LED1RedFlag = 1;
				break;
			case 1 :  
				digitalWrite(LED1GreenPin, LOW);
			    LED1GreenFlag = 1;
				break;
			case 2 :  
				digitalWrite(LED1BluePin, LOW);
				LED1BlueFlag = 1;
				break;
		}
	}
	else if(lednum == 2)
	{
		switch(ledcolor)
		{
			case 0 :  
				digitalWrite(LED2RedPin, LOW);
				LED2RedFlag = 1;
				break;
			case 1 :  
				digitalWrite(LED2GreenPin, LOW);
				LED2GreenFlag = 1;
				break;
			case 2 :  
				digitalWrite(LED2BluePin, LOW);
				LED2BlueFlag = 1;
				break;
		}		
	}
	else if(lednum == 3)
	{
		switch(ledcolor)
		{
			case 0 :  
				digitalWrite(LED3RedPin, LOW);
				LED3RedFlag = 1;
				break;
			case 1 :  
				digitalWrite(LED3GreenPin, LOW);
				LED3GreenFlag = 1;
				break;
			case 2 :  
				digitalWrite(LED3BluePin, LOW);
				LED3BlueFlag = 1;
				break;
		}
	}
}

void DMA_LED::LedOff(int lednum, int ledcolor)
{
	if(lednum == 1)
	{
		switch(ledcolor)
		{
			case 0 :  
				digitalWrite(LED1RedPin, HIGH);
				LED1RedFlag = 0;
				break;
			case 1 :  
				digitalWrite(LED1GreenPin, HIGH);
				LED1GreenFlag = 0;
				break;
			case 2 :  
				digitalWrite(LED1BluePin, HIGH);
				LED1BlueFlag  = 0;
				break;
		}
	}
	else if(lednum == 2)
	{
		switch(ledcolor)
		{
			case 0 :  
				digitalWrite(LED2RedPin, HIGH);
				LED2RedFlag = 0;
				break;
			case 1 :  
				digitalWrite(LED2GreenPin, HIGH);
				LED2GreenFlag = 0;
				break;
			case 2 :  
				digitalWrite(LED2BluePin, HIGH);
				LED2BlueFlag  = 0;
				break;
		}		
	}
	else if(lednum == 3)
	{
		switch(ledcolor)
		{
			case 0 :  
				digitalWrite(LED3RedPin, HIGH);
				LED3RedFlag = 0;
				break;
			case 1 :  
				digitalWrite(LED3GreenPin, HIGH);
				LED3GreenFlag = 0;
				break;
			case 2 :  
				digitalWrite(LED3BluePin, HIGH);
				LED3BlueFlag  = 0;
				break;
		}
	}	
}

void DMA_LED::LedToggle(int lednum, int ledcolor)
{
	if(lednum == 1)
	{
		switch(ledcolor)
		{
			case 0 :  
				if(LED1RedFlag == 0)
				{
					LedOn(1,0);	
				}
				else
				{
					LedOff(1,0);		
				}
				break;
			case 1 :
				if(LED1GreenFlag == 0)
				{
					LedOn(1,1);	
				}
				else
				{
					LedOff(1,1);		
				}
				break;
			case 2 :
				if(LED1BlueFlag == 0)
				{
					LedOn(1,2);	
				}
				else
				{
					LedOff(1,2);		
				}
				break;
		}
	}
	else if(lednum == 2)
	{
		switch(ledcolor)
		{
			case 0 :  
				if(LED2RedFlag == 0)
				{
					LedOn(2,0);	
				}
				else
				{
					LedOff(2,0);		
				}
				break;
			case 1 :
				if(LED2GreenFlag == 0)
				{
					LedOn(2,1);	
				}
				else
				{
					LedOff(2,1);		
				}
				break;
			case 2 :
				if(LED2BlueFlag == 0)
				{
					LedOn(2,2);	
				}
				else
				{
					LedOff(2,2);		
				}
				break;
		}
	}
	else if(lednum == 3)
	{
		switch(ledcolor)
		{
			case 0 :  
				if(LED3RedFlag == 0)
				{
					LedOn(3,0);	
				}
				else
				{
					LedOff(3,0);		
				}
				break;
			case 1 :
				if(LED3GreenFlag == 0)
				{
					LedOn(3,1);	
				}
				else
				{
					LedOff(3,1);		
				}
				break;
			case 2 :
				if(LED3BlueFlag == 0)
				{
					LedOn(3,2);	
				}
				else
				{
					LedOff(3,2);		
				}
				break;
		}		
	}
}


