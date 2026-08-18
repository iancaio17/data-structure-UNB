#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int parent[MAX];

void add_edge(int src, int dest) {
  graph[src][dest] = 1;
  graph[dest][src] = 1;
}

int DFS(int v, int n, int target) {
  visited[v] = 1;

  if (v == target) {
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (graph[v][i] == 1 && !visited[i]) {
      parent[i] = v;
      if (DFS(i, n, target))
        return 1;
    }
  }

  return 0;
}

void BFS(int graph[MAX][MAX], int n, int start, int target) {
  int visited[MAX] = {0};
  Queue q;

  init_queue(&q);

  visited[start] = 1;
  enqueue(&q, start);

  while (!is_empty(&q)) {
    int current = dequeue(&q);

    if (current == target)
      return;

    for (int i = 0; i < n; i++) {
      if (graph[current][i] == 1 && !visited[i]) {
        visited[i] = 1;
        parent[i] = current;
        enqueue(&q, i);
      }
    }
  }
}

void reset_visited(int n) {
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }
}

void print_path(int v) {
  if (v == -1)
    return;

  print_path(parent[v]);
  printf("%d ", v);
}
int main(){

  return 0;
}
