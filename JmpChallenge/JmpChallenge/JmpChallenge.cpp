// JmpChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool finished = false;
int result = 0x0;

int main()
{
	printf("Desafio 05 - Desvio (JMP)\n");

	printf("\nO codigo a seguir desvia do caminho correto (JMP), altere o de maneira que o resultado possua o valor de 0xBEEF.\n");

	int ch;

	while (finished == false)
	{
		__asm
		{
			jmp WRONG
			xor eax, eax
			mov result, 0xBEEF
			jmp END
		WRONG:
			mov result, 0xDEAD
		END:
		}

		if (result == 0xBEEF)
		{
			finished = true;
		}

		printf("\nResultado: 0x%X\n", result);
		
		printf("\nPressione qualquer tecla para executar novamente...\n");
		ch = _getch();
	}

	printf("\nParabens! Pressione qualquer tecla para terminar...\n");
	ch = _getch();

	return 0;
}


