/*
Suppose you are given a list of students who are assigned IDs. Write a C program to sort 
these students based on their id’s using heapsort. Find its time and space complexity
*/

/*
Time complexity -> O(n log n)
Space complexity -> O()
*/

#include<stdio.h>
#include<stdlib.h>

#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>

/*
heapify function maintaines the max heap
a -> heap n -> total nodes i -> index of parent node
index of left and right child = 2*i + 1, r = 2*i + 2 respectively
-> here i = index of root node
*/
void heapify(int a[], int n, int i){
    int largest = i,
        l = 2*i + 1,
        r = 2*i + 2;
    
    if(l < n && a[l] > a[largest])
        largest = l;
    if(r < n && a[r] > a[largest])
        largest = r;
    if(largest != i){
        int temp = a[i]; a[i] = a[largest]; a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n){
    int i;

    for(i = n/2 - 1; i>=0; i++)
        heapify(a, n, i);
    
    for(i=n-1; i>0; i--){
        int temp = a[0]; a[i]; a[i] = temp;
        heapify(a, i, 0);
    }
}

int main(){

    struct timeval start_time, end_time;
	struct rusage space_usage;

    int id[10], totalStudents, i;
    printf("\nEnter the total number of students : "); scanf("%d", &totalStudents);
    for(i=0; i<totalStudents; i++) scanf("%d", id + i);

	gettimeofday(&start_time, NULL);

    heapSort(id, totalStudents);

	gettimeofday(&end_time, NULL);

    printf("\nDisplaying the IDs after sorting :-\n");
    for(i=0; i<totalStudents; i++) printf("%d\t", id[i]);

	printf("\n\nTime taken = %f ms\n",(double)(end_time.tv_usec-start_time.tv_usec));
    getrusage(RUSAGE_SELF, &space_usage);
    printf("Memory used : %ld kb\n", space_usage.ru_maxrss);

	return 0;
}
