// LoopChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool finished = false;
uint32_t result = 0;
char fmt[] = "%d contando...\n";

void AnswerTask()
{
	while (result != 5)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	finished = true;
}

int main()
{
	std::thread t(AnswerTask);

	printf("Desafio 07 - Repeticao\n");

	printf("\nDeseja se contar ate 5 porem so se conta ate 3.\nAltere o codigo de maneira que passe a se contar ate 5.\n\n");

	int ch;

	while (finished == false)
	{
		__asm
		{
		REPEAT:
			inc result
			mov eax, result
			push eax
			push offset fmt
			call printf
			add esp, 0x8
			cmp result, 3
			jz END
			jmp REPEAT
		END:
		}

		printf("\nPressione qualquer tecla para executar novamente...\n\n");
		ch = _getch();

		result = 0;
	}

	printf("\nParabens! Pressione qualquer tecla para terminar...\n");
	ch = _getch();

	return 0;
}


