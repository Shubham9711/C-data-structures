//Number of ways bricks can be arranged 
/* if we have 1 brick it has only 1 ways 2 bricks can be arranged in two ways
3 brics can be arranges in 2 bricks ways + 1 brick ways and so on*/

#include<iostream>
int NUM_OF_WAYS(int total_bricks)
{
	if(total_bricks==1||total_bricks==2)
		return total_bricks;
	return NUM_OF_WAYS(total_bricks-1)+NUM_OF_WAYS(total_bricks-2);
}
int main()
{
	int t_bricks = 4;
	std::cout<<NUM_OF_WAYS(t_bricks);
}
