/*  Moscow State University - Faculty of Computing mathematics and Cybernetics
Magistrate  etrance exam - 2013   */

/*  
Evaluate  intagral of polynomial (its degree is supposed to be less than 99)
,if coefficients of this polynomial are defined in file input1.txt
In file 'input2.txt' there are 3 values defined: 
1nd and 2nd values are limits of integration of the definite integral;
3rd value is precision of calculation
(quantity of precision digits after point 0.0000);
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

//#define EPS 1.0e-4
#define JMAX 20

float  EPS;


#define FUNC(x)   ((*func)(x))

//int cnt1;
void nrerror(char error_text[])
/* Numerical Recipes standard error handler */
{
	//void _exit();

	fprintf(stderr,"Model run-time error...\n");
	fprintf(stderr,"%s\n",error_text);
	fprintf(stderr,"...now exiting to system...\n");
	exit();
}


float trapzd(float (*func)(float),float a,float b,int n)
{
	float x,tnm,sum,del;
	static float s;
	int it,j;
	if (n==1){

		return (s=0.5*(b-a)*(FUNC(a)+FUNC(b)));
	}
	else	{
		for (it=1,j=1;j<n-1;j++) it<<=1;
		tnm=it;
		del=(b-a)/tnm;
		x=a+0.5*del;
		for (sum=0.0,j=1;j<=it;j++,x+=del) sum+=FUNC(x);
			
			s=0.5*(s+(b-a)*sum/tnm);
			return s;
		
	}
}



/*  taken from the book "Numerical Recipes in C"   */
float qtrap(float (*f)(float),float a,float b,int n)
{
	/*
	Возвращает интеграл функции func ,взятый в пределах от a до b
    Параметру EPS может быть установлено значение точности,
	с которой необходимо получить результат.
	Параметру JMAX  - соответственно такое значение, что
	значение 2 в степени (JMAX - 1) - это максимум разрешенного количества шагов.
	Интегрирование производится по правилу трапеций.
	*/

	float trapzd(float (*func)(float),float a,float b,int n);
	void nrerror(char error_text[]);
	int j;
	float s,olds=0.0;  /* начальное значение olds может быть произвольным */

	for (j=1;j<=JMAX;j++)
	{
		s=trapzd(f,a,b,j);
		if (j>5)   // нужно, чтобы избежать ранней сходимости
			if (fabs(s-olds) < EPS*fabs(olds) ||
				(s == 0.0 && olds == 0.0)) {   return s;}
	      	olds = s;//printf("\ns=%f\n",s);
	}
	nrerror("Too many steps in routine qtrap");
	return 0.0;    // never   get here	
}

/*   This function takes coefficients of polynomial that has to be integrated as parameters
from input file  and returns value of this polynomial. In routine this function later is used as function pointer 
in the input to other eval function "trapezd" 
*/

float polynomial(float x)
{
	float f;
	float cf[5];
	
	freopen("polynomial.txt","r",stdin);
    for (int i=0;i<=5;i++)
    cin>>cf[i];



	cf[4]=1;cf[3]=0;cf[2]=0;cf[1]=2.277;cf[0]=1.33;

     f = cf[4]*pow(x,4)+cf[3]*pow(x,3)
	    +cf[2]*pow(x,2)+cf[1]*pow(x,1)+cf[0]*pow(x,0);
	 //cnt1++;

	 //printf("\nx=%f\n",x);
	 //printf("\nf=%f\n",f);
     return f;
}


//int addInt(int n, int m) {
//    return n+m;
//}
//
//int add2to3(int (*functionPtr)(int, int)) {
//    return (*functionPtr)(2, 3);
//}


void main()
{
	float a,b,result;
	int n;
    //a=1,b=2;

	freopen("parameters.txt","r",stdin);
   // for (int i=0;i<=2;i++)		
     cin>>a>>b>>n;
	 EPS = 1/(pow(10,(float)n));


    cin.clear();
	//float function;
	//n=1;
	//float param[3];




  float (*func)(float);
 
  func = &polynomial;
result = qtrap(func,a,b,n);





freopen("result.txt","w",stdout);
printf("\nEPS=%f\n",EPS);
printf("result=%f",result);


//First thing, lets define a pointer to a function which receives 2 ints and returns and int:

//int (*functionPtr)(int,int);
//
////Now we can safely point to our function:
//
//functionPtr = &addInt;
//
////Now that we have a pointer to the function, lets use it:
//
////int sum = (*functionPtr)(2, 3); // sum == 5
//int sum;
//sum=add2to3(*functionPtr);


//Passing the pointer to another function is basically the same:

//printf("\n\ncnt1=%d\n",cnt1);
getchar();

}
