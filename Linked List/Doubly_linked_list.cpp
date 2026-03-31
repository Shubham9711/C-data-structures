#include<conio.h>
#include<iostream>
#include"Linklist.h"
using namespace Linked_list;
int main ()  
{  Dnode* start = NULL;
   int choice =0;  
    while(choice !=11)  
    {   
	    system("cls");
        std::cout<<"\n1. Insert in begining";
		std::cout<<"\n2. Insert at last";
		std::cout<<"\n3. Insert at specific index";
		std::cout<<"\n4. Delete from Beginning";
		std::cout<<"\n5. Delete from last";
		std::cout<<"\n6. Delete at specific index";
		std::cout<<"\n7 Reverse";
		std::cout<<"\n8. Display";
		std::cout<<"\n9. Search";
		std::cout<<"\n10 Calculate no. of elements in list";
		std::cout<<"\n11. Exit";  
        std::cout<<"\nEnter your choice?\n";  
        std::cin>>choice;  
        switch(choice)  
        {  
            case 1:  
            	int val;
	         	std::cout<<"\nEnter the data";
			 	std::cin>>val;
			 	insertatbegining(&start,val);  
			 	break;			
            case 2:  
            	int val1;
	            std::cout<<"\nEnter the data";
				std::cin>>val1;
				insertatend(&start,val1);
				break;
			case 3:
			    int val2,index;
	            std::cout<<"\nEnter the data and index";
				std::cin>>val2>>index;
				insertatpos(&start,index,val2);
				break;
				
            case 4:  
            	deletionfrombeg(&start);  
            break;  
            case 5:  
            	deletionfromend(&start);  
            break;  
            case 6:
            	int ind;
	            std::cout<<"\nEnter the index";
				std::cin>>ind;
				deletevalueatindex(&start,ind);
				break;
            case 7:  
            reverse(&start);  
            break;  
            case 8:  
            traverse(start);  
            break; 
			case 9:
			search(start);
			break; 
			case 10:
				std::cout<<"currently there are "<<calcsize(start)<<" elements in the list";
				break;
            case 11:  
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

