#pragma once

/**
 * Author: Gotheru
 * Description: 1-based with closed ranges $[a,b]$. T = long long is prefered as you have to multiply elements by N.
 * Source: cp-algorithms
 * Time: O(\log{N})
 * Verification: @todo
 */

#include "../../contest/template.hpp"

tcT> struct FT {
    V<T> B1, B2;
    FT(int N) : B1(N+1), B2(N+1) {};
    void add(V<T>& b, int p, T x) { for(;p<sz(b);p+=p&-p) b[p]+=x; }
    void range_add(int l, int r, T x) {
        add(B1, l, x);
        add(B1, r + 1, -x);
        add(B2, l, x * (l - 1));
        add(B2, r + 1, -x * r);
    }
    T sum(V<T>& b, int p) { T s = 0; for(;p;p-=p&-p) s+=b[p]; return s; }
    T prefix_sum(int idx) { return sum(B1,idx)*idx - sum(B2,idx); }
    T range_sum(int l, int r) {return prefix_sum(r) - prefix_sum(l - 1);}
};