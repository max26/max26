
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <limits>
#include <vector>

using namespace std;
/*   check-lines   routine   */

/*
This is based off an explanation and expanded math presented by
Paul   Bourke:

It takes  two lines  as inputs  and returns 1 if they intersect,
0  if they do not.

hitp  returns  the point   where the two lines intersected.

This  function   expects  integer  value  inputs
and  stores   if the two lines  intersect.
The  internal calculations are fixed point  with  a  14  bit
fractional precision for processors without floating point units
*/
typedef struct point
{
	float x;
	float y;
	
} point;

typedef struct line
{
	point p1;
	point p2;
} line;

enum IsParallel {Parallel,Intersect,Coincident,NoIntersect} ;
IsParallel mySlope = Intersect;



point* SubtractPoints(point p1,point p2)
{   
	point p;
	point *result=&p;
	result->x = p2.x - p1.x;
	result->y= p2.y - p1.y;	
	return result;
}


//
//float  DenominatorCrossProduct(line *l1,line *l2)
//{
//	float cross,crossl2Y,crossl1X,crossl2X,crossl1Y;
//    crossl2Y =(SubtractPoints(l2->p2,l2->p1))->y;
//    crossl1X =(SubtractPoints(l1->p2,l1->p1))->x;	
//    crossl2X= (SubtractPoints(l2->p2,l2->p1))->y;
//    crossl1Y =(SubtractPoints(l1->p2,l1->p1))->y;	
//
//
//	return (cross = (l2->p2.y - l2->p1.y)*(l1->p2.x - l1->p1.x)
//		-(l2->p2.x - l2->p1.x)*(l1->p2.y - l1->p1.y));
//	
//}
//float  NumeratorCrossProduct(line *l1,line *l2)
//{
//	float crossl1l2X,crossl1l2Y,crossline2X,crossline2Y;
//    crossline2X =(SubtractPoints(l2->p2,l2->p1))->x;
//    crossline2Y =(SubtractPoints(l2->p2,l2->p1))->y;	
//    crossl1l2Y= (SubtractPoints(l1->p1,l2->p1))->y;
//    crossl1l2X =(SubtractPoints(l1->p1,l2->p1))->x;	
//
//	return (crossline2X*crossl1l2Y)-(crossline2Y*crossl1l2X);
//	// (l2->p2.x - l2->p1.x)*(l1->p1.y - l2->p1.y) -
//		//(l2->p2.y-l2->p1.y)*(l1->p1.x-l2->p1.x));
//}


point check_lines(line *line1, line *line2,point *hitp)
{   	
	point crossl1,crossl2,crossl1l2;
	crossl2.x= (SubtractPoints(line2->p2,line2->p1))->x;
	crossl2.y=(SubtractPoints(line2->p2,line2->p1))->y;

	crossl1.x= (SubtractPoints(line1->p2,line1->p1))->x;
	crossl1.y=(SubtractPoints(line1->p2,line1->p1))->y;

	crossl1l2.x= (SubtractPoints(line1->p1,line2->p1))->x;
	crossl1l2.y=(SubtractPoints(line1->p1,line2->p1))->y;

	float d = crossl2.y*crossl1.x - crossl2.x*crossl1.y;
	float n_a= crossl2.x*crossl1l2.y-crossl2.y*crossl1l2.x;
	float n_b= crossl1.x*crossl1l2.y-crossl1.y*crossl1l2.x;

	//float  d = (line2->p2.y - line2->p1.y)*(line1->p2.x - line1->p1.x) -
	//	(line2->p2.x - line2->p1.x)*(line1->p2.y - line1->p1.y);
	//float n_a = (line2->p2.x - line2->p1.x)*(line1->p1.y - line2->p1.y) -
	//	(line2->p2.y-line2->p1.y)*(line1->p1.x-line2->p1.x);

 //   float n_b = (line1->p2.x - line1->p1.x)*(line1->p1.y - line2->p1.y) -
	//	(line1->p2.y - line1->p1.y)*(line1->p1.x - line2->p1.x);

		if (d==0)
		{	
		/*			if (line1->p1.x==line2->p2.x)				
						mySlope = Parallel;
					if (line1->p1.y==line2->p2.y)*/
						mySlope = Parallel;
					if (line1->p1.x==line2->p1.x && line1->p1.y==line2->p1.y
						&&  line1->p2.x==line2->p2.x && line1->p2.y==line2->p2.y )
						mySlope = Coincident;	
		}  
		else
		{   
			float  ua=(n_a)/d;
			float ub=(n_b)/d;
			//if(ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1)
			 if(ub >= 0 && ub <= 1)
			 {
				hitp->x = line2->p1.x + (ub * (line2->p2.x - line2 -> p1.x));
				hitp->y = line2->p1.y + (ub * (line2->p2.y - line2->p1.y));
				mySlope = Intersect;
			 }	
			 else
			 {   
				mySlope = NoIntersect;
			 }
		 }
return *hitp;
}

void pointPrint(point p)
{   
		if (mySlope != NoIntersect)		
		{     
			if (mySlope == Parallel)
		    {
                cout<<"Parallel!"<<endl;
		    }
			else if (mySlope == Coincident)
			{
                cout<<"Coincident Lines!"<<endl;
			}
		    else 
			{
				 cout<<setw(8)<<setprecision(7)<<"X: "<<p.x<<"\t"<<"Y: "<<p.y<<endl;
		    }
		}		
		//else if (mySlope == NoIntersect) 
		else
		{
			cout<<"No intersection!"<<endl;
		}
}	


//struct complex 
//{
//	double r;
//	double i;
//};

istream& operator >>(istream& in,line& l)
{
	in >> l.p1.x >> l.p1.y>>l.p2.x>>l.p2.y;
	return in;
}


void main()
{ 
	/*try
	{*/
point hit[30];
point *hitP;
hitP=hit;	


line lin[5];
line rect[4];

//float r[8][2],l[10][2];

//printf("enum=%d\n",mySlope);

//point point1,point2;
//point1.x=2;point1.y=19;
//point2.x=8;point2.y=1729;
//
////printf("\npoint1 = {%f,%f}\n",point1.x,point1.y);
//point res;
//point *SubtractResult=&res;
//SubtractResult->x=-90;
//SubtractResult->y=-90;
//SubtractResult=SubtractPoints(point1,point2);
//printf("\nSubtract Point = {%.2f,%.2f}\n",SubtractResult->x,SubtractResult->y);
//system("pause");
freopen("rectangle.txt","r",stdin);
freopen("RectangleOutput.txt","w",stdout);




//ifstream file1();




//istream& operator>> (istream& in,point& p)
//{
//	//fin>>p1.x>>p1.y>>p2.x>>p2.y;
//
//	return in;
//}
//ofstream& operator << (ofstream& out,point& p)
//{
//	cout<<setw(8)<<setprecision(7)<<"X: "<<p.x<<"\t"<<"Y: "<<p.y<<endl;
//	return out;
//}
for (int l=0;l<=3;l++)
	cin>>rect[l];

//for (int i=0;i<=7;i++)		
//cin>>r[i][0]>>r[i][1];

//for (int i=0,l=0;i<=6,l<=3;(i=i+2),l++)
//{
//	rect[l].p1.x=r[i][0];			
//	rect[l].p1.y=r[i][1];
//	rect[l].p2.x=r[i+1][0];			
//	rect[l].p2.y=r[i+1][1];
//	
//}

cout<<rect[1].p1.x<<"\n"<<rect[1].p1.y<<"\n\n"<<rect[1].p2.x<<"\n"<<rect[1].p2.y<<"\n\n";

cin.clear();


freopen("points2.txt","r",stdin);

for (int m=0;m<=4;m++)	
cin>>lin[m];

//for (int i=0;i<=9;i++)	
//cin>>l[i][0]>>l[i][1];
//
//
//for (int i=0,m=0;i<=8,m<=4;(i=i+2),m++)
//{
//	lin[m].p1.x=l[i][0];			
//	lin[m].p1.y=l[i][1];
//	lin[m].p2.x=l[i+1][0];			
//	lin[m].p2.y=l[i+1][1];
//}	

//cout<<lin[4].p1.x<<"\n"<<lin[4].p1.y<<"\n\n"<<lin[4].p2.x<<"\n"<<lin[4].p2.y<<"\n\n";


freopen("intersection.txt","w",stdout);

line *linp;linp=&lin[0];
line *rectp;rectp=&rect[0];


point intersect[5][4];

	for (int m=0;m<=4;m++)
	{
		for (int l=0;l<=3;l++)
		{		
		intersect[m][l]=check_lines(&linp[m],&rectp[l],hitP);
		printf("Intersection of %i-th line with %i-th side of rectangle is:",m+1,l+1);
		pointPrint(intersect[m][l]);	
		}
	}
	//system("pause");
}

