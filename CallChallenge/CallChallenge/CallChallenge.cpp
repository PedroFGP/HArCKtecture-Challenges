// CallChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool finished = false;
int a = 0;

void Incrementar()
{
	printf("\nMetodo 0x%X chamado!.\n", &Incrementar);
	a++;
}

int main()
{
	printf("Desafio 10 - Chamadas de funcao (CALL)\n");

	printf("\nDeseja se chamar o metodo 0x%X duas vezes consecutivas, altere o assembly de maneira que isso ocorra.\n\n", &Incrementar);

	int input = 0;

	while (finished == false)
	{
		a = 0;

		__asm
		{
			call Incrementar
			nop
			nop
			nop
			nop
			nop
		}

		if (a == 2)
		{
			finished = true;
		}

		printf("\nPressione qualquer tecla para executar novamente...\n\n");
		input = _getch();
	}

	printf("\nParabens! Pressione qualquer tecla para terminar...\n");
	input = _getch();

	return 0;
}
