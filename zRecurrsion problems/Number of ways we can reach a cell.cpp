//Number of ways we can reach a cell (0,0) to (m,n) in a matrix of M X N , if we have matrix containing blocked inicies
#include<iostream>
int NUM_OF_WAYS(int arr[][4] ,int row , int col)
{
	int i=row;
	int j=col;
	if(i == 0||j == 0)
		return 1;
	if(i==0&&j==0)
		return 0;
	if(arr[i][j]==1)
		return 0;
	return NUM_OF_WAYS(arr,i-1,j)+NUM_OF_WAYS(arr,i,j-1);
	
	
}
int main()
{
	int arr[][4]={
					{0,0,1,0},
					{0,1,0,1},
					{0,0,0,0},
					{0,0,1,0}
	};
	std::cout<<NUM_OF_WAYS(arr,4,4);
}
