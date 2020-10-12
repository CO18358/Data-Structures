//write a program for implmentation of 2 dimensional array using pointers for following operations on matrix:
//1. addition 
//2. subtraction
//3. transpose

#include<iostream>
#include<cstdlib>

using namespace std;

	int arr1[10][10], arr2[10][10],res[10][10];
	int *a, *b, *c, *A, *B;
	int m,n,p,q,i,j,option;
	

int * add(int *a, int *b)
{
	if(m!=p || n!=q)
	{
		cout<<"Addition is not Possible"<<endl;
	}
	else
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				res[i][j] += arr1[i][j] + arr2[i][j];
			}
		}
		return (&res[0][0]);
	}
	
}

int * sub(int *a, int *b)
{
	if(m!=p || n!=q)
	{
		cout<<"Subtraction is not Possible"<<endl;
		
	}
	else
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				res[i][j] = arr1[i][j] - arr2[i][j];
			}
		}
		return (&res[0][0]);
	}
}

void transpose(int *a, int *b)
{
	cout<<"First array: "<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<arr1[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"Transpose of first array: "<<endl;
	for(j=0;j<n;j++)
	{
		for(i=0;i<m;i++)
		{
			cout<<arr1[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"Second array: "<<endl;
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			cout<<arr2[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"Transpose of second array: "<<endl;
	for(j=0;j<q;j++)
	{
		for(i=0;i<p;i++)
		{
			cout<<arr2[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main()
{
	
	cout<<endl<<"Enter dimensions of first array: ";
	cin>>m>>n;
	cout<<endl<<"Enter dimensions of second array: ";
	cin>>p>>q;
	
	
	
	cout<<endl<<"Enter elements of first array: "<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			a=&arr1[i][j];
			cin>>*a;
		}
	}
	cout<<endl<<"Enter elements of second array: "<<endl;
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			b=&arr2[i][j];
			cin>>*b;
		}
	}
	cout<<endl;
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			res[i][j]=0;
		}
	}
	cout<<endl;
	cout<<"1. Addition"<<endl;
	cout<<"2, Subtraction"<<endl;
	cout<<"3. Transpose"<<endl;
	cout<<"4. Exit"<<endl;
	
	do{
		cout<<endl<<"Choose Your Option: ";
		cin>>option;
		switch(option)
		{
			case 1:
				{
					add(&arr1[0][0],&arr2[0][0]);
					cout<<"Resultant Array: "<<endl;
					for(i=0;i<p;i++)
					{
						for(j=0;j<q;j++)
						{
							c=&res[i][j];
							cout<<*c<<"\t";
						}
						cout<<endl;
					}
				}
				break;
			case 2:
				{
					sub(&arr1[0][0],&arr2[0][0]);
					cout<<"Resultant Array: "<<endl;
					for(i=0;i<p;i++)
					{
						for(j=0;j<q;j++)
						{
							c=&res[i][j];
							cout<<*c<<"\t";
						}
						cout<<endl;
					}
				}
				break;
			case 3:
				{
					transpose(&arr1[0][0],&arr2[0][0]);
				}
			default:
				exit(0);
		}
	}while(option>0&&option<4);
	
	return 0;
}
