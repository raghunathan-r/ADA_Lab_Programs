/*
Q 4. Consider a network having 'n' systems. Design a DFS based program in 'C' which outputs 
all systems reachable from a given system. Find its time and space complexity.
*/

/*
Time complexity -> O(V + E)
Space complexity -> O(V)
*/

#include<stdio.h>
#include<stdlib.h>

#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>

int adjMatrix[10][10], *visited, vertesis;

void DFS(int node){
    visited[node] = 1;

    for(int i=1; i<=vertesis; i++){
        if(adjMatrix[node][i] == 1 && visited[i] != 1){
            printf("%d --> %d\n", node, i);
            DFS(i);
        }
    }
}

int main(){

    struct timeval start_time, end_time;
	struct rusage space_usage;

    int i, j, startNode;

    printf("\nEnter the total number of systems in the network : "); scanf("%d", &vertesis);
    visited = (int *)malloc(sizeof(int) * vertesis);

    printf("\nEnter the adjeceny matrix :-\n");
    for(i=1; i<=vertesis; i++){
        for(j=1; j<=vertesis; j++)
            scanf("%d", &adjMatrix[i][j]);
    }

    printf("Enter the system to start form : "); scanf("%d", &startNode);

    printf("Displaying the path to reach all systems using DFS ...\n");

	gettimeofday(&start_time, NULL);

    DFS(startNode);

	gettimeofday(&end_time, NULL);


	printf("\n\nTime taken = %f ms\n",(double)(end_time.tv_usec-start_time.tv_usec));
    getrusage(RUSAGE_SELF, &space_usage);
    printf("Memory used : %ld kb\n", space_usage.ru_maxrss);

	return 0;
}