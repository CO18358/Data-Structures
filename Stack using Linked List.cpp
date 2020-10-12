#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct record {
	int info;
	struct record *next;
} slist;
slist *node, * top;
int op, num;

void push(int data) 
{  
    node = new slist(); 
  
    if (!node) { 
        cout << endl<<"Stack Overflow"; 
        exit(1); 
    } 
    node->info = data;
    node->next = top; 
    top = node; 
} 
  
int pop() 
{ 
	int e;
    if (top == NULL) { 
        cout << "\nStack Underflow" << endl; 
        exit(1); 
    } 
    else { 
        node = top; 
        e = node->info;
        top = top->next;  
        node->next = NULL;  
        free(node);
		return (e); 
    } 
} 

void display()  
{ 
    if (top == NULL) { 
        cout << "\nStack Underflow"; 
        exit(1); 
    } 
    else { 
        node = top; 
        cout<<"Elements of Stack are: ";
        while (node != NULL) 
		{ 
            cout<< node->info<<endl; 
            node = node->next; 
        } 
    } 
} 

int main()
{
	top = NULL;
		do{	
		cout<<endl;
 		cout<<"1. PUSH an element"<<endl;
	 	cout<<"2. POP an element"<<endl;
		cout<<"3. Display Stack"<<endl;
		//cout<<"4. Peep an element"<<endl;
		cout<<endl<<"Choose your option: ";
		cin>>op;
		cout<<endl;
		
		switch(op)
		{
				case 1:
					{	cout<<"Enter Value of Element:";
						cin>>num;
						push(num);	
					}
					break;
				case 2:
					{
						num =pop();
						cout<<"Element: "<<num<<" popped out.";
					}
					break;
				case 3:
					{
						display();
					}	
					break;
				/*case 4: 
					{
						cout<<"Enter element you wish to peep: ";
						cin>>num;
						//peep(num);
					}*/
				default:
					exit(0);
			}
	}while(op!=4);
	
	return 0;
}

