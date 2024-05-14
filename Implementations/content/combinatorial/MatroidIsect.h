#pragma once

/**
 * Description: Computes a set of maximum size which is independent 
 	* in both graphic and colorful matroids, aka a spanning forest where
 	* no two edges are of the same color. In general, construct the exchange
 	* graph and find a shortest path. Can apply similar concept to partition
 	* matroid. M1 should have the slower matroid and M2 the faster matroid.
 * Time: $O(GI^{1.5})$ calls to oracles, where $G$ is size of ground set 
 	* and $I$ is size of independent set.
 * Source: https://codeforces.com/blog/entry/69287
 	* chilli (KACTL)
 * Verification: https://vjudge.net/problem/Gym-102156D
 * 				 https://vjudge.net/problem/SPOJ-COIN
 * Usage: MatroidIsect<Gmat,Cmat> M(Gmat(V,ed),Cmat(col),sz(ed)); M.solve();
 */

#include "../contest/template.hpp"
#include "../graphs/DSU/DSU.h"

struct Gmat { // graphic matroid
	int n; vpi ed; DSU D;
	Gmat(int _n, vpi _ed): n(_n), ed(_ed) { D.init(n); }
	void clear() { D.init(n); }
	void ins(int i) { assert(D.unite(ed[i].f, ed[i].s)); }
	bool indep(int i) { return !D.sameSet(ed[i].f, ed[i].s); }
};
struct Cmat { // colorful matroid
	int C = 0; vi col; vb used;
	Cmat(vi col):col(col) {each(t,col) ckmax(C,t+1); clear(); }
	void clear() { used.assign(C,0); }
	void ins(int i) { used[col[i]] = 1; }
	bool indep(int i) { return !used[col[i]]; }
};
struct Xmat { // XOR lineal matroid
	vl v, b;
	Xmat(vl _v) : v(_v) {}
	ll fun(ll a) { each(x, b) ckmin(a, a ^ x); return a; }
	void clear() { b.clear(); }
	void ins(int i) {
		ll a = fun(v[i]);
		for (i = 0; i < sz(b) && a < b[i]; ++i);
		b.insert(b.begin() + i, a);
	}
	bool indep(int i) { return fun(v[i]) > 0; }
};
template<class M1, class M2> struct MatroidIsect {
    int n;
    vb iset;
    M1 m1; M2 m2;
    MatroidIsect(M1 _m1, M2 _m2, int _n) : n(_n), iset(_n + 1), m1(_m1), m2(_m2) {}
    vi solve() {
        F0R(i, n) if (m1.indep(i) && m2.indep(i))
            iset[i] = true, m1.ins(i), m2.ins(i);
        while (augment());
        vi ans;
        F0R(i, n) if (iset[i]) ans.pb(i);
        return ans;
    }
    vi frm;
    queue<int> q;
    vi fwdE(int a) {
        vi ans;
        m1.clear();
        F0R(v, n) if (iset[v] && v != a) m1.ins(v);
        F0R(b, n) if (!iset[b] && frm[b] == -1 && m1.indep(b))
            ans.pb(b), frm[b] = a;
        return ans;
    }
    int backE(int b) {
        m2.clear();
        F0R(c,2) F0R(v, n)
            if ((v == b || iset[v]) && (frm[v] == -1) == c) {
                if (!m2.indep(v))
                    return c ? q.push(v), frm[v] = b, v : -1;
                m2.ins(v);
            }
        return n;
    }
    bool augment() {
        frm.assign(n, -1);
        q = {}; q.push(n); // dummy node
        while (!q.empty()) {
			int a = q.front(), c; q.pop();
			for (int b : fwdE(a))
				while((c = backE(b)) >= 0) if (c == n) {
					while (b != n) iset[b] = !iset[b], b = frm[b];
					return true;
				}
		}
		return false;
    }
};