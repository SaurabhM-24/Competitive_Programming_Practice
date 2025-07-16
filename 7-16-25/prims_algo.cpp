#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int prims(vector<vector<pair<int, int>>>& adj, int V) {

    priority_queue<tuple<int, int, int>>pq;
    vector<bool>visited(V, false);
    vector<int>parent(V, -1);

    int sum=0;

    pq.push(make_tuple(0,0,-1));

    while(!pq.empty()) {
        tuple<int,int,int> t = pq.top();
        pq.pop();
        int cost = get<0>(t) * -1;
        int curr = get<1>(t);
        int parn = get<2>(t);

        if(visited[curr] == true)
            continue;

        sum += cost;
        parent[curr] = parn;
        visited[curr] = true;

        for(int i=0; i<adj[curr].size(); i++) {

            pair<int, int>p = adj[curr][i];
            int next = p.first;
            int weight = p.second;

            if(visited[next]==true)
                continue;
            
            pq.push(make_tuple(-weight, next, curr));
        }
    }
    return sum;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>>adj(V);

    int u, v, w;

    for(int i=0; i<E; i++) {
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int sum = prims(adj, V);
    cout << sum;

    return 0;
}
