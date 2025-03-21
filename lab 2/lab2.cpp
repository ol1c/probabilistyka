#include <iostream>
using namespace std;


void zad1()
{
	printf("\nZad 1\n\n");
	unsigned int n = 100000;
	unsigned int a = 69069;
	unsigned int c = 1;
	unsigned int x = 15;
	unsigned int m = 1 << 31;
	int k = m / 10;
	int wyniki[10];
	for (int i = 0; i < 10; i++)
		wyniki[i] = 0;
	for (int i = 0; i < n; i++)
	{
		x = (a * x + c) % m;
		wyniki[x / k]++;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d-%d:\n     %d\n", (k * i), (k * (i + 1)), wyniki[i]);
	}
}

void zad2()
{
	printf("\nZad 2\n\n");
	unsigned int n = 100000;
	unsigned int m = 1 << 31;
	int k = m / 10;
	int wyniki[10];
	for (int i = 0; i < 10; i++)
		wyniki[i] = 0;
	int p = 7;
	int q = 3;
	int bity[31];
	int x;
	bity[0] = 1;
	bity[1] = 1;
	bity[2] = 0;
	bity[3] = 1;
	bity[4] = 0;
	bity[5] = 0;
	bity[6] = 1;
	for (int i = 7; i < 31; i++)
	{
		bity[i] = 0;
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 7; i < 31; i++)
		{
			bity[i] = (bity[i - p] + bity[i - q]) % 2;
		}
		x = 0;
		for (int i = 0; i < 31; i++)
		{
			x = x << 1;
			/*if (i > 6)
			{
				bity[i] = (bity[i - p] + bity[i - q]) % 2;
			}*/
			x += bity[i];
		}
		wyniki[x / k]++;
		for (int i = 0; i < 7; i++)
		{
			bity[i] = bity[24 + i];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d-%d:\n     %d\n", (k * i), (k * (i + 1)), wyniki[i]);
	}
}

int main()
{
	zad1();
	zad2();
}
