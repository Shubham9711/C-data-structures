//Minimun no. denomination needed to sum up an amount
#include<iostream>
int* min_denom(int denom_arr[],int size, int a =0 , int b=0,int i = 1)
{	
	int a1[] = min_denom(denom_arr,10 , a+denom_arr[i-1],b,i+1);
	 int a2[]=	min_denom(denom_arr,10 , a,b+denom_arr[i-1],i+1);
	int a3[] =	min_denom(denom_arr,10 , a,b,i+1);
	if(i==size)
	{
		if(a1[0]==a1[1])
			return a1;
		else if(a2[0]==a2[1])
			return a2;
		else
			return a3;
	}
		

	
	
	
		
}
int main()
{
	int denomination_array[] = { 1,2,3};
	int arr[2] = min_denom(denomination_array,3);
	std::cout<<arr[1];
	
	return 0;
}
