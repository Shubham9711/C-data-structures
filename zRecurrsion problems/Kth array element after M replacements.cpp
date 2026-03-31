/*
Kth array element after M replacements of array elements by XOR of adjacent pairs

Given an array arr[] of size N and two integers M and K, 
the task is to find the array element at the Kth index after performing following M operations on the given array.

Input: arr[] = {3, 2, 6}, M = 2, K = 1 
Output: -1 
Explanation: 
Since M = 2, operation has be performed twice. 
On performing 1st operation on the array {3, 2, 6} it is modified as {3^2, 2^6} = {1, 4}. 
On performing 2nd operation on the array {1, 4}, it is modified as {1^4} = {5}. 
After performing 2 operations, the size of the array is reduced to 1. This implies that the index K = 1 doesn’t exist after 2 operations. 
Hence, the given input is invalid. So the output is -1.
*/


#include <iostream>
#include <vector>
using namespace std;

int m_step_xor(int a[], int m, int k , int length)
{
	if(m == 0 && length-1 >= k)
      return a[k];
  	else if(m == 0 && length-1 < k)
      return -1;
  	else
    {
      for(int i = 0 ; i < length ; i++)
        a[i] = a[i] ^ a[i+1];
      return m_step_xor( a,  m-1,  k , length-1);
    }
  
}

int main()
{

	int a[] = { 1, 4, 5, 6, 7 };

	int m = 1, k = 2;

	// Function call
	int ans = m_step_xor(a, m, k,5);
	
	cout << ans << "\n";

	return 0;
}
