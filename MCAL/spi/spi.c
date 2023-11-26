/********************************************************************
 * Module       : spi                                           *
 * File Name    : spi.c                                         *
 * Description  : spi Implementation                            *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/


#include "bit_math.h"
#include "spi.h"
#include "spi_private.h"



/*******************************************************************************
 *                               Global Variables                              *
 *******************************************************************************/

static volatile void (*TX_CallBack[2])(u16) = {NULL_PTR};
static volatile void (*RX_CallBack[2])(void) = {NULL_PTR};

/*******************************************************************************
 *                                      ISR                                    *
 *******************************************************************************/

void SPI1_IRQHandler(void)
{
	if(TX_CallBack[0] != NULL_PTR)
	{
		TX_CallBack[0](SPI[0]->DR);
	}
	/* IDK when to use it cuz it sends IRQs when the the buffer is busy */
	if(RX_CallBack[0] != NULL_PTR)
	{
		RX_CallBack[0]();
	}
	
}

void SPI2_IRQHandler(void)
{
	if(TX_CallBack[1] != NULL_PTR)
	{
		TX_CallBack[1](SPI[1]->DR);
	}
	
	if(RX_CallBack[1] != NULL_PTR)
	{
		RX_CallBack[1]();
	}
	
}


/*******************************************************************************
 *                             Functions Definition                            *
 *******************************************************************************/


/******************************************************************
[Function Name] : SPI_init                                        *
[Description]   : Initializes SPI peripheral                      *
[Args]:         : u8 instanceID, SPI_ConfigType *cfgPtr           *
[in]	        : the ID of the SPI peripheral                    *
|                 pointer to the configuration structure          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void SPI_init(u8 instanceID, SPI_ConfigType *cfgPtr)
{
	
	SPI[instanceID]->CR1 = 0x00000300;
	SPI[instanceID]->CR1 |= (cfgPtr->DataFormat << 11);
	SPI[instanceID]->CR1 |= (cfgPtr->FirstBit << 7);
	SPI[instanceID]->CR1 |= (cfgPtr->BaudRate << 3);
	SPI[instanceID]->CR1 |= (cfgPtr->Master_Slave << 2);
	SPI[instanceID]->CR1 |= (cfgPtr->ClockPolarity << 1);
	SPI[instanceID]->CR1 |= (cfgPtr->ClockPhase << 0);
	
	SPI[instanceID]->CR2 = 0x00000000;
	SPI[instanceID]->CR2 |= (cfgPtr->TX_Interrupt << 7);
	SPI[instanceID]->CR2 |= (cfgPtr->RX_Interrupt << 6);
	
	TX_CallBack[instanceID] = (volatile void (*)(u16))cfgPtr->TX_INT_FUNC;
	RX_CallBack[instanceID] = (volatile void (*)(void))cfgPtr->RX_INT_FUNC;
	
	/* Enable SPI */
	SPI[instanceID]->CR1 |= (1 << 6);
}


/******************************************************************
[Function Name] : SPI_sendReceiveSync                             *
[Description]   : Sync function to Transmit data                  *
[Args]:         : u8 instanceID, u16 dataToTransmit               *
[in]	        : the ID of the SPI peripheral                    *
|                 data to be transmitted                          *
[out]	        : The received data                               *
[in/out]        : NOTHING                                         *
[Returns]       : u16                                             *
[NOTES]         : if Data format is 8 bit write 8bit data         *
|                 instead of 16 bit                               *
*******************************************************************/
u16 SPI_sendReceiveSync(u8 instanceID, u16 dataToTransmit)
{
	
	SPI[instanceID]->DR = dataToTransmit;
	while( GET_BIT( SPI[instanceID]->SR , 7) == 1 );
	
	return SPI[instanceID]->DR;
	
}


/******************************************************************
[Function Name] : SPI_sendReceiveAsync                            *
[Description]   : Sync function to Transmit data                  *
[Args]:         : u8 instanceID, u16 dataToTransmit               *
[in]	        : the ID of the SPI peripheral                    *
|                 data to be transmitted                          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
[NOTES]         : if Data format is 8 bit write 8bit data         *
|                 instead of 16 bit                               *
*******************************************************************/
void SPI_sendReceiveAsync(u8 instanceID, u16 dataToTransmit)
{
	SPI[instanceID]->DR = dataToTransmit;
    SPI_TXEinterruptEnable(instanceID);
}


/******************************************************************
[Function Name] : SPI_TXEinterruptEnable                          *
[Description]   : Enables the SPI TXE interrupt                   *
[Args]:         : u8 instanceID                                   *
[in]	        : the ID of the SPI peripheral                    *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void  SPI_TXEinterruptEnable(u8 instanceID)
{
    SET_BIT(SPI[instanceID]->CR2, 7);
}


/******************************************************************
[Function Name] : SPI_TXEinterruptDisable                         *
[Description]   : Disables the SPI TXE interrupt                  *
[Args]:         : u8 instanceID                                   *
[in]	        : the ID of the SPI peripheral                    *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
[NOTES]         : Remember to Disable the TXE interrupt in the    *
|                 call Back function after receiving the data     *
*******************************************************************/
void  SPI_TXEinterruptDisable(u8 instanceID)
{
    CLR_BIT(SPI[instanceID]->CR2, 7);
}
