#include<iostream>
namespace stack_implementation
{
   
    typedef struct Stack
	{
		int data;
		Stack* next;
	}st;
	
	typedef struct Stackarr
	{
		int stack[8],top;
		Stackarr()
		{
			stack[8]=0;
			top = -1;
		}
		
		
	}starr;

	
}


namespace stack_implementation //using Linked list
{
		void  push(st** top,int val)
	{
		st* temp =new st();
	    temp->data=val;
	    temp->next=(*top);
	    *top=temp;
	    std::cout<<"Data Successfully inserted";
	}
	
	
	void   pop(st** top)
	{                          
		if(*top==NULL)
		 {
			std::cout<<"Empty stack item cannot be deleted";
			return;
		 }
		else
	     {
			st* temp =*top;
	    	*top = (*top)->next;
	     	std::cout<<"\ndeleting "<<temp->data; 
	     	delete temp;
	      }	     
	}
	
	
	void  reverse(st* node)
	{
		if(node==NULL)
			return;
		else
		{
			reverse(node->next);
			std::cout<<node->data<<"\n";
			return;
		}

	}
	
	
	void  display(st* top)
	{
		if(top==NULL)
	    {
	    std::cout<<"empty list";
	    }
		else
		{   
			while(top!=NULL)
				{
					std::cout<<"\n"<<top->data<<" ";
					top=top->next;
				}
		}
	}


	void  search(st* n)//function to traverse the list
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
	
	
//	int  get(st* node);


	int  size(st *n)
	{
		st *temp;
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


namespace stack_implementation //using array
{
	void push(int* stack,int data,int* top,int size = 8 )
	{

		if(*top== size-1)
			std::cout<<"Stack is full cannot insert element";
		else
		   {
		   		(*top)++;
		   		stack[*top]=data;
		   		std::cout<<"Data Successfully inserted";
		   }
	}


	void pop(int* stack,int* top,int size = 8)
	{
		if(*top == -1)
		std::cout<<"Stack empty cannot be deleted";
		else
		{
			std::cout<<"\nDeleting "<< stack[*top];
			stack[*top]=0;
			(*top)--;
		}
	}


	void reverse(int* stack,int top)
	{
		if(top == -1)
		std::cout<<"\n Empty stack";
		else
			for(int i=0;i<=top;i++)
				std::cout<<"\n"<<stack[i];
	}


	void display(int* stack,int top)
	{
		if(top == -1)
		std::cout<<"\n Empty stack";
		else
			while(top>=0)
				std::cout<<"\n"<<stack[top--];
	}
	
	
	void search(int* stack,int top,int data)
	{
		if(top == -1)
		std::cout<<"\n Empty stack";
		else
		{
			int flag = 0;
			 while(top!= -1)
			{   
				top--;
				if(data==stack[top])	
				{ std::cout<<"\n"<<data<<" found at position "<<top;
				   flag = 1;
					}	
			}
			if(flag == 0 )
			    std::cout<<"\nData not found";
		}
		
	}
	
	
//	int get(int* stack);


	int size(int top)
	{
		if(top == -1)
			std::cout<<"\n Empty Stack";
		return top;
	}
	

}
