#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void randData(double *, int, int);

void findRowSum(const double *, double *, int, int);

void showData(double *, int, int);

int main()
{
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr, N, M);
	showData(dPtr, N, M);

	cout << "---------------------------------------------\n";

	findRowSum(dPtr, result, N, M);
	showData(result, N, 1);
}

//Write definition of randData(), showData() and findRowSum()
void randData(double *data, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			float x = rand() % 100;
			*(data + (M * i) + j) = x / 100;
		}
	}
}

void findRowSum(const double *data, double *sum, int N, int M)
{

	for (int i = 0; i < N * M; i++)
	{
		*(sum + (i / M)) += *(data + i);
	}
}

void showData(double *data, int N, int M)
{
	for (int i = 0; i < N * M; i++)
	{
		cout << *(data + i) << "\t";
		if (i % M == M - 1)
			cout << "\n";
	}
}
