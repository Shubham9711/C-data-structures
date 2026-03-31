
#include<bits/stdc++.h>
using namespace std;


class Undirected_Graph {
	map<int, vector<int> > adList;
public:
	void addEdge(int u,int v) {
		adList[u].push_back(v);
		adList[v].push_back(u);
	}

	void printGraph() {

		for(auto i: adList) {
			cout<<"Node "<<i.first<<" "<<"=>"<<" ";
			for(auto j: i.second)
				cout<<j<<" ";
			cout<<endl;
		}
	}

	void BFS(int start) {
		if(adList.find(start) == adList.end()) {
			cout<<"No such Node Found";
			return;
		}
		std::queue<int> q;
		q.push(start);
		map<int,bool> mp;
		mp[start] = true;
		while(!q.empty()) {
			int num = q.front();
			q.pop();
			cout<<num<<" ";
			vector<int> connections = adList[num];
			if(!connections.empty()) {
				for(auto i:connections) {
					if(mp[i]!=true) {
						q.push(i);
						mp[i] = true;
					}
				}
			}
		}

	}

	void DFS(int start, map<int,bool>& mp) {
		mp[start] = true;
		cout<<start<<" ";
		vector<int> connections = adList[start];
		for(auto i : connections) {

			if(!mp[i]) {
				DFS(i,mp);
			}
		}

	}

	bool cycleBFS(int start) {
		if(adList.find(start) == adList.end()) {
			cout<<"No such Node Found";
			return false;
		}
		std::queue<	pair<int,int>> q;
		q.push({start,-1});
		map<int,bool> mp;
		mp[start] = true;
		while(!q.empty()) {
			pair<int,int> p = q.front();
			q.pop();

			vector<int> connections = adList[p.first];
			if(!connections.empty()) {
				for(auto i:connections) {
					if(mp[i]!=true) {
						q.push({i,p.first});
						mp[i] = true;
					} else if(i != p.second)
						return true;
				}
			}
		}
		return false;

	}

	bool cycleDFS(int start,int parent,map<int,bool>& mp) {
		mp[start] = true;
		vector<int> connections = adList[start];
		for(auto i : connections) {
			if(i == parent)
				continue;
			if(mp[i] || cycleDFS(i,start,mp))
				return true;
		}
		return false;
	}

	bool checkBipartiteDFS(vector<vector<int>>& graph, int curr,vector<int> color,int currColor) {
		//any graph having odd nodes cycle is not bipartite and even node cycles is bipartite
		color[curr] = currColor;
		for(int v : graph[curr]) {
			if(color[v] == color[curr])
				return false;
			if(color[v] == -1) {
				int colorOfV = 1-color[curr];
				if(checkBipartiteDFS(graph,v,color,colorOfV) == false)
					return false;
			}
		}
		return true;
	}

	bool checkBipartiteBFS(vector<vector<int>>& graph, int curr,vector<int>& color,int currColor) {
		queue<int> q;
		q.push(curr);
		color[curr] = currColor;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i:graph[u]) {
				if(color[i] == color[u])
					return false;
				if(color[i] == -1) {
					color[i] = 1-color[u];
					q.push(i);
				}
			}
		}
		return true;
	}


	//  bool isBipartite(vector<vector<int>>& graph) {
	//     vector<int> color(graph.size(),-1);
	//     for(int i = 0;i<graph.size();i++){
	//         if(color[i] == -1){
	//             if(checkBipartiteDFS(graph,i,color,1) == false)
	//             return false;
	//         }
	//     }
	//     return true;
	// }

};

class directed_graph { //DAG directed acyclic graphs
public:

	void BFS(int start) {
		if(adList.find(start) == adList.end()) {
			cout<<"No such Node Found";
			return;
		}
		std::queue<int> q;
		q.push(start);
		map<int,bool> mp;
		mp[start] = true;
		while(!q.empty()) {
			int num = q.front();
			q.pop();
			cout<<num<<" ";
			vector<int> connections = adList[num];
			if(!connections.empty()) {
				for(auto i:connections) {
					if(mp[i]!=true) {
						q.push(i);
						mp[i] = true;
					}
				}
			}
		}

	}

	void DFS(int start, map<int,bool>& mp) {
		mp[start] = true;
		cout<<start<<" ";
		vector<int> connections = adList[start];
		for(auto i : connections) {

			if(!mp[i]) {
				DFS(i,mp);
			}
		}

	}

	bool cycleDFS_directedDraph(int start,map<int,bool>& mp,map<int,bool>& sameRec) {
		mp[start] = true;
		sameRec[start] = true;
		vector<int> connections = adList[start];
		for(auto i : connections) {
			if(mp[i] == false && cycleDFS_directedDraph(i,mp,sameRec))
				return true;
			else if(sameRec[i] == true)
				return true;
		}
		sameRec[start] = false; // cureent rec element as false cause we are retuning from current recursion
		return false;
	}

	//we can have multiple topological sort res
	void topologicalSort_DFS(int start, map<int,bool>& mp,stack<int>& st) {
		/*Can only be for directed acyclic graph because
			topological sort means from where we can go to where
			and start node always comes before node after
			also
			if there is cycle then the above condion fails coz we can go from nodes after o node before
			which is not topological sort
			eg u -> g and g-> u
			in sorting
			it should u g
			but g u also there so not possible
		*/
		//stack is used so we could add all people at end before we can go at last


		mp[start] = true;
		vector<int> connections = adList[start];
		for(auto i : connections) {
			if(!mp[i]) {
				topologicalSort_DFS(i,mp,st);
			}
		}
		st.push(start);

	}

	void topologicalSort_BFS(int n) {

		/*Can only be for directed acyclic graph because
			topological sort means from where we can go to where
			and start node always comes before node after
			also
			if there is cycle then the above condion fails coz we can go from nodes after o node before
			which is not topological sort
			eg u -> g and g-> u
			in sorting
			it should u g
			but g u also there so not possible
		*/
		//khans algorithm
		//used inDegree which says how many element before the element ie how many arrows coming to element
		//them sort element by indegree

		// u->v u indegree 0 , v indegree 1

		queue<int> q;
		vector<int> inDegree(n,0);
		for(int u = 0; u<n; i++) {
			for(int v:adList[u])
				inDegree[v]++;
		}// sabke elemenet adjList me indegree bada di

		for(int i = 0;)i<n;
		i++) {
			if(inDegree[i] == 0)
				q.push(i);
		} //fir queue me 0 waale push kar diye

		vector<int> res;
		while(!q.empty()) {
			int u = q.front();
			q.pop();//pehle pop ki the aage waale element as root element maanke unko dekha
			for(int v: adList[u]) {
				indegree[v]--;
				if(indegree[v] == 0)
					q.push(v);
			}


		}
	}

	bool cycleBFS_directedgraph(int n) {
		//its the code of topoliogical sort BFS because topological sort can be only be done for non cyclic graphs

		queue<int> q;
		vector<int> inDegree(n,0);
		int count = 0;
		// count = n means all visited else
		//if not visited that means cycle there coz all nodes topilocal sort cant be done
		for(int u = 0; u<n; i++) {
			for(int v:adList[u])
				inDegree[v]++;
		}

		for(int i = 0; i<n; i++) {
			if(inDegree[i] == 0) {
				count++;
				q.push(i);
			}

		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int v: adjList[u]) {
				inDegree[v]--;
				if(inDegree[v] == 0) {
					count++;
					q.push(v);
				}

			}
		}
		if(count == n)
			return true;
		return false;
	}

	bool checkBipartiteDFS(vector<vector<int>>& graph, int curr,vector<int> color,int currColor) {
		//any graph having odd nodes cycle is not bipartite and even node cycles is bipartite
		color[curr] = currColor;
		for(int v : graph[curr]) {
			if(color[v] == color[curr])
				return false;
			if(color[v] == -1) {
				int colorOfV = 1-color[curr];
				if(checkBipartiteDFS(graph,v,color,colorOfV) == false)
					return false;
			}
		}
		return true;
	}

	bool checkBipartiteBFS(vector<vector<int>>& graph, int curr,vector<int>& color,int currColor) {
		queue<int> q;
		q.push(curr);
		color[curr] = currColor;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i:graph[u]) {
				if(color[i] == color[u])
					return false;
				if(color[i] == -1) {
					color[i] = 1-color[u];
					q.push(i);
				}
			}
		}
		return true;
	}

	//  bool isBipartite(vector<vector<int>>& graph) {
	//     vector<int> color(graph.size(),-1);
	//     for(int i = 0;i<graph.size();i++){
	//         if(color[i] == -1){
	//             if(checkBipartiteDFS(graph,i,color,1) == false)
	//             return false;
	//         }
	//     }
	//     return true;
	// }
	
	// ------------------------------------------------------------------------------------------------//
	
	//strongly connected components are those in which if we can go from a to b the vice vresa is also possible
    // thats is why its only for directed graphs coz in undirected graph its true by default
	//Function to find number of strongly connected components in the graph and is only for directed graphs
	//so what we can do we will first take topological sort of nodes
	// then reverse all the edges
	//after reverseing we will traverse all nodes dfs
	// so then we will get all nodes SSC and also we will not go into different components from each other
	//coz they will marked visited due to topological sort
	int kosaraju(int V, vector<vector<int>>& adj) {
		stack<int> st;
		vector<bool> visited(V, false);

		for(int i = 0; i<V; i++) {
			if(!visited[i]) {
				topologicalSort_DFS(i, adj, visited, st);
			}
		}


		vector<vector<int>> adjReversed(V);
		for(int u = 0; u<V; u++) {
			for(int &v : adj[u]) {

				//u->v
				//v->u
				adjReversed[v].push_back(u);

			}
		}

		int count = 0;

		visited = vector<bool>(V, false);
		while(!st.empty()) {
			int node = st.top();
			st.pop();
			if(!visited[node]) {
				DFS(node, adjReversed, visited);
				count++;
			}
		}

		return count;

	}
	//Kosaraju's Algorithm :     Time  : O(V+E), V = # vertices, E = # edges , Space : O(V)


};

class disJointSet {
	//helps to combine to sets and also to tell whether to element belongs to same set or not
	//i.e telling whether two graphs are connectes or not
public:
	vector<int> parent;
	vector<int> rank;
	int setParent(int i,vector<int>& parent) { //also knnown as path compression
		if(i == parent[i])
			return i;
		parent[i] = setParent(parent[i],parent);
		return parent[i];
	}

	void findUnion(int x,int y,vector<int>& parent) {
		int x = setParent(x,parent);
		int y = setParent(y,parent);
		if(x != y)
			parent[x] = y;
		return;

	}

	void findUnionbyRank(int x,int y,vector<int>& parent) {
		int X = setParent(x,parent);
		int  = setParent(y,parent);
		if(x == y)
			return
			    //we have used rank to increase depdth of tree and whosoever rank is higher will be made parent
			else if(rank[x] > rank[y]) {
				parent[y] = x;
			}
			else if(rank[x] < rank[y]) {
				parent[x] = y;
			} else {
				parent[x] = y;
				rank[y] += 1;
			}
		return;

	}

};

class edge { //used for wieghted graphs containing detination from a node and its wieght
	int dest;
	int wieght;
public:
	edge(int e,int w) {
		dest = e;
		wieght = w;
	}
	int getdest() {
		return this->dest;
	}
	int getWieght() {
		return this->wieght;
	}
};

class Node {
public:
	int wieght;
	int node;
	int parent;
	Node(int w, int s,int d):wieght(w),node(s),parent(d) {}
}; //used for PRIMS MST

class Compare {
public:
	bool operator()(Node below, Node above)
	{
		if (below.wieght > above.wieght) {
			return true;
		}

		return false;
	}
};//used for PRIMS MST

class Undirected_or_directed_wieghted_graph {
	//whenever we talk about shortest path we sould think of BFS but it only works when we have same weights of all edges
	map<int, vector<edge>> adList;

public:

	void addEdge(int src, int dest, int wieght) {
		edge src_e(dest,wieght);
		edge dest_e(src,wieght);
		adList[src].push_back(src_e);//source to dest edge addition
		adList[dest].push_back(dest_e); //dest to source edge addition
	}

	void printGraph() {

		for(auto i: adList) {
			cout<<"Node "<<i.first<<" "<<"=>"<<" ";
			for(auto j: i.second)
				cout<<"dest: "<<j.getdest()<<" weight: "<<j.getWieght()<<" ";
			cout<<endl;
		}
	}

	//Spanning tree is conncted graph of all nodes ie V vertices with v-1 edges
	//a graph can have multiple spanning trees
	//MST is done by PRIMS or KRUSKALS algo and is ST with min wieght sum of all edges
	//spanning dont have cycles and is for connected weigthed graphs only


	void MST_Prim(int startNode) {
		vector<pair<int,int>> res;
		map<int, bool> mp;//to check if visited
		priority_queue< Node, vector<Node>, Compare> minheap;//min heap used to choose min edges first to get min res
		int sum = 0;
		Node n(0,startNode,-1);
		minheap.push(n);
		while(!minheap.empty()) {
			Node curr = minheap.top();
			minheap.pop();
			if(mp[curr.node]) {
				continue;
			}
			mp[curr.node] = true;
			sum += curr.wieght;
			if(curr.parent != -1)
				res.push_back({curr.node,curr.parent});
			vector<edge> connections = adList[curr.node];
			if(!connections.empty()) {
				for(auto i:connections) {
					if(mp[i.getdest()]!=true) {
						Node temp(i.getWieght(),i.getdest(),curr.node);
						minheap.push(temp);
					}
				}
			}
		}

		for(auto i : res)
			cout<<i.first<<" "<<i.second<<endl;
		cout<<"totalSum "<<sum;
	}

	int Kruskal(int V, vector<vector<int>> adj) {
        //Used DSU
		parent.resize(V);
		rank.resize(V, 0);

		for(int i = 0; i<V; i++)
			parent[i] = i;

		vector<vector<int>> vec;


		for(int i = 0; i<V; i++) {

			for(auto &temp : adj[i]) {

				int u = i;
				int v = temp[0];
				int d = temp[1];

				vec.push_back({u, v, d});

			}

		}


		auto lambda = [&](auto &v1, auto &v2) {
			return v1[2] < v2[2];
		};

		sort(begin(vec), end(vec), lambda);

		//first Sort edges according to wieghts
		//then connect edges using DSU and at end will have an MST
		int sum = 0;
		for(auto &temp : vec) {

			int u = temp[0];
			int v = temp[1];
			int wt = temp[2];

			int parent_u = find(u);
			int parent_v = find(v);

			if(parent_u != parent_v) {
				Union(u, v);
				sum += wt;
			}

		}

		//if(edgesConnected != V-1)
		//"It's not a MST" - REMEMBER THIS ALWAYS if anyone asks you how to check if we formed an MST or not


		return sum;
	}

	//dijkstra can't work with -ve elements and also -ve cycles o(elog(v))
	vector<int> dijkstra(int src, int n) {
		//using priority_queue
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

		vector<int> dist(n, INT_MAX);//distance of each node from source

		dist[src] = 0;//dist of source to source should 0 min

		pq.push({0, src}); //pushing source distance

		while(!pq.empty()) {

			int  currWt   = pq.top().first;
			int currNode = pq.top().second;
			pq.pop();

			for(auto adj: adList[currNode]) {
				int nextNode = adj.getdest();
				int nextWt = adj.getWieght;

				if(dist[nextNode] > currWt + nextWt) {
					dist[nextNode] = currWt + nextWt;//dist from parent to node > from current calculated
					pq.push({currWt + nextWt, nextNode});
				}
			}
		}

		return dist;
	}//shortest path from source node to all other nodes;

	vector<int> dijkstra(int src, int n) {
		//using set used because here we can erase any element if found a better one
		set<pair<int,int>> st;

		vector<int> dist(n, INT_MAX);//distance of each node from source
		vector<bool> visited(n, false);

		dist[src] = 0;//dist of source to source should 0 min

		st.insert({0, src}); //pushing source distance

		while(!st.empty()) {
			auto &it st.begin();
			int  currWt   = it.first;
			int currNode = it.second;
			st.erase(it);

			for(auto adj: adList[currNode]) {
				int nextNode = adj.getdest();
				int nextWt = adj.getWieght;

				if(dist[nextNode] > currWt + nextWt) {
					if(dist[nextNode] != INT_MAX)
						st.erase(dist[nextNode],nextNode);
					dist[nextNode] = currWt + nextWt;//dist from parent to node > from current calculated
					pq.push({currWt + nextWt, nextNode});
				}
			}
		}
		return dist;
	}

	//Bellmon Ford only works for directed graph and if we have undirected graph.
	// the we need to convert it into directed graphs
	// and it says if we relax all edges |v-1| times then we will get shortest Path from a source
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		//in this we dont need any priority_queue
		//like in dijikstra where we check shortest distance every time and change it thats relaxation
		// but here we relax v-1 times
		// to relax since we have a dist vector from source to all othere nodes with initially infinity
		// order of relaxation of edges will always be same for all v-1 times
		// relaxation means dist[u] + curr_to_v < dist[v] relax means change dist[v]

		//we have chosen v-1 times because it will relax all nodes dist and if we increase it wont change res
		// and if we there is any change after v-1 times then it means there would be any -ve cycle
		vector<int> result(V, 1e8);
		result[S] = 0;
		for(int c = 1; c<=V-1; c++) {
			for(auto &edge : edges) {
				int u = edge[0];
				int v = edge[1];
				int w = edge[2];
				if(result[u] != 1e8 && result[u] + w < result[v]) {
					result[v] = result[u] + w;//relaxation
				}
			}
		}

		//Now detect negative cycle
		//just relax one more time and check
		for(auto &edge : edges) {

			int u = edge[0];
			int v = edge[1];
			int w = edge[2];

			if(result[u] != 1e8 && result[u] + w < result[v]) {
				return {-1};
			}
		}
		return result;
	} O(E*V);


	//Finding Shortest Distance from all nodes to other nodes ie multi sources shortes Distance
	//for undirected we will make it directed O(N^3)
	//it can also detect -ve cycle and for that just check if grid[i][i] < 0 then it have -ve cycle
	void shortest_distance_Floyd Warshall(vector<vector<int>>& grid) {
		//it simply says if we want to go from u -> v;
		//then simply go to all nodes from u then to v then return shortest of all
		// do this for all nodes to other nodes goinh from all nodes in between
		/*
		     0 1 2 3 fill all fields i.e 0 - 1- 0  0 1 2  0 1  3 and so on so we will get are ans
		   0
		   1
		   2
		   3
		*/
		int n = grid.size();
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<n; j++) {
				if(grid[i][j] == -1)
					grid[i][j] = 100000; // if going from u->v is not possible ie no edge then making it infinity
			}
		}

		for(int via = 0; via < n; via++) {
			for(int i = 0; i<n; i++) {
				for(int j = 0; j<n; j++) {
					//updating matrix with min going via all paths in between
					grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);

				}
			}
		}

		for(int i = 0; i<n; i++) {
			for(int j = 0; j<n; j++) {

				if(grid[i][j] == 100000)
					grid[i][j] = -1;//changing back all infinity to -1 again
			}
		}
	}


}; //wieghted undirected graphs and algos

class Solution {
public:
	bool isEularCircuitExist(int V, vector<int>adj[]) {
		vector<int> degree(V, 0);

		for(int i = 0; i<V; i++) {

			degree[i] = adj[i].size();

		}

		for(int i = 0; i<V; i++) {
			if(degree[i] % 2 != 0) {
				return false;
			}
		}

		return true;
	}
};

class Solution {
public:

	void DFS(vector<int>adj[], int u, vector<bool>& visited) {
		visited[u] = true;

		for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
			if(visited[*it] == false) {
				DFS(adj, *it, visited);
			}
		}
	}

	bool isConnected(int V, vector<int>adj[]) {
		vector<bool> visited(V, false);

		//Find a vertex with non-zero degree
		int nonZeroDegreeVertex = -1;
		for(int i = 0; i<V; i++) {
			if(adj[i].size() != 0) {
				nonZeroDegreeVertex = i;
				break;
			}
		}

		// Start DFS traversal from a vertex with non-zero degree
		DFS(adj, nonZeroDegreeVertex, visited);

		// Check if all non-zero degree vertices are visited
		for(int i = 0; i<V; i++) {
			if(visited[i] == false && adj[i].size() > 0)
				return false;
		}
		return true;
	}

	int isEularCircuit(int V, vector<int>adj[]) {

		//Check if all non-zero degree vertices are connected
		if(isConnected(V, adj) == false) {
			return 0; //Non-Eulerian
		}

		//Count vertices with odd degree
		int oddCount = 0;
		for(int i = 0; i<V; i++) {
			if(adj[i].size()%2 != 0) {
				oddCount++;
			}
		}

		// If count is more than 2, then graph is not Eulerian
		if (oddCount > 2)
			return 0; //Non-Eulerian

		if(oddCount == 2) {
			return 1; //Semi-Eulerian (It has only Euler Path)
		}

		return 2; //(Euler Circuit)

	}
};

