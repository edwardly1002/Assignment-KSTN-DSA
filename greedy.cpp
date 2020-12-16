#include <bits/stdc++.h>
using namespace std;

#define i2 pair<int,int>

vector<int> adj[100];
int n;

void greedy_coloring(const vector<int>* adj, int n, vector<int> &result) {
    result.clear();
    for (int i = 0; i < n; ++i) result.push_back(0);

    int color = 1;

    while (true) {
        priority_queue<i2, vector<i2> > Q;
        for (int i = 0; i < n; ++i) { ///For step 4: eliminate colored vertices and resort the whole set
            if (result[i] == 0) Q.push({adj[i].size(), i});
        }

        if (Q.empty()) break; ///No more uncolored vertices

        set<int> eliminated; ///For step 2: dont touch vertices that are adjacent to vertices colored i
        while(!Q.empty()) {
            i2 u = Q.top();
            Q.pop();
            if (eliminated.find(u.second)==eliminated.end()) {
                result[u.second] = color;
                for (int j : adj[u.second]) eliminated.insert(j); ///eliminate all adjacent vertices
            }
        }
        color++;
    }
}


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

    vector<int> result;
    greedy_coloring(adj, n, result);

    for (int i : result) cout << i << " ";
    cout << endl;

    return 0;
}