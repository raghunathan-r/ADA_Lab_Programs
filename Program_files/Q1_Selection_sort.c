/*
Q1. Design a C program to sort ‘n’ elements using selection sort in ascending or descending order. 
Also find its space and time complexity.
*/
#include<stdio.h>

#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>

/*
Time complexity -> O(n)
Space complexity -> O(1)
*/

void selectionSort(int a[], int n){
    int i, j, minIndex, temp;

    for(i=0; i<n-1; i++){

        // assuming the element in subarray as the smallest
        minIndex = i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[minIndex]){
                minIndex = j;
            }
        }
        // swaping the smallest element with the next element in the sorted subarray
        temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;
    }
}

int main(){

    struct timeval start_time, end_time;
	struct rusage space_usage;

    int array[10], size, i;

    printf("Enter the size of the array : "); scanf("%d", &size);
    printf("Enter the elements of the array :-\n");
    for(i=0; i<size; i++){
        scanf("%d", array + i);
    }

	gettimeofday(&start_time, NULL);

    selectionSort(array, size);

	gettimeofday(&end_time, NULL);

    printf("\n\nDisplaying the sorted array :-\n");
    for(i=0; i<size; i++){
        printf("%d\t", array[i]);
    }


	printf("\n\nTime taken = %f ms\n",(double)(end_time.tv_usec-start_time.tv_usec));
    getrusage(RUSAGE_SELF, &space_usage);
    printf("Memory used : %ld kb\n", space_usage.ru_maxrss);

	return 0;
}

