/**
 * Description: Solves Divide and Conquer DP
 * Time: O(NM\log{M})
 * Source: cp-algorithms
 * Verification: @todo
 */

#include "../../contest/template.hpp"

using T = ll;
V<T> dp_before, dp_cur;
T C(int k, int j); // Cost function
// Computes dp_cur[l] ... dp_cur[r]
void compute(int l, int r, int optl, int optr) {
    if (l > r) return;
    int m = (l + r) >> 1;
    pair<T,int> best = mp(numeric_limits<T>::max(), -1);
    FOR(k,optl,min(m,optr+1))
        ckmin(best,mp((k?dp_before[k-1]:T(0))+C(k, m), k));
    dp_cur[m] = best.f;
    int opt = best.s;
    compute(l,m-1,optl,opt);
    compute(m+1,r,opt,optr);
}

T solve(int N, int M) {
    dp_before.assign(M,T(0));
    dp_cur.assign(M,T(0));
    F0R(i,M) dp_before[i] = C(0,i);
    FOR(i,1,N) compute(0,M-1,0,M-1), dp_before = dp_cur;
    return dp_before[M-1];
}