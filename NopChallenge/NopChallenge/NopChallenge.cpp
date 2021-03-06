// NopChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool finished = false;
uint8_t result = 0;
char pass[] = "Senha: 1961\n";

void printWrapper(const char* text)
{
	printf(text);

	result = 1;
}

int main()
{
	printf("Desafio 08 - Sem operacao (NOP)\n");

	printf("\nDeseja se impedir que o programa exiba a senha.\nAltere o codigo de maneira pare de exibir a senha.\n\n");

	int ch;

	while (finished == false)
	{
		result = 0;

		__asm
		{
			push offset pass
			call printWrapper
			pop ebx
		}

		if (result == 0)
		{
			finished = true;
		}

		printf("\nPressione qualquer tecla para executar novamente...\n\n");
		ch = _getch();
	}

	printf("\nParabens! Pressione qualquer tecla para terminar...\n");
	ch = _getch();

	return 0;
}


