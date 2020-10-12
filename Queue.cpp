//queue of an array
#include<iostream>
#include<cstdlib>

using namespace std;

#define MAX 5

struct QUEUE{
	int data[MAX];
	int rear, front;
};

typedef QUEUE queue;

queue q;
int e,i,op;

void insert()
{
	if((q.rear == MAX-1 && q.front == 0) || (q.front == q.rear + 1))
	{
		cout<<"Queue Overflowed"<<endl;
	}
	else if(q.rear == MAX-1 && q.front != 0)
	{
		cout<<"Element will be inserted in the front of queue"<<endl;
		cout<<"Enter the element you wish to insert: ";
		cin>>e;
		q.rear = 0;
		q.data[q.rear] = e;
	}
	else
	{
		if(q.front == -1)
		{
			q.front = 0;
		}
		cout<<"Enter the element you wish to insert: ";
		cin>>e;
		q.rear++;
		q.data[q.rear] = e;
	}
}
int remove()
{
	if( q.front == -1) 
	
	{
		cout<<"Queue underflowed"<<endl;	
	}
	else
	{
		e = q.data[q.front];
		cout<<"Element "<<e<<" is deleted from the queue."<<endl<<endl;
	}
	if(q.front == q.rear)
	{
		q.front=q.rear=-1;
		cout<<"Element deleted"<<endl<<"Queue is now Empty!"<<endl;
	}
	else if (q.front == MAX -1)
	{
		q.front = 0;
	}
	else
		q.front++;
		
	return (e);
}
void display()
{
	if(q.front == -1)
	{
		cout<<"Queue is Empty!"<<endl;
	}
	else
	{
		cout<<"Displaying Elements of the Queue: "<<endl;
		if(q.rear >= q.front)
		{
			for (i=q.front;i<=q.rear;i++) 
			{
				cout<<q.data[i]<<endl;
			}
		}
		else
		{ 
        for (i=q.front;i<MAX;i++) 
            cout<<q.data[i]<<endl;
  
        for (i=0;i<=q.rear;i++) 
            cout<<q.data[i]<<endl; 
		}
	}
	
}


int main()
{
	q.rear=	q.front= -1;
	do{	
		cout<<endl;
 		cout<<"1. Insert an element"<<endl;
	 	cout<<"2. Delete an element"<<endl;
		cout<<"3. Display Queue"<<endl;
		cout<<endl<<"Choose your option: ";
		cin>>op;
		cout<<endl;
		
		switch (op)
		{
			case 1:
				{
					insert();
				}
				break;
			case 2:
				{
					remove();	
				}
				break;
			case 3:
				{
					display();
				}
				break;
			default:
				exit(0);
		}
	}while(op!=4);
	return 0;
}

