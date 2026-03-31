#include<bits/stdc++.h>


struct node{
	
	int data;
	node* left;
	node* right;
	
	node(){
		data = 0;
		left = NULL;
		right = NULL;
	}
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};


void insert(node** temp,int data)//using level order travesal
{
	//Level Order traversal to insert node in a tree

	node* t = new node(data);
	
	if(*temp == NULL)
		{
			*temp = t;
			std::cout<<"\nData inserted successfully"; 
			return;
		}
		
    std::queue<node*> q;
	q.push(*temp);
	
	while(!q.empty())
	{
		node* tmp = q.front();
		 q.pop();
		
		
		if(tmp->left!=NULL)
			q.push(tmp->left);		
		else
			{
			tmp->left = t;
			std::cout<<"\nData inserted successfully"; 
			return;
		}
		
		
	 	if(tmp->right!=NULL)
			q.push(tmp->right);
		else
			{
				tmp->right = t;
				std::cout<<"\nData inserted successfully"; 
				return;
			}
	}
}


void Deleterightmost(node** temp,node* rightmost_node)//using level order travesal
{
		//thr function is created for deleting the element using data
		//and after swapping value of right most element we will del rightmost 
		//element by finding its parent node
		
		if(*temp == rightmost_node)
			{
				*temp = NULL;
				return;
			}
	
		else
			{	
				std::queue<node* >	q ;
				q.push(*temp);
				while(!q.empty())
				{
					node* tmp = q.front();
					
					q.pop();
					
					if(tmp->left!=NULL){
						
						if(tmp->left==rightmost_node)
							{
							 tmp->left = NULL;
								return;
							}
							
						else
							q.push(tmp->left);
						
					}
					
						if(tmp->right!=NULL){
						
						if(tmp->right==rightmost_node)
							{tmp->right = NULL;
							return;
						}
						else
							q.push(tmp->right);
						
					}
					
				}
			}
	}


void Delete(node** temp , int data)//using level order travesal
{
		int flag = 0;
		if(*temp == NULL)
			{
				std::cout<<"Empty Tree";
				return;
			}
		
		else if((*temp)->left == NULL && (*temp)->right == NULL)
			{
				if((*temp)->data == data)
						*temp = NULL;					
				return;	
			}
		
		else
			{	
				std::queue<node* >	q ;
				q.push(*temp);
				while(!q.empty())
				{
					node* tempr ;
					node* tmp = q.front();
					
					q.pop();
					
					if(tmp->data == data)
						{
						 tempr = tmp;
						flag = 1;
						}
					
					if(tmp->left!=NULL)
						q.push(tmp->left);
					if(tmp->right!=NULL)
						q.push(tmp->right);
					if(q.size()==0)
						{
							if(flag == 1)
								{
									std::cout<<"\ndeleting "<<tempr->data;
									tempr->data = tmp->data;
									Deleterightmost(temp,tmp);
									delete tmp;
									
									
								}
							else
								std::cout<<"\n Data not found";
						}
				}
			}
}

	
void Delete_from_root(node** temp)//using level order travesal
{
		int flag = 0;
		if(*temp == NULL)
			{
				std::cout<<"Empty Tree";
				return;
			}
		
		else if((*temp)->left == NULL && (*temp)->right == NULL)
			{
				*temp = NULL;					
				return;	
			}
		
		else
			{	
				std::queue<node* >	q ;
				q.push(*temp);
				while(!q.empty())
				{
					node* tmp = q.front();
					
					q.pop();
	
					if(tmp->left!=NULL)
						q.push(tmp->left);
					if(tmp->right!=NULL)
						q.push(tmp->right);
					if(q.size()==0)
						{
							std::cout<<"\ndeleting "<<(*temp)->data;
									(*temp)->data = tmp->data;
									Deleterightmost(temp,tmp);
									delete tmp;		
				
						}
				}
	}
}


void Delete_right(node** temp)//using level order travesal
{
		
		if(*temp == NULL)
			{
				std::cout<<"Empty Tree";
				return;
			}
		
		else if((*temp)->left == NULL && (*temp)->right == NULL)
			{
				*temp = NULL;					
				return;	
			}
		
		else
			{	
				std::queue<node* >	q ;
				q.push(*temp);
				while(!q.empty())
				{
					node* tmp = q.front();
					
					q.pop();
	
					if(tmp->left!=NULL)
						q.push(tmp->left);
					if(tmp->right!=NULL)
						q.push(tmp->right);
					if(q.size()==0)
						{
						
									Deleterightmost(temp,tmp);
									delete tmp;		
				
						}
				}
	}
}

	
void levelorder(node* temp)//Breadth first search Queue is used also known as level order
{
	std::queue<node*> q;
	q.push(temp);
	
	
	while(!q.empty())
	{
		node* tmp = q.front();
		 q.pop();
		
		if(tmp->left!=NULL)
			q.push(tmp->left);
		
	 	if(tmp->right!=NULL)
			q.push(tmp->right);
			
		std::cout<<tmp->data<<" ";
			
	}
}


void inorder(node* temp)//dfs
{
	node* tmp = temp;
	if(tmp==NULL)
		return;
	inorder(tmp->left);
	std::cout<<tmp->data<<" ";
	inorder(tmp->right);
	
}


void preorder(node* temp)///dfs
{
	node* tmp = temp;
	if(tmp==NULL)
		return;
	std::cout<<tmp->data<<" ";
	preorder(tmp->left);
	preorder(tmp->right);
	
}


void postorder(node* temp)//dfs
{
	node* tmp = temp;
	if(tmp==NULL)
		return;
	postorder(tmp->left);
	postorder(tmp->right);
	std::cout<<tmp->data<<" ";
	
}


void upadate_all_nodes_with_sum_sub_tree(node** root)
{
	if(*root == NULL)
		return;
	if((*root)->left!=NULL)
	{
		upadate_all_nodes_with_sum_sub_tree(&((*root)->left	));
		(*root)->data += (*root)->left->data;
	}
	if((*root)->right!=NULL)
	{
		upadate_all_nodes_with_sum_sub_tree(&((*root)->right));
		(*root)->data += (*root)->right->data;
	}
	
}


int sum_of_all_nodes(node* root)
{
	
	if(root == NULL)
	{
		return 0;
	}
	int sum = root->data;
	if(root->right!=NULL)
		sum +=  sum_of_all_nodes(root->right);
	if(root->left!=NULL)
		sum +=  sum_of_all_nodes(root->left);	
	return sum;	
}


void printleaf(node *temp)//printing leaf nodes
{
	if(temp==NULL)
		return;
	if(temp->left==NULL&&temp->right==NULL)
			std::cout<<temp->data<<" ";
	printleaf(temp->left);
	printleaf(temp->right);
}


bool isComplete(node* root)//chech whether a tree is complete binary tree or not
{
	if(root == NULL)
		return true;
	if(root->left==NULL && root->right==NULL)
		return true;
	
	if(root->left==NULL || root->right==NULL)
		return false;
		
	return isComplete(root->left)&&isComplete(root->right);
}


void print_nodes_having_right_child_but_not_left(node* root)
{
	if(root == NULL)
		return;
		
	if((root->left==NULL&&root->right!=NULL))
		std::cout<<root->data<<"\n";
		
	 print_nodes_having_right_child_but_not_left(root->left);
	  print_nodes_having_right_child_but_not_left(root->right);
		
	
}


node* search(node* temp,int data)//recursively
{
	
	if(temp == NULL)
		{ 
			return NULL;
		}
		
	else
	{
		static int flag = 0;
		if(data == temp->data)
			{
				std::cout<<"\nData found in steps ";
				flag = 1;
					return temp;
			}
			
			return search(temp->right,data);
			return search(temp->left,data);
	}
	
}


bool printAncestors(node* r, int val)
{
	//Given that all the nodes are unique. 
//And given a value, print all the ancestors of node with that value.

	if(r == NULL){ return false; }
	if(r->data == val){ return true; }//will return true when data found
	
	
	// the node is not data then we' ll check its child and if any of child has the data
	// the one of a and b is true;
	bool a = printAncestors(r->left, val);
	bool b = printAncestors(r->right, val);
	
	//printing all nodes that have any child as val
	if(a || b)
		std::cout<<r->data<< " ";
	
	//returning true so we can print node	
	return a||b;
}

std::vector<int> st;
void print_All_root_to_leaf(node* root)//blank
{
	if(root==NULL)
		return;
	st.push_back(root->data);
	if(root->left==NULL&&root->right==NULL){
		for(std::vector<int>::iterator it = st.begin();it!= st.end();it++)
			std::cout<<*it<<" ";
		std::cout<<"\n";
		st.pop_back();
		return;
	}
		
	
	else{
		print_All_root_to_leaf(root->left);
		print_All_root_to_leaf(root->right);
		
	}
}


int hieght_of_BT(node *root)
{
	if(root == NULL)
		return -1;
	else 
		return std::max(hieght_of_BT(root->right),hieght_of_BT(root->left))+1;
	
}


int Diameter_of_BT(node *root)
{
	if(root == NULL)
		return 0;
	/*
	Diameter is max leaf to leaf path 
	three cases either max diameter will be in left subtree	or
	three cases either max diameter will be in right subtree or
	it includes root element as a part
	so that is what we have done consider all the three cases and checked for the same
	
	
	*/
	int root_not_included_left = Diameter_of_BT(root->left);
	int root_not_included_right = Diameter_of_BT(root->right);
	int root_included = hieght_of_BT(root->left)+hieght_of_BT(root->right)+2;
	return std::max(root_included,std::max(root_not_included_left,root_not_included_right));

}


node* LCA_BT(node* root,int d1,int d2 )
{
	if(root == NULL)
		return NULL;
	if(root->data == d1 || root->data == d2)
		return root;
	
	node* left = LCA_BT(root->left ,d1,d2);
	node* right = LCA_BT(root->right,d1,d2);
	
	if(left != NULL && right != NULL)
		return root;
	if(left != NULL)
		return left;
	return right;
	
}

void print_left_view(node *root)
{
	 
	std::queue<node*> q;
	q.push(root);
	q.push(NULL);
	std::cout<<root->data<<"\n";
	while(!q.empty()){
		node* tmp = q.front();
		q.pop();
		
		if(q.empty())
			return;
		if(tmp == NULL){
			q.push(NULL);
			std::cout<<q.front()->data<<"\n";
	}
	else{
	
		
		if(tmp->left!=NULL)
			q.push(tmp->left);
		
	 	if(tmp->right!=NULL)
			q.push(tmp->right);
		
		}
	}
	
}


void print_Right_view(node *root)
{
	std::queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		node* tmp = q.front();
		 q.pop();
		if(q.empty())
			return;
		if(tmp==NULL)
			q.push(NULL);
		else{
		if(tmp->left!=NULL)
			q.push(tmp->left);
		if(tmp->right!=NULL)
			q.push(tmp->right);
		if(q.front()== NULL)
			std::cout<<tmp->data<<"\n";
		}
		
		
		}
		
	
}


void boundary_traversal(node *root)
{
	
}


bool subtree_or_not();
bool symmetrric ();


bool identical_trees_or_not(node* root1 ,node* root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1==NULL||root2==NULL)
		return false;
	if(root1->data != root2->data)
		return false;
	return identical_trees_or_not(root1->left,root2->left) && identical_trees_or_not(root1->right,root2->right);
}


////////////---------BST---------------/////////


void insertBST(node** temp,int data)
{
	//Level Order traversal to insert node in a tree
	
	
	if(*temp == NULL)
		{
			node* t = new node(data);
			*temp = t;
			std::cout<<"\nData inserted successfully"; 
			return;
		}
		
	else
	{
		if(data>(*temp)->data)
			insertBST(&((*temp)->right),data);
		else
			insertBST(&((*temp)->left),data);
	}
		
    
}


node* searchBSTrec(node* temp,int data)//recursiveky
{
	
	if(temp == NULL)
		{
			std::cout<<"\nData not found"; 
			return NULL;
		}
		
	else
	{
		if(data == temp->data)
			{
				std::cout<<"\nData found in steps ";
					return temp;
			}
		else if(data>temp->data)
			return searchBSTrec(temp->right,data);
		else
			return searchBSTrec(temp->left,data);
	}
	
}


node* searchBSTiter(node* temp,int data)//iteratively
{
	int flag = 1;
	while(temp!=NULL)
	{
		if(data == temp->data)
			{
				std::cout<<"\nData found in steps ";
					flag = 0;
					return temp;
			}
		else if(data>temp->data)
			temp=temp->right;
		else
			temp=temp->left;
	}
	
	if(flag == 1)
	{
		std::cout<<" data not found";
		return NULL;
	}
	
	
}


//void deletefrombst homework  

bool isBST(node *temp , int min , int max)
{
	
	//METHOD : 1
	//inorder traversal should be sorted
	
	//method : 2
	//checking range of each node which will greater than root or lesser than root
	//for example for left node range will it can range from root's minimum value to max of 
	//root data similar to root right data
	
	if(temp == NULL)
		return true;
	if(temp->data > min && temp->data < max)
		return false;
	else
		return isBST(temp->left,min,temp->data)&&isBST(temp->right,temp->data,max);
	
}


node* LCA(node* root ,int d1,int d2)
{
	if(root == NULL)
		return NULL;
	else if(d1 < root->data && d2 <root->data)
		return LCA(root->left,d1,d2);
	else if(d1 > root->data && d2 > root->data)
		return LCA(root->right,d1,d2);
	else 
	return root;
}



///////////////_________________HEAP___________///////////////






