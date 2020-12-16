#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int n, k;

bool check_coloring(const vector<int>* adj, int n, const vector<int> &result) {
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            if (result[i] == result[j]) return false;
        }
    }
    return true;
}

///return true if exist a valid coloring
/// polynomial is "chromatic polynomial"
/// t is the counting var, telling what vertex is processed
bool brute_force(const vector<int>* adj, int n, vector<int> &result, int &polynomial, int t) { 
    bool flag = false;
    for (int i = 1; i <= k; ++i) {
        result[t] = i;
        if (t == n-1) {
            bool tmp_flag = check_coloring(adj, n, result);
            flag = flag || tmp_flag;
            if (tmp_flag) {
                polynomial++;
                cout << "NEW COLORING" << endl;
                for (int j = 0; j < n; ++j) cout << result[j] << " ";
                cout << endl;
            }
        }
        else {
            bool tmp_flag = brute_force(adj, n, result, polynomial, t+1); 
            flag = flag || tmp_flag;
        }
    }
    return flag;
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


    k = 2; ///k colors 

    vector<int> result(n);
    int polynomial = 0;
    brute_force(adj, n, result, polynomial, 0);

    return 0;
}