/********************************************************************
 * Module       : i2c                                               *
 * File Name    : i2c.c                                             *
 * Description  : i2c Implementation                                *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/
/* NOTE: this driver will be all synchronous functions there will be no handling for I2C interrupts */

#include "bit_math.h"
#include "i2c.h"
#include "i2c_private.h"


/*******************************************************************************
 *                             Functions Definition                            *
 *******************************************************************************/


/******************************************************************
[Function Name] : I2C_init                                        *
[Description]   : Initializes I2C peripheral                      *
[Args]:         : u8 instanceID, I2C_ConfigType *cfgPtr           *
[in]	        : the ID of the I2C peripheral                    *
|                 pointer to the configuration structure          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void I2C_init(u8 instanceID, I2C_ConfigType *cfgPtr)
{
	
	/* Setting the I2C Configurations */
	I2C[instanceID]->CR1 = 0x00000000;
	I2C[instanceID]->CR2 = 0x00000000;
	I2C[instanceID]->CR2 |= cfgPtr->clock;

	I2C[instanceID]->OAR1 = 0x00004000;
	I2C[instanceID]->OAR1 |= (cfgPtr->address << 1);
	I2C[instanceID]->OAR2 = 0x00000000;

	I2C[instanceID]->CCR = 0x00000000;
	switch (cfgPtr->speed)
	{
	case I2C_STANDARD_SPEED:
		/* Nothing Required */
		break;

	case I2C_FAST_SPEED:
		I2C[instanceID]->CCR |= (1<<15) | (1<<14);
		break;
	
	default:
		return;
		break;
	}
	I2C[instanceID]->CCR |= cfgPtr->clock_control;

	I2C[instanceID]->TRISE = cfgPtr->riseTime;

	I2C[instanceID]->CR1 |= 0x00000001; /* Enable the I2C */
}




