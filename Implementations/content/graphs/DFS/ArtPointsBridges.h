#pragma once

/**
 * Description: Finds bridges and articulation points of an undirected graph.
    * Be careful with double counting.
 * Time: O(N+M)
 * Source: @todo
 * Verification: @todo
 */

#include "../../contest/template.hpp"

void artPointsBridges(V<vi> const& g) {
    int n = sz(g), cnt = 0, root = 0;
    vi num(n), low(n);
    auto dfs = [&](auto&& self, int u, int p)->void{
        num[u] = low[u] = cnt++;
        each(v, g[u]) if (!num[v]) {
            if (p == -1) ++root;
            self(self, v, u);
            if (low[v] >= num[u] and p != -1)
                // u is articulation point
            if (low[v] > num[v])
                // u<->v is a bridge
            ckmin(low[u],low[v]);
        } else ckmin(low[u],num[v]);
    };
    F0R(i,n) if (!num[i]) {
        root = 0; dfs(dfs, i, -1);
        if (root > 1) {}
            // i is an articulation point
    }
}