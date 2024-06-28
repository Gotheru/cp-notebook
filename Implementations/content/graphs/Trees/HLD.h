/**
 * Description: Heavy-Light Decomposition, add val to verts 
 	* and query sum in path/subtree. @todo change so that it works for new LazySegTree!!!!
 * Time: any tree path is split into $O(\log N)$ parts
 * Source: http://codeforces.com/blog/entry/22072, https://codeforces.com/blog/entry/53170
 * Verification: https://vjudge.net/problem/Yosupo-vertex_add_path_sum
 */

#include "../../data-structures/1D-range-queries/LazySegTree.h"

template<typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E), T(*ti)(), E (*ei)(), bool VALS_IN_EDGES>
struct HLD {
    int n, t, log, s;
    V<vi> adj;
    vi par, root, depth, sz, pos, rpos;
    LazySegTree<T, E, f, g, h, ti, ei> tree;
    HLD(int _N) { n = _N, s = 1, log = 0;
        while (s < n) s <<= 1, ++log;
        adj.rsz(s), par.rsz(s), root.rsz(s), depth.rsz(s), sz.rsz(s), pos.rsz(s);
        V<T> v(n,ti());
        tree = LazySegTree<T,E,f,g,h,ti,ei>(v);
    }
    void ae(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
    void dfsSz(int x) {
        sz[x] = 1;
        each(y,adj[x]) {
            par[y] = x, depth[y] = depth[x] + 1;
            adj[y].erase(find(all(adj[y]),x)); // remove parent from adj list
            dfsSz(y); sz[x] += sz[y];
            if (sz[y] > sz[adj[x][0]]) swap(y,adj[x][0]);
        }
    }
    void dfsHld(int x) {
        pos[x] = t++; rpos.pb(x);
        each(y,adj[x]) {
            root[y] = (y == adj[x][0] ? root[x] : y);
            dfsHld(y); }
    }
    void init(int R = 0) {
        par[R] = depth[R] = t = 0; dfsSz(R);
        root[R] = R; dfsHld(R);
    }
    int lca(int x, int y) {
        for(; root[x] != root[y]; y = par[root[y]])
            if (depth[root[x]] > depth[root[y]]) swap(x,y);
        return depth[x] < depth[y] ? x : y;
    }
    void set(int x, T const& v) {
        tree.set_val(pos[x],v);
    }
    template<class BinaryOp>
    void processPath(int x, int y, BinaryOp op) {
        for (; root[x] != root[y]; y = par[root[y]]) {
            if (depth[root[x]] > depth[root[y]]) swap(x,y);
            op(pos[root[y]], pos[y]); }
        if (depth[x] > depth[y]) swap(x,y);
        op(pos[x]+VALS_IN_EDGES,pos[y]);
    }
    void modifyPath(int x, int y, E const& v) {
        processPath(x,y,[this,&v](int l, int r){tree.update(l,r+1,v);}); }
    T queryPath(int x, int y) {
        T res = ti();
        processPath(x,y,[this,&res](int l,int r){res=f(res,tree.query(l,r+1));});
        return res; }
    void modifySubtree(int x, E const& v) {
        tree.update(pos[x]+VALS_IN_EDGES,pos[x]+sz[x],v); }
};