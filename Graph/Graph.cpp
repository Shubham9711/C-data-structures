
#include<iostream>
#include<list>
#include<map>
#include<queue>

 


typedef struct vertex{
	int id;
	char Name;
} vertex;

std::map<char , bool> tmap;
typedef struct graph{
	int NUM_vertices ;
	vertex* vertices[9] ;
	int edges[9][9]; //Adjancey matrix telling which veryex connected to which vertex
	//Constructor
	graph()
	{
		NUM_vertices = 9;
		for(int i = 0 ; i < 9 ; i++)
		{
			vertices[i]= NULL;
			for(int j = 0 ; j < 9 ; j++)
			edges[i][j] = 0;
			}	
	}
	
	graph(int i)
	{
		NUM_vertices = i;
		for(int i = 0 ; i < 9 ; i++)
		{
			vertices[i]= NULL;
			for(int j = 0 ; j < 9 ; j++)
			edges[i][j] = 0;
			}
	}
	
	void set_graph_vertices()
	{
		for(int i = 0;i<9 ; i++)
		{
			char NaMMe;
			vertices[i] = new vertex();
			std::cout<<"Enter vertice" <<i<<"  \n";
			std::cin>>NaMMe;
			vertices[i]->Name =NaMMe ;
			vertices[i]->id = i;
		}
	}
	
	vertex* getvertexinfo(char a)
	{
		for(int i =0;i<NUM_vertices;i++)
			if(vertices[i]->Name==a)
				return vertices[i];
		return NULL;
	
	}	
	
	vertex* getvertexinfo(int id)
	{
		for(int i =0;i<NUM_vertices;i++)
			if(vertices[i]->id==id)
				return vertices[i];
		return NULL;
	
	}	

	bool isAdjacent(char A , char B)
	{
		vertex* v1 = getvertexinfo(A);
		vertex* v2 = getvertexinfo(B);
	if(v1!=NULL && v2!= NULL)
	{
		if(edges[v1->id][v2->id] == 1)
			return true;
		else
			return false;
   }
	}
	
	bool isAdjacent(int A , int B)
	{
		
		if(edges[A][B] == 1)
			return true;
		else
			return false;
   }
   
	std::list<vertex*> allAdjacent(char A)
	{
		std::list <vertex*> my_list ;
		vertex* v1 = getvertexinfo(A);
		
			for(int i = 0; i<9;i++)
				if(edges[v1->id][i] == 1)
					my_list.push_back(getvertexinfo(i));
			return my_list;			
		
	}
	
	void DFSTraversal(int i = 0, int j = 0){
		if(i == NUM_vertices&& j == NUM_vertices)
			return;
		else if(i < NUM_vertices && j == NUM_vertices){
			DFSTraversal( i+1 , j);
			
		}
		else if(i == NUM_vertices&& j < NUM_vertices){
				DFSTraversal( i , j+1);
		}
		else{
				DFSTraversal( i+1 , j+1);
		}
		char a = getvertexinfo(i)->Name;
		if(tmap[a] == false){
			std::cout<<a;
			tmap[a] = true;
		}
		else 
		return;
		
	}
}graph;


typedef struct vertexlist{
	char Name;
	std::list<vertexlist> adjancylist;
	
}vertexlist;


std::map<char,bool> Traversalmap;

typedef struct graphlist{
	
	std::list<vertexlist> L1;
	
	void createNode()
	{
		vertexlist v1 ;
		std::cout<<"Enter vertex name";
		std::cin>>v1.Name;
		L1.push_back(v1);
	
		}

	vertexlist* getvertexinfo(char a)
	{
		std::list<vertexlist>::iterator li;
		for(li = L1.begin(); li !=L1.end() ;li++)
			if((*li).Name ==a)
				return &(*li);		
		return NULL;

	}	

	void join_node_connections(char a)
	{
		char b;
		vertexlist* v =getvertexinfo(a);
		std::cout<<"Enter Connection Node";
		std::cin>>b;
		vertexlist* v1 =getvertexinfo(b);
		if(v1== NULL||v==NULL)
			std::cout<<"Enter valid node\n";
		else
			v->adjancylist.push_back(*v1);
			return;
		
	}

	bool isAdjacent(char a , char b)
	{
		vertexlist* v = getvertexinfo(a);
		vertexlist* v1 = getvertexinfo(b);

		if(v==NULL||v1==NULL)
			return false;
		std::list<vertexlist>::iterator li;
		for(li = v->adjancylist.begin(); li !=v->adjancylist.end() ;li++)
			if((*li).Name ==v1->Name)
				return true;
		return false;
		
		
	}

	void bfstraversal( std::list<vertexlist> L2){
			while(!L2.empty()){
				
				vertexlist v1 = L2.front();
				L2.pop_front();
				if(Traversalmap[v1.Name] == false){
					Traversalmap[v1.Name] = true;
					std::cout<<v1.Name<<"\n";
					bfstraversal(v1.adjancylist);
				}
				else
					continue;
				
				}
				
		}
						
   	 	
}graphlist;

int main()
{

//	graphlist g1;
//	for(int i = 0;i<9;i++ )
//		g1.createNode();
//
//			char a = 'A';
//	for(int i = 0;i<10;i++ )
//		{  
//			std::cout<<"enter joining maine edge\n";
//			std::cin>>a;
//			g1.join_node_connections(a);
//		}
//		
//		g1.bfstraversal(g1.L1);
		
	{
	graph g1(9);
	g1.set_graph_vertices();
	
	{	
		//adjency matrix
		g1.edges[0][1] =1;
		g1.edges[0][4] =1;
		g1.edges[0][7] =1;
		g1.edges[0][8] =1;
		g1.edges[1][0] =1;
		g1.edges[1][2] =1;
		g1.edges[1][3] =1;
		g1.edges[2][2] =1;
		g1.edges[2][3] =1;
		g1.edges[3][1] =1;
		g1.edges[3][2] =1;
		g1.edges[3][5] =1;
		g1.edges[3][6] =1;
		g1.edges[3][7] =1;
		g1.edges[4][0] =1;
		g1.edges[5][3] =1;
		g1.edges[6][3] =1;
		g1.edges[7][3] =1;
		g1.edges[7][0] =1;
		g1.edges[8][0] =1;
		
	}
	
	
	vertex* v1	= g1.getvertexinfo(5);
	if(v1==NULL)
		std::cout<<"NULL VALUE";
	else
		std::cout<<"ID- "<<v1->id<<" NAME-"<<v1->Name<<"\n";
	
	std::cout<<g1.isAdjacent('D','C');
	
	std::list<vertex*> l1= g1.allAdjacent('A');

	while(!(l1.empty()))
	{
		
		vertex* v1 = l1.front();
		l1.pop_front();
		std::cout<<"\n"<<v1->Name<<"\n";
	}
	
	g1.DFSTraversal();
}

}


