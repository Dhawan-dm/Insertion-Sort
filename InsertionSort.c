
#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
void Create_Input(int a[],int n)
{
	for(int i =0; i<n; i++){
		a[i] = rand()% n + 1;
	}
	
}

void Swapping(int a[],int j){
	
	int temp = a[j];
	a[j] = a[j+1];
	a[j+1] = temp;
}

void insertion_Sort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
 
    
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void Create_Report(int initialSize , int increment){

	struct timeval te;
       	
	for(int i=0 ;i< 8 ;i++ )
	{
		int n = initialSize + increment*i;
		int a[n];

		Create_Input(a,n);
		gettimeofday( &te, NULL);

		long long start = te.tv_sec * 1000LL +te.tv_usec / 1000;

		insertion_Sort(a,n);

		gettimeofday( &te, NULL);

                long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;
		printf("\t %lld" , end - start);

		
	}	
}

int main(){
	int initialSize = 8000;
	int increment = 4000;
	printf("start");
	Create_Report(initialSize,increment);

	printf("\n");
}
