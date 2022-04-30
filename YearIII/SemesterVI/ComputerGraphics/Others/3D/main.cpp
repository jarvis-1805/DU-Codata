/**
 * @file main.cpp
 * @author Tanya Chawla
 * @brief 3D Implementation written in TurboC++
 * @version 0.1
 * @date 2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream.h>
#include<process.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
int x[10][4], coord, i, j, new_x[10][4], final[10][4];
int projx[4][4]={{0,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
int projy[4][4]={{1,0,0,0},{0,0,0,0},{0,0,1,0},{0,0,0,1}};
int projz[4][4]={{1,0,0,0},{0,1,0,0},{0,0,0,0},{0,0,0,1}};
void drawAxis()
{
	int maxx=getmaxx();
	int maxy=getmaxy();
	int maxx_2=maxx/2;
	int maxy_2=maxy/2;
	line(maxx_2,0,maxx_2,maxy);
	line(0,maxy_2,maxx,maxy_2);
}

void draw_z()
{
	int gdrive=DETECT, gmode;
	initgraph(&gdrive, &gmode, "C:\\TC\\BGI");
	drawAxis();
	int xx=getmaxx()/2;
	int yy=getmaxy()/2;
	setcolor(RED);
	double x1, y1, x2, y2;
	for(i=0; i<coord-1; i++)
	{
		if(i+1==coord)
		{
			line(ceil(final[coord-1][0]+xx), ceil(yy-final[coord-1][1]), ceil(final[0][0]+xx), ceil(yy-final[0][1]));
		}
		else
		{
			line(ceil(final[i][0]+xx), ceil(yy-final[i][1]), ceil(final[i+1][0]+xx), ceil(yy-final[i+1][1]));
		}
	}
	getch();
	closegraph();
}
void draw_y()
{
	int gdrive=DETECT, gmode;
	initgraph(&gdrive, &gmode, "C:\\TC\\BGI");
	drawAxis();
	int xx=getmaxx()/2;
	int yy=getmaxy()/2;
	setcolor(RED);
	double x1, y1, x2, y2;
	for(i=0; i<coord-1; i++)
	{
		x1=final[i][0]+final[i][1]*(cos(2.3562));
		y1=final[i][2]-final[i][1]*(sin(2.3562));
		x2=final[i+1][0]+final[i+1][1]*(cos(2.3562));
		y2=final[i+1][2]-final[i+1][1]*(sin(2.3562));
		line(x1+xx, yy-y1, x2+xx, yy-y2);
	}
	getch();
	closegraph();
}

void draw_x()
{
	int gdrive=DETECT, gmode;
	initgraph(&gdrive, &gmode, "C:\\TC\\BGI");
	drawAxis();
	int xx=getmaxx()/2;
	int yy=getmaxy()/2;
	setcolor(RED);
	double x1, y1, x2, y2;
	for(i=0; i<coord-1; i++)
	{
		x1=final[i][1]+final[i][0]*(cos(2.3562));
		y1=final[i][2]-final[i][0]*(sin(2.3562));
		x2=final[i+1][1]+final[i+1][0]*(cos(2.3562));
		y2=final[i+1][2]-final[i+1][0]*(sin(2.3562));
		line(x1+xx, yy-y1, x2+xx, yy-y2);
	}

	getch();
	closegraph();
}

void projection()
{
	int proj_choice;
	cout<<"\n1. Projection onto z=0 plane";
	cout<<"\n2. Projection onto y=0 plane";
	cout<<"\n3. Projection onto x=0 plane";
	cout<<"\nEnter your choice: ";
	cin>>proj_choice;
	if(proj_choice==1)
	{
		for(i=0; i<coord; i++)
		{
			for(j=0; j<4; j++)
			{
				final[i][j]=0;
			}
		}
		for(i=0; i<coord; i++)
		{
			for(j=0; j<4; j++)
			{
				for(int k=0; k<4; k++)
				{
					final[i][j]+=new_x[i][k]*projz[k][j];
				}
			}
		}
		draw_z();
	}
	else if(proj_choice==2)
	{
		for(i=0; i<coord; i++)
		{
			for(j=0; j<4; j++)
			{
				final[i][j]=0;
			}
		}
		for(i=0; i<coord; i++)
		{
			for(j=0; j<4; j++)
			{
				for(int k=0; k<4; k++)
				{
					final[i][j]+=new_x[i][k]*projy[k][j];
				}
			}
		}
		draw_y();
	}
	else if(proj_choice==2)
	{
		for(i=0; i<coord; i++)
		{
			for(j=0; j<4; j++)
			{
				final[i][j]=0;
			}
		}
		for(i=0; i<coord; i++)
		{
			for(j=0; j<4; j++)
			{
				for(int k=0; k<4; k++)
				{
					final[i][j]+=new_x[i][k]*projx[k][j];
				}
			}
		}
		draw_x();
	}
}
void input()
{
	clrscr();
	cout<<"\nEnter number of co-ordinates(less than 10): ";
	cin>>coord;
	if(i>10)
	{
		cout<<"\nInvalid number";
		exit(0);
	}
	else
	{
		for(i=0; i<coord; i++)
		{
			cout<<"\nEnter co-ordinates of "<<i+1<<" point: ";
			cout<<"\nEnter x co-ordinate: ";
			cin>>x[i][0];
			cout<<"\nEnter y co-ordinate: ";
			cin>>x[i][1];
			cout<<"\nEnter z co-ordinate: ";
			cin>>x[i][2];
			x[i][3]=1;
		}
	}
}
void multiply(float arr[4][4])
{
	for(i=0; i<coord; i++)
	{
		for(j=0; j<4; j++)
		{
			new_x[i][j]=0;
		}
	}
	for(i=0; i<coord; i++)
	{
		for(j=0; j<4; j++)
		{
			for(int k=0; k<4; k++)
			{
				new_x[i][j]+=x[i][k]*arr[k][j];
			}
		}
	}
}

void translation()
{
	float trans[4][4];
	int option;
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(i==j)
				trans[i][j]=1;
			 else
				trans[i][j]=0;
		}
	}
	cout<<"\n1. Translation through x axis";
	cout<<"\n2. Translation through y axis";
	cout<<"\n3. Translation through z axis";
	cout<<"\n4. Translation through all the axis";
	cout<<"\nEnter your choice: ";
	cin>>option;
	float xfactor, yfactor,zfactor;
	switch(option)
	{
		case(1):{	cout<<"\nEnter x translation factor: ";
				cin>>xfactor;
				trans[3][0]=xfactor;
				break;
			}
		case(2):{	cout<<"\nEnter y translation factor: ";
				cin>>yfactor;
				trans[3][1]=yfactor;
				break;
			}
		case(3):{	cout<<"\nEnter z translation factor: ";
				cin>>zfactor;
				trans[3][2]=zfactor;
				break;
			}
		case(4):{       cout<<"\nEnter x translation factor: ";
				cin>>xfactor;
				trans[3][0]=xfactor;
				cout<<"\nEnter y translation factor: ";
				cin>>yfactor;
				trans[3][1]=yfactor;
				cout<<"\nEnter z translation factor: ";
				cin>>zfactor;
				trans[3][2]=zfactor;
				break;
			}
		default:{ cout<<"\nInvalid input"; break; }
	}
	multiply(trans);
}
void rotation()
{
	float R[4][4];
	int direction;
	double angle;
	cout<<"\n1. About x axis";
	cout<<"\n2. About y axis";
	cout<<"\n3. About z axis";
	cout<<"\nEnter direction: ";
	cin>>direction;
	cout<<"\nEnter angle: ";
	cin>>angle;
	if(direction==1)
	{
		R[0][0]=1;
		R[0][1]=0;
		R[0][2]=0;
		R[0][3]=0;
		R[1][0]=0;
		R[1][1]=cos(angle*(M_PI/180));
		R[1][2]=sin(angle*(M_PI/180));
		R[1][3]=0;
		R[2][0]=0;
		R[2][1]=-sin(angle*(M_PI/180));
		R[2][2]=cos(angle*(M_PI/180));
		R[2][3]=0;
		R[3][0]=0;
		R[3][1]=0;
		R[3][2]=0;
		R[3][3]=1;
	}
	else if(direction==2)
	{
		R[0][0]=cos(angle*(M_PI/180));
		R[0][1]=0;
		R[0][2]=-sin(angle*(M_PI/180));
		R[0][3]=0;
		R[1][0]=0;
		R[1][1]=1;
		R[1][2]=0;
		R[1][3]=0;
		R[2][0]=sin(angle*(M_PI/180));
		R[2][1]=0;
		R[2][2]=cos(angle*M_PI/180);
		R[2][3]=0;
		R[3][0]=0;
		R[3][1]=0;
		R[3][2]=0;
		R[3][3]=1;
	}
	else if(direction==3)
	{
		R[0][0]=cos(angle*(M_PI/180));
		R[0][1]=sin(angle*(M_PI/180));
		R[0][2]=0;
		R[0][3]=0;
		R[1][0]=-sin(angle*(M_PI/180));
		R[1][1]=cos(angle*(M_PI/180));
		R[1][2]=0;
		R[1][3]=0;
		R[2][0]=0;
		R[2][1]=0;
		R[2][2]=1;
		R[2][3]=0;
		R[3][0]=0;
		R[3][1]=0;
		R[3][2]=0;
		R[3][3]=1;
	}
	multiply(R);
}
void reflection()
{
	float refl[4][4];
	int option;
	cout<<"\n1. Reflection through xy plane";
	cout<<"\n2. Reflection through yz plane";
	cout<<"\n3. Reflection through xz plane";
	cout<<"\nEnter your choice: ";
	cin>>option;
	if(option==1)
	{
		refl[0][0]=1;
		refl[0][1]=0;
		refl[0][2]=0;
		refl[0][3]=0;
		refl[1][0]=0;
		refl[1][1]=1;
		refl[1][2]=0;
		refl[1][3]=0;
		refl[2][0]=0;
		refl[2][1]=0;
		refl[2][2]=-1;
		refl[2][3]=0;
		refl[3][0]=0;
		refl[3][1]=0;
		refl[3][2]=0;
		refl[3][3]=1;
	}
	else if(option==2)
	{
		refl[0][0]=-1;
		refl[0][1]=0;
		refl[0][2]=0;
		refl[0][3]=0;
		refl[1][0]=0;
		refl[1][1]=1;
		refl[1][2]=0;
		refl[1][3]=0;
		refl[2][0]=0;
		refl[2][1]=0;
		refl[2][2]=1;
		refl[2][3]=0;
		refl[3][0]=0;
		refl[3][1]=0;
		refl[3][2]=0;
		refl[3][3]=1;
	}
	else if(option==3)
	{
		refl[0][0]=1;
		refl[0][1]=0;
		refl[0][2]=0;
		refl[0][3]=0;
		refl[1][0]=0;
		refl[1][1]=-1;
		refl[1][2]=0;
		refl[1][3]=0;
		refl[2][0]=0;
		refl[2][1]=0;
		refl[2][2]=1;
		refl[2][3]=0;
		refl[3][0]=0;
		refl[3][1]=0;
		refl[3][2]=0;
		refl[3][3]=1;
	}
	multiply(refl);
}
void shearing()
{
	float shear[4][4];
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(i==j)
				shear[i][j]=1;
			else
				shear[i][j]=0;
		}
	}
	int option, xshear, yshear, zshear;
	cout<<"\n1. Shearing in x direction";
	cout<<"\n2. Shearing in y direction";
	cout<<"\n3. Shearing in z direction";
	cout<<"\nEnter your choice: ";
	cin>>option;
	if(option==1)
	{
		cout<<"\nEnter y shearing factor: ";
		cin>>yshear;
		cout<<"\nEnter z shearing factor: ";
		cin>>zshear;
		shear[0][1]=yshear;
		shear[0][2]=zshear;
	}
	else if(option==2)
	{
		cout<<"\nEnter x shearing factor: ";
		cin>>xshear;
		cout<<"\nEnter z shearing factor: ";
		cin>>zshear;
		shear[1][0]=xshear;
		shear[1][2]=zshear;
	}
	else if(option==3)
	{
		cout<<"\nEnter x shearing factor: ";
		cin>>xshear;
		cout<<"\nEnter y shearing factor: ";
		cin>>yshear;
		shear[2][0]=xshear;
		shear[2][1]=yshear;
	}
	multiply(shear);
}
void scaling()
{
	float scal[4][4];
	int option;
	float xscal, yscal, zscal, overall;
	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
			if(i==j)
				scal[i][j]=1;
			else
				scal[i][j]=0;

	cout<<"\n1. Scaling along x direction";
	cout<<"\n2. Scaling along y direction";
	cout<<"\n3. Scaling along z direction";
	cout<<"\n4. Scaling along all direction";
	cout<<"\n5. Overall scaling";
	cout<<"\nEnter your choice: ";
	cin>>option;
	if(option==1)
	{
		cout<<"\nEnter x scaling factor: ";
		cin>>xscal;
		scal[0][0]=xscal;
	}
	else if(option==2)
	{
		cout<<"\nEnter y scaling factor: ";
		cin>>yscal;
		scal[1][1]=yscal;
	}
	else if(option==3)
	{
		cout<<"\nEnter z scaling factor: ";
		cin>>zscal;
		scal[2][2]=zscal;
	}
	else if(option==4)
	{
		cout<<"\nEnter x scaling factor: ";
		cin>>xscal;
		scal[0][0]=xscal;
		cout<<"\nEnter y scaling factor: ";
		cin>>yscal;
		scal[1][1]=yscal;
		cout<<"\nEnter z scaling factor: ";
		cin>>zscal;
		scal[2][2]=zscal;
	}
	else if(option==5)
	{
		cout<<"\nEnter overall scaling factor: ";
		cin>>overall;
		scal[3][3]=overall;
	}
	multiply(scal);
}

void main()
{
	clrscr();
	int choice;
	do
	{
		cout<<"\n\n\nMENU";
		cout<<"\n1. Translation";
		cout<<"\n2. Rotation";
		cout<<"\n3. Scaling";
		cout<<"\n4. Reflection";
		cout<<"\n5. Shearing";
		cout<<"\n6. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;

		switch(choice)
		{
			case(1):{	input();
					translation();
					projection();
					break;
				}
			case(2):{	input();
					rotation();
					projection();
					break;
				}
			case(3):{	input();
					scaling();
					projection();
					break;
				}
			case(4):{	input();
					reflection();
					projection();
					break;
				}
			case(5):{ 	input();
					shearing();
					projection();
					break;
				}
			case(6):{	exit(0); }
			default:{	cout<<"\nWrong choice\nEnter again";}
		}
	}while(choice!=6);
	getch();
}

