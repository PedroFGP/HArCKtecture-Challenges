// SubChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool finished = false;
int8_t result = 0;

#define A 7
#define B 2

void AnswerTask()
{
	while (result != A - B)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	finished = true;
}

int main()
{
	std::thread t(AnswerTask);

	printf("\nDesafio 02 - Subtracao");

	printf("\nConserte a equaçao abaixo abaixo.\n");

	int ch;

	while (finished == false)
	{
		printf("\n7 - 2 = ");

		__asm
		{
			mov al, A
			sub al, 5
			mov result, al
		}

		printf("%d\n", result);

		printf("\nPressione qualquer tecla para executar novamente...\n");
		ch = _getch();
	}

	printf("\nParabens! Pressione qualquer tecla para terminar...\n");
	ch = _getch();

	return 0;
}


