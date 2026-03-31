#include<iostream>
namespace Queue_implementation
{
struct Qnode
	{
		int data ;
		Qnode* next;
		Qnode(int d)
		{
			data = d;
			next = NULL;
		}
	};
  struct Queue{
		Qnode* front;
		Qnode* rear;
		Queue(){
			front = NULL;
			rear = NULL;
		}
	
  };
  
  
   struct Queuearr
	{
		int Queue[8],front,rear;
		Queuearr()
		{
			Queue[8]= 0;
			front = rear = -1;
		}
		
		
	};
  
}


namespace Queue_implementation//using Linked list
{
	
	
 void enQueue(Queue** obj,int val)
    {
  
        // Create a new LL node
        Qnode *temp =  new Qnode(val);
		if((*obj)->rear == NULL)
		{
			(*obj)->front = (*obj)->rear = temp;
			return;
		}
		
		(*obj)->rear->next = temp;
		(*obj)->rear = temp;
    }
   
    
 void deQueue(Queue** obj)
	 {
	 	
	 	if((*obj)->front == NULL)
			std::cout<<"Cant delete Queue is empty";
			
		else if((*obj)->front == (*obj)->rear)
		{
			Qnode *temp = (*obj)->front;
			int data = (*obj)->front->data;
			std::cout<<"Deleting "<<data;
			(*obj)->front = (*obj)->rear = NULL;
			delete temp;
		}
		
		else
		{
			Qnode *temp = (*obj)->front;
			int data = (*obj)->front->data;
			std::cout<<"Deleting "<<data;
			(*obj)->front= (*obj)->front->next;
			delete temp;
			
		}
		
 	}
  
    
 void display(Queue* obj)
	{
		Qnode* Front = obj->front; //Coz structure is passed and inside value of front should be copied
		if(Front == NULL)
		{
				std::cout<<"\n Empty Queue";
				return;
			}
		while( Front != NULL)
			{
				std::cout<<"\n"<<Front->data;
				Front = Front->next;
			}
	}
	
	
void  reverse(Qnode* node)
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


void  search(Queue* obj)//function to traverse the list
	{   Qnode* n = obj->front;
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


int  size(Queue* obj)
	{
		Qnode* temp = obj->front;
		int count = 0;
		while(temp!=NULL)
		{
			count++;
			temp = temp->next;
		}
		delete temp;
		
		return count;
	}


}


namespace Queue_implementation//Double ended Queue using Linked list
{
	

    void enQueuefromfront(Queue** obj,int val)
    {
  
        // Create a new LL node
        Qnode *temp =  new Qnode(val);
		if((*obj)->front == NULL)
		{
			(*obj)->front = (*obj)->rear = temp;
			return;
		}
		temp->next = (*obj)->front;
		(*obj)->front = temp;
    }
   
    
 	void deQueuefromrear(Queue** obj)
	 {
	 	
	 	if((*obj)->rear == NULL)
			std::cout<<"Cant delete Queue is empty";
			
		else if((*obj)->front == (*obj)->rear)
		{
			Qnode *temp = (*obj)->front;
			int data = (*obj)->front->data;
			std::cout<<"Deleting "<<data;
			(*obj)->front = (*obj)->rear = NULL;
			delete temp;
		}
		
		else
		{
			Qnode *temp = (*obj)->front;
			while(temp->next!=(*obj)->rear)
				temp=temp->next;	
			int data = temp->next->data;
			std::cout<<"Deleting "<<data;
			temp->next=NULL;
			Qnode *tmp = (*obj)->rear;
			(*obj) ->rear= temp;
			delete tmp;
		}
	}
}


namespace Queue_implementation //using array
{
	
	void enQueue(int* q , int data, int* front, int* rear, int size = 8 )
		{
	
			if(*rear== size-1)
				std::cout<<"Queue is full cannot insert element";
			else if(*front == -1)
			{
				(*front)++;
				(*rear)++;
				q[*rear]=data;
			}
			else
			   {
			   		(*rear)++;
			   		q[*rear]=data;
			   		std::cout<<"Data Successfully inserted";
			   }
		}


	void deQueue(int* q ,int* front, int* rear)
	{
		if(*front== -1)
		std::cout<<"Queue empty cannot be deleted";
		else if(*front == *rear)
		{
			std::cout<<"\nDeleting "<< q[*rear];
			q[*rear]=0;
			(*rear) = (*front) = -1;
		}
		else
		{
			std::cout<<"\nDeleting "<< q[*front];
			q[*front]=0;
			(*front)++;
		}
	}


	void reverse(int* q ,int front, int rear)
	{
		if(front == -1)
		std::cout<<"\n Empty queue";
		else
			while(rear >= 0 )
				std::cout<<"\n"<<q[rear--];
	}


	void display(int* q ,int front, int rear)
	{
		if(front == -1)
		std::cout<<"\n Empty Queue";
		else
			while(front <= rear)
				std::cout<<"\n"<<q[front++];
	}
	
	
	void search(int* q ,int front, int rear, int data)
	{
		if(front == -1)
		std::cout<<"\n Empty Queue";
		else
		{
			int flag = 0;
			 while(front!= rear+1)
			{   
				front++;
				if(data == q[front])	
				{ std::cout<<"\n"<<data<<" found at position "<<front+1;
				   flag = 1;
					}	
			}
			if(flag == 0 )
			    std::cout<<"\nData not found";
		}
		
	}
	

	int size(int* q , int rear)
	{
		if(rear == -1)
			std::cout<<"\n Empty Queue";
		return rear+1;
	}
	

}


//namespace Queue_implementation //Circular Queue using array
//{
//	void enQueue(int* q , int data, int* front, int* rear, int size = 8 )
//	{
//
//		if(*rear== size-1)
//			std::cout<<"Queue is full cannot insert element";
//		else if(*front == -1)
//		{
//			(*front)++;
//			(*rear)++;
//			q[*rear]=data;
//		}
//		else
//		   {
//		   		(*rear)++;
//		   		q[*rear]=data;
//		   		std::cout<<"Data Successfully inserted";
//		   }
//	}
//
//
//	void deQueue(int* q ,int* front, int* rear)
//	{
//		if(*front== -1)
//		std::cout<<"Queue empty cannot be deleted";
//		else if(*front == *rear)
//		{
//			std::cout<<"\nDeleting "<< q[*rear];
//			q[*rear]=0;
//			(*rear) = (*front) = -1;
//		}
//		else
//		{
//			std::cout<<"\nDeleting "<< q[*front];
//			q[*front]=0;
//			(*front)++;
//		}
//	}
//
//
//	void reverse(int* q ,int front, int rear)
//	{
//		if(front == -1)
//		std::cout<<"\n Empty queue";
//		else
//			while(rear >= 0 )
//				std::cout<<"\n"<<q[rear--];
//	}
//
//
//	void display(int* q ,int front, int rear)
//	{
//		if(front == -1)
//		std::cout<<"\n Empty Queue";
//		else
//			while(front <= rear)
//				std::cout<<"\n"<<q[front++];
//	}
//	
//	
//	void search(int* q ,int front, int rear, int data)
//	{
//		if(front == -1)
//		std::cout<<"\n Empty Queue";
//		else
//		{
//			int flag = 0;
//			 while(front!= rear+1)
//			{   
//				front++;
//				if(data == q[front])	
//				{ std::cout<<"\n"<<data<<" found at position "<<front+1;
//				   flag = 1;
//					}	
//			}
//			if(flag == 0 )
//			    std::cout<<"\nData not found";
//		}
//		
//	}
//	
//
//	int size(int* q , int rear)
//	{
//		if(rear == -1)
//			std::cout<<"\n Empty Queue";
//		return rear+1;
//	}
//	
//
//}
//


namespace Queue_implementation //Double Ended Queue using array
{
	void enQueuefromfront(int* q , int data, int* front, int* rear, int size = 8 )
	{

		if(*rear== size-1 || front == rear-1)
			std::cout<<"Queue is full cannot insert element";
		
		else if(*front == -1)
		{
			(*front)++;
			(*rear)++;
			q[*rear]=data;
		}
		
		else if (*front > 0 )
		{
			(*front)--;
		   		q[*front]=data;
		   		std::cout<<"Data Successfully inserted";
		}
		else
		   {
				int i = *rear;
				(*rear)++;
		   		while(i>=1)
		   			q[i+1]= q[i--];
		   			
		   		q[0]=data;
		   		std::cout<<"Data Successfully inserted";
		   }
	}


	void deQueuefromrear(int* q ,int* front, int* rear)
	{
		if(*rear== -1)
			std::cout<<"Queue empty cannot be deleted";
		else if(*front == *rear)
		{
			std::cout<<"\nDeleting "<< q[*rear];
			q[*rear]=0;
			(*rear) = (*front) = -1;
		}
		else
		{
			std::cout<<"\nDeleting "<< q[*rear];
			q[*rear]=0;
			(*rear)--;
		}
	}


	
}


