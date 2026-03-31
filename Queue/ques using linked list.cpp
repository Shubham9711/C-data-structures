#include<iostream>
#include<conio.h>
#include"Queue.h"

using namespace Queue_implementation;
int main()
{
	Queue* Qobj = new Queue();//initialize it coz it has only two pointers so while sending it must contain something
    int choice =0;  
    while(choice !=8)  
    {   
	    system("cls");
        std::cout<<"\n1. Insert an element";
		std::cout<<"\n2. Delete an element";
		std::cout<<"\n3 Reverse";
		std::cout<<"\n4. Display";
		std::cout<<"\n5. Search";
		std::cout<<"\n6 Calculate no. of elements in stack";
		std::cout<<"\n7. Exit";  
        std::cout<<"\nEnter your choice?\n";  
        std::cin>>choice;  
        switch(choice)  
        {  
            case 1:  
            	int val;
	         	std::cout<<"\nEnter the data";
			 	std::cin>>val;
			 	enQueue(&Qobj,val);  
			 	break;			
            
            case 2:  
            	deQueue(&Qobj);  
            	break;  
            case 3:  
           	reverse(Qobj->front);  
		           break;  
           case 4:
            	display(Qobj);
				break;
            case 5:  
            	search(Qobj);  
            	break;  
            case 6:  
            	std::cout<<"currently there are "<<size(Qobj)<<" elements in the Queue"; 
            break; 
            case 7:  
            exit(0);  
            break;  
            default:  
            std::cout<<"\nPlease enter valid choice..";  
        }  
        
		getch();
    } 
	delete Qobj;
    return 0;
}  





