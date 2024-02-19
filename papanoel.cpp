#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rk;
 int n,m;

void make_set(int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap(a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            rk[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};


int main()
{
       
     while(scanf("%d %d",&n,&m),n!=0 && m!=0){
        vector<Edge> edges;
        while(m--){
            int a,b,peso;
            scanf("%d %d %d",&a,&b,&peso);
            edges.push_back({a,b,peso});
        }
        long long cost = 0;
        vector<Edge> result;
        parent.resize(n);
        rk.resize(n);
        for (int i = 0; i < n; i++)
            make_set(i);

        sort(edges.begin(), edges.end());

        for (Edge e : edges) {
            if (find_set(e.u) != find_set(e.v)) {
                cost += e.weight;
                result.push_back(e);
                union_sets(e.u, e.v);
            }
        }
       printf("%d\n",cost);
       
    }
}