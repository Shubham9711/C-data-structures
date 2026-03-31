#include<iostream>
#include<math.h>
#include<list>
class search{
public:

	int linearsearch(int *arr, int size,int element)
	{
	// normal element is searched at each index
		int pos=-1;
		for(int i = 0;i < size ; i++ )
		{
			if(arr[i] == element)
				pos=i;
		}
		return pos;
	//Time Complexity O(n)
	}
	
	
	int linearsearchimproved(int *arr, int size,int element)
	{
		//an improved version of linearsearch
		/*if element Found at last  O(n) to O(1)
			if element Not found O(n) to O(n/2)*/
		int pos=-1,i,j;
		for( i = 0,j = (size-1) ; i<=j ; i++,j-- )
		{
			if(arr[i] == element)
				pos=i;
		    if(arr[j] == element)
				pos=j;
		}
		return pos;
	}
	
	
	int binarysearch(int *arr, int size,int element )
	{
	    //array must be sorted and divided into two parts and the element is compared in which 
	    // part it should lie and searched in that part with similar technique
		int left = 0;
		int right = size-1;
		int mid ,pos = -1;
		while(left<=right)
		{
			mid = (left+right)/2;
		    if(arr[left] == element)
		   	pos = left;
            else if(arr[mid] == element)
		   	pos = mid;
		   	else if(arr[right] == element)
		   	pos = right;
            std::cout<<left<<right<<mid<<"\n";
			if(element>arr[mid])
		   	left = mid+1;
		   	else 
			right = (mid-1);

		}
		
		return pos;
		            /*Time Complexity: 
			  O(log n), where n is the size of the array.*/
	}
	
	
	int binarysearchrec(int *arr, int left ,int right,int element )
	{
		    if(left<=right)
		    {
			int mid = (left+right)/2;
		    if(arr[left] == element)
		   	return left;
            else if(arr[mid] == element)
		   	return mid;
		   	else if(arr[right] == element)
		   	return right;
            if(element>arr[mid])
		   	binarysearchrec(arr,mid+1,right,element);
		   	else 
			binarysearchrec(arr,left,mid-1,element);
		   	}
            else 
            return -1;
		}


	int interpolationsearch(int *arr, int left ,int right,int element )
	{
		    //Basically its an improved version of binary search where we are increasing
		    //or decreasing two array parts within
			//same as binary search just that the middle element sis found using interpolation
		    //whoese formula is pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo])
			if(left<=right&& element>=arr[left] && element<=arr[right])
		    {
				int mid=left
             	 		+ (((double)(right - left) / (arr[right] - arr[left]))
                 		* (element - arr[left]));
               
			    if(arr[mid] == element)
		   			return mid;
            	if(element>arr[mid])
		   			interpolationsearch(arr,mid+1,right,element);
		   		else 
					interpolationsearch(arr,left,mid-1,element);
		   	}
            else 
            return -1;
		}


	int ternarysearchrec(int *arr, int left ,int right,int element )
	{
		    /* is similar to binary search where we divide the sorted array into two parts
			 but in this algorithm, we divide the given array into three parts and 
			 determine which has the key (searched element).
			 mid1 = l + (r-l)/3 
			mid2 = r – (r-l)/3 */
			if(left<=right)
		    {
			int mid1= (left+right)/3;
			int mid2= 2*(left+right)/3;
		    if(arr[left] == element)
		   	return left;
            else if(arr[mid1] == element)
		   	return mid1;
		   	else if(arr[mid2] == element)
		   	return mid2;
		   	else if(arr[right] == element)
		   	return right;
            if(element>arr[mid2])
		   	ternarysearchrec(arr,mid2+1,right,element);
		   	else if(element<arr[mid1]) 
			ternarysearchrec(arr,left,mid1-1,element);
		   	else 
		   	ternarysearchrec(arr,mid1+1,mid2-1,element);
		   }
            else 
            return -1;
            
            /*Time Complexity: 
			  O(\log _{3} n), where n is the size of the array.*/
		}


    int exponentialsearch(int* arr , int size , int element)
    {
    	/*Exponential search involves two steps:
		  Find range where element is present
		  Do Binary Search in above found range.
		  The idea is to start with subarray size 1, 
		  compare its last element with x, then try size 2, 
		  then 4 and so on until last element of a subarray is not greater. 
          Once we find an index i (after repeated doubling of i), we know that 
		  the element must be present between i/2 and i 
		  (Why i/2? because we could not find a greater value in previous iteration)
		  time complexity = O(Log n) */
    	if(arr[0] == element)
    		return 0 ;
    	else if(arr[size-1] == element)
    		return size-1;
    		int i = 1;
    	while(arr[i]<=element&&i<size)
    	    i = i*2;
    	return binarysearchrec(arr,i/2,std::min(i,size-1),element);

	}


	int jumpsearch(int *arr , int lo, int hi,int element)
	{
		//sorted array
		//similar to exponential but here we devid arrays into sqrt(n)
		//then search in part which is most optimal acc to sorted part
		//Time complexity = 
		int step = sqrt(hi),pos = -1;
		int i= 0;
		for(; i< hi&&arr[i]<=element ; i= i+step);	
		int prev = i-step;
		while(prev<=i){
			if(arr[prev]== element)
			pos = prev;
			prev++;
 		}
		return pos;
		/*The optimal size of a block to be jumped is (v n). 
		This makes the time complexity of Jump Search O(v n).
        The time complexity of Jump Search is between Linear Search ( ( O(n) ) 
		and Binary Search ( O (Log n) ).*/
		
	}
};


class sort{
	
	public:
        void swap(int* i , int* j)
		{
			if(*i == *j)
			{
				return;
			}
			*i = *i+*j;
			*j=*i-*j;
			*i = *i-*j;
			std::cout<<"\nswapping"<<*i<<"and"<<*j;
		}
		
		
		void printArray(int arr[], int n)
		{
		    int i;
		    for (i = 0; i < n; i++)
		        std::cout << arr[i] << " ";
		    std::cout<<"\n";
		}
	
	
		void printArray(int arr[], int n,int k)
		{
		    int i;
		    for (i = n; i <= k; i++)
		        std::cout << arr[i] << " ";
		    std::cout<<"\n";
		}
		
		
		void selection(int* arr ,int size,bool order = 1)//1 for asc order
		{
				/*Time Complexity: O(n2) as there are two nested loops.
				Auxiliary Space: O(1)*/
			for(int i = 0;i< size ; i++)
			{
				int min = i;
				int max = i;
				for(int j = i+1;j<size ; j++)
				{
					if(arr[min]>arr[j])
						min = j;
					else if(arr[max]<arr[j])
						max = j;
				}
				if(order==1)
      				swap(&arr[i],&arr[min]);
				else
					swap(&arr[i],&arr[max]);
				
			}
		}


		void bubble(int* arr ,int size,bool order = 1)//1 for asc order
		{
				/*Time Complexity: O(n^2) as there are two nested loops.
				best case coplexity with all sorted algos be O(n)
				Auxiliary Space: O(1)*/
			for(int i = size-1; i>0 ; i--)
			{
				bool swapped = false;
				for(int j = 0;j<i ; j++)
				{
					if(arr[j]>arr[j+1] && order == 1)
					{	swap(&arr[j],&arr[j+1]);
					     swapped=true;
						}	
					else if(arr[j]<arr[j+1]&& order== 0)
					{	swap(&arr[j],&arr[j+1]);
					     swapped=true;
						}	
				}
				if(swapped==false)
				break;//will break the loop if no swapping takes place ie sorted array
			}
		}

		
		void insertion(int* arr ,int size,bool order = 1)//1 for asc order
		{
			/*Time Complexity: O(n^2) 
			  Auxiliary Space: O(1)
			 Boundary Cases: Insertion sort takes maximum time 
			 to sort if elements are sorted in reverse order. 
			 And it takes minimum time (Order of n) when elements are already sorted.*/
			for(int i = 0; i < size-1 ; i++)
			{
				int pos= i;
			    int temp=arr[i];
				for(int j = i+1; j < size ; j++)
					{
						if(arr[i]>arr[j]&& order == 1)
						{
							temp=arr[j];
							pos=j;
							for(int k = pos;k>i;k--)
				  				arr[k]=arr[k-1];
				  				arr[i]=temp;
						}
						else if(arr[i]<arr[j]&& order == 0)
						{
							temp=arr[j];
							pos=j;
							for(int k = pos;k>i;k--)
				  				arr[k]=arr[k-1];
				  				arr[i]=temp;
						}
						
				  } 
			}
		}

	
		void mergesort(int *arr,int low ,int high)
		{
			//Time comlexity
			if(low < high)
			{
				int mid = (low + high)/2 ;
		
				mergesort(arr,low,mid);
				mergesort(arr,mid+1,high);
			
			// merge section 
				int len1 = mid-low + 1;
				int len2 = high-mid;
				int arr1[len1],arr2[len2];
			
				for(int i = 0 ; i < len1 ; i++)
					arr1[i]=arr[low+i];
			
				for(int i = 0 ; i <len2 ; i++)
					arr2[i]= arr[mid+i+1];
				
				int i = 0;
				int j = 0;
				int k = low;
				
				while(i<len1 && j<len2)
				{
					
					if(arr1[i]<arr2[j])
					{
						arr[k++]=arr1[i++];
					}
					else
					{
						arr[k++]=arr2[j++];
					}
					
				}	
				
				while(i<len1)
					arr[k++]=arr1[i++];
				
				while(j<len2)
					arr[k++]=arr2[j++];
			}
			
			return;
							
		}


		void quick(int* arr ,int low , int high)
		{
			/*Time taken by QuickSort, in general, can be written as following. 
				 T(n) = T(k) + T(n-k-1) + \theta(n)
				 Worst case:
				T(n) = T(0) + T(n-1) + \theta(n)         //1,2,3,4,5,6,7,8,9
				which is equivalent to  
				T(n) = T(n-1) + \theta(n)
				The solution of above recurrence is  \theta        (n2).
				best case:
				T(n) = 2T(n/2) + \theta(n)
				The solution of above recurrence is \theta        (nLogn)
				average case: T(n) = T(n/9) + T(9n/10) + \theta(n)
				Solution of above recurrence is also O(nLogn)
			*/
			
		
            if(low>=high)//condtion of worst case senario ie array
            {            //has either zero elements to sort or onle one element is there in array
            	return;
			}
			else if(low+1==high)//array to be pivoted has only two elements
			{
				if(arr[low]>arr[high])
					swap(&arr[low],&arr[high]);
					return;
			}
			else
			{
				int High = high;
				int pivot = low;
				low = low+1;
				while(low<=High)
				{
					while(arr[low]<arr[pivot]&&low!=high+1)//moving pointer low towards left 
						low++;               //untill it gets element greater than pivot
					while(arr[High]>arr[pivot])//moving pointer hi towards right 
						High--;				//	untill it gets element smaller than pivot
					if(High>low)           //if there is distance between high and low
						swap(&arr[High],&arr[low]);//swapping elements of high and low
					   				
				}
				if(pivot!=High)
					swap(&arr[pivot],&arr[High]);//swapping pivot element 
					                       //if high pointer is not pivot coz else not needed
				quick(arr,0,High-1);
				quick(arr,High+1,high);
			}
			
		}

		
		void shell(int* arr ,int size,bool order = 1)//1 for asc 
		{
			//Time complexity is O(n^2)
			for(int gap = size/2 ; gap >= 1 ; gap = gap/2 )
			// gap sequence ie gap between compared elements
				
				for(int j = gap ; j <= size-1 ; j++ )
				//j pos initialised with gap to compared with i th pos
				//so that we can compare to previous gap element 
				
					for(int i = j-gap ; i >= 0; i = i-gap ) 
				
					{		
					    if(order == 1)//for asc desecending only
							{//if swapped  //coz if element not swapped then no need to 
							 //check with previous and move to next element
							if(arr[i+gap] >= arr[i])	
								break;
								//and now since we arent breaking so this will
						    else     //and now since we arent breaking so this will 
								swap(&arr[i+gap],&arr[i]);//check with previous gap element also
						    }
						    
						    else
						    {
						    	if(arr[i+gap] <= arr[i])	
									break;
						        else    	
									swap(&arr[i+gap],&arr[i]);
							}
						
						    
						    
					
						}
					
		}
		

		void comb(int* arr ,int size,bool order =1)//1 for asc 
		{
			//Time complexity is O(n^2) in worst case
		    //improved version of bubble sort just like shell sort is of insertion sort
			for(int gap = size/1.3 ; gap >= 1 ; gap = gap/1.3 )
			// gap sequence ie gap between compared element
				for(int i = 0 ; i < size-gap ; i++ )
				//j pos initialised with gap to compared with i th pos
				//so that we can compare to previous gap element
					{		
					    if(order == 1)
						{
								if(arr[i] > arr[i+gap])	
								swap(&arr[i+gap],&arr[i]);
						}
									    
					   else
						   {
							 if(arr[i] < arr[i+gap])	  	
								swap(&arr[i+gap],&arr[i]);
							}
					}
					
		}
		

		void count(int *arr , int size)
		{
			//Time complexity is O(n)
			 int max=  arr[0];
			 int count = 0;
			 
        	 for(int i = 0; i< size ; i++)//finding max value in array
        	 	if(arr[i] > max)
        	 		max = arr[i];
        	 		
        	 int array[size] = {0};		
        	 int temparray[max+1] = {0};// initializing temp array of size max to have array 
        	                           // indicies till max
        	                           
        	for(int i = 0; i< size ; i++) //counting no. of elements in array
		    	++temparray[arr[i]]	;// storing them in temp array
		    
			for(int i = 1; i< max+1 ; i++) // summing up array so that we can insert 
		    	temparray[i] = temparray[i]+temparray[i-1];//values at incidices
		    
		    for(int i = size-1; i>=0 ; i--)// since summ array has indicies of element 
		    	array[--temparray[arr[i]]] = arr[i];

		    for(int i = 0; i< size ; i++)
		    	arr[i] = array[i];
		    	   	 
		}


		void radix(int* arr , int size)//using count sort
		{
			//Time complexity O(digit*(size+ base ))
			int max = arr[0];
			int array[size];
			for(int i = 0; i< size ; i++)//finding max value in array
        	 	if(arr[i] > max)
        	 		max = arr[i];
        
        	 	
        	int digit =10;
			while(max>0)
			{
				int count[10]={0};
				for(int i = 0; i< size ; i++)
					++count[( arr[i]%digit )/(digit/10)];
				//( arr[i]%digit )/(digit/10) will check each digit one by one at hundreth tens once place
				//( arr[i]%digit ) will give modulus of answer
				//(digit/10) will give midlle digit
					
				for(int i = 1; i< 10 ; i++) // summing up array so that we can insert 
		    		count[i] = count[i]+count[i-1];//values at incidices according to unit place
					
		    		
		    	for(int i = size-1; i>=0 ; i--)// since summ array has indicies of element 
		    		array[--count [ ( arr[i]%digit )/(digit/10) ] ] = arr[i];
		    		
		    	for(int i = 0; i< size ; i++)
					arr[i]=array[i];
		    	max = max/10;
		    	digit = digit*10;
		    	
			}
			

		}


		void bucket(int* arr,int size)
		{
			std::list<int> l[size]  ;
			int max = arr[0];
			for(int i = 0;i < size ; i++)
				if(max<arr[i])
					max = arr[i];
						
			int digit = 1;
				
			while(max > 10)//getting the digit value according to max
				{
					max = max/10;
					digit= digit*10;
				}
				
				for(int i = 0;i < size ; i++)
					l[arr[i]/digit].push_front(arr[i]);// pushing into list according to max
				
				for(int i = 0;i < size ; i++)
					l[i].sort();//sorting individual list
				
				int j = 0;
					for(int i = 0;i < size ; i++)//getting back sorted array
					{	
						int k = l[i].size();
						while(k>0)
						{
							arr[j++] = l[i].front();
							l[i].pop_front();
							k--;
						}
					}		
		}

};

 
int main()
{

	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	sort s1; 
	s1.insertion(arr,9,1);
	//std::cout<<"\n";
	s1.printArray(arr,7);
	
	return 0;
	
}

