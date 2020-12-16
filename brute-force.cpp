#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int n;

int main() {

    n = 5;
    bool G[5][5] = {
                {0,1,1,0,0},
                {1,0,0,0,0},
                {1,0,0,1,1},
                {0,0,1,0,1},
                {0,0,1,1,0}
                };
    for (int i = 0; i < n; ++i) adj[i].clear();
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (G[i][j] == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }


    return 0;
}