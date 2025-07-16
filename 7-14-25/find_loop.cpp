#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int>> adj;
vector<int> parent, visited;
vector<int> loop;

bool dfs(int u, int p) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v, u)) return true;
        } else if (v != p) {
            // Found a loop
            int cur = u;
            loop.push_back(v);
            while (cur != v) {
                loop.push_back(cur);
                cur = parent[cur];
            }
            loop.push_back(v);
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    parent.resize(n + 1, -1);
    visited.resize(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                cout << loop.size() << endl;
                for (int x : loop)
                    cout << x << " ";
                cout << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
