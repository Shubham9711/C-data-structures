#include<iostream>
using namespace std;

int Minopr(int n)
{
	if(n == 0)
		return 0;
	else
	{
		int b = 1;
		while((b<<1)<=n)
			b = b<<1;
		 return(Minopr((b>>1)^b^n)+b);
		
		
		
	}
}

//Driver code
int main()
{
	int n =6;
	std::cout<<Minopr(n);
	return 0;
}




