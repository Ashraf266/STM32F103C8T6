/********************************************************************
 * Module       : spi                                               *
 * File Name    : spi_PBcfg.c                                      *
 * Description  : Post build configuration for spi driver          *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#include "spi.h"


SPI_ConfigType SPI_1_Cfg = {
                            SPI_8_BIT_DATA_FORMAT,
                            SPI_MSB_BIT_FIRST,
                            SPI_CLK_DIV_64,
                            SPI_MASTER_MODE,
                            SPI_IDLE_HIGH,
                            SPI_WRITE_ON_FIRST_EDGE,
                            SPI_INTERRUPT_DISABLE,
                            SPI_INTERRUPT_DISABLE,
                            NULL_PTR,
                            NULL_PTR
};

SPI_ConfigType SPI_2_Cfg = {
                            SPI_8_BIT_DATA_FORMAT,
                            SPI_MSB_BIT_FIRST,
                            SPI_CLK_DIV_64,
                            SPI_MASTER_MODE,
                            SPI_IDLE_HIGH,
                            SPI_WRITE_ON_FIRST_EDGE,
                            SPI_INTERRUPT_DISABLE,
                            SPI_INTERRUPT_DISABLE,
                            NULL_PTR,
                            NULL_PTR
};

