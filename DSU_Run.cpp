#include <bits/stdc++.h>
#include "DSU.h"

using namespace std;


int main()
{
    DSU dsu(7);

    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(4, 5);
    dsu.unionBySize(6, 7);
    dsu.unionBySize(5, 6);

    if(dsu.findParent(3) == dsu.findParent(7)) cout << "same" << endl;

    else cout << "Not Same" << endl;

    dsu.unionBySize(3, 7);

    if(dsu.findParent(3) == dsu.findParent(7)) cout << "same" << endl;

    else cout << "Not Same" << endl;
}