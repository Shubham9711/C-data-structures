//Length Longeest common sub sequence in the string
#include<iostream>
using namespace std;
 string s1 = " ";
int Longest_common_subseq(string str1 , string str2, int i = 0 , int j = 0)
{
	
	if(i >= str1.length() || j >= str2.length())
		return 0;
	
		//if equal Add 1 to LCS
	if(str1[i] == str2[j])
		return Longest_common_subseq(str1, str2, i+1, j+1) + 1;
	
		//If not Equal  check for max maximum of rest string left first with s1 and then with s2
	int a = Longest_common_subseq(str1, str2, i+1, j);
	int b = Longest_common_subseq(str1, str2, i, j+1);
	
	return max(a, b);

}
int main()
{
	cout<<Longest_common_subseq("ABXBCD","AXBXD")<<"\n";
	
	
	return 0;
}
