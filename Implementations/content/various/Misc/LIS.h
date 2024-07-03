#pragma once

/**
 * Description: Returns indices of a longest increasing sequence
 * Time: O(N \log{N})
 * Source: gthr
 * Verification: @todo
 */

#include "../../contest/template.hpp"

tcT> vi lis(V<T> const& S) {
    if (!sz(S)) return {};
    vi prev(sz(S)); V<pair<T,int>> res;
    F0R(i,sz(S)) {
        // Change 0 to i for non-decreasing
        auto it = lb(all(res), mp(S[i],0));
        if (it == end(res)) res.eb(), it = res.end() - 1;
        *it = mp(S[i],i);
        prev[i] = it == begin(res) ? 0 : (it-1)->s;
    }
    int L = sz(res), cur = res.bk.s; vi ans(L);
    while (L--) ans[L] = cur, cur = prev[cur];
    return ans;
}