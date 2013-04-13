#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
void mergeSort(int FileNumber, int size)
{
	int leftFileNumber, rightFileNumber,n,number1, number2;
	FILE *bu, *left, *right;
	string strBu, strLeft, strRight;
	if(size==1)
		return;
	int size1 = size/2;
	int size2 = size-size1;
	
	stringstream ss;
	ss << FileNumber;
	strBu = ss.str();
	bu = fopen(strBu.c_str(),"r");
	leftFileNumber = FileNumber*2;
	ss.str("");
	ss.clear();
	ss << leftFileNumber;
	strLeft=ss.str();
	left = fopen(strLeft.c_str(),"w");
	rightFileNumber = leftFileNumber+1;
	ss.str("");
	ss.clear();
	ss << rightFileNumber;
	strRight=ss.str();
	right= fopen(strRight.c_str(),"w");
	
	for(int i=0; i<size1; i++)
	{
		fscanf(bu, " %d", &n);
		fprintf(left, "%d\n", n);
	}
	for(int i=size1; i<size; i++)
	{
		fscanf(bu, " %d", &n);
		fprintf(right, "%d\n", n);
	}
	
	fclose(bu);
	fclose(left);
	fclose(right);
	
	mergeSort(leftFileNumber,size1);
	mergeSort(rightFileNumber,size2);
	
	left = fopen(strLeft.c_str(),"r");
	right = fopen(strRight.c_str(),"r");
	bu = fopen(strBu.c_str(),"w");
	
	fscanf(left, " %d", &number1);
	fscanf(right, " %d", &number2);
	
	for(int i=0, j=0; i<size1 || j<(size2);)
	{
		if(i< size1 && (j==size2 || number1<number2))
		{
			fprintf(bu, "%d\n", number1);
			i++;
			fscanf(left, " %d", &number1);
		}
		else
		{
			fprintf(bu, "%d\n", number2);
			j++;
			fscanf(right, " %d", &number2);
		}
	}
	fclose(left);
	fclose(right);
	fclose(bu);
	remove(strRight.c_str());
	remove(strLeft.c_str());
}

int main(int count, char *vars[])
{
	FILE *r, *w, *b; // read-write
	int FileNumber = 1;
	int t,n,i,size;
	
	stringstream ss;
	ss<< FileNumber;
	string str = ss.str();
	
	r = fopen(vars[1],"r");
	
	b = fopen(str.c_str(),"w");
	
	// read
	for(i=0; 1; i++)
	{
		t = fscanf(r, " %d", &n);
		if(t==-1)
			break;
		fprintf(b, "%d\n", n); // write
	}
	fclose(b);
	fclose(r);
	
	size=i;
	mergeSort(1,size);
	
	w = fopen(vars[2],"w");
	
	b = fopen(str.c_str(),"r");
	
	for(i=0; 1; i++)
	{
		t = fscanf(b, " %d", &n);
		if(t==-1)
			break;
		fprintf(w, "%d\n", n); // write
	}
	fcloseall();
	return 0;
}
