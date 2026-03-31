#include<iostream>
using namespace std;
int main(){
	int arr[][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}	};
	int i=0,j=0;
	while(i!=4&&j!=4){
		while(i!=j){
			std::cout<<arr[i][j]<<" ";
			i--;
			j--;
		}
		std::cout<<arr[i][j]<<" ";
		i++;
		j++;
		std::cout<<"\n ";
		
	}
	return 0;
}
