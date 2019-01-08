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

uint32_t calc_average(uint32_t* value, uint8_t qnt)
{
	if (qnt <3) return 0;

	sprintf(DataChar,"qnt=%d\r\n", (int)qnt);
	HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);

	for (int q=0; q<qnt; q++)
	{
		sprintf(DataChar," %d ", (int)value[q]);
		HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);
	}

	sprintf(DataChar,"\r\n", (int)qnt);
	HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);

	for (int j=0; j<qnt-1; j++)
	{
		for (int i=0; i < qnt-i; i++)
		{
			if (value[i] > value[i+1])
			{
				uint32_t tmp = value[i];
				value[i] = value[i+1];
				value[i+1] = tmp;
			}
		}
	}

	sprintf(DataChar,"qnt=%d\r\n", (int)qnt);
	HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);

	for (int q=0; q<qnt; q++)
	{
		sprintf(DataChar," %d ", (int)value[q]);
		HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);
	}

	sprintf(DataChar,"\r\n", (int)qnt);
	HAL_UART_Transmit(&huart1, (uint8_t *)DataChar, strlen(DataChar), 100);

	uint32_t rezult = 0;
	for (int s=1; s<qnt-1; s++)
	{
		rezult = rezult + value[s];
	}

	rezult = rezult / (qnt-2);

	return rezult;
}

/*
**************************************************************************
*                           LOCAL FUNCTIONS
**************************************************************************
*/
