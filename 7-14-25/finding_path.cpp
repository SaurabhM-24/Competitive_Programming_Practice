#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isPathExists(const vector<vector<int>>& adj, int a, int b) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(a);
    visited[a] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == b) return true;
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);

    cout << "Enter edges (from to):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int a, b;
    cout << "Enter start and end points: ";
    cin >> a >> b;

    if (isPathExists(adj, a, b)) {
        cout << "Path exists from " << a << " to " << b << endl;
    } else {
        cout << "No path exists from " << a << " to " << b << endl;
    }

    return 0;
}
