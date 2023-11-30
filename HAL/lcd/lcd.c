/********************************************************************
 * Module       : lcd                                               *
 * File Name    : lcd.c                                             *
 * Description  : lcd Implementation                                *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/


#include "bit_math.h"
#include "lcd.h"
#include "lcd_private.h"
#include "dio.h"


/*******************************************************************************
 *                               Global Variables                              *
 *******************************************************************************/

DIO_pinGroupType dataPins = {
#if ((LCD_DATA_MODE == LCD_8_BIT_MODE))
    0xFF,
#elif (LCD_DATA_MODE == LCD_4_BIT_MODE)
    0xF,
#endif
    LCD_DATA_OFFSET,
    LCD_DATA_PORT_ID
    };


/*******************************************************************************
 *                             Functions Definition                            *
 *******************************************************************************/

/* function to make delays in ms not accurate but it does the work */
static void delay(int ms)
{
    int i;
    for (i = 0; i < ms*1000*LCD_CPU_CLK; i++)
    {
        __asm("NOP");
    }
}

/******************************************************************
[Function Name] : LCD_init                                        *
[Description]   : Initializes The LCD                             *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_init(void)
{

    delay(20);		/* LCD Power ON delay always > 15ms */

#if ((LCD_DATA_MODE == LCD_8_BIT_MODE))
    
    /* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
    
#elif (LCD_DATA_MODE == LCD_4_BIT_MODE)
    
    /* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#endif

	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */

}



/******************************************************************
[Function Name] : LCD_sendCommand                                 *
[Description]   : Sends command to The LCD                        *
[Args]:         : u8 command                                      *
[in]	        : command to be send to the LCD                   *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_sendCommand(u8 command)
{
    DIO_writePin(LCD_RW_PORT_ID, LCD_RW_PIN_ID, DIO_PIN_LOW);
    DIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, DIO_PIN_LOW);
    delay(1);
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_HIGH);
    delay(1);

#if ((LCD_DATA_MODE == LCD_8_BIT_MODE))
    
    DIO_writePinGroup(&dataPins, command);
    delay(1);

#elif (LCD_DATA_MODE == LCD_4_BIT_MODE)

    DIO_writePinGroup(&dataPins, (command>>4));
    delay(1);
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_LOW);
    delay(1);
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_HIGH);
    delay(1);
    DIO_writePinGroup(&dataPins, command);
    delay(1);

#endif
    DIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_PIN_LOW);
    delay(1);
}
