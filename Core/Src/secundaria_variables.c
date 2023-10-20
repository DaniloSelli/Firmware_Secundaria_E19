/*
 * secundaria_variables.c
 *
 *  Created on: Mar 9, 2022
 *      Author: Rodolfo
 */

#include "secundaria.h"

//CAN
CAN_RxHeaderTypeDef RxHeader;
CAN_TxHeaderTypeDef TxHeader;
uint8_t RxData[8];
uint8_t TxData[8];
uint32_t TxMailbox;

//DATA
uint8_t Verify_CAN;
uint16_t
	Verify,
	ADC_Buffer[NBR_OF_CHANNELS];

//TIMING
uint32_t
	Acc_Msg[NBR_OF_MESSAGES],
	Per_Msg[NBR_OF_MESSAGES];
