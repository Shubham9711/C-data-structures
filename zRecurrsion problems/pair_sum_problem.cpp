#include<iostream>
int sum = 10;
bool sum_exist(int *arr , int low,int high){
	if(low == high || low>high)
		return false;
	if(arr[low]+arr[high]==sum)
		return true;
	return sum_exist(arr , low+1,high)||sum_exist(arr , low+1,high-1)||sum_exist(arr , low,high-1);
}
int main(){
	int arr[] = {2,6,18,7,9};
	std::cout<<sum_exist(arr,0,5);
	return 0;
}
