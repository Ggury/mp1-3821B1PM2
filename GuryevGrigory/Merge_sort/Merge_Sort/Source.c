#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <math.h>

float* mergeSort(float* arr, float* buff, unsigned int strt,unsigned int end)
{
	unsigned int mid;

	float *buff_one;	
	float *buff_two;
	
	float *arr2;
	unsigned int s;
	unsigned int m;
	
	if (strt == end)
	{
		buff[strt] = arr[strt];
		return buff;
	}
	mid = strt + ((end - strt)/ 2);

	buff_one = mergeSort(arr, buff, strt, mid);	
	buff_two = mergeSort(arr, buff, mid + 1, end);
	
	if (buff_one == arr)
	{
		arr2 = buff;
	}
	else
	{
		arr2 = arr;
	}
	s = strt;
	m = mid + 1;
	for (int i = s; i <= end; i++)
	{
		if (s <= mid && m <= end)
		{
			if (buff_one[s] < buff_two[m])
			{
				arr2[i] = buff_one[s];
				s++;
			}
			else
			{
				arr2[i] = buff_two[m];
				m++;
			}
		}
		else if (s <= mid)
		{
			arr2[i] = buff_one[s];
			s++;
		}
		else
		{
			arr2[i] = buff_two[m];
			m++;
		}
	}
	return arr2;
}

int main()
{
	int lenght = 1000;
	float* m = (float*)malloc(lenght * sizeof(float));
	float* xd;


	srand(1005483580247);
	for (int i=0; i < lenght; i++)
	{
		m[i] = (rand() % 1001 + (rand() % 1000) / 1000.0f) * pow(-1.0, (rand() % 2));
	}
	float* arr = (float*)malloc(lenght * sizeof(float));
	for (int i = 0; i < lenght; i++)
	{
		arr[i] = m[i];
	}
	xd = mergeSort(m, arr, 0, lenght - 1);
	for (int j = 0; j < lenght; j++)
	{
		printf("%f,\n", xd[j]);
	}
}
