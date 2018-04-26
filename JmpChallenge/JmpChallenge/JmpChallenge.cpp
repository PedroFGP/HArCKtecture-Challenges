// JmpChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool finished = false;
int result = 0x0;

#define A 3

void AnswerTask()
{
	while (result != 0xDEAD)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	finished = true;
}

int main()
{
	std::thread t(AnswerTask);

	printf("Desafio 05 - Desvio (JMP)\n");

	printf("\nO codigo a seguir desvia do caminho correto (JMP), altere o de maneira que o resultado possua o valor de 0xDEAD.\n");

	int ch;

	while (finished == false)
	{
		__asm
		{
			jmp Lbl_Wrong
			push eax
			pop eax
			mov result, 0xDEAD
		Lbl_Wrong:
		}

		printf("\nResultado: 0x%X\n", result);
		
		printf("\nPressione qualquer tecla para executar novamente...\n");
		ch = _getch();
	}

	printf("\nParabens! Pressione qualquer tecla para terminar...\n");
	ch = _getch();

	return 0;
}


