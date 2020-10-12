#include<iostream>
#include<cstdlib>
#include"untitled3.h"
#include"untitled4.h"
#include"untitled5.h"
#include"untitled6.h"
#include"untitled7.h"
#include"untitled8.h"
#include"untitled9.h"
#include"untitled11.h"
#include"untitled12.h"

using namespace std;

int main()
{
	int op; 
	
	cout<<"1. Student Record System using Array of Structures"<<endl;
	cout<<"2. Student Record System using Singly Linked List"<<endl;
	cout<<"3. Student Record System using Doubly Linked List"<<endl;
	cout<<"4. Matrix Operations using pointers"<<endl;
	cout<<"5. Implentation of Stack using Array"<<endl;
	cout<<"6. Implentation of Stack using Singly Linked List"<<endl;
	cout<<"7. Implentation of Circular Queue using Array"<<endl;
	cout<<"8. Implentation of Priority Queue using Doubly Linked List"<<endl;
	cout<<"9. Implentation of Binary Tree"<<endl;
	
	do{
		cout<<"Choose your option: ";
		cin>>op;
		switch(op)
		{
			case 1:
				main_3();
				break;
			case 2:
				main_4();
				break;
			case 3:
				main_5();
				break;
			case 4:
				main_6();
				break;
			case 5:
				main_7();
				break;
			case 6:
				main_8();
				break;
			case 7:
				main_9();
				break;
			case 8:
				main_11();
				break;
			case 9:
				main_12();
				break;
			default:
				exit (0);
		}
	}while(op!=10);
	return 0;
	
}
