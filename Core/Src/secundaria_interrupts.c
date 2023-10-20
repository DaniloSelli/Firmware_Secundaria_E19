/*
 * secundaria_interrupt.c
 *
 *  Created on: Jan 16, 2022
 *      Author: Rodolfo
 */

#include "secundaria.h"

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	if(HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData) == HAL_OK)
	{
		Verify_CAN |= 2;

		if((RxHeader.ExtId == CONFIG_ID) && (RxHeader.IDE == CAN_ID_EXT))
			Secundaria_Receive_Config(&hi2c1, RxData);
	}

	else
		Verify_CAN &= 1;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM7)
	{
		Acc_Msg[0]++;
		Acc_Msg[1]++;
		Acc_Msg[2]++;
		Acc_Msg[3]++;
		Acc_Msg[4]++;
	}
}
