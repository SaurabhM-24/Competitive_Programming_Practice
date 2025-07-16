#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> bfs_min_path(const vector<vector<int>>& adj, int a, int b) {
    int n = adj.size();
    vector<int> dist(n, -1), parent(n, -1);
    queue<int> q;
    dist[a] = 0;
    q.push(a);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    if (dist[b] == -1) return path;

    for (int v = b; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*
    int a, b;
    cin >> a >> b;
    */

    vector<int> path = bfs_min_path(adj, 1, n);
    if (path.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << path.size() << "\n";
        for (int v : path) cout << v << " ";
        cout << "\n";
    }
    return 0;
}
