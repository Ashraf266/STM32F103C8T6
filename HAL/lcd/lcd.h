/********************************************************************
 * Module       : lcd                                              *
 * File Name    : lcd.h                                            *
 * Description  : contains definitions & interfaces for lcd driver *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef LCD_H
#define LCD_H

#include "lcd_cfg.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/******* LCD *******/
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80



/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/


/******************************************************************
[Function Name] : LCD_init                                        *
[Description]   : Initializes The LCD                             *
[Args]:         : void                                            *
[in]	        : NOTHING                                         *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_init(void);



/******************************************************************
[Function Name] : LCD_sendCommand                                 *
[Description]   : Sends command to The LCD                        *
[Args]:         : u8 command                                      *
[in]	        : command to be send to the LCD                   *
[out]	        : NOTHING                                         *
[in/out]        : NOTHING                                         *
[Returns]       : void                                            *
*******************************************************************/
void LCD_sendCommand(u8 command);


#endif /* LCD_H */
