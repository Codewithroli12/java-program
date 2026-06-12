class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int LOG = 18;

    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> adj;

    void dfs(int u, int p) {
        up[0][u] = p;

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i))
                u = up[i][u];
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        }

        return up[0][u];
    }

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        adj.resize(n + 1);
        depth.assign(n + 1, 0);
        up.assign(LOG, vector<int>(n + 1));

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 1);

        for (int i = 1; i < LOG; i++) {
            for (int v = 1; v <= n; v++) {
                up[i][v] = up[i - 1][up[i - 1][v]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int a = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[a];

            ans.push_back(modPow(2, dist - 1));
        }

        return ans;
    }
};