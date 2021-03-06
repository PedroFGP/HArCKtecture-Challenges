// MulChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool finished = false;
uint32_t result = 0;

#define A 3
#define B 2

void AnswerTask()
{
	while (result != A * B)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	finished = true;
}

int main()
{
	std::thread t(AnswerTask);

	printf("Desafio 04 - Multiplicacao\n");

	printf("\nA seguinte conta abaixo apresenta um resultado errado.\nConserte a conta de maneira que o resultado seja correto (3 * 2 = 6)\n");

	int ch;

	while (finished == false)
	{
		printf("\n 3 * 2 = ");

		__asm
		{
			mov eax, A
			mov ebx, 1
			mul ebx
			mov result, eax
		}

		printf("%d\n", result);

		printf("\nPressione qualquer tecla para executar novamente...\n");
		ch = _getch();
	}

	printf("\nParabens! Pressione qualquer tecla para terminar...\n");
	ch = _getch();

	return 0;
}


