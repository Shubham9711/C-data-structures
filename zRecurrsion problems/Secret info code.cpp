#include<bits/stdc++.h>
using namespace std;
int main(){
	string  s1 ;
	
	cin>>s1;
	string s2 = "";
	for(int i= 0 ;i<s1.length();i++){
		if(isupper(s1[i])||isdigit(s1[i]))
			s2 += s1[i];
		
	}
	cout<<s2;
	return 0;
	
}

