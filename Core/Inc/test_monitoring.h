/*
 * test_monitoring.h
 *
 *  Created on: May 8, 2023
 *      Author: sche
 */

#ifndef INC_TEST_MONITORING_H_
#define INC_TEST_MONITORING_H_

// stm32h7xx_hal_pcd.c <<<<<<
// void HAL_PCD_IRQHandler(PCD_HandleTypeDef *hpcd)
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

int HAL_PCD_IRQHandler_test = 0;
int USB_GetMode_test = 0;
int IS_INVALID_INTERR = 0;
int HAL_PCD_GET_FLAG_MMIS_test = 0;//0
int HAL_PCD_GET_FLAG_RXFLVL_test = 0;
int RegVal_USB_OTG_GRXSTSP_PKTSTS_test = 0;
int RegVal_USB_OTG_GRXSTSP_BCNT_test = 0;//0
int RegVal_USB_OTG_GRXSTSP_PKTSTS_test_else = 0;
int else_test = 0;
int HAL_PCD_GET_FLAG_USB_OTG_GINTSTS_OEPINT_test = 0;
int while_ep_intr_test = 0;
int ep_intr_0x1U = 0;
int epint_USB_OTG_DOEPINT_XFRC = 0;
int epint_USB_OTG_DOEPINT_STUP = 0;
int epint_USB_OTG_DOEPINT_OTEPDIS = 0;//0
int epint_USB_OTG_DOEPINT_EPDISD = 0;//0
int USBx_GINTSTS_USB_OTG_GINTSTS_BOUTNAKEFF = 0;//0
int ep_is_iso_incomplete_1U = 0;//0
int epint_USB_OTG_DOEPINT_OTEPSPR = 0;//0
int epint_USB_OTG_DOEPINT_NAK = 0;
int HAL_PCD_GET_FLAG_hpcd_USB_OTG_GINTSTS_IEPINT = 0;
int while_ep_intr_0U = 0;
int ep_intr_0x1U_0U = 0;
int epint_USB_OTG_DIEPINT_XFRC = 0;
int hpcd_Init_dma_enable_1U = 0;//0
int epnum_0U = 0;//0



#endif /* INC_TEST_MONITORING_H_ */
