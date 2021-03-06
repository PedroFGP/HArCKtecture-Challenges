// PtrChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool finished = false;
int *pass = (int*)1337;
char wrongAnswer[] = "Resposta errada!\n";
char rightAnswer[] = "Resposta correta!\n";

int main()
{
	printf("Desafio 09 - Ponteiros\n");

	printf("\nDeseja se descobrir a senha.\nPesquise no codigo e a memoria para descobrir a senha.\n\n");

	int input = 0;

	while (finished == false)
	{
		printf("\nDigite a senha numerica (4 digitos): \n\n");

		std::cin >> input;

		if (std::cin.fail())
		{
			abort();
		}

		__asm
		{
			mov eax, input
			cmp eax, [pass]
			jnz WRONG
			push offset rightAnswer
			call printf
			pop ebx
			mov finished, 1
			jmp END
		WRONG:
			push offset wrongAnswer
			call printf
			add esp, 0x4
		END:
		}
	}

	printf("\nParabens! Pressione qualquer tecla para terminar...\n");
	input = _getch();

	return 0;
}


