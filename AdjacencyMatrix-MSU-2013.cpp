/*********************************************** 
 *   Copyright (C) 2014 by Maxim Fetisov       *                             
 *   blizzard005 at gmail dot com              *
 **********************************************/
#include <stdio.h>
#include <iostream>

void getEdgesPositions();
int **newmultidim_array(int);
int getMaxDimension();

using namespace std;

#define max(a,b) ((a)>(b))? (a):(b)

	int edges[100][2];
	int n,cnt1,cnt2;

int **newmultidim_array(int n)
{
	int** matrix; 
	int i;

	matrix=(int**)malloc(n*(sizeof(int *)));
	for (i=0;i<n;i++)
	{
		matrix[i]=(int*)malloc(n*(sizeof(int)));
	}
	return matrix;
}
int getMaxDimension(int cnt1)
{
	int temp=0,maxDim1=0,maxDim2=0,maximum=0;

	for (int i=0;i < cnt1;i++)
	{
		maxDim1=max(edges[i][0],maxDim1);
	}
	for (int j=0;j < cnt1;j++)
	{		
		maxDim2=max(edges[j][1],maxDim2);
	}
	printf("\nmaxDim1 = %d\n",maxDim1);
	printf("\nmaxDim2 = %d\n",maxDim2);

	maximum=max(maxDim1,maxDim2);
	printf("maximum = %d\n",maximum);
	return maximum;
}

void getEdgesPositions(int cnt1,int n,int** matrix)
{

	//printf("edges[%d][0]= %d and edges[%d][1]= %d\n",0,edges[0][0],0,edges[0][1]);
	//printf("\nn = %d\n",n);

	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			matrix[i][j]=0;
		}
	}	
	for (int k=0;k<cnt1;k++)
	{   
		cnt2=1;
		for (int m=0;m<cnt1;m++)
		{
			if (m!=k)
			{				
				//printf("\nOK2\n");
		       if (edges[k][0]== edges[m][0] && edges[k][1] == edges[m][1])
			   {
				   cnt2++;
			   }
			}
		}
		matrix[edges[k][0]-1][edges[k][1]-1]=cnt2;	
	}
}


void printMatrix(int** matrix)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			printf("%d\t",matrix[i][j]);		
		}
		printf("\n");
	}
}


int main()
{	system ("chcp 1251");
   
	FILE* input_file;
	input_file=freopen("AdjacencyEdges.txt","r",stdin);
	freopen("OutputMatrix.txt","w",stdout);
	int c,cnt1=0,i=0;
	int** matr=NULL;
	memset(edges,-1,sizeof(edges));
	do{
		  cin>>edges[i][0]>>edges[i][1];
		  i++;
		  cnt1++;
	}	
	while(c=fgetc(input_file)!=EOF);

	 // printf("edges[%d][0]= %d and edges[%d][1]= %d\n",1,edges[1][0],1,edges[1][1]);
	//  printf("cnt1=%d\n",cnt1);
	  n = getMaxDimension(cnt1);
	  matr = newmultidim_array(n);
	  getEdgesPositions(cnt1,n,matr);
	  printMatrix(matr);

	getchar();

	system("pause");
	return 0;
}
