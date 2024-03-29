/**
* \file
* \version 1.0
* \author bazhen.levkovets
** \date 2018
*
*************************************************************************************
* \copyright	Bazhen Levkovets
* \copyright	Brovary, Kyiv region
* \copyright	Ukraine
*
*************************************************************************************
*
* \brief
*
*/

/*
**************************************************************************
*							INCLUDE FILES
**************************************************************************
*/

#include "average_calc_3_from_5.h"

/*
**************************************************************************
*							LOCAL DEFINES
**************************************************************************
*/

extern UART_HandleTypeDef huart1;

/*
**************************************************************************
*							LOCAL CONSTANTS
**************************************************************************
*/


/*
**************************************************************************
*						    LOCAL DATA TYPES
**************************************************************************
*/


/*
**************************************************************************
*							  LOCAL TABLES
**************************************************************************
*/

/*
**************************************************************************
*								 MACRO'S
**************************************************************************
*/


/*
**************************************************************************
*						    GLOBAL VARIABLES
**************************************************************************
*/

/*
**************************************************************************
*                        LOCAL FUNCTION PROTOTYPES
**************************************************************************
*/

/*
**************************************************************************
*                           GLOBAL FUNCTIONS
**************************************************************************
*/

uint32_t Calc_Average(uint32_t* _value_arr_u32, uint8_t _aver_qnt_u8) {
	if (_aver_qnt_u8 <3) return 0;

	char DataChar[100];

	for (int q=0; q<_aver_qnt_u8; q++) {
		sprintf(DataChar,"%d  ", (int)_value_arr_u32[q]);
		HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);
	}

	sprintf(DataChar,"->  ");
	HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);

	Bubble_sort(_value_arr_u32, _aver_qnt_u8);

	for (int q=0; q<_aver_qnt_u8; q++) {
		sprintf(DataChar,"%d  ", (int)_value_arr_u32[q]);
		HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);
	}
		//	sprintf(DataChar,"\r\n");
		//	HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);

	uint32_t rezult_u32 = 0;
	for (int s=1; s<_aver_qnt_u8-1; s++) {
		rezult_u32 = rezult_u32 + _value_arr_u32[s];
	}

	rezult_u32 = rezult_u32 / (_aver_qnt_u8-2);
	sprintf(DataChar,"(%d)\r\n", (int)rezult_u32);
	HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);
	return rezult_u32;
}
//*****************************************************************************

void Bubble_sort(uint32_t* _sort_arr_u32, uint8_t _sort_qnt_u8) {
	for (int j=0; j<_sort_qnt_u8-1; j++) {
		for (int i=0; i < _sort_qnt_u8-j-1; i++) {
			if (_sort_arr_u32[i] > _sort_arr_u32[i+1]) {
				uint32_t tmp_u32 = _sort_arr_u32[i];
				_sort_arr_u32[i] = _sort_arr_u32[i+1];
				_sort_arr_u32[i+1] = tmp_u32;
			}
		}
	}
}
//*****************************************************************************


/*
**************************************************************************
*                           LOCAL FUNCTIONS
**************************************************************************
*/
