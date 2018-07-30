# IMPORTANT: Keep startup_stm32f407xx.S the first entry, otherwise build will not work with gcc 7, see github issue #1416
BL_HAL_SRC := \
basesw/mcHF/Src/startup_stm32f407xx.S \
basesw/mcHF/Src/adc.c \
basesw/mcHF/Src/dac.c \
basesw/mcHF/Src/dma.c \
basesw/mcHF/Src/fatfs.c \
basesw/mcHF/Src/fsmc.c \
basesw/mcHF/Src/gpio.c \
basesw/mcHF/Src/i2c.c \
basesw/mcHF/Src/i2s.c \
basesw/mcHF/Src/main.c \
basesw/mcHF/Src/rtc.c \
basesw/mcHF/Src/spi.c \
basesw/mcHF/Src/stm32f4xx_hal_msp.c \
basesw/mcHF/Src/stm32f4xx_it.c \
basesw/mcHF/Src/tim.c \
basesw/mcHF/Src/usb_host.c \
basesw/mcHF/Src/usbd_conf.c \
basesw/mcHF/Src/usbh_conf.c \
basesw/mcHF/Src/user_diskio.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/option/syscall.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/option/unicode.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/drivers/usbh_diskio.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/diskio.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/ff.c \
basesw/mcHF/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_core.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ctlreq.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ioreq.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_pipes.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/MTP/Src/usbh_mtp_ptp.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/HID/Src/usbh_hid.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/HID/Src/usbh_hid_keybd.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/HID/Src/usbh_hid_mouse.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/HID/Src/usbh_hid_parser.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Src/usbh_cdc.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
basesw/mcHF/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_can.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cec.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_crc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cryp_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dac_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dcmi.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dcmi_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dfsdm.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_eth.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_fmpi2c.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_fmpi2c_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hash_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_irda.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_iwdg.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_lptim.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nand.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_nor.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pccard.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_qspi.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rng.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rtc_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sai.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sai_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sdram.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_smartcard.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spdifrx.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sram.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_usart.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_wwdg.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fsmc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.c \
basesw/mcHF/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c \
basesw/mcHF/Src/system_stm32f4xx.c \
\
