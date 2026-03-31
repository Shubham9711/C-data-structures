#include<iostream>
namespace Linked_list//Linked list nodes and function declarations
{


	typedef struct Node 
{
	int data;
	Node* next;
	Node()
	{
	data = 0;
	next =NULL;
	}
	Node(int d)
	{
		data = d;
		next =NULL;
	}

}node; 


typedef struct doubly_linked_list
{
	int data;
	doubly_linked_list *previous;
	doubly_linked_list* next;
	doubly_linked_list()
	{
		data = 0;
		previous = NULL;
		next = NULL;
	}
		
}Dnode;




//singlyLinkedlist
void insertatbegining( node** n,int val);
void insertatend( node** n,int val);
void insertatpos(node** n,int pos,int data);
void deletionfrombeg(node** tmp );
void deletionfromend(node** tmp );
void deletevalueatindex(node** n,int pos);
void reverse(node** n);
void traverse(node* n);
void traverseRecRev(node* n);//print in rev using recursion;
void traverseRec(node* n);
void search(node* n);
int calcsize(node *n);
int calcsizerec(node *n);//calculate size recursively
//Doublylinkedlist
void insertatbegining( Dnode** n,int val);
void insertatend( Dnode** n,int val);
void insertatpos(Dnode** n,int pos,int data);
void deletionfrombeg(Dnode** tmp );
void deletionfromend(Dnode** tmp );
void deletevalueatindex(Dnode** n,int pos);
void reverse(Dnode** n);
void traverse(Dnode* n);
void search(Dnode* n);
int calcsize(Dnode *n);
//Circularsinglylist
void cinsertatbegining( node** n,int val);
void cinsertatend( node** n,int val);
void cinsertatpos(node** n,int pos,int data);
void cdeletionfrombeg(node** tmp );
void cdeletionfromend(node** tmp );
void cdeletevalueatindex(node** n,int pos);
void creverse(node** n);
void ctraverse(node* n);
void csearch(node* n);
int ccalcsize(node *n);
//Circulardoublylinkedlist
void cinsertatbegining( Dnode** n,int val);
void cinsertatend( Dnode** n,int val);
void cinsertatpos(Dnode** n,int pos,int data);
void cdeletionfrombeg(Dnode** tmp );
void cdeletionfromend(Dnode** tmp );
void cdeletevalueatindex(Dnode** n,int pos);
void creverse(Dnode** n);
void ctraverse(Dnode* n);
void csearch(Dnode* n);
int ccalcsize(Dnode *n);




}

 
namespace Linked_list  //SINGLYLISTFUNCTIONS
{
		
	void  insertatbegining( node** n,int val)//double pointer is use as node * is itself storing node type pointer 
	{                            // so we need to store its address
		node* temp =new node();
	    temp->data=val;
	    temp->next=(*n);
	    *n=temp;
	    std::cout<<"Node Successfully inserted";
	}
	
	
	void  insertatend( node** n,int val)//double pointer is use as node * is itself storing node type pointer 
	{                           // so we need to store its address
	    node* temp =new node();
	    temp->data=val;
	    temp->next=NULL;
	    if(*n == NULL)
	       *n=temp;
		else
	   	{ 
	    	node* last=*n;//another variable taken to take the address of *n so that my start doesnt change
	   	 	while((last)->next!=NULL)
		 	(last)=(last)->next;
		 	(last)->next=temp;
		 	std::cout<<"Node successfully inserted";
		}	
	}
	
	
	void  insertatpos(node** n,int pos,int data)
	{
		if(*n==NULL)
		{
			std::cout<<"Empty List";
		}	
		else if(pos>(calcsize(*n)+1)||pos<1)
		 {
			std::cout<<"Enter valid index";
		 }		
		else 
		{
			if(pos == 1)
				{
					std::cout<<"you have entered pos 1 so call insertion at begining";
					insertatbegining(n,data);
			}
		 	else if(pos==(calcsize(*n)+1))
				{
				    std::cout<<"you have entered pos 1 greater than size so call insertion at end";
					insertatend(n,data);
				}
			else
			{
				node *temp = *n;
				node* tmp = new node(data);
				int i = 1;
				while(i++!=pos-1)
				{
					temp = temp->next;
				}
				tmp->next=temp->next;
				temp->next=tmp;
				std::cout<<"Node successfully inserted";
			}
		}
	}
	
	
	void deletionfrombeg(node** tmp )//double pointer is use as node * is itself storing node type pointer 
	{                            // so we need to store its address
		if(*tmp==NULL)
		 {
			std::cout<<"Empty List item cannot be deleted";
			return;
		 }
		else
	     {
			node* temp =*tmp;
	    	*tmp = (*tmp)->next;				     	
	     	int d = temp->data;
			 delete temp;
	     	return ;
	      }
	}
	
	
	void  deletionfromend(node** tmp )//double pointer is use as node * is itself storing node type pointer 
	{                          // so we need to store its address
	   if(*tmp==NULL)
		{
			std::cout<<"Empty List item cannot be deleted";
			return;
		}
		else if((*tmp)->next == NULL)
		{
			std::cout<<"\ndeleting "<<(*tmp)->data; 
	     	*tmp = NULL;
		}
		else 
	  	{
	  		node* temp =*tmp;
	  		while(temp->next->next!=NULL)
	  			{
	  				temp = temp->next;
		  		}
	     std::cout<<"\nDeleting "<<temp->next->data; 
	     delete temp->next;
	     temp->next=NULL;
	     }
	}
	
	
	void  deletevalueatindex(node** n,int pos)
	{
		if(*n==NULL)
		 {
			std::cout<<"Empty List";
			return;
		 }	
			
		else if(pos>calcsize(*n)||pos<1)
		{
			std::cout<<"Enter valid index";
		}
		else if(pos == 1)
		{
			std::cout<<"you have entered pos 1 so call deletion at begining";
					deletionfrombeg(n);
		}
		else if(pos==calcsize(*n))
		{
				std::cout<<"you have entered the last pos so call  at end";
				deletionfromend(n);
		}
		 
		else
		{
			node *temp = *n;
			int i = 0;
			while(++i!=pos-1)
				temp = temp->next;
			std::cout<<"\nDeleting "<<temp->next->data;
			temp->next=temp->next->next;
		}
	}
	
	
	void  reverse(node** n) //using list traversal
	{    				     //In this we creating a node and storing its first element then traverse it further and adding
		//the node to its begining in this we the colplexity will n+constant 1
		if(*n==NULL)
		  std::cout<<"empty List";
		else
		{   
		    node* temp = new node;
		    temp->data=(*n)->data;
		    temp->next=NULL;
		    node* last=*n;
	        while((last)->next!=NULL)
		    { 
			  (last)=(last)->next;
		      insertatbegining(&temp,last->data);  
	        }
	        *n=temp;
	        std::cout<<"List is reversed";
		  }  
	}
	
	
	void  traverse(node* n)//function to traverse the list
	{   
	    if(n==NULL)
	    {
	    std::cout<<"empty list";
	    }
		else
	{   while(n!=NULL)
		{
		std::cout<<"\n"<<n->data<<" ";
		n=n->next;
		}
	}
	}
	
	
	void traverseRecRev(node* n)
	{
		if(n==NULL)
			return;
		else
		{
			traverseRecRev(n->next);
			std::cout<<n->data<<"\n";
			return;
		}
	}
	
	
	void traverseRec(node* n)
	{
		if(n==NULL)
			return;
		else
		{
			std::cout<<n->data<<"\n";
			traverseRec(n->next);
			return;
		}
	}
	
	void  search(node* n)//function to traverse the list
	{   
	    int val;
	    int flag = 0;
	    std::cout<<"Enter the value to be searched for";
	    std::cin>>val;
	    int index = 0;
	    if(n==NULL)
	    {
	    std::cout<<"empty list";
	    }
		else
	    {   while(n!=NULL)
			{  
	    		index++; 
				if(val==n->data)	
				{ std::cout<<"\n"<<n->data<<" found at position "<<index;
				   flag = 1;
					}	
				n=n->next;
			}
			if(flag == 0 )
			    std::cout<<"\nData not found";
	}
	}
	
	
	int  calcsize(node *n)
	{
		node *temp;
		int count = 0;
		temp = n;
		while(temp!=NULL)
		{
			count++;
			temp = temp->next;
		}
		delete temp;
		
		return count;
	}

	
	int calcsizerec(node *n)
	{
		if(n==NULL)
			return 0;
		else
		    return 1+calcsizerec(n->next);
	}
}


namespace Linked_list  //DOUBLYLISTFUNCTIONS
{
		
	void  insertatbegining( Dnode** n,int val)//double pointer is use as node * is itself storing node type pointer 
	{                            // so we need to store its address
		Dnode* temp =new Dnode();
	    temp->data=val;
	    temp->next=(*n);
	    if(*n!=NULL)
		(*n) -> previous = temp;
	    *n=temp;
	    std::cout<<"Node successfully inserted";
	}
	
	
	void  insertatend( Dnode** n,int val)//double pointer is use as node * is itself storing node type pointer 
	{                            // so we need to store its address
	    Dnode* temp =new Dnode();
	    temp->data=val;
	    temp->next=NULL;
	    if(*n == NULL)
	       {
	       		temp->previous=NULL;
		   		*n=temp;
		   		
		   }
		else
	   	{ 
	    	Dnode* last=*n;//another variable taken to take the address of *n so that my start doesnt change
	   	 	while((last)->next!=NULL)
		 	(last)=(last)->next;
		 	(last)->next=temp;
		 	temp->previous = last;
		 	std::cout<<"Node successfully inserted";
		}	
	}
	
	
	void  insertatpos(Dnode** n,int pos,int data)
	{
		if(*n==NULL)
		{
			std::cout<<"Empty List";
		}	
		else if(pos>(calcsize(*n)+1)||pos<1)
		 {
			std::cout<<"Enter valid index";
		 }		
		else
		{
			if(pos == 1)
				{
					std::cout<<"you have entered pos 1 so call insertion at begining";
					insertatbegining(n,data);
			}
		 	else if(pos==(calcsize(*n)+1))
				{
				    std::cout<<"you have entered pos 1 greater than size so call insertion at end";
					insertatend(n,data);
				}
			else
			{
				Dnode *temp = *n;
				Dnode* tmp = new Dnode();
				tmp->data = data;
				int i = 1;
				while(i++!=pos)
		        {
				temp = temp->next;
				}
				tmp->next=temp;
				tmp->previous = temp->previous;
				temp->previous->next=tmp;
				temp->previous = tmp;
				std::cout<<"Node successfully inserted";
				
			}
		}
	}
	
	
	void  deletionfrombeg(Dnode** tmp )//double pointer is use as node * is itself storing node type pointer 
	{                            // so we need to store its address
		if(*tmp==NULL)
		 {
			std::cout<<"Empty List item cannot be deleted";
			return;
		 }
		else
	     {
			Dnode* temp =*tmp;
	    	*tmp = (*tmp)->next;
	    	(*tmp)->previous = NULL;
	     	std::cout<<"\ndeleting "<<temp->data; 
	     	delete temp;
	      }
	}
	
	
	void  deletionfromend(Dnode** tmp )//double pointer is use as node * is itself storing node type pointer 
	{                          // so we need to store its address
	   if(*tmp==NULL)
		{
			std::cout<<"Empty List item cannot be deleted";
			return;
		}
		else if((*tmp)->next == NULL)
		{
			std::cout<<"\ndeleting "<<(*tmp)->data; 
	     	*tmp = NULL;
		}
		else 
	  	{
	  		Dnode* temp =*tmp;
	  		while(temp->next!=NULL)
	  			{
	  				temp = temp->next;
		  		}
	     std::cout<<"\nDeleting "<<temp->data; 
	     temp->previous->next=NULL;
	     }
	}
	
	
	void  deletevalueatindex(Dnode** n,int pos)
	{
		if(*n==NULL)
		 {
			std::cout<<"Empty List";
			return;
		 }
		else if(pos>calcsize(*n)||pos<1)
		{
			std::cout<<"Enter valid index";
		}	
		 else if(pos == 1)
		{
			std::cout<<"you have entered pos 1 so call deletion at begining";
					deletionfrombeg(n);
		}
		else if(pos==calcsize(*n))
		{
				std::cout<<"you have entered the last pos so call  at end";
				deletionfromend(n);
		}
		 
		else
		{
			Dnode *temp = *n;
			int i = 1;
			while(i++!=pos)
				temp = temp->next;
			std::cout<<"\nDeleting "<<temp->data;
			temp->next->previous=temp->previous;
			temp->previous->next = temp->next;
			delete temp;
		}
	}
	
	
	void  reverse(Dnode** n) //using list traversal
	{    				     //In this we creating a node and storing its first element then traverse it further and adding
		//the node to its begining in this we the colplexity will n+constant 1
		if(*n==NULL)
		  std::cout<<"empty List";
		else
		{   
		    Dnode* temp = new Dnode();
		    temp->data=(*n)->data;
		    temp->next=NULL;
		    Dnode* last=*n;
	        while((last)->next!=NULL)
		    { 
			  (last)=(last)->next;
		      insertatbegining(&temp,last->data);  
	        }
	        *n=temp;
	        std::cout<<"List reversed";
		  }  
	}
	
	
	void  traverse(Dnode* n)//function to traverse the list
	{   
	    if(n==NULL)
	    {
	    std::cout<<"empty list";
	    }
		else
	{   while(n!=NULL)
		{
		std::cout<<"\n"<<n->data<<" ";
		n=n->next;
		}
	}
	}
	
	
	void  search(Dnode* n)//function to traverse the list
	{   
	    int val;
	    int flag = 0;
	    std::cout<<"Enter the value to be searched for";
	    std::cin>>val;
	    int index = 0;
	    if(n==NULL)
	    {
	    std::cout<<"empty list";
	    }
		else
	    {   while(n!=NULL)
			{  
	    		index++; 
				if(val==n->data)	
				{ std::cout<<"\n"<<n->data<<" found at position "<<index;
				   flag = 1;
					}	
				n=n->next;
			}
			if(flag == 0 )
			    std::cout<<"\nData not found";
	}
	}
	
	
	int  calcsize(Dnode *n)
	{
		Dnode *temp;
		int count = 0;
		temp = n;
		while(temp!=NULL)
		{
			count++;
			temp = temp->next;
		}
		delete temp;
		
		return count;
	}
}


namespace Linked_list  //circularSINGYLISTFUNCTIONS
{
	void  cinsertatbegining( node** n,int val)//double pointer is use as node * is itself storing node type pointer 
	{                            // so we need to store its address
		node* temp =new node();
	    temp->data=val;
	    if(*n==NULL)
	    	{ 
			*n=temp;
			temp->next=*n;
			}
		else
		{
			temp->next=*n;
			node* tmp = *n;
			while(tmp->next!=*n)
				tmp=tmp->next;
			tmp->next=temp;
			(*n)= temp;
		}
		std::cout<<"Node successfully inserted";
	}
	   
	 
	 void  cinsertatend( node** n,int val)//double pointer is use as node * is itself storing node type pointer 
	{                            // so we need to store its address
	
	    node* temp =new node();
	    temp->data=val;
	    if(*n == NULL)
	    {
	     	*n=temp;
	     	temp->next=*n;
		}
		else
	   	{ 
	    	node* last=*n;//another variable taken to take the address of *n so that my start doesnt change
	   	 	while(last->next!=*n)
		 	last=last->next;
		 	last->next=temp;
		 	temp->next = *n;
		}	
		std::cout<<"Node SucessFully Inserted";
	}
	
	
	void  cinsertatpos(node** n,int pos,int data)
	{
		if(*n==NULL)
		{
			std::cout<<"Empty List";
		}	
		else if(pos>(ccalcsize(*n)+1)||pos<1)
		 {
			std::cout<<"Enter valid index";
		 }		
		else 
		{
			if(pos == 1)
				{
					std::cout<<"you have entered pos 1 so call insertion at begining\n";
					cinsertatbegining(n,data);
			}
		 	else if(pos==(ccalcsize(*n)+1))
				{
				    std::cout<<"you have entered pos 1 greater than size so call insertion at end\n";
					cinsertatend(n,data);
				}
			else
			{
				node *temp = *n;
				node* tmp = new node(data);
				int i = 1;
				while(i++!=pos-1)
				{
					temp = temp->next;
				}
				tmp->next=temp->next;
				temp->next=tmp;
				std::cout<<"Node successfully inserted";
			}
		}
	}
	
	
	void  cdeletionfrombeg(node** tmp )//double pointer is use as node * is itself storing node type pointer 
	{                            // so we need to store its address
		if(*tmp==NULL)
		 {
			std::cout<<"Empty List item cannot be deleted";
			return;
		 }
		 else if((*tmp)->next==(*tmp))
			{
				std::cout<<"\ndeleting "<<(*tmp)->data;
				*tmp = NULL;
			}
		else
	     {
			node* temp = *tmp;
			std::cout<<"\ndeleting "<<temp->data; 
	    	while(temp->next!= *tmp)
	    	{
			 temp = temp->next;
			}
			temp->next = (*tmp)->next;
			delete *tmp;
			(*tmp)=temp->next;	
	      }
	}
	
	
	void  cdeletionfromend(node** tmp )//double pointer is use as node * is itself storing node type pointer 
	{                          // so we need to store its address
	   node* temp =*tmp;
	   if(*tmp==NULL)
		{
			std::cout<<"Empty List item cannot be deleted";
			return;
		}
		else if(temp->next == *tmp)
		{
			std::cout<<"\ndeleting "<<temp->data; 
	     	*tmp = NULL;
		}
		else 
	  	{
	  		while(temp->next->next!=*tmp)
	  			{
	  				temp = temp->next;
		  		}
	     std::cout<<"\nDeleting "<<temp->next->data; 
	     delete temp->next;
		 temp->next=*tmp;
	     }
	}
	
	
	void  cdeletevalueatindex(node** n,int pos)
	{
	    if(*n==NULL)
		 {
			std::cout<<"Empty List";
			return;
		 }	
		else if(pos>ccalcsize(*n)||pos<1)
		{
			std::cout<<"Enter valid index";
		}	 
		else if(pos == 1)
		{
			std::cout<<"you have entered pos 1 so call deletion at begining\n";
					cdeletionfrombeg(n);
		}
		else if(pos==ccalcsize(*n))
		{
				std::cout<<"you have entered the last pos so call  at end\n";
				cdeletionfromend(n);
		}
		 
		else
		{
			node *temp = *n;
			int i = 0;
			while(++i!=pos-1)
				temp = temp->next;
			std::cout<<"\nDeleting "<<temp->next->data;
	        node*ptr = temp->next;
			temp->next=temp->next->next;
			delete ptr;
		}
	}
	
	
	 void  creverse(node** n) //using list traversal
	{    				     //In this we creating a node and storing its first element then traverse it further and adding
		//the node to its begining in this we the colplexity will n+constant 1
		if(*n==NULL)
		  std::cout<<"empty List";
		else
		{   
		    node* temp= NULL;
		    node* last=*n;
	        cinsertatbegining(&temp,last->data);
			while((last)->next!=*n)
		    { 
			  (last)=(last)->next;
		      cinsertatbegining(&temp,last->data);
			}
	        *n=temp;
	        std::cout<<"\nList reversed";
		  }  
	}
	 
	   
	void  ctraverse(node* n)//function to traverse the list
	{   
		node* tmp = n;
	    if(n==NULL)
	    {
	    std::cout<<"empty list";
	    }
		else
		{   while(tmp->next!=n)
			{
				std::cout<<"\n"<<tmp->data<<" ";
				tmp=tmp->next;
			}
			std::cout<<"\n"<<tmp->data<<" ";//coz we have written temp->next is not equal to n 
			                           //due to which node at which next=n that data will not be printed
		}
	}
	
	
	void  csearch(node* n)//function to traverse the list
	{   
	    node* tmp = n;
	    int val;
	    int flag = 0;
	    std::cout<<"Enter the value to be searched for";
	    std::cin>>val;
	    int index = 0;
	    if(n==NULL)
	    {
	    std::cout<<"empty list";
	    }
		else
	    {   while(tmp->next!=n)
			{  
	    		index++; 
				if(val==tmp->data)	
				{ std::cout<<"\n"<<tmp->data<<" found at position "<<index;
				   flag = 1;
				}	
				tmp=tmp->next;
			}
			index++;
			if(val==tmp->data)	
				{ std::cout<<"\n"<<tmp->data<<" found at position "<<index;
				   flag = 1;
				}	
			if(flag == 0 )
			    std::cout<<"\nData not found";
	    }
	}
	
	
	int  ccalcsize(node *n)
	{
		int count = 1;
		if(n==NULL)
		return 0;
		else
		{
			node *temp = n;
			while(temp->next!=n)
			{
				count++;
				temp = temp->next;
			}
		return count;
		}
	}
}


namespace Linked_list  //circularSINGYLISTFUNCTIONS
{
	void  cinsertatbegining( Dnode** n,int val)//double pointer is use as node * is itself storing node type pointer 
	{                            // so we need to store its address
		Dnode* temp =new Dnode();
	     temp->data=val;
	    if(*n==NULL)
	    	{ 
			*n=temp;
			temp->next=*n;
			temp->previous = *n;
			}
		else
		{
			temp->next=*n;
			temp->previous = (*n)->previous;
			(*n)->previous->next = temp;
			(*n)->previous=temp;
			(*n) = temp;
			
		}
		std::cout<<"Node successfully inserted";
	}
	
	
	 void  cinsertatend( Dnode** n,int val)//double pointer is use as node * is itself storing node type pointer 
	{                            // so we need to store its address
	
	    Dnode* temp =new Dnode();
	    temp->data=val;
	    if(*n == NULL)
	    {
	     	*n=temp;
	     	temp->next=*n;
	     	temp->previous=*n;
		}
		else
	   	{ 
	        temp->previous=(*n)->previous;
	        temp->next = *n;
	   	 	(*n)->previous->next = temp;
		 	(*n)->previous = temp;
		}	
		std::cout<<"Node SucessFully Inserted";
	}
	
	
	void  cinsertatpos(Dnode** n,int pos,int data)
	{
		if(*n==NULL)
		{
			std::cout<<"Empty List";
		}	
		else if(pos>(ccalcsize(*n)+1)||pos<1)
		 {
			std::cout<<"Enter valid index";
		 }		
		else 
		{
			if(pos == 1)
				{
					std::cout<<"you have entered pos 1 so call insertion at begining\n";
					cinsertatbegining(n,data);
			}
		 	else if(pos==(ccalcsize(*n)+1))
				{
				    std::cout<<"you have entered pos 1 greater than size so call insertion at end\n";
					cinsertatend(n,data);
				}
			else
			{
				Dnode *temp = *n;
				Dnode* tmp = new Dnode();
				tmp->data = data;
				int i = 1;
				while(i++!=pos-1)
				{
					temp = temp->next;
				}
				tmp->next=temp->next;
				tmp->previous=temp;
				temp->next->previous=tmp;
				temp->next=tmp;
				std::cout<<"Node successfully inserted";
			}
		}
	}
	
	
	void  cdeletionfrombeg(Dnode** tmp )//double pointer is use as node * is itself storing node type pointer 
	{                            // so we need to store its address
		if(*tmp==NULL)
		 {
			std::cout<<"Empty List item cannot be deleted";
			return;
		 }
		 else if((*tmp)->next==(*tmp))
			{
				std::cout<<"\ndeleting "<<(*tmp)->data;
				*tmp = NULL;
			}
		else
	     {
			Dnode* temp = (*tmp);
			std::cout<<"\ndeleting "<<temp->data; 
		    temp=(*tmp)->next;
	        (*tmp)->next->previous = (*tmp)->previous;
	        (*tmp)->previous->next = (*tmp)->next;
			delete *tmp;
			(*tmp)=temp;	
	      }
	}
	
	
	void  cdeletionfromend(Dnode** tmp )//double pointer is use as node * is itself storing node type pointer 
	{                          // so we need to store its address
	   Dnode* temp =*tmp;
	   if(*tmp==NULL)
		{
			std::cout<<"Empty List item cannot be deleted";
			return;
		}
		else if(temp->next == *tmp)
		{
			std::cout<<"\ndeleting "<<temp->data; 
	     	*tmp = NULL;
		}
		else 
	  	{
	  	 
		 Dnode* temp =(*tmp)->previous;
	     std::cout<<"\nDeleting "<<(*tmp)->previous->data;
	     (*tmp)->previous->previous->next = *tmp;
	     (*tmp)->previous = (*tmp)->previous->previous;
	     delete temp;
		 
	     }
	}
	
	
	void  cdeletevalueatindex(Dnode** n,int pos)
	{
	    if(*n==NULL)
		 {
			std::cout<<"Empty List";
			return;
		 }	
		else if(pos>ccalcsize(*n)||pos<1)
		{
			std::cout<<"Enter valid index";
		}	 
		else if(pos == 1)
		{
			std::cout<<"you have entered pos 1 so call deletion at begining\n";
					cdeletionfrombeg(n);
		}
		else if(pos==ccalcsize(*n))
		{
				std::cout<<"you have entered the last pos so call  at end\n";
				cdeletionfromend(n);
		}
		 
		else
		{
			Dnode *temp = *n;
			int i = 0;
			while(++i!=pos-1)
				temp = temp->next;
			std::cout<<"\nDeleting "<<temp->next->data;
			Dnode* ptr = temp->next;
	    	temp->next->next->previous=temp;
	    	temp->next=temp->next->next;
	    	delete ptr;
		}
	}
	
	
	void  creverse(Dnode** n) //using list traversal
	{    				     //In this we creating a node and storing its first element then traverse it further and adding
		//the node to its begining in this we the colplexity will n+constant 1
		if(*n==NULL)
		  std::cout<<"empty List";
		else
		{   
		    Dnode* temp= NULL;
		    Dnode* last=*n;
	        cinsertatbegining(&temp,last->data);
			while((last)->next!=*n)
		    { 
			  (last)=(last)->next;
		      cinsertatbegining(&temp,last->data);
			}
	        *n=temp;
	        std::cout<<"\nList reversed";
		  }  
	}
	 
	 
	void  ctraverse(Dnode* n)//function to traverse the list
	{   
		Dnode* tmp = n;
	    if(n==NULL)
	    {
	    std::cout<<"empty list";
	    }
		else
		{   while(tmp->next!=n)
			{
				std::cout<<"\n"<<tmp->data<<" ";
				tmp=tmp->next;
			}
			std::cout<<"\n"<<tmp->data<<" ";//coz we have written temp->next is not equal to n 
			                           //due to which node at which next=n that data will not be printed
		}
	}
	
	
	void  csearch(Dnode* n)//function to traverse the list
	{   
	    Dnode* tmp = n;
	    int val;
	    int flag = 0;
	    std::cout<<"Enter the value to be searched for";
	    std::cin>>val;
	    int index = 0;
	    if(n==NULL)
	    {
	    std::cout<<"empty list";
	    }
		else
	    {   while(tmp->next!=n)
			{  
	    		index++; 
				if(val==tmp->data)	
				{ std::cout<<"\n"<<tmp->data<<" found at position "<<index;
				   flag = 1;
				}	
				tmp=tmp->next;
			}
			index++;
			if(val==tmp->data)	
				{ std::cout<<"\n"<<tmp->data<<" found at position "<<index;
				   flag = 1;
				}	
			if(flag == 0 )
			    std::cout<<"\nData not found";
	    }
	
	}
	
	
	int  ccalcsize(Dnode *n)
	{
		int count = 1;
		if(n==NULL)
		return 0;
		else
		{
			Dnode *temp = n;
			while(temp->next!=n)
			{
				count++;
				temp = temp->next;
			}
		return count;
		}
	}
}
