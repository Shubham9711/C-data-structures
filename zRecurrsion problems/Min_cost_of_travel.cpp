//Min cost of travelling from station to another given a cost
#include<iostream>
using namespace std;
int mincost_travel(int arr[][4] , int start_stn , int end_stn )
{
	if(start_stn==end_stn || end_stn == start_stn +1)
		arr[start_stn ][end_stn]; 

	int min = arr[start_stn ][end_stn];
	for(int i = start_stn+1; i<end_stn ; i++ )
	{
		int temp= mincost_travel(arr ,start_stn, i ) + mincost_travel(arr , i , end_stn );
		if(min >temp)
			min = temp;
	}
	return min;
}
int main()
{
	int arr[][4]={
					{0,10,50,85},
					{0,0,45,50},
					{0,0,0,25},
					{0,0,0,0}
	};
	std::cout<<mincost_travel(arr,0,3);
	return 0;
}
