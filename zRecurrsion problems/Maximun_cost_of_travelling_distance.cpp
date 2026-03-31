#include<iostream>
using namespace std;
int cost[7] = {0,2,5,8,9,10,11};
int maxCost(int n)
{
	int mc = cost[n];
	for(int k = 1; k<n; k++)
	{
		int temp = cost[k] + maxCost(n-k);
		if(temp > mc)
			mc = temp;
	}
	return mc;
}
int main()
{
	cout<<maxCost(6);
	
}
