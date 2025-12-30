#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int vertex; 
    struct Node* next; 
}; 
 
struct GraphList { 
    int numVertices; 
    struct Node** adjLists; 
}; 
 
struct Node* createNode(int v) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->vertex = v; 
    newNode->next = NULL; 
    return newNode; 
} 
 
struct GraphList* createGraphList(int vertices) { 
    struct GraphList* graph = (struct GraphList*)malloc(sizeof(struct GraphList)); 
    graph->numVertices = vertices; 
 
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*)); 
 
    for (int i = 0; i < vertices; i++) 
        graph->adjLists[i] = NULL; 
 
    return graph; 
} 
 
void addEdgeList(struct GraphList* graph, int src, int dest) { 
    struct Node* newNode = createNode(dest); 
    newNode->next = graph->adjLists[src]; 
    graph->adjLists[src] = newNode; 
 
    newNode = createNode(src); 
    newNode->next = graph->adjLists[dest]; 
    graph->adjLists[dest] = newNode; 
}
void printGraphList(struct GraphList* graph) { 
    for (int v = 0; v < graph->numVertices; v++) { 
        struct Node* temp = graph->adjLists[v]; 
        printf("\nAdjacency list of vertex %d: ", v); 
        while (temp) { 
            printf("%d -> ", temp->vertex); 
            temp = temp->next; 
        } 
        printf("NULL"); 
    } 
} 
 
void createGraphMatrix(int V) { 
    int graph[V][V]; 
    int edges, src, dest; 
 
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++) 
            graph[i][j] = 0; 
 
    printf("\nEnter number of edges: "); 
    scanf("%d", &edges); 
 
    printf("Enter edges (source destination):\n"); 
    for (int i = 0; i < edges; i++) { 
        scanf("%d %d", &src, &dest); 
        graph[src][dest] = 1; 
        graph[dest][src] = 1;   
    } 
 
    printf("\nAdjacency Matrix:\n"); 
    for (int i = 0; i < V; i++) { 
        for (int j = 0; j < V; j++) 
            printf("%d ", graph[i][j]); 
        printf("\n"); 
    } 
} 
 
 
int main() { 
    int V; 
    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
    printf("Enter number of vertices: "); 
    scanf("%d", &V);
    createGraphMatrix(V); 
 
    struct GraphList* graph = createGraphList(V); 
 
    int E, src, dest; 
    printf("\nEnter number of edges for adjacency list: "); 
    scanf("%d", &E); 
 
    printf("Enter edges (source destination):\n"); 
    for (int i = 0; i < E; i++) { 
        scanf("%d %d", &src, &dest); 
        addEdgeList(graph, src, dest); 
    } 
 
    printGraphList(graph); 
 
    return 0; 
} 
 
 
