/********************************************************************
 * Module       : lcd                                               *
 * File Name    : lcd_cfg.h                                         *
 * Description  : lcd driver static configurations                  *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#ifndef LCD_CFG_H
#define LCD_CFG_H

/******************************************************************
[Required] : Choose LCD Mode                                      *
[Options]  : 1- LCD_4_BIT_MODE                                    *
|            2- LCD_8_BIT_MODE                                    *
*******************************************************************/
#define LCD_DATA_MODE   LCD_4_BIT_MODE


/******************************************************************
[Required] : Select RS Port & PIN IDs                             *
[Options]  : 1- PORT:                                             *
|                    DIO_PORT_A_ID                                *
|                    DIO_PORT_B_ID                                *
|                    DIO_PORT_C_ID                                *
|            2- PIN: 0 -> 15                                      *
*******************************************************************/
#define LCD_RS_PORT_ID                 DIO_PORT_A_ID
#define LCD_RS_PIN_ID                  (0u)

/******************************************************************
[Required] : Select RW Port & PIN IDs                             *
[Options]  : 1- PORT:                                             *
|                    DIO_PORT_A_ID                                *
|                    DIO_PORT_B_ID                                *
|                    DIO_PORT_C_ID                                *
|            2- PIN: 0 -> 15                                      *
*******************************************************************/
#define LCD_RW_PORT_ID                  DIO_PORT_A_ID
#define LCD_RW_PIN_ID                   (1u)


/******************************************************************
[Required] : Select E Port & PIN IDs                              *
[Options]  : 1- PORT:                                             *
|                    DIO_PORT_A_ID                                *
|                    DIO_PORT_B_ID                                *
|                    DIO_PORT_C_ID                                *
|            2- PIN: 0 -> 15                                      *
*******************************************************************/
#define LCD_E_PORT_ID                  DIO_PORT_A_ID
#define LCD_E_PIN_ID                   (2u)


/******************************************************************
[Required] : Select Data Port ID                                  *
[Options]  : 1- PORT:                                             *
|                    DIO_PORT_A_ID                                *
|                    DIO_PORT_B_ID                                *
|                    DIO_PORT_C_ID                                *
*******************************************************************/
#define LCD_DATA_PORT_ID               DIO_PORT_B_ID


/******************************************************************
[Required] : Select Data Pin Offset                               *
[Options]  : Ex: if first data pin is PA5 offset is 5             *
*******************************************************************/
#define LCD_DATA_OFFSET                (3)


/******************************************************************
[Required] : Set the CPU clock in MHZ                             *
[Options]  : Ex: if first data pin is PA5 offset is 5             *
*******************************************************************/
#define LCD_CPU_CLK                    (8)

#endif /* LCD_CFG_H */
