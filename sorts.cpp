#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <fstream>

using namespace std;

void shuffle(int arr[], int size)
{
   srand(time(0));
   int randLoc;
   for(int i = 0; i < size; i++)
   {
      randLoc = rand() % size;
      swap(arr[i], arr[randLoc]);
   }
}

void swap(int& a, int& b)
{
   if ( a != b) {
      int temp = a;
      a = b;
      b = temp;
   }
}

int select_partition(int array[], int start, int size) 
{
	return start;
}

int find_median( int array[], int start, int size)
{
	int less, greater;
	for ( int i = start; i < start + size; i++ )
	{
		less = 0;
		greater = 0;
		for (int j = start; j < start + size; j++ )
		{
			if ( array[j] < array[i]) { less++; }
			else if (array[j] > array[i]) { greater++;}
		}
		if ( less == greater || less == greater + 1 || less == greater - 1 ) {
		    //cout << "pivot: " << i << endl;
		    return i;
		}
	}
	return 0;
}

void bsort(int array[], int size, int& cost)
{
	for(int i = 0; i < size-1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(array[j] > array[j+1])
			{
				swap(array[j], array[j+1]);
			}
			cost++;
		}
	}
}

void isort(int array[], int size, int& cost)
{
	int value;
	for (int i = 0; i < size; i++)
	{
		int j = i - 1;
		value = array[i];
		cost++;
		while(j >= 0 && array[j] > value)
		{
			array[j+1] = array[j];
			j = j-1;
			cost++;
		}
		array[j+1] = value;
	}
}

void ssort(int array[], int size, int& cost)
{
	int min;
	for(int i = 0; i < size - 1; i++)
	{
		min = i;
		for(int j = i+1; j < size; j++)
		{
			if(array[j] < array[min])
			{
				min = j;
			}
			cost++;
		}
		swap(array[min], array[i]);
	}
}

void msort(int array[], int size, int& cost)
{

	if(size > 1)
	{
		int middle = size / 2;
		int other = size - middle;
		int temp1[middle];
		int temp2[other];

		for(int i = 0; i < middle; i++)
		{
			temp1[i] = array[i];
		}
		for(int j = 0; j < other; j++)
		{
			temp2[j] = array[j + middle];
		}
		msort(temp1, middle, cost);
		msort(temp2, other, cost);
		
		int k = 0;
		int n = 0;
		int p = 0;
		while(k < middle && n < other)
		{
			if(temp1[k] <= temp2[n])
			{
				array[p] = temp1[k];
				k++;
			}
			else
			{
				array[p] = temp2[n];
				n++;
			}
			p++;
			cost++;
		}
	
		while (k < middle)
		{
			array[p] = temp1[k];
			k++;
			p++;
		}
		while(n < other)
		{
			array[p] = temp2[k];
			n++;
			p++;
		}	
	}
	cout << "Size: " << size << endl;
	for (int i = 0; i < size; i++ )
	{
		cout << array[i] << endl;
	}
}

void my_qsort( int array[], int start, int size, int& cost, int (*choose_pivot) (int[] , int, int) )
{
    if (size == 2) {
	if (array[start] > array[start+1]) {
	    swap(array[start],array[start+1]);
	}
	cost++;
    }else if (size > 2) {
	int pivot = choose_pivot(array, start, size );
	int x = array[pivot];
        swap(array[pivot], array[start + size-1]);
        int i = start-1;
        for (int j = start; j < (start + size - 1); j++) {
	    if (array[j] < x) {
		i++;
	        swap(array[i],array[j]);
	    }
	    cost++;
        }
        swap(array[i+1], array[start + size-1]);
	int size_l = i + 1 - start;
	int size_r = size - size_l - 1;
	int start_r = i+2;
	if (i > 0) {my_qsort( array, start, size_l, cost, choose_pivot );}
	//return;
	if (size_r > 1 && start_r < start + size) {my_qsort( array, start_r, size_r, cost, choose_pivot );}
        
    }
}
