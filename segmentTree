struct Node {
    ll val;
};
int a[N];
 
struct segmentTree {
    vector<Node> segment;
    ll neutral;
 
    segmentTree(int n) {
        segment.assign(n * 4, {0});
        neutral = 0;
    }
 
    Node merge(Node u, Node v) {
        u.val += v.val;
        return u;
    }
 
    void build(int node, int st, int ed) {
        if (st == ed) {
            segment[node].val = a[st];
            return;
        }
        int mid = (st + ed) >> 1;
        build(node << 1, st, mid);
        build(node << 1 | 1, mid + 1, ed);
        segment[node] = merge(segment[node << 1], segment[node << 1 | 1]);
 
    }
 
    void update(int node, int st, int ed, int idx, int val) {
        if (idx < st or idx > ed)
            return;
        if (st == ed) {
            segment[node].val = val;
            return;
        }
        int mid = (st + ed) >> 1;
        if (idx <= mid) update(node << 1, st, mid, idx, val);
        else update(node << 1 | 1, mid + 1, ed, idx, val);
        segment[node] = merge(segment[node << 1], segment[node << 1 | 1]);
    }
    Node query(int node,int st,int ed,int l,int r)
    {
         if(st > r or ed < l)
             return {(int)neutral};
        if (st >= l and ed <= r )
            return segment[node];
         int mid = (st + ed) >> 1;
         Node q1 = query(node << 1 , st , mid,l,r);
         Node q2 = query(node << 1 | 1 , mid + 1 , ed,l,r);
        return merge(q1,q2);
    }
};
