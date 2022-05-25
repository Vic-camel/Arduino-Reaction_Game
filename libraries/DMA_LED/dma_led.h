#ifndef dma_led_h
#define dma_led_h


class DMA_LED 
{
public:
	DMA_LED();
	void LedInit();
	void LedOn(int lednum, int ledcolor);
	void LedOff(int lednum, int ledcolor);
	void LedToggle(int lednum, int ledcolor);

private:


};

#endif