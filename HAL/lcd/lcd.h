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




#endif /* LCD_H */
