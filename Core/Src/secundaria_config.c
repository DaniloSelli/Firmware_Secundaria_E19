/*
 * secundaria_config.c
 *
 *  Created on: Jan 16, 2022
 *      Author: Rodolfo
 */

#include "secundaria.h"

static HAL_StatusTypeDef Load_EEPROM(I2C_HandleTypeDef* hi2c);
static HAL_StatusTypeDef Save_EEPROM(I2C_HandleTypeDef* hi2c);

void Secundaria_Init(CAN_HandleTypeDef* hcan, I2C_HandleTypeDef* hi2c, TIM_HandleTypeDef* htim)
{
	if(Load_EEPROM(hi2c) != HAL_OK)
		Secundaria_Hard_Code_Init();

	HAL_ADC_Start_DMA(&hadc1, (uint32_t*) &ADC_Buffer[0], 8);
	HAL_ADC_Start_DMA(&hadc2, (uint32_t*) &ADC_Buffer[8], 8);
	HAL_TIM_Base_Start_IT(htim);

	Secundaria_CAN_Start(hcan);
}

HAL_StatusTypeDef Secundaria_Receive_Config(I2C_HandleTypeDef* hi2c, uint8_t* data)
{
	if(data[0] == 2)
	{
		__LOAD_FREQ(data[1], Per_Msg[Analog_1_4]);
		__LOAD_FREQ(data[2], Per_Msg[Analog_5_8]);
		__LOAD_FREQ(data[3], Per_Msg[Analog_9_12]);
		__LOAD_FREQ(data[4], Per_Msg[Analog_13_16]);
		__LOAD_FREQ(data[5], Per_Msg[Verify_Msg]);

		return Save_EEPROM(hi2c);
	}

	else
		return HAL_OK;
}

__weak void Secundaria_Hard_Code_Init(){
	Per_Msg[Analog_1_4] = MSG_FREQ_50HZ;
	Per_Msg[Analog_5_8] = MSG_FREQ_100HZ;
	Per_Msg[Analog_9_12] = MSG_FREQ_50HZ;
	Per_Msg[Analog_13_16] = MSG_DISABLED;
	Per_Msg[Verify_Msg] = MSG_FREQ_5HZ;

	Save_EEPROM(&hi2c1);
}


static HAL_StatusTypeDef Load_EEPROM(I2C_HandleTypeDef* hi2c)
{
	uint8_t buffer[EEPROM_BUFFER_SIZE_READ];
	HAL_StatusTypeDef retVal;

	HAL_I2C_Master_Transmit(hi2c, EEPROM_ADDRESS_WRITE, 0x00, 1, EEPROM_TIMEOUT_WRITE);

	retVal = HAL_I2C_Master_Receive(hi2c, EEPROM_ADDRESS_READ, buffer, EEPROM_BUFFER_SIZE_READ, EEPROM_TIMEOUT_READ);

	if(retVal != HAL_OK)
		return retVal;

	__LOAD_FREQ(buffer[0], Per_Msg[Analog_1_4]);
	__LOAD_FREQ(buffer[1], Per_Msg[Analog_5_8]);
	__LOAD_FREQ(buffer[2], Per_Msg[Analog_9_12]);
	__LOAD_FREQ(buffer[3], Per_Msg[Analog_13_16]);
	__LOAD_FREQ(buffer[4], Per_Msg[Verify_Msg]);

	return retVal;
}

static HAL_StatusTypeDef Save_EEPROM(I2C_HandleTypeDef* hi2c)
{
	uint8_t buffer[EEPROM_BUFFER_SIZE_WRITE];

	buffer[0] = 0x00;

	__SAVE_FREQ(buffer[1], Per_Msg[Analog_1_4]);
	__SAVE_FREQ(buffer[2], Per_Msg[Analog_5_8]);
	__SAVE_FREQ(buffer[3], Per_Msg[Analog_9_12]);
	__SAVE_FREQ(buffer[4], Per_Msg[Analog_13_16]);
	__SAVE_FREQ(buffer[5], Per_Msg[Verify_Msg]);

	return 	HAL_I2C_Master_Transmit(hi2c, EEPROM_ADDRESS_WRITE, buffer, EEPROM_BUFFER_SIZE_WRITE, EEPROM_TIMEOUT_WRITE);
}
