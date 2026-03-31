//max_Sum_array
#include<bits/stdc++.h>
int max_sum_array(int arr[],int size,int sum , int index){
	if(index == 8)
		return sum;
	int a = max_sum_array(arr,size,sum+arr[index],index+1);
	int b = max_sum_array(arr,size,sum,index+1);
	return std::max(a,b);
}

int max_sum_subarray_O_N3(int arr[],int size){
	//brute force approach 
	/*
	In this we are considering all possible subset sum and the taking best of it
	In this complexity is O(n3)
	*/
	int best = 0;
	for(int a = 0;a<size;a++){
		for(int b = a; b<size; b++){
			int sum = 0;
			for(int i = a;i<=b ; i++)
				sum += arr[i];
				best = std::max(best,sum);
			
		}
	}
	return best;
}

int max_sum_subarray_O_N2(int arr[],int size){
	
	/*
	In this we have removed inner loop as we dont need coz
	we can calcuclate sum directly and selecting best at same time while iterarting 
	last index which is b so from a to b we considering at each b value and storing best 
	at same time
	Time complexity reduces to O(n2)
	*/
		int best = INT_MIN;
	for(int a = 0;a<size;a++){
		int sum = 0;
		for(int b = a; b<size; b++)
			{
			sum += arr[b];
			best = std::max(best,sum);
			}
	}
	return best;
}


int max_sum_subarray_O_N(int arr[],int size){
	/*
In this we Have reduced complexity to O(n)
by removing inner loop also
in this everything is done at the same time 
*/

		int best = 0;
		int sum = 0;
	for(int a = 0;a<size;a++){
			sum = std::max(arr[a],sum+arr[a]);
			best = std::max(best,sum);
	}
	return best;
}




int main(){
	int arr[]= { -1,2,4,-3,5,2,-5,2};
	int sum = 0,size = 8;
	
	sum = max_sum_array(arr,8,sum,0);
	std::cout<<"Maximum array sum is "<<sum;
	std::cout<<"\nMaximum subarray sum is "<<max_sum_subarray_O_N3(arr,size);
	std::cout<<"\nMaximum subarray sum is "<<max_sum_subarray_O_N2(arr,size);
	std::cout<<"\nMaximum subarray sum is "<<max_sum_subarray_O_N(arr,size);
	return 0;
}
