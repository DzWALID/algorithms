/*
This merge sort algorithm sorts 25000000 integers less than 60 seconds
*/
#include <cstdio>
#include <iostream>
using namespace std;
void mergeSort(int *p, int size)
{
	if(size==1)
		return;
		
	int *q;
	int *other=p;
	int size1 = size/2;
	int size2 = size-size1;
		
	mergeSort(p,size1);
	mergeSort(p+size1,size2);
		
	int *ar1 = new int[size1+1];
	int *ar2 = new int[size1+1];
	int *other1=ar1;
	int *other2=ar2;
	q=ar1;
	for(int i=0; i<size1; i++)
	{
		*q = *other;
		q++;
		other++;
	}
	q=ar2;
	for(int i=size1; i<size; i++)
	{
		*q = *other;
		q++;
		other++;
	}
	q=p;
	for(int i=0, j=0; i<size1 || j<(size2);)
	{
		if(i< size1 && (j==size2 || ar1[i]<ar2[j]))
		{
			*q=*other1;
			i++;
			other1++;
		}
		else
		{
			*q=*other2;
			j++;
			other2++;
		}
		q++;
	}
	delete []ar1;
	delete [] ar2;
}

int main(int count, char *vars[])
{
	FILE *r, *w; // read-write
	int *ar = new int[25000000];
	
	r = fopen(vars[1],"r");
	
	// read
	for(int i=0; i < 25000000; i++)
	{
		fscanf(r, " %d", &ar[i]);
	}
	mergeSort(ar,25000000);
	
	w = fopen(vars[2],"w");
	// write
	for(int i=0; i<25000000; i++)
	{
		fprintf(w, "%d\n", ar[i]);
	}
	
	fcloseall();
	return 0;
}
