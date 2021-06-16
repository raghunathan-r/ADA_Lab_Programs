/*
Consider a list of 'n' files numbered using ID’s. Write a C program to sort files
based on its ID using merge sort. Also find its time and space complexity.
*/

#include<stdio.h>

#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>

/*
Time complexity -> O(n log n)
Space complexity -> O(n)
*/

void merge(int a[], int l, int m, int h){
    int n1, n2, i, j, k;

    // n1 and n2 are the size of the left and right array
    n1 = m - l + 1;
    n2 = h - m;

    // copying the left and right sub array into temp array
    int L[n1], R[n2];

    for(i=0; i<n1; i++){
        L[i] = a[l + i];
    }
    for(i=0; i<n2; i++){
        R[i] = a[m + 1 + i];
    }

    i = 0; j = 0; k = l;
    // coping the elements from left and right subarray in sorted manner into main array
    while(i < n1 && j < n2){
        // copying the lowest element of left sub array to main array and incrimenting i and j
        if(L[i] < R[j]){
            a[k] = L[i];
            i++; k++;
        }
        // copying the lowest element of right sub array to main array and incrimenting i and j
        else {
            a[k] = R[j];
            j++; k++;
        }
    }

    // copying the remaining elements if any remaing to main array
    while(i < n1){
        a[k] = L[i];
        i++; k++;
    }
    while(j < n2){
        a[k] = R[j];
        j++; k++;
    }
}

void mergeSort(int a[], int l, int h){
    // the recursive relation is executed while the array is not empty
    if(l < h){
        int m = (l + h) / 2;

        // sorting the left half of the array
        mergeSort(a, l, m);
        // sorting the right half of the array
        mergeSort(a, m + 1, h);

        // merging the two half of sorted arrays
        merge(a, l, m, h);
    }
}

int main(){

    struct timeval start_time, end_time;
	struct rusage space_usage;

    int fileID[10], size, i;
    printf("\nEnter the total number of files : "); scanf("%d", &size);
    printf("Enter the IDs of the files :-\n");
    for(i=0; i<size; i++){
        scanf("%d", fileID + i);
    }

	gettimeofday(&start_time, NULL);

    mergeSort(fileID, 0, size - 1);

	gettimeofday(&end_time, NULL);

    printf("\nDisplaying the IDs in sorted order :-\n");
    for(i=0; i<size; i++){
        printf("%d\t", fileID[i]);
    }  

	printf("\n\nTime taken = %f ms\n",(double)(end_time.tv_usec-start_time.tv_usec));
    getrusage(RUSAGE_SELF, &space_usage);
    printf("Memory used : %ld kb\n", space_usage.ru_maxrss);

	return 0;
}
