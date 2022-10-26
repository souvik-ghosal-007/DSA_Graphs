#include <bits/stdc++.h>
using namespace std;

class DSU {

    vector<int> rank, parent, size;

public:
    explicit DSU(int n)
    {
        rank.resize(n+1, 0);

        parent.resize(n+1);
        for(int i = 0; i <= n; i++) parent[i] = i;

        size.resize(n+1, 1);
    }

    //find ultimate parent and path compression
    int findParent(int node)
    {
        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if(parentU == parentV) return;

        if(rank[parentU] < rank[parentV])
        {
            //the smaller rank goes and gets attached to the bigger rank
            parent[parentU] = parentV;
        }
        else if(rank[parentV] < rank[parentU])
        {
            //the smaller rank goes and gets attached to the bigger rank
            parent[parentV] = parentU;
        }
        else
        {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if(parentU == parentV) return;

        if(size[parentU] < size[parentV])
        {
            //the smaller size goes and gets attached to the bigger rank
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else
        {

            //the smaller size goes and gets attached to the bigger rank
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};