#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Add_All- Costos de sumas

int A[5500];
int heapsize=0;

int parent(int i)
{
	return i/2;
}

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i + 1;
}

void MinHeapify(int Q[], int i)
{
	int l,r,least,aux;
	l=left(i);
	r=right(i);
	if( (l<=heapsize) && (Q[l] < Q[i]) )
		least=l;
	else
		least=i;
	if( (r<=heapsize) && (Q[r] < Q[least]) )
		least=r;
	if(least != i)
	{
		aux = Q[i];
		Q[i] = Q[least];
		Q[least] = aux;

		MinHeapify(Q, least);
	}
}

int MinPQ_Extract(int Q[])
{
	int min;
	if (heapsize < 1)
		printf("Error: heap underflow");
	else
	{
		min = Q[1];
		Q[1] = Q[heapsize];
		heapsize = heapsize - 1;
		MinHeapify(Q,1);
		return min;
	}
}

void MinPQ_DecreaseKey(int Q[], int i, int key)
{
	int aux;
	if(key>Q[i])
		printf("Error: new key is higher than current key");
	else
	{
		Q[i]=key;
		while(i>1 && Q[parent(i)]>Q[i] )
		{
			aux = Q[parent(i)];
			Q[parent(i)] = Q[i];
			Q[i] = aux;
			i = parent(i);
		}
	}
}

void MinPQ_Insert(int Q[], int key)
{
	heapsize=heapsize+1;
	Q[heapsize]=2147483000;
	MinPQ_DecreaseKey(Q,heapsize,key);
}
