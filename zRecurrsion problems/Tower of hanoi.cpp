#include<iostream>
void Tower_of_hanoi(char col1 , char col3 , char col2 , int Number_of_disk)
{
	//Transfering Disk from col1 to col3 using col2
	if (Number_of_disk == 0)
	{
		return;
	}
	Tower_of_hanoi(col1 , col2 , col3 , Number_of_disk-1);
	std::cout<<"transfering disk "<<Number_of_disk<<" from "<<col1<<" to "<<col3<<"\n";
	Tower_of_hanoi(col2, col3 , col1 , Number_of_disk-1);
	
}
int main()
{
	Tower_of_hanoi('A','C','B',9);
	return 0;
	
}
