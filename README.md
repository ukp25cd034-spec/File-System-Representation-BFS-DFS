
# File System Representation and Search Using BFS and DFS

## Project Description
This project is developed using C programming. It represents a file system as a graph using an adjacency matrix. Each file or directory is represented as a node, and connections between them are represented as edges.

The project implements Breadth First Search (BFS) and Depth First Search (DFS) algorithms to search for a specified file or directory.

## Objectives

- To represent a file system using a graph.
- To implement an adjacency matrix.
- To perform BFS traversal.
- To perform DFS traversal.
- To search for a specific file or directory.

## Programming Language
- C Programming

## Concepts Used
- Graph
- Adjacency Matrix
- Breadth First Search (BFS)
- Depth First Search (DFS)
- Queue
- Recursion

## Algorithm
### BFS
1. Start from the selected node.
2. Mark the node as visited.
3. Insert it into the queue.
4. Visit adjacent unvisited nodes.
5. Continue until the queue is empty.

### DFS
1. Start from the selected node.
2. Mark the node as visited.
3. Visit an unvisited adjacent node.
4. Repeat recursively.
5. Stop when all reachable nodes are visited.

## Sample Input
```text
Number of nodes: 5

Root
Documents
Pictures
Notes
Photo

Connections:
0 1
0 2
1 3
2 4

Starting node: 0
Search file: Photo
```

## Sample Output
```text
BFS Traversal:
Root Documents Pictures Notes Photo

BFS Result: File Found

DFS Traversal:
Root Documents Notes Pictures Photo

DFS Result: File Found
```

## Advantages
- Easy file searching.
- Demonstrates graph traversal.
- Uses simple data structures.
- Supports BFS and DFS searching.

## Applications
- File system navigation.
- Directory searching.
- Graph traversal.
- Data organization.

## Conclusion
This project demonstrates file system representation using graphs and searching using BFS and DFS algorithms. It helps understand graph representation and traversal techniques in data structures.

## Developed By
Muhammad Ashik PN
