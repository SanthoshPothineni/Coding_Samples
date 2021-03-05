#include <stdio.h>
#include <stdlib.h>
#include "Bit_Flags.h"
/*********************************
Author: Santhosh Pothineni
Date:

Purpose:
**********************************/


int main(int argc, char* argv[])
{
	int j;
	int i = 0;
	BIT_FLAGS* hBit_flags;
	hBit_flags = bit_flags_init_number_of_bits(65);

	bit_flags_set_flag(hBit_flags, 32);
	bit_flags_set_flag(hBit_flags, 63);
	bit_flags_set_flag(hBit_flags, 36);
	bit_flags_set_flag(hBit_flags, 18);

	bit_flags_set_flag(hBit_flags, 11);
	bit_flags_set_flag(hBit_flags, 45);

	

	for (j = 0; j <= ((bit_flags_get_capacity(hBit_flags) - 1)); j++)
	{
		i++;
		printf("%d", bit_flags_check_flag(hBit_flags, j));
		if ((j + 1) % 4 == 0 && j != 0)
		{
			printf(" ");
		}

		if (i == 32)
		{
			printf("%d\n", i);
			i = 0;
		}
	}
		
	bit_flags_set_flag(hBit_flags, 22);
	bit_flags_set_flag(hBit_flags, 90);
	bit_flags_unset_flag(hBit_flags, 32);
	bit_flags_unset_flag(hBit_flags, 11);
		
	printf("\n");

	for (j = 0; j <= ((bit_flags_get_capacity(hBit_flags) - 1)); j++)
	{
		i++;
		printf("%d", bit_flags_check_flag(hBit_flags, j));
		if ((j + 1) % 4 == 0 && j != 0)
		{
			printf(" ");
		}

		if (i == 32)
		{
			printf("%d\n", i);
			i = 0;
		}
	}

	bit_flags_destroy(&hBit_flags);
	return 0;

}