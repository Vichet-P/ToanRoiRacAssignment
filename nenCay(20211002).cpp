#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n);
    unordered_map<int, int> degree;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[i].push_back(u);
        edges[i].push_back(v);
        degree[u]++;
        degree[v]++;
    }

    vector<int> prufer;

    for (int i = 1; i <= n + 1; i++) {
        if (degree[i] == 1) {
            for (int j = 0; j < n; j++) {
                if (edges[j][0] == i || edges[j][1] == i) {
                    int u = edges[j][0];
                    int v = edges[j][1];
                    prufer.push_back(u == i ? v : u);
                    degree[u]--;
                    degree[v]--;
                    break;
                }
            }
        }
    }

    for (int i : prufer) {
        cout << i << " ";
    }

    return 0;
}
