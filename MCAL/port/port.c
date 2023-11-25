/********************************************************************
 * Module       : port                                              *
 * File Name    : port.c                                            *
 * Description  : port Implementation                               *
 * Author       : Mohamed Ashraf                                    *
 *******************************************************************/

#include "std_types.h"
#include "bit_math.h"
#include "port.h"
#include "port_private.h"





/******************************************************************
[Function Name] : PORT_init                                       *
[Description]   : Initializes All MC Pins                         *
[Args]:         : PORT_ConfigType *Config                         *
[in]	        : pointer to the configuration structure          *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void PORT_init(PORT_ConfigType *Config)
{
    u8 pinNumber;
    u8 portNumber;
    for(pinNumber = 0; pinNumber < PORT_NUM_OF_PINS; pinNumber++)
    {
        if((pinNumber = 13) || (pinNumber = 14) || (pinNumber = 18) || (pinNumber > 31))
        {
            continue;
        }
        portNumber = pinNumber/16;


        

    }
}


