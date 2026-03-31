/*
Virus Outbreak (100 Marks)
In the Martian land faraway, a new virus has evolved and is attacking the individuals at a fast pace. The scientists have figured out the virus composition, V. The big task is to identify the people who are infected. The sample of N people is taken to check if they are POSITIVE or NEGATIVE. A report is generated which provides the current blood composition B of the person. 


POSITIVE or NEGATIVE ?

If the blood composition of the person is a subsequence of the virus composition V, then the person is identified as POSITIVE otherwise NEGATIVE.


Example:

Virus Composition, V = coronavirus

Blood Composition of the person , B = ravus


The person in question is POSITIVE as B is the subsequence of the V. 

 

The scientists are busy with their research for medicine and request you to build a program which can quickly figure out if the person is POSITIVE or NEGATIVE. They will provide you with the virus composition V and all the people’s current blood composition. Can you help them?


Note: The virus and blood compositions are lowercase alphabet strings.

Input Format
The first line of the input consists of the virus composition, V

The second line of he input consists of the number of people, N

Next N lines each consist of the blood composition of the ith person, Bi




Constraints
1<= N <=10

1<= |B|<= |V|<= 10^5



Output Format
For each person, print POSITIVE or NEGATIVE in a separate line

Sample TestCase 1
Input
coronavirus
3
abcde
crnas
onarous
Output
NEGATIVE
POSITIVE
NEGATIVE
Time Limit(X):
0.50 sec(s) for each input.
Memory Limit:
512 MB
Source Limit:
100 KB
Allowed Languages:
C, C++, C++11, C++14, C#, Java, Java 8, Kotlin, PHP, PHP 7, Python, Python 3, Perl, Ruby, Node Js, Scala, Clojure, Haskell, Lua, Erlang, Swift, VBnet, Js, Objc, Pascal, Go, F#, D, Groovy, Tcl, Ocaml, Smalltalk, Cobol, Racket, Bash, GNU Octave, Rust, Common LISP, R, Julia, Fortran, Ada, Prolog, Icon, Elixir, CoffeeScript, Brainfuck, Pypy, Lolcode, Nim, Picolisp, Pike, pypy3


Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<string>
using namespace std;
bool is_sequence(string v,string B)
{
	if(v.length()<B.length())
		return false;
	else
	{	int i = 0,j= 0;
		for( ;i<v.length()&&j<B.length();)
		{
			if(B[j]==v[i])
				{
					i++;
					j++;
				}
			else
				i++;
		}
		if(j>=B.length())
			return true;
		else 
			return false;
	}
}
int main()
{
	//Write code here
	string virus ;
	int num;
	cin>>virus;
	cin>>num;
	string  str[num];
	for(int i = 0;i<num;i++)
		{
			cin>>str[i];
			if(is_sequence(virus, str[i]))
				cout<<"POSITIVE\n";
			else
				cout<<"NEGATIVE\n";
			
			}
	
}
