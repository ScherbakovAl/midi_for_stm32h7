/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : usb_device.c
 * @version        : v1.0_Cube
 * @brief          : This file implements the USB Device
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/

#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_cdc.h"
#include "usbd_cdc_if.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USB Device Core handle declaration. */
USBD_HandleTypeDef hUsbDeviceFS;

/*
 * -- Insert your variables declaration here --
 */
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*
 * -- Insert your external function declaration here --
 */
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
 * Init USB device Library, add supported class and start the library
 * @retval None
 */
void MX_USB_DEVICE_Init(void) {
	/* USER CODE BEGIN USB_DEVICE_Init_PreTreatment */

	/* USER CODE END USB_DEVICE_Init_PreTreatment */

	/* Init Device Library, add supported class and start the library. */
	if (USBD_Init(&hUsbDeviceFS, &FS_Desc, DEVICE_FS) != USBD_OK) {
		Error_Handler();
	}
	if (USBD_RegisterClass(&hUsbDeviceFS, &USBD_CDC) != USBD_OK) {
		Error_Handler();
	}
	if (USBD_CDC_RegisterInterface(&hUsbDeviceFS, &USBD_Interface_fops_FS)
			!= USBD_OK) {
		Error_Handler();
	}
	if (USBD_Start(&hUsbDeviceFS) != USBD_OK) {
		Error_Handler();
	}

	/* USER CODE BEGIN USB_DEVICE_Init_PostTreatment */
	HAL_PWREx_EnableUSBVoltageDetector();

	uint8_t txbuf[8];
	txbuf[0] = 0x9; //??
	txbuf[1] = 0xB0 | 0x00; //0xB0 - Control Change (for hi-res midi) | channel
	txbuf[2] = 0x7F & 88; // 88 (for hi-res midi)
	txbuf[3] = 0x7F & 75; //velocity xx.75

	txbuf[4] = 0x9; //??
	txbuf[5] = 0x90 | 0x00; //0x8 - note off, 0x9 - note on | channel
	txbuf[6] = 0x7F & 53; //number note
	txbuf[7] = 0x7F & 86; //velocity 86.xx

	HAL_Delay(1000);

	while (1) {
		USBD_LL_Transmit(&hUsbDeviceFS, 0x81, txbuf, 8);
		HAL_Delay(1200);
	}
	/* USER CODE END USB_DEVICE_Init_PostTreatment */
}

/**
 * @}
 */

/**
 * @}
 */

