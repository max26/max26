/*********************************************** 
 *   Copyright (C) 2014 by Maxim Fetisov       *                             
 *   blizzard005 at gmail dot com              *
 **********************************************/
ВМИК МГУ-2013, магистратура, вступительный экзамен.
Задание 2 (из 4-х).
В текстовом файле edges.txt непустым списком дуг задан ориентированный граф,
каждая строка файла содержит информацию о дуге графа в виде разделенных пробелом номеров вершин,
которые она соединяет.Граф содержит n вершин, перенумерованных от 1 до n, где n - максимальный номер вершины,
встретившийся в файле edges.txt.
Построить матрицу смежности данного графа, то есть квадратнцю матрицу размера n, в которой элемент
a_{ij} равен количеству дуг, непосредственно соединяющих i-ю вершину j-й.
Вывести матрицу в текстовый файл matrix.txt , каждая строка которого должна соответствовать
строке матрицы, а элементы внутри строки должны быть разделены пробелом.
Пример файла edges.txt
1 2
1 5
3 1
3 2
3 1
2 5
Пример файла matrix.txt
0 1 0 0 1
0 0 0 0 1
2 1 0 0 0
0 0 0 0 0
 
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
