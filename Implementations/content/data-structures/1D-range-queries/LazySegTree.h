#pragma once

/**
 * Description: Segment Tree with lazy updates. Segments are [l,r)
 * Source: Nyaan's Library
 * Verification:
    * https://vjudge.net/problem/Yosupo-range_affine_range_sum
 * Time: O(\log N) per query
 */

#include "../../contest/template.hpp"

template<typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E), T(*ti)(), E (*ei)()>
struct LazySegTree {
    int n, log, s;
    V<T> val; V<E> laz;
    LazySegTree() {}
    LazySegTree(V<T> const& v) { init(v); }
    void init(V<T> const& v) {
        n = 1, log = 0, s = sz(v);
        while (n < s) n <<= 1, ++log;
        val.rsz(2 * n, ti());
        laz.rsz(n, ei());
        F0R(i, s) val[i+n] = v[i];
        ROF(i,1,n) _update(i);
    }
    void update(int l, int r, E const& x) {
        if (l >= r) return;
        l += n, r += n;
        ROF(i,1,log+1) {
            if (((l>>i)<<i) != l) _push(l>>i);
            if (((r>>i)<<i) != r) _push((r-1)>>i);
        }
        int l2 = l, r2 = r;
        while (l < r) {
            if (l & 1) _apply(l++,x);
            if (r & 1) _apply(--r,x);
            l >>= 1, r >>= 1;
        }
        l = l2, r = r2;
        FOR(i,1,log+1) {
            if (((l>>i)<<i) != l) _update(l>>i);
            if (((r>>i)<<i) != r) _update((r-1)>>i);
        }
    }
    T query(int l, int r) {
        if (l >= r) return ti();
        l += n, r +=n;
        T L = ti(), R = ti();
        ROF(i,1,log+1) {
            if (((l>>i)<<i) != l) _push(l>>i);
            if (((r>>i)<<i) != r) _push((r-1)>>i);
        }
        while (l < r) {
            if (l & 1) L = f(L,val[l++]);
            if (r & 1) R = f(val[--r], R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }
    void set_val(int k, T const& x) {
        k += n;
        ROF(i,1,log+1)
            if (((k>>i)<<i) != k or (((k+1)>>i)<<i) != (k+1))
                _push(k>>i);
        val[k] = x;
        FOR(i,1,log+1)
            if (((k>>i)<<i) != k or (((k+1)>>i)<<i) != (k+1))
                _update(k>>i);
    }
private:
    void _push(int i) {
        if (laz[i] != ei()) {
            F0R(j,2) val[2*i+j] = g(val[2*i+j],laz[i]);
            if (2*i<n) F0R(j,2) compose(laz[2*i+j], laz[i]);
        }
        laz[i] = ei();
    }
    inline void _update(int i) { val[i] = f(val[2*i],val[2*i+1]); }
    inline void _apply(int i, E const& x) {
        if (x != ei()) {
            val[i] = g(val[i], x);
            if (i < n) compose(laz[i], x);
        }
    }
    inline void compose(E& a, E const& b) { a = a == ei() ? b : h(a, b); }
};