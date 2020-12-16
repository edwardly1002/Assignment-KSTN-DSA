#include <bits/stdc++.h>
using namespace std;

#define i2 pair<int,int>

vector<int> adj[100];
int n;

void to_line_graph(vector<int>* adj, int n, vector<int>* &result, int &out_n) {
    ///computing number of output vertices
    out_n = 0;
    for (int i = 0; i < n; ++i) out_n += adj[i].size();
    out_n /= 2;
    
    if (result) delete[] result;
    result = new vector<int>[out_n];

    ///new vertices
    int cnt = 0; 
    map<i2, int> m;
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            if (j > i) m[{i, j}] = cnt++;
        }
    }
    //preprocess before adding edges
    vector<int>* cpy_adj = new vector<int>[n];
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            if (j > i) cpy_adj[i].push_back(m[{i,j}]);
            else cpy_adj[i].push_back(m[{j, i}]);
        }
    }
    //add edges
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < cpy_adj[i].size(); ++j) {
            for (int k = j+1; k < cpy_adj[i].size(); ++k) {
                result[cpy_adj[i][j]].push_back(cpy_adj[i][k]);
                result[cpy_adj[i][k]].push_back(cpy_adj[i][j]);
            }
        }
    }

    delete[] cpy_adj;
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

    vector<int>* result = nullptr;
    int out_n;
    to_line_graph(adj, n, result, out_n);
    // for (int i = 0; i < out_n; ++i) {
    //     cout << "i = " << i << endl;
    //     for (int j : result[i]) cout << j << " ";
    //     cout << endl;
    // }


    return 0;
}