# LA - I - ADA Lab Internals Practice

Chapter content: https://www.notion.so/Part-A-73cbc57425cd4e8bbf3c20244ee7b6a8
Last edited: Jun 15, 2021 9:29 PM
Subject: https://www.notion.so/91667517fc37424285b4e6e358a62d2d
Tags: Rough notes ✏

**Q 1. Design a C program to sort 'n' elements using selection sort in ascending or descending order. Also find its space and time complexity.**

`Page - 3 - Unit 2 - Mohan notes`

[Selection Sort - GeeksforGeeks](https://www.geeksforgeeks.org/selection-sort/)

[Space Complexity of Algorithms - How to Calculate Space Complexity of Algorithms in Data Structures - YouTube](https://www.youtube.com/watch?v=yOb0BL-84h8)

- Code

    ```c
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
    ```

**Q 2. Consider a list of 'n' files numbered using ID’s. Write a C program to sort files based on its ID using merge sort. Also find its time and space complexity.**

`Page - 17 - Unit 2 - Mohan notes`

[Merge Sort - GeeksforGeeks](https://www.geeksforgeeks.org/merge-sort/)

[Merge Sort | Code and Explanation | C++ Course - 19.1 - YouTube](https://www.youtube.com/watch?v=4z9I6ZmeLOQ)

- Code

    ```c
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
    ```

**Q 3. Write a C program that, for a given digraph outputs all the vertices reachable from a given starting vertex using BFS method. Find its time and space complexity.**

[Breadth First Search or BFS for a Graph - GeeksforGeeks](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)

[Breadth First Search (BFS): Visualized and Explained - YouTube](https://www.youtube.com/watch?v=xlVX7dXLS64)

`Page 195 - DA Textbook`

`📹 **Unit 3 - ADA Class 07-06-21**`

- Code

    ```c
    /*
    Write a C program that, for a given digraph outputs all the vertices reachable
    from a given starting vertex using BFS method. Find its time and space complexity.
    */

    #include<stdio.h>
    #include<stdlib.h>

    #include<sys/time.h> 
    #include<time.h>
    #include<sys/resource.h> 

    typedef struct Queue Queue;

    struct  Queue{
    	int *Q;
    	int front;
    	int rear;
    };

    void enqueue(Queue *q, int num){
    	q->Q[++ q->front] = num;
    }

    int dequeue(Queue *q){
    	return q->Q[++ q->rear];
    }

    void BFS(int **mat, int n, int v){
        int i;
        // initailising the queue structure
        Queue q; q.front = -1; q.rear = -1; q.Q = (int *)malloc(sizeof(int) * n);

        // initailing any array to note status of node, initailly 0 -> not visited
        int *visited = (int *)malloc(sizeof(int) * (n+1));

        // adding the starting node to the queue and marking it as visited
        enqueue(&q, v);
    	visited[v] = 1;

        // until the queue is not empty the DFS process is executed
        while(q.front != q.rear){
    		v = dequeue(&q);
            printf("%d--> ", v);

    		for(i=1; i<=n; i++){
    			if(mat[v][i] == 1 && visited[i]!=1){
    				enqueue(&q, i);
    				visited[i] = 1;
    			}
    		}
    	}

    }

    int main(){

    	struct timeval start_time, end_time;
    	struct rusage space_usage;

    	int startVertex, vertesis, i, j;
    	printf("\nEnter the total vertesis in the graph : ");
    	scanf("%d", &vertesis);

    	// int adjMatrix[vertesis + 1][vertesis + 1];
        int **adjMatrix = (int **)malloc(sizeof(int *) * (vertesis+1));
        for(int i=0; i<vertesis+1; i++){
            adjMatrix[i] = (int *)malloc((vertesis+1) * sizeof(*adjMatrix[i]));
        }

    	printf("\nEnter the adjecency matrix :-\n");
    	for(i=1; i<=vertesis; i++){
    		for(j=1; j<=vertesis; j++)
    			scanf("%d", &adjMatrix[i][j]);
    	}

    	printf("\nEnter the selected element to start from : ");
    	scanf("%d", &startVertex);
    	

    	gettimeofday(&start_time, NULL);

        BFS(adjMatrix, vertesis, startVertex);
    	
    	gettimeofday(&end_time, NULL);

    	printf("\n\nTime taken = %f microseconds\n",(double)(end_time.tv_usec-start_time.tv_usec));
        getrusage(RUSAGE_SELF, &space_usage);
        printf("Memory used : %ld kb\n", space_usage.ru_maxrss);

    	return 0;
    }
    ```

**Q 4. Consider a network having 'n' systems. Design a DFS based program in 'C' which outputs all systems reachable from a given system. Find its time and space complexity.**

- Code

    ```c
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
    ```

**Q 5. Suppose you are given a list of students who are assigned IDs. Write a C program to sort these students based on their id’s using heapsort. Find its time and space complexity**

[2.6.3 Heap - Heap Sort - Heapify - Priority Queues - YouTube](https://www.youtube.com/watch?v=HqPJF2L5h9U&t=2464s)

- Code

    ```c
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
    ```
