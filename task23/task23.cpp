// Определить, сколько элементов массива являются числами фибоначи

#include <iostream>
using namespace std;
int** memory(int n, int m);
void fill(int** a, int n, int m);
bool chek_fibonachi(int n);
int counter(int**a ,int n);

int main()
{
	int n;
	printf("vvedite razmer\n");
	scanf_s("%d", &n);
	int** A = memory(n, n);
	fill(A, n, n);
	/*if (chek_fibonachi(0))
	{
		printf("1");
	}*/
	printf("%d", counter(A, n));
}

//выделение памяти
int** memory(int n, int m)
{
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	return a;
}
//заполнение элементов
void fill(int** a, int n, int m)
{
	printf("zapolnite massiv\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
}
//порверка на чисто фибоначи
bool chek_fibonachi(int n)
{
	int chislo=2,temp1,temp2,temp3;
	temp1 = temp2 = 1;
	while (chislo<n)
	{
		temp3 = temp1;
		temp1 = temp2;
		temp2 = chislo;
		chislo = temp1 + temp2;
	}
	if (chislo==n||n==1||n==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//подсчёт количества чисел фибоначи в массиве
int counter(int** a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (chek_fibonachi(a[i][j]))
				count++;
		}
	}
	return count;
}