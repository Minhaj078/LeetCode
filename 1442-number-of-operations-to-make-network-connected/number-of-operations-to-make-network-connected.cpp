class Solution {
public:
    class DisjointSet {
    public:
        vector<int> parent, size;

        DisjointSet(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int findPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int pu = findPar(u);
            int pv = findPar(v);
            if (pu == pv) return;
            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;

        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            if (ds.findPar(u) == ds.findPar(v)) {
                extraEdges++;  // cycle/extra edge
            } else {
                ds.unionBySize(u, v);
            }
        }

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (ds.findPar(i) == i)
                components++;
        }

        int neededEdges = components - 1;
        if (extraEdges >= neededEdges)
            return neededEdges;
        return -1;
    }
};
