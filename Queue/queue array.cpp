#include"Queue.h"
#include<iostream>
#include<conio.h>
using namespace Queue_implementation;
int main()
{
	Queuearr* q = new Queuearr();
   int choice =0;  
    while(choice !=8)  
    {   
	    system("cls");
        std::cout<<"\n1. Insert an element";
		std::cout<<"\n2. Delete an element";
		std::cout<<"\n3 Reverse";
		std::cout<<"\n4. Display";
		std::cout<<"\n5. Search";
		std::cout<<"\n6. Calculate no. of elements in Queue";
		std::cout<<"\n7. Exit";  
        std::cout<<"\nEnter your choice?\n";  
        std::cin>>choice;  
        switch(choice)  
        {  
            case 1:  
            	int val;
	         	std::cout<<"\nEnter the data";
			 	std::cin>>val;
			 	enQueuefromfront(q->Queue,val,&q->front,&q->rear);  
			 	break;			
            
            case 2:  
            	deQueuefromrear(q->Queue,&q->front,&q->rear);  
            break;  
            case 3:  
            	reverse(q->Queue,q->front,q->rear);  
            break;  
            case 4:
            	display(q->Queue,q->front,q->rear);
				break;
            case 5:  
                int val1;
	         	std::cout<<"\nEnter the data to be searched for";
			 	std::cin>>val1;
            	search(q->Queue,q->front,q->rear,val1);  
            break;  
            case 6:  
            	std::cout<<"currently there are "<<size(q->Queue , q->rear)<<" elements in the Queue"; 
            break; 
            case 7:  
            exit(0);  
            break;  
            default:  
            std::cout<<"\nPlease enter valid choice..";  
        }  
        
		getch();
    } 
	delete q; 
    return 0;
}  





