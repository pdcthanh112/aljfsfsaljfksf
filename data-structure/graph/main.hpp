#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct Edge {
  int src, dest, weight;
};

class Graph {
 public:
  int V, E;
  std::vector<Edge> edges;

  Graph(int V, int E) {
    this->V = V;
    this->E = E;
  }

  void addEdge(int src, int dest, int weight) {
    Edge edge = {src, dest, weight};
    edges.push_back(edge);
  }

  void kruskal();
  void prim();
  void dijkstra(int startVertex);
  void BFS(int startVertex);
  void DFS(int startVertex);
};

struct DisjointSets {
  int *parent, *rank;
  int n;

  DisjointSets(int n) {
    this->n = n;
    parent = new int[n + 1];
    rank = new int[n + 1];

    for (int i = 0; i <= n; i++) {
      rank[i] = 0;
      parent[i] = i;
    }
  }

  int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

  void merge(int x, int y) {
    x = find(x), y = find(y);

    if (rank[x] > rank[y])
      parent[y] = x;
    else
      parent[x] = y;

    if (rank[x] == rank[y])
      rank[y]++;
  }
};

void Graph::kruskal() {
  std::vector<Edge> result;
  int e = 0, i = 0;

  std::sort(edges.begin(), edges.end(), [](Edge const& a, Edge const& b) {
    return a.weight < b.weight;
  });

  DisjointSets ds(V);

  while (e < V - 1 && i < E) {
    Edge next_edge = edges[i++];
    int x = ds.find(next_edge.src);
    int y = ds.find(next_edge.dest);

    if (x != y) {
      result.push_back(next_edge);
      ds.merge(x, y);
      e++;
    }
  }

  std::cout << "Kruskal's Minimum Spanning Tree:\n";
  for (i = 0; i < e; i++)
    std::cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << std::endl;
}

void Graph::prim() {
  std::vector<int> parent(V, -1);
  std::vector<int> key(V, INT_MAX);
  std::vector<bool> inMST(V, false);

  key[0] = 0;

  for (int count = 0; count < V - 1; count++) {
    int u = -1;
    for (int v = 0; v < V; v++) {
      if (!inMST[v] && (u == -1 || key[v] < key[u]))
        u = v;
    }

    inMST[u] = true;

    for (Edge& edge : edges) {
      if (edge.src == u && !inMST[edge.dest] && edge.weight < key[edge.dest]) {
        parent[edge.dest] = u;
        key[edge.dest] = edge.weight;
      }
    }
  }

  std::cout << "Prim's Minimum Spanning Tree:\n";
  for (int i = 1; i < V; i++)
    std::cout << parent[i] << " - " << i << " : " << key[i] << std::endl;
}

void Graph::dijkstra(int startVertex) {
  std::vector<int> dist(V, INT_MAX);
  dist[startVertex] = 0;

  std::vector<bool> visited(V, false);

  for (int count = 0; count < V - 1; count++) {
    int u = -1;
    for (int v = 0; v < V; v++) {
      if (!visited[v] && (u == -1 || dist[v] < dist[u]))
        u = v;
    }

    visited[u] = true;

    for (Edge& edge : edges) {
      if (edge.src == u && dist[u] != INT_MAX && dist[u] + edge.weight < dist[edge.dest])
        dist[edge.dest] = dist[u] + edge.weight;
    }
  }

  std::cout << "Dijkstra's Shortest Path from vertex " << startVertex << ":\n";
  for (int i = 0; i < V; i++)
    std::cout << "Vertex " << i << " : " << dist[i] << std::endl;
}

void Graph::BFS(int startVertex) {
  std::vector<bool> visited(V, false);
  std::queue<int> q;

  visited[startVertex] = true;
  q.push(startVertex);

  std::cout << "BFS Traversal starting from vertex " << startVertex << ":\n";

  while (!q.empty()) {
    int u = q.front();
    std::cout << u << " ";
    q.pop();

    for (Edge& edge : edges) {
      if (edge.src == u && !visited[edge.dest]) {
        visited[edge.dest] = true;
        q.push(edge.dest);
      }
    }
  }
  std::cout << std::endl;
}

void Graph::DFS(int startVertex) {
  std::vector<bool> visited(V, false);
  std::stack<int> s;

  s.push(startVertex);

  std::cout << "DFS Traversal starting from vertex " << startVertex << ":\n";

  while (!s.empty()) {
    int u = s.top();
    s.pop();

    if (!visited[u]) {
      std::cout << u << " ";
      visited[u] = true;
    }

    for (Edge& edge : edges) {
      if (edge.src == u && !visited[edge.dest]) {
        s.push(edge.dest);
      }
    }
  }
  std::cout << std::endl;
}

void handleGraph() {
  int V = 12;  // Số đỉnh
  int E = 15;  // Số cạnh
  Graph graph(V, E);

  graph.addEdge(0, 1, 10);
  graph.addEdge(0, 2, 6);
  graph.addEdge(0, 3, 5);
  graph.addEdge(1, 3, 15);
  graph.addEdge(2, 3, 4);
  graph.addEdge(2, 4, 2);
  graph.addEdge(3, 5, 8);
  graph.addEdge(4, 5, 3);
  graph.addEdge(4, 6, 9);
  graph.addEdge(5, 7, 7);
  graph.addEdge(6, 7, 11);
  graph.addEdge(7, 8, 1);
  graph.addEdge(8, 9, 12);
  graph.addEdge(9, 10, 13);
  graph.addEdge(10, 11, 14);

  int choice;
  do {
    std::cout << "===============================================================================================================\n";
    std::cout << "||                                                        GRAPH                                              ||\n";
    std::cout << "||                              -------------------------------------------------------                      ||\n";
    std::cout << "||                      1. Kruskal                                                                           ||\n";
    std::cout << "||                      2. Prim                                                                              ||\n";
    std::cout << "||                      3. Dijkstra                                                                          ||\n";
    std::cout << "||                      4. Breadth First Search - BFS                                                        ||\n";
    std::cout << "||                      5. Depth First Search - BFS                                                          ||\n";
    std::cout << "||                      0. Exits                                                                             ||\n";
    std::cout << "===============================================================================================================\n";
    choice = getUserChoice(1, 5, 0);

    switch (choice) {
      case 1: {
        graph.kruskal();
        break;
      }
      case 2: {
        graph.prim();

        break;
      }
      case 3: {
        graph.dijkstra(0);

        break;
      }
      case 4: {
        graph.BFS(0);
        break;
      }
      case 5:
        graph.DFS(0);
        break;
      default:
        break;
    }
  } while (choice != 0);
}
