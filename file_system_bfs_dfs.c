#include <stdio.h>
#include <string.h>

#define MAX 50
#define NAME_LEN 50

int graph[MAX][MAX];
char names[MAX][NAME_LEN];
int visited[MAX];
int n;

// Breadth First Search (BFS)
int bfs(int start, const char target[])
{
    int queue[MAX];
    int front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];

        printf("%s ", names[current]);

        if (strcmp(names[current], target) == 0)
            found = 1;

        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return found;
}

// Depth First Search (DFS)
void dfsVisit(int current, const char target[], int *found)
{
    visited[current] = 1;

    printf("%s ", names[current]);

    if (strcmp(names[current], target) == 0)
        *found = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[current][i] == 1 && !visited[i])
        {
            dfsVisit(i, target, found);
        }
    }
}

int dfs(int start, const char target[])
{
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");

    dfsVisit(start, target, &found);

    return found;
}

// Main Function
int main()
{
    int edges, parent, child, start;
    char target[NAME_LEN];

    printf("FILE SYSTEM USING BFS AND DFS\n");

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter name of node %d: ", i);
        scanf("%49s", names[i]);
    }

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of connections: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > n * n)
    {
        printf("Invalid number of connections.\n");
        return 1;
    }

    printf("Enter parent and child node numbers:\n");

    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &parent, &child);

        if (parent < 0 || parent >= n ||
            child < 0 || child >= n)
        {
            printf("Invalid connection.\n");
            return 1;
        }

        graph[parent][child] = 1;
    }

    printf("\nNode List:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d - %s\n", i, names[i]);
    }

    printf("\nEnter starting node: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting node.\n");
        return 1;
    }

    printf("Enter file name to search: ");
    scanf("%49s", target);

    // BFS Search
    if (bfs(start, target))
        printf("\nBFS Result: File Found");
    else
        printf("\nBFS Result: File Not Found");

    // DFS Search
    if (dfs(start, target))
        printf("\nDFS Result: File Found");
    else
        printf("\nDFS Result: File Not Found");

    return 0;
}
