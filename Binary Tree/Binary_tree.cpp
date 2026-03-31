#include<iostream>
#include"BTree.h"
#include<conio.h>


//Driver code
int main()
{
	node* root = NULL;
	
		for(int i = 0; i< 17;i++)
			{
				insert(&root,i);
			
			}
		 int choice =0;  
    while(choice !=11)  
    {   
	    //system("cls");
        std::cout<<"\n1. Deleterightmost node";
		std::cout<<"\n2. delete";
		std::cout<<"\n3. Delete from root";
		std::cout<<"\n4. Delete right";
		std::cout<<"\n5. levelorder";
		std::cout<<"\n6. Inorder";
		std::cout<<"\n7 Preorder";
		std::cout<<"\n8. Postorder";
		std::cout<<"\n9. update elements with sum of subtree";
		std::cout<<"\n10. sum of all nodes";
		std::cout<<"\n11. printleaf";
		std::cout<<"\n12. iscomplete";
		std::cout<<"\n13. print all nodes having right child but not left";
		std::cout<<"\n14. printancestors";
		std::cout<<"\n15. print all root to leaf path";
		std::cout<<"\n16. hieght";
		std::cout<<"\n17. diameter";
		std::cout<<"\n18. LCA of bt";
		std::cout<<"\n19. printleftview";
		std::cout<<"\n20. printrightview";
		std::cout<<"\n21. Identical tress or not";
		
		std::cout<<"\n22. Exit";  
        std::cout<<"\nEnter your choice?\n";  
        std::cin>>choice;  
        switch(choice)  
        {  
            case 1:
            	break;
            case 2:std::cout<<"Enter the values";
				int data;
				std::cin>>data;
				Delete(&root,data);
            	break;
            	
            case 3:Delete_from_root(&root);
            	break;
            case 4:Delete_right(&root);
            	break;
            case 5:levelorder(root);
            	break;
            case 6:inorder(root);
            	break;
            case 7:preorder(root);
            	break;
            case 8:postorder(root);
            	break;
            case 9:upadate_all_nodes_with_sum_sub_tree(&root);
            	break;
            case 10:std::cout<<sum_of_all_nodes(root);
            	break;
            case 11:printleaf(root);
            	break;
            case 12:std::cout<<isComplete(root);//doubt
            	break;
            case 13:print_nodes_having_right_child_but_not_left(root);
            	break;
            case 14:
            	std::cout<<"Enter the values";
				int val;
				std::cin>>val;
				printAncestors(root,  val);
            	break;
            case 15:print_All_root_to_leaf(root);
            	break;
            case 16:std::cout<<hieght_of_BT(root);
            	break;
            case 17:std::cout<<Diameter_of_BT(root);
            	break;
            case 18:
				std::cout<<"Enter the values";
				int d1,d2;
				std::cin>>d1>>d2;				
//				node* rt = LCA_BT(root,d1,d2 );
				std::cout<<LCA_BT(root,d1,d2 )->data;
            	break;
            case 19:print_left_view(root);
            	break;
            case 20:print_Right_view(root);
            	break;
            case 21:std::cout<< identical_trees_or_not(root ,root);
            	break;
            case 22:
            	exit(0);
            	break;
            default:  
            std::cout<<"\nPlease enter valid choice..";  
        }  
        getch();
    } 
		
		
	
	
	return 0;
}






