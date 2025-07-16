// create and print a graph using using its adjacency list

#include <iostream>
#include <vector>
using namespace std;

void printGraph(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        cout << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V+1);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Adjacency List:" << endl;
    printGraph(adj);

    return 0;
}
