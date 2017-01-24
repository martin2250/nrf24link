#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include "usbdrv/usbdrv.h"
#include "spi.h"

uint8_t usbFunctionSetup(uint8_t data[8])
{
	usbRequest_t *rq = (void *)data;

	if((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS)
	{
		switch(rq->bRequest)
		{
			default:
				break;
		}
	}

	return 0;
}


int main(void)
{
	spi_init();
	usbInit();

	usbDeviceDisconnect();
	_delay_ms(250);
	usbDeviceConnect();

	sei();

    while (1)
    {
		usbPoll();
	}
}
