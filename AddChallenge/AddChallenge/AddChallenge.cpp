// AddChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool finished = false;
int result = 0;

#define A 21
#define B 55

void AnswerTask()
{
	while (result != A + B)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	finished = true;
}

int main()
{
	std::thread t(AnswerTask);

	printf("\nDesafio 01 - Adicao");

	printf("\nConserte a equaçao abaixo abaixo.\n");

	int ch;

	while (finished == false)
	{
		printf("\n21 + 55 = ");

		__asm
		{
			mov eax, 31
			add eax, A
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