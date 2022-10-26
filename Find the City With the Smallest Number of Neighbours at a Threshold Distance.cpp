#include <bits/stdc++.h>
using namespace std;

int dikjstra(int n, vector<pair<int, int>> adj[], int distanceThreshold, int src)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    while(!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;

            if(edW + dis < dist[adjNode])
            {
                dist[adjNode] = edW + dis;

                pq.push({edW + dis, adjNode});
            }
        }
    }

    int count = 0;
    for(auto it: dist)
    {
        if(it <= distanceThreshold && it != src) count++;
    }

    return count;
}

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
{
    vector<pair<int, int>> adj[n];
    for(auto it: edges)
    {
        adj[it[0]].emplace_back(it[1], it[2]);
        adj[it[1]].emplace_back(it[0], it[2]);
    }

    int mini = 1e9;
    int minCity = 0;

    for(int i = 0; i < n; i++)
    {
        int noOfCities = dikjstra(n, adj, distanceThreshold, i);

        if(mini >= noOfCities)
        {
            mini = noOfCities;
            minCity = i;
        }
    }
    
    return minCity;
}

int main()
{
    int n;
    cin >> n;


}
