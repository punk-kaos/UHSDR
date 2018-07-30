/*  -*-  mode: c; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4; coding: utf-8  -*-  */
/**
  ******************************************************************************
  * @file    EEPROM_Emulation/inc/eeprom.h
  * @author  MCD Application Team
   * @version V1.0.0
  * @date    10-October-2011
  * @brief   This file contains all the functions prototypes for the EEPROM
  *          emulation firmware library.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EEPROM_H
#define __EEPROM_H

/* Includes ------------------------------------------------------------------*/
#include "uhsdr_mcu.h"
/* Exported constants --------------------------------------------------------*/
#if defined(STM32F4) || defined(STM32F7)
    /* Define the size of the sectors to be used */
    #define PAGE_SIZE               ((uint32_t)0x4000)  /* Page size = 16KByte */

    /* Device voltage range supposed to be [2.7V to 3.6V], the operation will
       be done by word  */
    #define VOLTAGE_RANGE           VOLTAGE_RANGE_3

    /* EEPROM start address in Flash */
    #define EEPROM_START_ADDRESS  ((uint32_t)0x08008000) /* EEPROM emulation start address:
                                                            from sector2 : after 32KByte of used
                                                            Flash memory */
    #define PAGE0_ID               FLASH_SECTOR_2
    #define PAGE1_ID               FLASH_SECTOR_3
#elif defined(STM32H7)
#define PAGE_SIZE               (uint32_t)0x20000  /* Page size = 128KByte */

    /* Device voltage range supposed to be [2.7V to 3.6V], the operation will
       be done by word  */
    #define VOLTAGE_RANGE           VOLTAGE_RANGE_3

    /* EEPROM start address in Flash */
    #define EEPROM_START_ADDRESS  ((uint32_t)0x08020000) /* EEPROM emulation start address:
                                                            from sector1 : after 128KByte of used
                                                            Flash memory */
    #define PAGE0_ID               FLASH_SECTOR_1
    #define PAGE1_ID               FLASH_SECTOR_2
#endif

/* Pages 0 and 1 base and end addresses */
#define PAGE0_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + 0x0000))
#define PAGE0_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + (PAGE_SIZE - 1)))

#define PAGE1_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + PAGE_SIZE))
#define PAGE1_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + (2 * PAGE_SIZE - 1)))

/* Used Flash pages for EEPROM emulation */
#define PAGE0                  ((uint16_t)0x0000)
#define PAGE1                 ((uint16_t)0x0001)

/* No valid page define */
#define NO_VALID_PAGE         ((uint16_t)0x00AB)

/* Page status definitions */
#define ERASED                ((uint16_t)0xFFFF)     /* Page is empty */
#define RECEIVE_DATA          ((uint16_t)0xEEEE)     /* Page is marked to receive data */
#define VALID_PAGE            ((uint16_t)0x0000)     /* Page containing valid data */

/* Valid pages in read and write defines */
#define READ_FROM_VALID_PAGE  ((uint8_t)0x00)
#define RECEIVE_WRITE_PAGE   ((uint8_t)0x01)
#define WRITE_TO_VALID_PAGE   ((uint8_t)0x02)


/* Page full define */
#define PAGE_FULL             ((uint8_t)0x80)

/* Variables' number */
#define NB_OF_VAR               (0x1ff)
// to allow memories >




//
//
/* Exported types ------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint16_t Flash_Init();
uint16_t Flash_ReadVariable(uint16_t addr, uint16_t* value);
uint16_t Flash_WriteVariable(uint16_t addr, uint16_t value);
uint16_t Flash_UpdateVariable(uint16_t addr, uint16_t value);

#endif /* __EEPROM_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
