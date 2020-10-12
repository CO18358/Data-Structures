#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct queue
{
	int data;
	int priority;
	struct queue *next;
	struct queue *prev;
} pqueue;

	pqueue *node, *temp, *ptr, *rear, *front;
	int op, value, priority, new_p;

void insert(pqueue **rear,pqueue **front,int value,int prior)
{
	node = new pqueue;
	node->data=value;
	node->priority=prior;
	if(*rear==NULL && *front==NULL)
	{
		node->next='\0';
		node->prev='\0';
		*front=node;
		*rear=node;
	}
	
	else if(prior>(*front)->priority)
	{
			(*front)->next=node;
			node->prev=*front;
			node->next='\0';
			*front=node;
	}
		
	else
	{
			node->prev='\0';
			node->next=*rear;
			(*rear)->prev=node;
			*rear=node;
	}
}

void traverse(pqueue *front)
{
	temp = new pqueue;
	temp=front;
	while(temp!=NULL)
	{
		printf("%d %d\n",temp->data,temp->priority);
		temp=temp->prev;
	}
}

void remove(pqueue **rear,pqueue **front)
{
	temp = new pqueue;
	temp=*front;
	if(temp!=NULL)
	{
		*front=(*front)->prev;
		free(temp);
	}
	else
		cout<<"Underflow \n";
}

void update(pqueue **rear,pqueue **front)
{
	temp = new pqueue;
	temp=*rear;
	
	cout<<"Enter element : ";
	cin>>value;
	
	while(temp!=NULL)
	{
		if(temp->data==value)
		{
			cout<<"Priority is: "<<temp->priority<<endl;
			if(temp==*front)
			{
				*front=temp->prev;
				temp->prev->next='\0';
				free(temp);
			}
			else if(temp==*rear)
			{
				*rear=temp->next;
				temp->next->prev='\0';
				free(temp);
			}
			else
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;		
				free(temp);
			}
			break;
		}
		
		else
			temp=temp->next;
	}
	
	cout<<"Enter new priority : ";
	cin>>new_p;
	insert(&rear,&front,value,new_p);
}

int main()
{
	front = new pqueue;
	rear = new pqueue;
	if(rear==NULL || front==NULL)
	{
		cout<<"Queue cannot be created\n";
		exit(0);
	}
	front = rear = NULL;
	do{
		cout<<"1. Insert a Record. \n";
		cout<<"2. Traverse the Queue. \n";
		cout<<"3. Remove a Record. \n";
		cout<<"4. Update a Record Priority. \n";
		cout<<"\n Choose your option: ";
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"Enter Record Vaue andd Priority: ";
				cin>>value>>priority;
				insert(&rear,&front,value,priority);
	      		cout<<endl<<endl;
	      break;

			case 2:
				remove(&rear,&front);
				break;

			case 3:
				traverse(front);
				break;
				
			case 4:
				update(&rear,&front);
				break;

			default:	 
			   exit(1);
		}
	}while(op!=5);
	
	return 0;
}
