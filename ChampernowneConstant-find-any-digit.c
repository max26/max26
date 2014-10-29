#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int findChampernowneDigit(int m)
{	
   //  m  - это m-ая цифра константы Чамперноуна, которую нужно найти
    long N[10];// массив для хранения всех 1-значных чисел,2-хзначных чисел,3-хзначных чисел,....
    char Dbuffer[10];/* массив для хранения последнего k-значного числа (число x2),которое содержит m-ое число нашей последовательности на y-ом месте,считая от начала числа x2 */
    long x1=0,x2=0,y;
    int k,i,result;
    int remainder2; 

    for (i=0;i<10;i++)
    {
        N[i]=0;
    }       
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
        }
    
        x1 = (m - N[k-2])/(k-1) ;

        if (x1<1)
        {
            x1=1;
            x2 = x1 + (int)pow((double)10,1)+1;
            y=1;
		printf("x1 = %d\n\n",x1);
        }               
        else
        {
            x2 = x1 + (int)pow((double)10,k-2)-1;  //  target (k-1)-th number that we're lookin for
            y = (m - N[k-2]) - x1*(k-1);

			remainder2 = (m - N[k-2])%(x1*(k-1));
			if (remainder2 == 0) { y = k-1;}
        }  
    }
    itoa(x2,Dbuffer,10);
    result = Dbuffer[y-1]-'0';
    return result;    
}


void  main()
{ 
	//clock_t t;
 // int f;
 // t = clock();	
	/*struct timeval  tv1, tv2;
gettimeofday(&tv1, NULL);*/
	clock_t begin, end;
    double time_spent;

begin = clock();
/* here, do your time-consuming job */
    int i;
	int num[]={1,10,100,1000,10000,100000,1000000};
	int product=1,digit[10];

	for (i=0;i<(sizeof(num)/sizeof(num[0]));i++)
	{ 		
		digit[i]=findChampernowneDigit(num[i]);
		//printf("the %d-th digit of sequence is %d\n\n",num[i],digit[i]);
		product *= digit[i] ;
	}
	int dig=1001;
	printf("digit on %i-th place is %i\n",dig,findChampernowneDigit(dig));	
	//printf("digit on %d-th place is %d\n",28383,findDigit(28383));	
	//printf("digit on %d-th place is %d\n",206788,findDigit(206788));	
	printf("Product of d1*d10*d100*d1000*d10000*d100000*d1000000 = %d\n\n",product);

	end = clock();
   time_spent = (double)(end - begin); /* CLOCKS_PER_SEC;*/
  //printf("\nTime of execution is %f\n",time_spent);
	//t = clock() - t;
  //printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
   printf ("It took me %f clicks (%f seconds).\n",time_spent,(time_spent)/CLOCKS_PER_SEC);

   getchar();
}
