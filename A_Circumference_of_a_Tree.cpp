#include "stdc++.h"

using namespace std;

class Node {
public:
    vector<Node> adj;
    int dist;
};

void dfs (Node from, vector<Node> nodes) {
    for (auto nn : nodes) {
        nn.dist = -1;
    }
    from.dist = 0;
    deque<Node> s;
    s.push_back(from);
    while (!s.empty()) {
        Node next = s.front();
        s.pop_front();
        for (auto nn : next.adj) {
            if (nn.dist == -1) {
                nn.dist = next.dist + 1;
                s.push_back(nn);
            }
        }
    }
}

Node farthest (vector<Node> nodes) {
    Node max = nodes[0];
    for (auto nn : nodes) {
        if (nn.dist > max.dist) {
            max = nn;
        }
    }
    return max;
}

int main () {
    int n; cin >> n;
    vector<Node> nodes(n);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        nodes[a].adj.push_back(nodes[b]);
        nodes[b].adj.push_back(nodes[a]);
    }
    dfs(nodes[0], nodes);
    Node far = farthest(nodes);
    dfs(far, nodes);
    cout << 3 * farthest(nodes).dist << endl;
}