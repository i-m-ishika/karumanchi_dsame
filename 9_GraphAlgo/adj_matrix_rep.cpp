// Adjacency matrix representation of a graph.
// If there is an edge between vertices v and u, adj[u][v] = adj[v][u] = 1 (or true).

#include <stdio.h>
#include <iostream>
#include <vector>

using ::std::vector;
namespace graph {
  struct Graph {
    int v;
    int e;
    vector<vector<int>> *adj;
    Graph(int v=0, int e=0) {
      this->v = v;
      this->e = e;
      adj = new vector<vector<int>>(v, vector<int>(v, 0));
    }
    void SetEdge(int u, int v) {
      if (u>=this->v || v>=this->v) {
        std::cout << "Enter valid node.";
        throw std::exception();
      }
      (*adj)[u][v] = 1;
      (*adj)[v][u] = 1;
    }
  };
  Graph CreateGraphFromUserInput();
} // namespace graph

graph::Graph graph::CreateGraphFromUserInput() {
  int v, e;
  std::cout << "Enter number of vertices: ";
  std::cin >> v;
  std::cout << "Enter number of edges: ";
  std::cin >> e;
  Graph g(v, e);
  for (int i=0; i<e; ++i) {
    int u, v;
    std::cout << "Enter nodes for edges in the format <node1> <node2>:\n";
    std::cin>>u>>v;
    g.SetEdge(u, v);
  }
  return g;

}

int main() {
  graph::Graph g = graph::CreateGraphFromUserInput();
  std::cout<<g.v<<" "<<g.e<<"\n";
  return 0;
}
