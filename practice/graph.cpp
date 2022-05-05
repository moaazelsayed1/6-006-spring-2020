#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>

using namespace std;

template <typename T> class Graph {
private:
  map<T, list<T>> adj;
  bool directed;
  vector<T> dfs_order;
  vector<T> bfs_order;

public:
  Graph(bool directed = false) : directed(directed) {}

  void addEdge(T u, T v) {
    adj[u].push_back(v);
    if (!directed)
      adj[v].push_back(u);
  }

  void reset() {
    dfs_order.clear();
    bfs_order.clear();
  }

  void bfs(T s, map<T, bool> &visited) {
    queue<T> q;
    q.push(s);
    while (!q.empty()) {
      T u = q.front();
      q.pop();
      bfs_order.push_back(u);
      for (auto v : adj[u]) {
        if (!visited[v]) {
          q.push(v);
          visited[v] = true;
        }
      }
    }
  }

  vector<T> bfs_traversal() {
    reset();
    map<T, bool> visited;
    for (auto v : adj) {
      if (!visited[v.first]) {
        visited[v.first] = true;
        bfs(v.first, visited);
      }
    }
    return bfs_order;
  }

  void dfs(T s, map<T, bool> &visited, bool topsort = false) {

    if (!topsort) {
      dfs_order.push_back(s);
    }
    for (auto v : adj[s]) {
      if (!visited[v]) {
        visited[v] = true;
        dfs(v, visited, topsort);
      }
    }
    if (topsort) {
      dfs_order.push_back(s);
    }
  }

  vector<T> dfs_traversal() {
    reset();
    map<T, bool> visited;
    for (auto v : adj) {
      if (!visited[v.first]) {
        visited[v.first] = true;
        dfs(v.first, visited);
      }
    }
    return dfs_order;
  }

  vector<T> topological_sort() {
    reset();
    map<T, bool> visited;
    for (auto v : adj) {
      if (!visited[v.first]) {
        visited[v.first] = true;
        dfs(v.first, visited, true);
      }
    }
    reverse(dfs_order.begin(), dfs_order.end());
    return dfs_order;
  }
};

int main() {
  Graph<char> g(true);
  g.addEdge('A', 'D');
  g.addEdge('D', 'H');
  g.addEdge('D', 'G');
  g.addEdge('C', 'A');
  g.addEdge('C', 'B');
  g.addEdge('B', 'D');
  g.addEdge('E', 'D');
  g.addEdge('E', 'F');
  g.addEdge('E', 'A');
  g.addEdge('F', 'J');
  g.addEdge('F', 'K');
  g.addEdge('H', 'I');
  g.addEdge('H', 'J');
  g.addEdge('K', 'J');
  g.addEdge('J', 'M');
  g.addEdge('J', 'L');
  g.addEdge('I', 'L');
  g.addEdge('G', 'I');

  cout << "BFS: ";
  vector<char> b = g.bfs_traversal();
  for (auto c : b)
    cout << c << " ";
  cout << endl;

  vector<char> d = g.dfs_traversal();
  cout << "DFS: ";
  for (auto v : d)
    cout << v << " ";
  cout << endl;
  g.reset();

  cout << "Topological Sort: ";
  vector<char> t = g.topological_sort();
  for (auto v : t)
    cout << v << " ";
  cout << endl;
}
