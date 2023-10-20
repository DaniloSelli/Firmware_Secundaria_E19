/*
 * secundaria.h
 *
 *  Created on: Jan 16, 2022
 *      Author: Rodolfo
 */

#ifndef INC_SECUNDARIA_H_
#define INC_SECUNDARIA_H_

/*BEGIN INCLUDES*/
#include "main.h"
/*END INCLUDES*/

/*BEGIN DEFINES*/
//CAN
#define CAN_CFG_FILTER	0x0000
#define CAN_CFG_MASK	0x0000
#define CAN_DAQ_FILTER	0x500
#define CAN_DAQ_MASK	0x700
#define CONFIG_ID		0
#define FIRST_ID		0x51D

//DATA
#define ADC_THRESHOLD	90
#define NBR_OF_CHANNELS	16
#define NBR_OF_MESSAGES	5

//CONFIGURATION
#define EEPROM_ADDRESS_READ			0xA1
#define EEPROM_ADDRESS_WRITE		0xA0
#define EEPROM_BUFFER_SIZE_READ		5
#define EEPROM_BUFFER_SIZE_WRITE	6
#define EEPROM_TIMEOUT_READ			5
#define EEPROM_TIMEOUT_WRITE		10

//FREQUENCIES
#define MSG_DISABLED	0
#define MSG_FREQ_1HZ	1000
#define MSG_FREQ_2HZ	500
#define MSG_FREQ_5HZ	200
#define MSG_FREQ_10HZ	100
#define MSG_FREQ_20HZ	50
#define MSG_FREQ_25HZ	40
#define MSG_FREQ_50HZ	20
#define MSG_FREQ_100HZ	10
#define MSG_FREQ_200HZ	5
#define MSG_FREQ_250HZ	4
#define MSG_FREQ_500HZ	2

//LEDS
#define LED_OK			LED0_GPIO_Port, LED0_Pin
#define LED_CAN_TX		LED1_GPIO_Port, LED2_Pin
#define LED_CAN_RX		LED2_GPIO_Port, LED3_Pin
/*END DEFINES*/

/*BEGIN MACROS*/
#define __LOAD_FREQ(__BUFFER__, __PER__)	\
	switch(__BUFFER__)						\
	{										\
		case 1:								\
			(__PER__) = MSG_FREQ_1HZ;		\
			break;							\
		case 2:								\
			(__PER__) = MSG_FREQ_2HZ;		\
			break;							\
		case 3:								\
			(__PER__) = MSG_FREQ_5HZ;		\
			break;							\
		case 4:								\
			(__PER__) = MSG_FREQ_10HZ;		\
			break;							\
		case 5:								\
			(__PER__) = MSG_FREQ_20HZ;		\
			break;							\
		case 6:								\
			(__PER__) = MSG_FREQ_25HZ;		\
			break;							\
		case 7:								\
			(__PER__) = MSG_FREQ_50HZ;		\
			break;							\
		case 8:								\
			(__PER__) = MSG_FREQ_100HZ;		\
			break;							\
		case 9:								\
			(__PER__) = MSG_FREQ_200HZ;		\
			break;							\
		case 10:							\
			(__PER__) = MSG_FREQ_250HZ;		\
			break;							\
		case 11:							\
			(__PER__) = MSG_FREQ_500HZ;		\
			break;							\
		default:							\
			(__PER__) = 0;					\
			break;							\
	}

#define __SAVE_FREQ(__BUFFER__, __PER__)	\
	switch(__PER__)							\
	{										\
		case MSG_FREQ_1HZ:					\
			(__BUFFER__) = 1;				\
			break;							\
		case MSG_FREQ_2HZ:					\
			(__BUFFER__) = 2;				\
			break;							\
		case MSG_FREQ_5HZ:					\
			(__BUFFER__) = 3;				\
			break;							\
		case MSG_FREQ_10HZ:					\
			(__BUFFER__) = 4;				\
			break;							\
		case MSG_FREQ_20HZ:					\
			(__BUFFER__) = 5;				\
			break;							\
		case MSG_FREQ_25HZ:					\
			(__BUFFER__) = 6;				\
			break;							\
		case MSG_FREQ_50HZ:					\
			(__BUFFER__) = 7;				\
			break;							\
		case MSG_FREQ_100HZ:				\
			(__BUFFER__) = 8;				\
			break;							\
		case MSG_FREQ_200HZ:				\
			(__BUFFER__) = 9;				\
			break;							\
		case MSG_FREQ_250HZ:				\
			(__BUFFER__) = 10;				\
			break;							\
		case MSG_FREQ_500HZ:				\
			(__BUFFER__) = 11;				\
			break;							\
		default:							\
			(__BUFFER__) = 0;				\
			break;							\
	}
/*END MACROS*/

/*BEGIN ENUMS*/
typedef enum{
	Analog_1_4 = 0x00,
	Analog_5_8,
	Analog_9_12,
	Analog_13_16,
	Verify_Msg
}CAN_Message;
/*END ENUMS*/

/*BEGIN VARIABLES*/
//AUTO GENERATED VARIABLES
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern I2C_HandleTypeDef hi2c1;

//CAN
extern CAN_RxHeaderTypeDef RxHeader;
extern CAN_TxHeaderTypeDef TxHeader;
extern uint8_t RxData[8];
extern uint8_t TxData[8];
extern uint32_t TxMailbox;

//DATA
extern uint8_t Verify_CAN;
extern uint16_t
	Verify,
	ADC_Buffer[NBR_OF_CHANNELS];

//TIMING
extern uint32_t
	Acc_Msg[NBR_OF_MESSAGES],
	Per_Msg[NBR_OF_MESSAGES];
/*END VARIABLES*/

/*BEGIN FUNCTON PROTOTYPES*/
//CAN
void Secundaria_CAN_Start(CAN_HandleTypeDef* hcan);

void Secundaria_Transmit_Message(CAN_HandleTypeDef* hcan, uint8_t can_msg);

//CONFIGURATION
void Secundaria_Init(CAN_HandleTypeDef* hcan, I2C_HandleTypeDef* hi2c, TIM_HandleTypeDef* htim);

HAL_StatusTypeDef Secundaria_Receive_Config(I2C_HandleTypeDef* hi2c, uint8_t* data);

void Secundaria_Read_Location();

void Secundaria_Hard_Code_Init();
/*END FUNCTION PROTOTYPES*/

#endif /* INC_SECUNDARIA_H_ */
