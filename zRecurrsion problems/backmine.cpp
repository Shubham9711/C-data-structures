#include<iostream>
#include<math.h>
//goldmine problem dp class
int backmine(int arr[][5] , int i , int j,int row)
{
			static int cache[6][5] = {0};
			if(cache[i][j]== 0)
			{

			int max_extract;
	
			if(j == 0)
				return arr[i][j];
			else if(i == 0)
				max_extract =  arr[i][j] + std::max(backmine(arr,i,j-1,row),backmine(arr ,i+1,j-1,row));
			else if(i == row-1)
				max_extract =  arr[i][j] + std::max(backmine(arr,i,j-1,row),backmine(arr ,i-1,j-1,row));
			else
				max_extract =  arr[i][j] + std::max(backmine(arr,i,j-1,row),std::max(backmine(arr ,i-1,j-1,row),backmine(arr ,i+1,j-1,row)));
	    	
			return max_extract;
	}
	
	else 
	return cache[i][j];
}

int main()
{
	int arr[][5]={	  
				  {5,1,2,2,1},
				  {6,2,1000,4,5},
				  {3,1,1,3,1},
				  {2,3,8,2,6},
				  {1,1,3,1,3},
				  {1,4,600,4,4}
				 };
	int max = 0;
	for(int i =0; i<6 ; i++){
		
		int temp = backmine(arr,i,4,6);
		if(max<temp)
			max = temp;
			std::cout<<temp<<"\n";
	}
	
	std::cout<<max;
	
}
