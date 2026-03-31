//Min edit distanxe between 2 strings
// Explanation in Mca clg notebook
#include<iostream>
using namespace std;

int Min_Edit_Distance(string str1 , string str2 ,int i,int j)
{	
			if(i ==str1.length()&&j==str2.length())
				return 0;
			if(i == str1.length())
				return (str2.length()-j);
			if(j == str1.length())
				return (str1.length()-i);
			if(str1[i]==str2[j])
				return Min_Edit_Distance(str1,str2,i+1,j+1);
			
			int x= Min_Edit_Distance(str1,str2,i,j+1)+1; // if we insert an element in str1
			int y = Min_Edit_Distance(str1,str2,i+1,j)+1;//if we del an element in str1
	    	int z = Min_Edit_Distance(str1,str2,i+1,i+1)+1;//if we update an element in str1
			return min(min(x,y),z);
		
}

int main()
{
	string sttr1 = "shubham";
	string sttr2= "richa";
	cout<<Min_Edit_Distance(sttr1,sttr2,0,0);
	return 0;
}
