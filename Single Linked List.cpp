//single linked list

#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

typedef struct student{
	char name[20],roll[10], branch[10];
	int id,sem;
	struct student *next;
} list;

list *start, *node , *current_node;
int i, option, n, loc;
	
void create(list *node)
{
	cout<<endl<<"Enter no. of students: ";
	cin>>n;
	cout<<endl;
	i=0;
	while(i<n-1)
	{
		cout<<"Name: ";
		cin>>node->name;
		cout<<"Roll no: ";
		cin>>node->roll;
		cout<<"Branch: ";
		cin>>node->branch;
		cout<<"Semester: ";
		cin>>node->sem;
		cout<<endl;
		node->id = i;
		node->next=(list*)new list;
		node=node->next;
		i++;
	}
	cout<<"Name: ";
	cin>>node->name;
	cout<<"Roll no: ";
	cin>>node->roll;
	cout<<"Branch: ";
	cin>>node->branch;
	cout<<"Semester: ";
	cin>>node->sem;
	cout<<endl;
	node->id = n-1;
	node->next='\0';
}

void traversal(list *start)
{
	while(start)
	{
		if(start==NULL)
		{
			cout<<"Linked List does not exist!";
			exit(0);
		}
		cout<<endl;
		cout<<"Node ID: "<<start->id<<endl;
		cout<<"Name: "<<start->name<<endl;
		cout<<"Roll no: "<<start->roll<<endl;
		cout<<"Branch: "<<start->branch<<endl;
		cout<<"Semester: "<<start->sem<<endl<<endl;
		start=start->next;
	}
}

void insert_node(list *start)
{
	
	current_node = start;
	cout<<"Enter Node ID after which you want to insert new node:";
	cin>>loc;
	while(current_node->id!=loc&&current_node!=NULL)
		current_node=current_node->next;
	if(current_node==NULL) {
	   cout<<"\n The element after which you want to insert does not exist:";
	   exit(0);
	}
	list *newnode;
	newnode=(list *)new list;
	cout<<"Name: ";
	cin>>newnode->name;
	cout<<"Roll no: ";
	cin>>newnode->roll;
	cout<<"Branch: ";
	cin>>newnode->branch;
	cout<<"Semester: ";
	cin>>newnode->sem;
	cout<<endl;
	newnode->next=current_node->next;
	current_node->next=newnode;
	
	i=0;
	while(start)
	{
		if(start==NULL)
		{
			cout<<"Linked List does not exist!";
			exit(0);
		}
		start->id=i;
		i++;
		start=start->next;
	}
}

void delete_node(list *start)
{
	list *temp;
	current_node = start;
	cout<<"Enter Node's ID which you want to delete:";
	cin>>loc;
	while(current_node->id!=loc&&current_node!=NULL)
		current_node=current_node->next;
	if(current_node==NULL) {
	   cout<<"\n The Node which you want to deletet does not exist:";
	   exit(0);
	}
	temp = current_node;
	
	current_node=start;
	while(current_node->id!=loc-1&&current_node!=NULL)
		current_node=current_node->next;
	if(current_node==NULL) {
	   cout<<"\n The Node which you want to deletet does not exist:";
	   exit(0);
	}
	current_node = temp->next;
	free(temp);
} 

void update(list * start)
{
	current_node = start;
	cout<<"Enter Node ID you want to update:";
	cin>>loc;
	while(current_node->id!=loc&&current_node!=NULL)
		current_node=current_node->next;
	if(current_node==NULL) {
	   cout<<"\n The element after which you want to insert does not exist:";
	   exit(0);
	}
	cout<<"Name: ";
	cin>>current_node->name;
	cout<<"Roll no: ";
	cin>>current_node->roll;
	cout<<"Branch: ";
	cin>>current_node->branch;
	cout<<"Semester: ";
	cin>>current_node->sem;
	cout<<endl;
}

void search(list *start)
{
	current_node = start;
	cout<<"Enter Node ID  you want to search:";
	cin>>loc;
	while(current_node->id!=loc&&current_node!=NULL)
		current_node=current_node->next;
	if(current_node==NULL) {
	   cout<<"\n The element after which you want to insert does not exist:";
	   exit(0);
	}
	cout<<"Node ID: "<<current_node->id<<endl;
	cout<<"Name: "<<current_node->name<<endl;
	cout<<"Roll no: "<<current_node->roll<<endl;
	cout<<"Branch: "<<current_node->branch<<endl;
	cout<<"Semester: "<<current_node->sem<<endl;
}

void generate(list *start)
{
	char xbranch[10];
	int op,xsem,x;
	cout<<"Generate Report according to Brannch or Semester: ";
	cin>>op;
	if(op==1)
	{
		cout<<"Enter Branch Name: ";
		cin>>xbranch;
		while(start)
		{	
			x=strcmp(xbranch,start->branch);
			if(x==0 && start!=NULL)
			{
				cout<<"Node ID: "<<start->id<<endl;
				cout<<"Name: "<<start->name<<endl;
				cout<<"Roll no: "<<start->roll<<endl;
				cout<<"Branch: "<<start->branch<<endl;
				cout<<"Semester: "<<start->sem<<endl<<endl;	
			}
			start=start->next;	
		}
	}
	else if(op==2)
	{
		cout<<"Enter Semester: ";
		cin>>xsem;
		while(start)
		{	
			if(start->sem==xsem && start!=NULL)
			{
				cout<<"Node ID: "<<start->id<<endl;
				cout<<"Name: "<<start->name<<endl;
				cout<<"Roll no: "<<start->roll<<endl;
				cout<<"Branch: "<<start->branch<<endl;
				cout<<"Semester: "<<start->sem<<endl<<endl;	
			}
			start=start->next;	
		}
	}
	else
	{
		exit(1);
	}
}

int main()	
{
	cout<<"Student Database\n\n";
	cout<<"1. Create a list\n";
	cout<<"2. Traverse the list\n";
	cout<<"3. Insert a record \n";
	cout<<"4. Delete a record \n";
	cout<<"5. Update a record \n";
	cout<<"6. Search a record \n";
	cout<<"7. Report Generation \n";
	cout<<"8. Exit \n";
	
	
	node=(list *) malloc(sizeof(list));
	start=node;
	
	do{
		cout<<"Choose your option: ";
		cin>>option;
		
		switch(option)
		{
			case 1:
				{
					create(node);
				}
				break;
			case 2:
				{
					traversal(node);		
				}
				break;
			case 3:
				{
					insert_node(start);	
				}
				break;
			case 4:
				{
					delete_node(start);
				}
				break;
			case 5:
				{
					update(start);
				}
				break;
			case 6:
				{
					search(start);
				}
				break;
			case 7:
				{
					generate(start);
				}
				break;
				default: 
					exit(0);
		}
		cout<<endl;
	}while(option>0&&option<8);
	
	return 0;
}
	
	

