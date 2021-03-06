// CmpChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool finished = false;
uint8_t result = 0;
char wrongAnswer[] = "Assinatura incorreta!\n";
char rightAnswer[] = "A senha principal é 123321!\n";
char *lastestPrint = wrongAnswer;

void AnswerTask()
{
	while (strcmp((const char*)lastestPrint, rightAnswer) != 0)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	finished = true;
}

void printWrapper(char *text)
{
	printf(text);

	lastestPrint = text;
}

int main()
{
	std::thread t(AnswerTask);

	printf("Desafio 06 - Comparacao\n");

	printf("\nDeseja se descobrir a senha final.\nAltere o codigo de maneira que ele exiba a senha final.\n\n");

	int ch;

	while (finished == false)
	{
		__asm
		{
			cmp result, 0xBEEF
			jne NOT_EQUAL
			push offset rightAnswer
			call printWrapper
			pop ebx
		NOT_EQUAL:
			push offset wrongAnswer
			call printWrapper
			pop ebx
		}

		printf("\nPressione qualquer tecla para executar novamente...\n\n");
		ch = _getch();
	}

	printf("\nParabens! Pressione qualquer tecla para terminar...\n");
	ch = _getch();

	return 0;
}


