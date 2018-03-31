// MulChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool finished = false;
int result = 0;

#define A 3

void AnswerTask()
{
	while (result != 0xDEADBEEF)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	finished = true;
}

int main()
{
	std::thread t(AnswerTask);

	printf("Desafio 05 - Desvio (JMP)\n");

	printf("\nA seguinte conta abaixo apresenta um resultado errado.\nConserte a conta de maneira que o resultado seja correto (3 * 2 = 6)\n");

	int ch;

	while (finished == false)
	{
		__asm
		{
			jmp Lbl_Wrong
			mov result, 0xDEADBEEF
		Lbl_Wrong:
		}

		printf("\nPressione qualquer tecla para executar novamente...\n");
		ch = _getch();
	}

	printf("\nParabens! Pressione qualquer tecla para terminar...\n");
	ch = _getch();

	return 0;
}


