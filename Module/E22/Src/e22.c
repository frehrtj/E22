/*
 * e22.c
 *
 *  Created on: Sep 3, 2024
 *      Author: feger
 */
#include "main.h"
#include <stdio.h>

extern UART_HandleTypeDef huart1;

void set_register()
{
	uint8_t data[4] = {0, };
	int idx = 0;

	data[idx++] = 0xC0;
	data[idx++] = 0x05;
	data[idx++] = 0x01;
	data[idx++] = 0x09;

	HAL_UART_Transmit(&huart1, data, idx, 1000);
}

void read_register()
{
	uint8_t data[3] = {0, };
	int idx = 0;

	data[idx++] = 0xC1;
	data[idx++] = 0x05;
	data[idx++] = 0x01;

	HAL_UART_Transmit(&huart1, data, idx, 1000);
}

void set_temporary_registers()
{
	uint8_t data[4] = {0, };
	int idx = 0;

	data[idx++] = 0xC2;
	data[idx++] = 0x05;
	data[idx++] = 0x01;
	data[idx++] = 0x09;

	HAL_UART_Transmit(&huart1, data, idx, 1000);
}

void wireless_configuration()
{
	uint8_t data[6] = {0, };
	int idx = 0;

	data[idx++] = 0xCF;
	data[idx++] = 0xCF;
	data[idx++] = 0xC0;
	data[idx++] = 0x05;
	data[idx++] = 0x01;
	data[idx++] = 0x09;

	HAL_UART_Transmit(&huart1, data, idx, 1000);
}

void normal_mode()
{
	HAL_GPIO_WritePin(M1_GPIO_Port, M1_Pin, 0);
	HAL_GPIO_WritePin(M0_GPIO_Port, M0_Pin, 0);
}

void wor_mode()
{
	HAL_GPIO_WritePin(M1_GPIO_Port, M1_Pin, 0);
	HAL_GPIO_WritePin(M0_GPIO_Port, M0_Pin, 1);
}

void configuration_mode()
{
	HAL_GPIO_WritePin(M1_GPIO_Port, M1_Pin, 1);
	HAL_GPIO_WritePin(M0_GPIO_Port, M0_Pin, 0);
}

void deep_sleep_mode()
{
	HAL_GPIO_WritePin(M1_GPIO_Port, M1_Pin, 1);
	HAL_GPIO_WritePin(M0_GPIO_Port, M0_Pin, 1);
}

