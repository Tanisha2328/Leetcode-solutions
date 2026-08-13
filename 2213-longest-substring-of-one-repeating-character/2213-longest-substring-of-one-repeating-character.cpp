class Solution {
     struct Node {
        int l, r;
        int leftMax, rightMax, best;
    };

    vector<Node> tree;
    string s;

    void build(int node, int l, int r) {
        tree[node] = {l, r, 1, 1, 1};

        if (l == r)
            return;

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        merge(node);
    }

    void merge(int node) {
        Node &L = tree[node * 2];
        Node &R = tree[node * 2 + 1];
        Node &cur = tree[node];

        cur.leftMax = L.leftMax;
        cur.rightMax = R.rightMax;

        cur.best = max(L.best, R.best);

        if (s[L.r] == s[R.l]) {
            cur.best = max(cur.best, L.rightMax + R.leftMax);

            if (L.leftMax == L.r - L.l + 1)
                cur.leftMax += R.leftMax;

            if (R.rightMax == R.r - R.l + 1)
                cur.rightMax += L.rightMax;
        }
    }

    void update(int node, int idx, char ch) {
        if (tree[node].l == tree[node].r) {
            s[idx] = ch;
            return;
        }

        int mid = (tree[node].l + tree[node].r) / 2;

        if (idx <= mid)
            update(node * 2, idx, ch);
        else
            update(node * 2 + 1, idx, ch);

        merge(node);
    }
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
          this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, idx, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};
