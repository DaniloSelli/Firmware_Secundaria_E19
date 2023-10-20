/*
 * secundaria_can.c
 *
 *  Created on: Jan 16, 2022
 *      Author: Rodolfo
 */

#include "secundaria.h"

static void Verify_Data()
{
	Verify = 0;

	for(uint8_t i = 0; i < NBR_OF_CHANNELS; i++)
		if(ADC_Buffer[i] > ADC_THRESHOLD)
			Verify |= (1 << i);

	HAL_GPIO_TogglePin(LED_OK);

	if((Verify_CAN & 1) == 1)
		HAL_GPIO_WritePin(LED_CAN_TX, GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(LED_CAN_TX, GPIO_PIN_RESET);

	if((Verify_CAN & 2) == 2)
		HAL_GPIO_WritePin(LED_CAN_RX, GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(LED_CAN_RX, GPIO_PIN_RESET);
}

static void Tx_Analog_1_4(CAN_HandleTypeDef* hcan)
{
	TxHeader.IDE = CAN_ID_STD;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.TransmitGlobalTime = DISABLE;
	TxHeader.StdId = FIRST_ID;
	TxHeader.DLC = 8;

	TxData[0] = ADC_Buffer[0] >> 8;
	TxData[1] = ADC_Buffer[0] & 0xff;
	TxData[2] = ADC_Buffer[1] >> 8;
	TxData[3] = ADC_Buffer[1] & 0xff;
	TxData[4] = ADC_Buffer[2] >> 8;
	TxData[5] = ADC_Buffer[2] & 0xff;
	TxData[6] = ADC_Buffer[3] >> 8;
	TxData[7] = ADC_Buffer[3] & 0xff;

	if((HAL_CAN_AddTxMessage(hcan, &TxHeader, TxData, &TxMailbox) == HAL_OK) && (hcan->ErrorCode == 0))
		Verify_CAN |= 1;
	else
		Verify_CAN &= 2;

	//Wait Transmission finish
	for(uint8_t i = 0; HAL_CAN_GetTxMailboxesFreeLevel(hcan) != 3 && i < 3; i++);
}

static void Tx_Analog_5_8(CAN_HandleTypeDef* hcan)
{
	TxHeader.IDE = CAN_ID_STD;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.TransmitGlobalTime = DISABLE;
	TxHeader.StdId = FIRST_ID + 1;
	TxHeader.DLC = 8;

	TxData[0] = ADC_Buffer[4] >> 8;
	TxData[1] = ADC_Buffer[4] & 0xff;
	TxData[2] = ADC_Buffer[5] >> 8;
	TxData[3] = ADC_Buffer[5] & 0xff;
	TxData[4] = ADC_Buffer[6] >> 8;
	TxData[5] = ADC_Buffer[6] & 0xff;
	TxData[6] = ADC_Buffer[7] >> 8;
	TxData[7] = ADC_Buffer[7] & 0xff;

	if((HAL_CAN_AddTxMessage(hcan, &TxHeader, TxData, &TxMailbox) == HAL_OK) && (hcan->ErrorCode == 0))
		Verify_CAN |= 1;
	else
		Verify_CAN &= 2;

	//Wait Transmission finish
	for(uint8_t i = 0; HAL_CAN_GetTxMailboxesFreeLevel(hcan) != 3 && i < 3; i++);
}

static void Tx_Analog_9_12(CAN_HandleTypeDef* hcan)
{
	TxHeader.IDE = CAN_ID_STD;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.TransmitGlobalTime = DISABLE;
	TxHeader.StdId = FIRST_ID + 2;
	TxHeader.DLC = 8;

	TxData[0] = ADC_Buffer[8] >> 8;
	TxData[1] = ADC_Buffer[8] & 0xff;
	TxData[2] = ADC_Buffer[9] >> 8;
	TxData[3] = ADC_Buffer[9] & 0xff;
	TxData[4] = ADC_Buffer[10] >> 8;
	TxData[5] = ADC_Buffer[10] & 0xff;
	TxData[6] = ADC_Buffer[11] >> 8;
	TxData[7] = ADC_Buffer[11] & 0xff;

	if((HAL_CAN_AddTxMessage(hcan, &TxHeader, TxData, &TxMailbox) == HAL_OK) && (hcan->ErrorCode == 0))
		Verify_CAN |= 1;
	else
		Verify_CAN &= 2;

	//Wait Transmission finish
	for(uint8_t i = 0; HAL_CAN_GetTxMailboxesFreeLevel(hcan) != 3 && i < 3; i++);
}

static void Tx_Analog_13_16(CAN_HandleTypeDef* hcan)
{
	TxHeader.IDE = CAN_ID_STD;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.TransmitGlobalTime = DISABLE;
	TxHeader.StdId = FIRST_ID + 3;
	TxHeader.DLC = 8;

	TxData[0] = ADC_Buffer[12] >> 8;
	TxData[1] = ADC_Buffer[12] & 0xff;
	TxData[2] = ADC_Buffer[13] >> 8;
	TxData[3] = ADC_Buffer[13] & 0xff;
	TxData[4] = ADC_Buffer[14] >> 8;
	TxData[5] = ADC_Buffer[14] & 0xff;
	TxData[6] = ADC_Buffer[15] >> 8;
	TxData[7] = ADC_Buffer[15] & 0xff;

	if((HAL_CAN_AddTxMessage(hcan, &TxHeader, TxData, &TxMailbox) == HAL_OK) && (hcan->ErrorCode == 0))
		Verify_CAN |= 1;
	else
		Verify_CAN &= 2;

	//Wait Transmission finish
	for(uint8_t i = 0; HAL_CAN_GetTxMailboxesFreeLevel(hcan) != 3 && i < 3; i++);
}

static void Tx_Verify(CAN_HandleTypeDef* hcan)
{
	TxHeader.IDE = CAN_ID_STD;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.TransmitGlobalTime = DISABLE;
	TxHeader.StdId = FIRST_ID + 4;
	TxHeader.DLC = 7;

	Verify_Data();

	TxData[0] = Verify >> 8;
	TxData[1] = Verify & 0xff;

	__SAVE_FREQ(TxData[2], Per_Msg[Analog_1_4]);
	__SAVE_FREQ(TxData[3], Per_Msg[Analog_5_8]);
	__SAVE_FREQ(TxData[4], Per_Msg[Analog_9_12]);
	__SAVE_FREQ(TxData[5], Per_Msg[Analog_13_16]);
	__SAVE_FREQ(TxData[6], Per_Msg[Verify_Msg]);

	if((HAL_CAN_AddTxMessage(hcan, &TxHeader, TxData, &TxMailbox) == HAL_OK) && (hcan->ErrorCode == 0))
		Verify_CAN |= 1;
	else
		Verify_CAN &= 2;

	//Wait Transmission finish
	for(uint8_t i = 0; HAL_CAN_GetTxMailboxesFreeLevel(hcan) != 3 && i < 3; i++);
}

void Secundaria_CAN_Start(CAN_HandleTypeDef* hcan)
{
	CAN_FilterTypeDef sFilterConfig;
	uint32_t filter_id = 0, mask_id = 0;

	filter_id = CAN_DAQ_FILTER;
	mask_id = CAN_DAQ_MASK;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh = filter_id >> 13;
	sFilterConfig.FilterIdLow = (filter_id << 3) & 0xFFF8;
	sFilterConfig.FilterMaskIdHigh = mask_id >> 13;
	sFilterConfig.FilterMaskIdLow = (mask_id << 3) & 0xFFF8;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.FilterBank = 0;
	sFilterConfig.SlaveStartFilterBank = 14;

	HAL_CAN_ConfigFilter(hcan, &sFilterConfig);

	filter_id = CAN_CFG_FILTER;
	mask_id = CAN_CFG_MASK;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh = filter_id >> 13;
	sFilterConfig.FilterIdLow = (filter_id << 3) & 0xFFF8;
	sFilterConfig.FilterMaskIdHigh = mask_id >> 13;
	sFilterConfig.FilterMaskIdLow = (mask_id << 3) & 0xFFF8;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.FilterBank = 1;
	sFilterConfig.SlaveStartFilterBank = 15;

	HAL_CAN_ConfigFilter(hcan, &sFilterConfig);

	HAL_CAN_Start(hcan);

	HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
}

void Secundaria_Transmit_Message(CAN_HandleTypeDef* hcan, uint8_t can_msg)
{
	switch(can_msg)
	{
		case Analog_1_4:
			Tx_Analog_1_4(hcan);
			break;

		case Analog_5_8:
			Tx_Analog_5_8(hcan);
			break;

		case Analog_9_12:
			Tx_Analog_9_12(hcan);
			break;

		case Analog_13_16:
			Tx_Analog_13_16(hcan);
			break;

		case Verify_Msg:
			Tx_Verify(hcan);
			break;

		default:
			return;
	}
}
