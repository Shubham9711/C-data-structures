#include<iostream>
int sum(int n){
	if(n==0)
		return 0;
	return (n%10) + sum(n/10);
	
}
int main()
{
	int num = 0;
	std::cout<<"Enter any number you want";
	std::cin>>num;
	
	std::cout<<"Sum of digits of entered number is"<<sum(num);
	return 0;
}
