#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int findDigit(int m)
{	
	//  m  -  is  m-th digit of Champerknowne constant that has to be found
	long N[10];// an array  for keeping  sum  of all 1-digit, all 2-digit,all 3-digit nambers 
	char Dbuffer[10]; /* char array for storing last k-digit number (number x)
	   which contains m-th digit of our sequence on y-th place from beginning of number x */
	long x1=0,x2=0,y;

	int k,i,result;

	for (i=0;i<10;i++)
	{
		N[i]=0;
	}

	k=1;	

	if  (m==1)
	{
		x2=1;
		y=1;          
	}
	else
	{			
		for (k=1;N[k-1]<=m;k++)
		{ 
		    N[k] = N[k-1] + (k)*9*((int)(pow((double)10,k-1)));
		    //	printf("N[%d] = %d\n\n",k,N[k]);
		}

		x1 = (int) floor( (double)((m - N[k-2])/(k-1)) );
		if (x1<1)
		{
			x1=1;
			x2 = x1 + (int)pow((double)10,1)-1; 
			y=1;// printf("x1 = %d\n\n",x1);
		}	             
		else
		{ 
			x2 = x1 + (int)pow((double)10,k-2)-1;  //  target (k-1)-th number that we're lookin for
			y = (m - N[k-2]) - x1*(k-1);
		}	
	}
	itoa(x2,Dbuffer,10);
//	printf("Dbuffer=%s\n",Dbuffer);
//	printf("Dbuffer[%d]=%c\n",y-1,Dbuffer[y-1]);
	result = Dbuffer[y-1]-'0';
//	printf("result=%d\n",result);
	return result;	
}

void  main()
{
	int i,num[]={1,10,100,1000,10000,100000,1000000};
	int product=1,digit[10];

	for (i=0;i<(sizeof(num)/sizeof(num[0]));i++)
	{ 		
		digit[i]=findDigit(num[i]);
		printf("the %d-th digit of sequence is %d\n\n",num[i],digit[i]);
		product *= digit[i] ;
	}
	printf("digit on %d-th place is %d\n",28383,findDigit(28383));	
	printf("digit on %d-th place is %d\n",206788,findDigit(206788));	
	printf("Product of d1*d10*d100*d1000*d10000*d100000*d1000000 = %d\n\n",product);
	getchar();
}
