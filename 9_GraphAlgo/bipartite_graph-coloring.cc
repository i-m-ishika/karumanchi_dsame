// Solution to the Bipartite problem using 2-Graph Coloring.

// A graph is called bipartite iff it doesn't have an odd length cycle.
// k-Graph Coloring of a graph G is an assignment of one color to each vertex of G such that no more than k colors are used and no two vertices are assigned the same color.

#include <stdio.h>
#include <vector>
#include <queue>
using ::std::vector;
namespace graph {
  bool isComponentBipartite(const vector<vector<int>> &graph, int start, vector<int>& vstd);
  bool isBipartite(const vector<vector<int>>& graph);
}; // namespace graph

bool graph::isComponentBipartite(const vector<vector<int>>& graph, int start, vector<int> &vstd) {
  vstd[start] = 0;
  std::queue<int> nbrs;
  nbrs.push(start);
  while (!nbrs.empty()) {
    int nd = nbrs.front();
    nbrs.pop();
    // Iterate over all neigbhours of nd.
    for (int n: graph[nd]) {
      if (vstd[n] == vstd[nd]) {
        return false;
      }
      if (vstd[n] == -1) {
        // Assign color complementary to the color of node nd.
        vstd[n] = ~vstd[nd];
        nbrs.push(n);
      }
    }
  }
  return true;
}

bool graph::isBipartite(const vector<vector<int>> &graph) {
  // Input graph has - no self edges, no parallel edges, undirected.
  vector<int> vstd(graph.size(), -1);
  // Check all components of the graph.
  for (int i=0; i<graph.size(); ++i) {    
    if (vstd[i]==-1 && !isComponentBipartite(graph, i, vstd)) {
      return false;
    }
  }
  return true;
}

int main() {
  return 0;
}
