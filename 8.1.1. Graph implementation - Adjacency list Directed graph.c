#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int vertex;
};
typedef struct node *GNODE;

GNODE graph[20];
void print(int *N) {
	for (int i = 1; i <= *N; i++) {
		if (graph[i] != NULL) {
			printf("%d=>", i);

			GNODE p = graph[i];
			while (p != NULL) {
				printf("%d\t", p->vertex);
				p = p->next;
			}
			printf("\n");
		}
	}
} void insertEdge(int *N) {
	int src, dest;

	printf("Enter the source vertex of the edge : ");
	scanf("%d", &src);

	printf("Enter the destination vertex of the edge : ");
	scanf("%d", &dest);

	if (src < 1 || src > *N || dest < 1 || dest > *N) {
		printf("Invalid vertex.\n");
		return;
	}
