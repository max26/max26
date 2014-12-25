/***********************************************
 *   Copyright (C) 2014 by Maxim Fetisov       *
 *   blizzard005 at gmail dot com              *
 **********************************************/
 Moscow state university (MSU) -postgraduate entrance exam - 2005
Faculty of computing mathematics and cybernetics
Task Description:
 
 ВМиК МГУ-2005, магистратура (вступительный экзамен)
Задание:
Написать и отладить программу, которая будет находить все корни нескольких многочленов пятой степени, т.е. все решения нескольких уравнений вида:
[latex] \begin{equation} x^5 + a_4x^4 + a_3x^3 + a_2 x^2 + a_1x + a_0 = 0 \end{equation} [/latex]
при дополнительном условии, что корни каждого многочлена различные и целочисленные.
Входные данные:
В качестве параметра входной строки в программу передается файл, содержащий несколько строк с коэффициентами уравнений. Каждая строка содержит пять разделенных пробелами чисел, которые являются коэффициентами многочлена, записанными в порядке
[latex]a_4, a_3, a_2, a_1, a_0.[/latex] Строка, состоящая из 5 нулей, считается признаком окончания ввода и не обрабатывается.
Выходные данные:
Для каждой пятерки коэффициентов из файла с входными данными в стандартный вывод должна быть записана строка, содержащая корни соответствующего многочлена, отсортированные в порядке возрастания и записанные через пробел.

Рациональные корни
(oakroadsystems.com/math/polysol.htm)
Предполагая, что вы уже выделили в качестве множителей (factored out) простые мономиальные множители и специальные произведения,что вам делать дальше, если вы все еще имеете многочлен (полином) степени 3 и выше?Ответ - это "Тест на рациональные корни". Он может отыскать вам все возможные кандидаты на рациональные корни.
Рассмотрим многочлен в стандартной форме, записанный от высшей степени к низшей и только с целыми коэффициентами [latex]f(x) = a_nx^n+\ldots+a_0[/latex]
В Теореме о рациональных корнях утверждается, что если многочлен имеет рациональный корень, то это должна быть дробь [latex]\dfrac{p}{q}[/latex], где [latex]p[/latex] - это множитель завершающей константы и [latex]q[/latex] - множитель первого коэффициента [latex]a_n[/latex]
Пример, используемый в программе ниже:   [latex] p(x)=2x^4-11x^3-6x^2+64x+32 [/latex].
Данный в программе алгоритм автоматически распространяется и на многочлены любых других степеней.
 
#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>
#include <math.h>
#include <string.h>

int factors[100],len=0,len1=0,len2=0,
possibleRootCounter=0,rootsCounter=0;

float pRoots[100],Roots[100];

int polynomial(float x)
{
	int f;
	int cf[6];
	//freopen("polynomial.txt","r",stdin);
	//for (int i=0;i<=6;i++)
	//	  scanf("%d",&cf[i]);
	//-15 85 -225 274 120 

	//cf[5]=1;cf[4]=-15;cf[3]=85;cf[2]=-225;cf[1]=274;cf[0]=120;
	//f = cf[5]*pow(x,5)+cf[4]*pow(x,4)+cf[3]*pow(x,3)+cf[2]*pow(x,2)+cf[1]*pow(x,1)+cf[0];

	cf[4]=2;cf[3]=-11;cf[2]=-6;cf[1]=64;cf[0]=32;
	f = cf[4]*pow(x,4)+cf[3]*pow(x,3)+cf[2]*pow(x,2)+cf[1]*pow(x,1)+cf[0];

	return f;

}

int* getFactors(int num,int factors[])
{
	//int m=100;
	int i,j=0;

	//for (i=0;i<m;i++)
	//	factors[i]=-1;

	for (i=1;i<=num;++i)
	{
      if(num%i == 0)
	  {
		  //printf("%d is factor of %d\n",i,num);
		  factors[j]=i;
		//  printf("%d is factor of %d\n",factors[j],num);
		  j++;
	  }
	}
	return factors;
}

int getQuantityOfFactors(int factors[])
{
	int count=0;
	for (int i=0;factors[i]!=-1;i++)
	{
		count++;
	}
	return count;
}

float* getPossibleRoots(int coefLast,int coefFirst,float possibleRoots[])
{
	int i,j,len1=0,len2=0,factors1[100],factors2[100];
        memset(factors1,-1,sizeof(factors1)/sizeof(factors1[0]));
	memset(factors2,-1,sizeof(factors2)/sizeof(factors2[0]));

	getFactors(coefLast,factors1);
	getFactors(coefFirst,factors2);

	len1 = getQuantityOfFactors(factors1);
	len2 = getQuantityOfFactors(factors2);

	int m=0;
	for (i=0;i<len1;i++)
	{
		for (j=0;j<len2;j++)
		{
			if (factors1[i]%factors2[j]==0 || factors1[i]%factors2[j]==1)
			{
              possibleRoots[m++]=((float)factors1[i]/factors2[j]);
			  possibleRootCounter++;
			  printf("possibleRoots[%d]=%f\n",m-1,possibleRoots[m-1]);
              possibleRoots[m++]=(-1)*((float)factors1[i]/factors2[j]);
			  possibleRootCounter++;
		      printf("possibleRoots[%d]=%f\n",m-1,possibleRoots[m-1]);
			}
		}
	}
return possibleRoots;
}

float getRoots(float possibleRoots[],int possibleRootCounter)
{
	int j=0;
	for (int i=0;i<possibleRootCounter;i++)
	{
           if (polynomial((float)possibleRoots[i]) == 0)
	   {
			Roots[j++]=possibleRoots[i];
			printf("Roots[%d]=%f\n",j-1,Roots[j-1]);
			rootsCounter++;
		}
	}
	return rootsCounter;
}

void main(int argc,char* argv[])
{	//system ("chcp 1251");

	int num1=32,num2=2;

	memset(factors,-1,sizeof(factors)/sizeof(factors[0]));
	memset(pRoots,0,sizeof(pRoots)/sizeof(pRoots[0]));
	memset(Roots,0,sizeof(Roots)/sizeof(Roots[0]));

	//getFactors(num1,factors);
	//len=getQuantityOfFactors(factors);
	//printf("Quantity of factors is %d\n",len);
	getPossibleRoots(num1,num2,pRoots);
	int rootsNumber=0;
	rootsNumber=getRoots(pRoots,possibleRootCounter);

	printf("possibleRootCounter of %d is %d\n",num1,possibleRootCounter);
	printf("rootsCounter of %d is %d\n",num1,rootsNumber);
	printf("roots[0] of %d is %f\n",num1,Roots[0]);
	printf("roots[1] of %d is %f\n",num1,Roots[1]);
	printf("roots[2] of %d is %f\n",num1,Roots[2]);
	printf("roots[3] of %d is %f\n",num1,Roots[3]);
	printf("roots[4] of %d is %f\n",num1,Roots[4]);
	printf("roots[5] of %d is %f\n",num1,Roots[5]);
	printf("roots[6] of %d is %f\n",num1,Roots[6]);
	printf("roots[7] of %d is %f\n",num1,Roots[7]);

	getchar();

}
