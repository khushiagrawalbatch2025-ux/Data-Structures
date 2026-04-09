#include <stdio.h>
}

// Function to sort the adjacency list for each vertex
void sortAdjList(int V) {
    for (int i = 0; i < V; i++) {
        struct Node *ptr1, *ptr2;
        for (ptr1 = adjList[i]; ptr1 != NULL; ptr1 = ptr1->next) {
            for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
                if (ptr1->vertex > ptr2->vertex) {
                    int temp = ptr1->vertex;
                    ptr1->vertex = ptr2->vertex;
                    ptr2->vertex = temp;
                }
            }
        }
	}
}

// Depth-First Search (DFS) function
void DFS(int start) {
        visited[start] = 1;
    printf("%d ", start);

    struct Node* temp = adjList[start];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!visited[v]) {
            DFS(v);
        }
        temp = temp->next;
	}
}

int main() {
    int V, E;
    int u, v, start;

    // Read number of vertices and edges
    scanf("%d %d", &V, &E);

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Read the edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Sort the adjacency list for each vertex
    sortAdjList(V);

    // Read the starting node
    scanf("%d", &start);

    // Perform DFS starting from the given node
    DFS(start);

    return 0;
}
