#include"stackh.h"
#include<iostream>
#include<conio.h>
using namespace stack_implementation;
int main()
{
	starr* start = new starr();
   int choice =0;  
    while(choice !=8)  
    {   
	    system("cls");
        std::cout<<"\n1. Insert an element";
		std::cout<<"\n2. Delete an element";
		std::cout<<"\n3 Reverse";
		std::cout<<"\n4. Display";
		std::cout<<"\n5. Search";
		std::cout<<"\n6. Get element at pos";
		std::cout<<"\n7 Calculate no. of elements in stack";
		std::cout<<"\n8. Exit";  
        std::cout<<"\nEnter your choice?\n";  
        std::cin>>choice;  
        switch(choice)  
        {  
            case 1:  
            	int val;
	         	std::cout<<"\nEnter the data";
			 	std::cin>>val;
			 	push(start->stack,val,&start->top);  
			 	break;			
            
            case 2:  
            	pop(start->stack,&start->top);  
            break;  
            case 3:  
            	reverse(start->stack,start->top);  
            break;  
            case 4:
            	display(start->stack,start->top);
				break;
            case 5:  
                int val1;
	         	std::cout<<"\nEnter the data to be searched for";
			 	std::cin>>val1;
            	search(start->stack,start->top,val1);  
            break;  
            case 7:  
            	std::cout<<"currently there are "<<size(start->top)<<" elements in the stack"; 
            break; 
            case 8:  
            exit(0);  
            break;  
            default:  
            std::cout<<"\nPlease enter valid choice..";  
        }  
        
		getch();
    } 
	delete start; 
    return 0;
}  




