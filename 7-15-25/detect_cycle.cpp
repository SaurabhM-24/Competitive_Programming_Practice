// given an undirected graph, check if a cycle is present in it using DSU

#include <iostream>
using namespace std;

int find(int i, int parent[]) {

    if(i==parent[i])
        return i;
    
    return parent[i] = find(parent[i], parent);
}

bool hasCycle(int x, int y, int parent[], int rank[]) {

    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    if(x_parent == y_parent)
        return true;
    
    if(rank[x_parent] > rank[y_parent])
        parent[y_parent] = x_parent;
    
    else if(rank[y_parent] > rank[x_parent])
        parent[x_parent] = y_parent;
    
    else {
        parent[x_parent] = y_parent;
        rank[y_parent] += 1;
    }

    return false;
}

int main() {

    int V, E;
    cin >> V >> E;

    int parent[V+1];
    for(int i=0; i<=V; i++) {
        parent[i] = i;
    }

    int rank[V+1];
    fill(rank, rank+V+1, 0);

    int u, v;
    bool cycle = false;

    for(int i=0; i<E; i++) {
        cin >> u >> v;
        if(hasCycle(u, v, parent, rank))
        cycle = true;
    }

    if(cycle == false)
        cout << "No cycle exists.\n";
    else
        cout << "Cycle found!\n";
    
    return 0;
}