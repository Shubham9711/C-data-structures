//Number of ways we can step up a ladder if we can only take either one or two steps
#include<iostream>
int NUM_OF_WAYS(int total_steps)
{
	if(total_steps==1||total_steps==2)
		return total_steps;
	return NUM_OF_WAYS(total_steps-1)+NUM_OF_WAYS(total_steps-2);
}
int main()
{
	int t_steps = 3;
	std::cout<<NUM_OF_WAYS(t_steps);
}
