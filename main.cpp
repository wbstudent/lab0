#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fibon(int l_elem);
void cata(int l_elem);

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("Użycie: ciagi liczba_elementow wybor_ciagu\nliczba_elementów > 0, wybor_ciagu f lub g");
		return 1;
	}

	if (atoi(argv[1]) <= 0)
	{
		printf("Ilość elementów musi być >= 0!\n");
		return 2;
	}

	if(strcmp(argv[2], "f") == 0) //strcmp == 0 oznacza, że stringi są takie same, litera wybierająca ciąg to drugi argument wiersza poleceń
		fibon(atoi(argv[1]));
	else if (strcmp(argv[2], "g") == 0)
		cata(atoi(argv[1]));
	else(printf("Nie rozpoznano argumentu: %s\nDostępne opcje to: <f> lub <g>\n", argv[2]));

	return 0;
}

//Ciąg Fibonacciego
void fibon(int l_elem)
{
	if(l_elem > 93)
	{
		printf("Wydrukuję maksymalną możliwą liczbę elementów zamiast %d\n", l_elem);
		l_elem = 93;
	}
	unsigned long long int a = 0;
	unsigned long long int b = 1;
	unsigned long long int buf = 0;
	printf("0. 0\n");

	for(int i = 0; i < l_elem; i++)
	{
		printf("%d. %llu \n", i+1, b);	
		buf = b;
		b += a;
		a = buf;
		
	}
}	


//Liczby Catalana
void cata(int l_elem)
{
	if(l_elem > 35)
	{
		printf("Wydrukuję maksymalną możliwą liczbę elementów zamiast %d\n", l_elem);
		l_elem = 35;
	}
	unsigned long long int element = 1;
	for(int i = 1; i <= l_elem; i++)
	{
		printf("%i.%llu \n",i-1, element);
		element = ((2*(2*i-1)*element)/(i+1));
	}
}
