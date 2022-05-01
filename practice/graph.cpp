#include <bits/stdc++.h>

using namespace std;

template <typename T> class Graph {
private:
  map<T, list<T>> adj;
  bool directed;
  map<T, bool> vertices;
  vector<T> dfs_order;

public:
  Graph(bool directed = false) : directed(directed) {}

  void addEdge(T u, T v) {
    vertices[u] = true;
    vertices[v] = true;
    adj[u].push_back(v);
    if (!directed)
      adj[v].push_back(u);
  }

  void reset() { dfs_order.clear(); }

  map<T, T> bfs(T s) {
    queue<T> q;
    q.push(s);
    map<T, T> parent;
    parent[s] = s;
    while (!q.empty()) {
      T u = q.front();
      q.pop();
      cout << u << " ";
      for (auto v : adj[u]) {
        if (parent.find(v) == parent.end()) {
          q.push(v);
          parent[v] = u;
        }
      }
    }
    return parent;
  }

  vector<T> dfs(T s) {
    map<T, bool> visited;
    dfs_order.push_back(s);
    for (auto v : adj[s]) {
      if (!visited[v]) {
        visited[v] = true;
        dfs(v);
      }
    }
    return dfs_order;
  }

  vector<T> topological_sort() {
    vector<T> v = dfs(vertices.begin()->first);
    reverse(v.begin(), v.end());
    return v;
  }
};
// int main (int argc, char *argv[])
int main() {
  Graph<char> g(true);
  g.addEdge('A', 'D');
  g.addEdge('A', 'B');
  g.addEdge('A', 'C');
  g.addEdge('D', 'E');
  g.addEdge('D', 'F');
  g.addEdge('B', 'G');
  g.addEdge('B', 'H');
  g.addEdge('C', 'I');
  g.addEdge('C', 'J');

  cout << "BFS: ";
  g.bfs('A');
  cout << endl;

  vector<char> d = g.dfs('A');
  cout << "DFS: ";
  for (auto v : d)
    cout << v << " ";
  cout << endl;
  g.reset();
  vector<char> srt = g.topological_sort();
  cout << "Topological Sort: ";
  for (auto v : srt) {
    cout << v << " ";
  }
  cout << endl;
  g.reset();
}
