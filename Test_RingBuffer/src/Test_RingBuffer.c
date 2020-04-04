/*
===============================================================================
 Name        : Test_modulos.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>

#include <RingBuffer.h>

static int buff_memoria[25];

int main(void)
{
	RingBuffer rb_1 =
	{
		.memory_buffer = &buff_memoria[0],
		.data_size = sizeof(int),
		.element_amount = 15
	};

	RingBuffer rb_2 =
	{
		.memory_buffer = &buff_memoria[15],
		.data_size = sizeof(int),
		.element_amount = 10
	};

	int i;

	RingBufferInit(&rb_1);
	RingBufferInit(&rb_2);

	// Lleno el buffer 1 con valores continuos
	for(i = 0; i < rb_1.element_amount; i++)
	{
		RingBufferPutElement(&rb_1, &i);
	}

	// Ocupo los primeros 3 espacios del buffer 2 con valores 0, 10, 20
	for(i = 0; i < 3; i++)
	{
		int k = i * 10;
		RingBufferPutElement(&rb_2, &k);
	}

	while(1)
	{
		int resultado;
		int dato;

		// Demostracion de error por intentar pisar algun dato en el RingBuffer
		dato = 199;
		resultado = RingBufferPutElement(&rb_1, &dato);

		// Saco un dato y vuelvo a itnentar poner el dato que queria, ya no hay error
		resultado = RingBufferPopElement(&rb_1, &dato);
		dato = 199;
		resultado = RingBufferPutElement(&rb_1, &dato);

		// Cantidad de elementos libres y ocupados en el buffer 2
		resultado = RingBufferGetAvailableElements(&rb_2);
		resultado = RingBufferGetAvailableSpace(&rb_2);

		// Libero buffer 2 y hago mismos chequeos
		RingBufferClear(&rb_2);
		resultado = RingBufferGetAvailableElements(&rb_2);
		resultado = RingBufferGetAvailableSpace(&rb_2);

		while(1);
	}

    return 0 ;
}
