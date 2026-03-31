//min_cost we can reach a cell (0,0) to (m,n) in a matrix of M X N , if we have matrix containing blocked inicies
#include<iostream>
int Min_cost(int arr[][4] ,int row , int col)
{
	int i=row;
	int j=col;
	if(i==0&&j==0)
		return arr[i][j];
	if(j == 0)
		return Min_cost(arr,i-1,j)+arr[row][col];
	if(i == 0)
		return Min_cost(arr,i,j-1)+arr[row][col];
	return std::min(Min_cost(arr,i-1,j),Min_cost(arr,i,j-1))+arr[row][col];
	
	
}
int main()
{
	int arr[][4]={
					{2,5,1,4},
					{3,7,1,3},
					{9,8,2,1},
					{8,10,4,3}
	};
	std::cout<<Min_cost(arr,4,4);
}
