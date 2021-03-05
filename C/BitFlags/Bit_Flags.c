#include <stdio.h>
#include <stdlib.h>
#include "Bit_Flags.h"
/*********************************
Author: Santhosh Pothineni
Purpose: Creates a bit_flags opaque object that can set , unset and check flags.
Interface proposal: I think that including a unset all flags function which would
set all the flags to zero. This would be useful iff you wanted to reset all the flags without
induvidually unset every flag.
**********************************/
struct Bit_flags
{
	unsigned int* data;
	int size;
	int capacity;
};

typedef struct Bit_flags Bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
	Bit_flags* pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
	int i;
	int temp = (number_of_bits / (sizeof(unsigned int) * 8));
	if (number_of_bits % (sizeof(unsigned int) * 8) != 0)
	{
		temp += 1;
	}
	if (pBit_flags != NULL)
	{
		pBit_flags->size = number_of_bits;
		pBit_flags->capacity = temp * sizeof(unsigned int) * 8;
		pBit_flags->data = (unsigned int*)malloc(temp * sizeof(unsigned int));
		if (pBit_flags->data == NULL)
		{
			free(pBit_flags);
			return NULL;
		}
		for (i = 0; i < temp; i++)
		{
			pBit_flags->data[i] = 0;
		}
	}

	return pBit_flags;

}


Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int temp;
	unsigned int* temparr;
	int index = flag_position / (sizeof(unsigned int) * 8);
	if (flag_position >= pBit_flags->size)
	{
		temparr = (unsigned int*)malloc(sizeof(unsigned int) * (index + 1));
		if (temparr == NULL)
		{
			free(temparr);
			return FAILURE;
		}
		unsigned int i;
		for (i = 0; i < (index + 1); i++)
		{
			temparr[i] = 0;
		}
		for (i = 0; i < ((pBit_flags->capacity) / (sizeof(unsigned int) * 8)); i++)
		{
			temparr[i] = pBit_flags->data[i];
		}
		free(pBit_flags->data);
		pBit_flags->data = temparr;
		pBit_flags->size = flag_position + 1;
		pBit_flags->capacity = sizeof(unsigned int) * (index + 1) * 8;
	}
	temp = 1 << (flag_position - (index * (sizeof(unsigned int) * 8) - index));
	pBit_flags->data[index] = pBit_flags->data[index] | temp;
	return SUCCESS;
}


Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	unsigned int* temparr;
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int index = flag_position / (sizeof(unsigned int) * 8);
	if (flag_position >= pBit_flags->size)
	{
		temparr = (unsigned int*)malloc(sizeof(unsigned int) * index + 1);
		if (temparr == NULL)
		{
			free(temparr);
			return FAILURE;
		}
		unsigned int i;
		for (i = 0; i < index + 1; i++)
		{
			temparr[i] = 0;
		}
		for (i = 0; i < ((pBit_flags->capacity)/ (sizeof(unsigned int) * 8)); i++)
		{
			temparr[i] = pBit_flags->data[i];
		}
		free(pBit_flags->data);
		pBit_flags->data = temparr;
		pBit_flags->size = flag_position + 1;
		pBit_flags->capacity = sizeof(unsigned int) * (index + 1) * 8;
	}
	int temp = ~(1 << (flag_position - (index * (sizeof(unsigned int) * 8) - index)));
	pBit_flags->data[index] = pBit_flags->data[index] & temp;

	return SUCCESS;
}


int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	if (flag_position >= pBit_flags->capacity)
	{
		return -1;
	}

	int index = flag_position / (sizeof(unsigned int) * 8);
	if (pBit_flags->data[index] & (1 << (flag_position - (index * ((sizeof(unsigned int) * 8) - 1)))))
	{
		return 1;
	}

	else
	{
		return 0;
	}
}


int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	return pBit_flags->size;

}


int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	return pBit_flags->capacity;

}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)*phBit_flags;
	free(pBit_flags->data);
	free(pBit_flags);
	*phBit_flags = NULL;
}