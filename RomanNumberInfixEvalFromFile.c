/*problem from Postgraduate (magistracy) entrance exam MSU (Moscow State University)
Faculty of Computing Mathematics and Cybernetics 2010

Description:
"Roman digits calculator"

In text file  input.txt  there defined arithmetcal expression
written by Roman digits.Example of such expression is as below:
IX-VII-XX+XVI/II-XI

Task is to write routine that takes as input this expression from file,
converts it into decimal system and then finds its value.
Value of this expression has to be written to text  file output.txt.
Files input.txt and output.txt are to be stored in the same folder
as executable files of the routine
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
	int top;
	double item[100];
};

int empty(stack *s)
{
if (s->top==-1)
	return 1;
else
	return 0;
}
double pop(struct stack *ps)
{	
	return (ps->item[ps->top--]);
}

void push(struct stack *ps,double symb)
{

	ps->top=ps->top+1;
	ps->item[ps->top]=symb;
}

int ISDIGIT(char s)
{
	if (s>='0' && s<='9') return 1;
	else return 0;
}

int ISROMAN(char s)
{
	if ( s>='C' && s<='X'|| s>='c' && s<='x')
		return 1;
	else return 0;
}

int RomanToDec(char *roman)
{

	int   dec[20];
	int   len,i,k;

	len=strlen(roman);
	//printf("Test print!!");
	for (i=0;i<len;i++)
	{
		if (roman[i]=='I'||roman[i]=='i')
			dec[i]=1;
		else if (roman[i]=='V'||roman[i]=='v')
			dec[i]=5;
		else if (roman[i]=='X'||roman[i]=='x')
			dec[i]=10;
		else if (roman[i]=='L'|| roman[i]=='l')
			dec[i]=50;
		else if (roman[i]=='C'||roman[i]=='c')
			dec[i]=100;
		else if (roman[i]=='D'||roman[i]=='d')
			dec[i]=500;
		else if (roman[i]=='M'||roman[i]=='m')
			dec[i]=1000;	
	    else
	    {
          printf("Please,input correct Roman  number!\n");
		  getchar();
		  exit(0);
		}
	}
		k=dec[len-1];

		for (i=len-1;i>0;i--)
		{
			if (dec[i-1]<dec[i])
				k=k-dec[i-1];
			else 
				k=k+dec[i-1];
		}
		printf("Decimal value of this Roman number is: %d\n",k);			
		return k;
}

double power(double op1,double op2)
{
	int i;
	double op11;
	op11=op1;
	for (i=1; i<op2;i++)
	{
		op1=op1*op11;
	}
	return op1;
}

double oper(char symb,double op1,double op2)
{
	switch(symb)
	{
	case '+':return(op1+op2);break;
	case '-':return (op1-op2);break;
    case '*':return(op1*op2);break;		
    case '/':return(op1/op2);break;
    case '$':return(power(op1,op2));break;
	default:printf("invalid operator\n");return 0;break;
	}
}

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}


double evalpre()
{
	struct stack ps;
	ps.top=-1;
	int len;
	int i,k,l,Break,p;
	char string[100],c,symbol;
	double s[10],d[10];
	char str[10]; 
	double op1,op2;//top1,top2;
	double value;

	//printf("Enter arithmetical expression in prefix form values,like 12*8/4:\n");
	
	//scanf("%s",string);
	fscanf(stdin,"%s",string);

	len=strlen(string);
	value=0;

	for (l=0;l<sizeof(s)/sizeof(s[0]);l++)
		s[l]=0;
	for (l=0;l<sizeof(str)/sizeof(str[0]);l++)
	     str[l]=0;

	l=0;
    for (i=0;i<len;i++)
	{  	
				if (!ISROMAN(string[i])) 
		        { 
					symbol=string[i];printf("\nsymbol=%c\n",symbol);str[l+1]=0;l++;
						continue;
		        }               		
				else
				{                          
					 if (ISROMAN(string[i]))
					   {  	//if (l==1) {printf("\n!i=%d\n",i);}
					                      
					  	 append(&str[l],string[i]);
						  printf("\n\nstr[%d]=%s\n\n",l,&str[l]);
						  s[l]=RomanToDec(&str[l]);	
					   }

                        printf("OK!!"); //s[l]=atof(d[l]);					
					    printf("\n\ns[%d]=%f\n\n",l,s[l]);
		      // end of 'for' loop  
						
			  if (ISROMAN(string[i]) && !ISROMAN(string[i+1]))
			  {        push(&ps,s[l]);			          	          
					   printf("item[top]=%f\n",ps.item[ps.top]);
		               printf("top=%d\n",ps.top);   
			  }

			 if (ps.top>=1)	
			 //if (ps.top>=1 && string[i+1]!='*' ||ps.top>=1 && string[i+1]!='/')	
		      {		
			      printf("\nOK!\n");
				  op2=pop(&ps);op1=pop(&ps);
				  value=(oper(symbol,op1,op2));
			      push(&ps,value);	
			      printf("\nvalue=%f\n",value);
			  }
			 
			 //else
			 //{
			 //     printf("\nOK2!\n");
				//  op2=pop(&ps);//op1=pop(&ps);
				//  int temp;
				//  temp  = s[0];
				//  printf("temp=%f\n",temp);
				//  value=(oper(symbol,s[1],op2));
			 //     //push(&ps,value);	
			 //     printf("\nvalue2=%f\n",value);
			 //}


	     }
      } 
		return value;
}

void main()
{
double val;
int c;
FILE* input_file;
input_file=freopen("RomanInput.txt","r",stdin);
freopen("RomanOutput.txt","w",stdout);


//char stringf[100];
//char teststr[]="test!";
do{
val=evalpre();
printf("\nValue=%f\n",val);
}
while((c = fgetc(input_file)) != EOF );
system("pause");
}


