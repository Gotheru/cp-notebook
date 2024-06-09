#pragma once

/** 
 * Description: $K$-th shortest walk from \texttt{src} to \texttt{des} in digraph. 
 	* All edge weights must be non-negative.
 * Time: O((M+N)\log N+K\log K)
 * Memory: O((M+N)\log N+K)
 * Source:
 	* nor (https://judge.yosupo.jp/submission/87297)
 * Verification:
 	* https://judge.yosupo.jp/problem/k_shortest_walk
 */

#include "../../contest/template.hpp"
#include "../../data-structures/LeftistHeap.h"

template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

tcTU> auto dijkstra(const U& g, int s) {
    vector d(g.size(), numeric_limits<T>::max());
    vector prv(g.size(), -1);
    min_heap<pair<T, int>> heap;
    heap.emplace(d[s] = 0, s);
    while (!heap.empty()) {
        auto [dv, v] = heap.top();
        heap.pop();
        if (dv != d[v]) continue;
        for (auto&& [to, w] : g[v]) {
            if (d[to] > dv + w) {
                d[to] = dv + w;
                heap.emplace(d[to], to);
                prv[to] = v;
            }
        }
    }
    return make_pair(d, prv);
}

tcTU> auto kth_shortest_paths(int n, const U& g, int source, int sink, int k) {
    U g_rev(n);
    for (int u = 0; u < n; ++u)
        for (auto [v, w] : g[u]) g_rev[v].push_back({u, w});
    auto [d, prv] = dijkstra<T>(g_rev, sink);
    if (d[source] == numeric_limits<T>::max())
        return vector<T>{};
    vector<basic_string<int>> tree(n);
    for (int u = 0; u < n; ++u)
        if (prv[u] != -1) tree[prv[u]].push_back(u);
    using heap_t = LeftistHeap<T, int>;
    vector<heap_t*> h(n, nullptr);
    {
        queue<int> q({sink});
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            bool seen_p = false;
            for (auto [v, w] : g[u]) {
                if (d[v] == numeric_limits<T>::max()) continue;
                auto c = w + d[v] - d[u];
                if (not seen_p and v == prv[u] and c == 0) {
                    seen_p = true;
                    continue;
                }
                h[u] = heap_t::insert(h[u], c, v);
            }
            for (auto v : tree[u]) h[v] = h[u], q.push(v);
        }
    }
    vector<T> ans{d[source]};
    ans.reserve(k);
    if (not h[source]) return ans;
    {
        min_heap<pair<T, heap_t*>> q;
        q.push({d[source] + h[source]->key, h[source]});
        while (!q.empty() and (int) ans.size() < k) {
            auto [cd, ch] = q.top();
            q.pop();
            ans.push_back(cd);
            if (h[ch->value]) q.push({cd + h[ch->value]->key, h[ch->value]});
            if (ch->left) q.push({cd + ch->left->key - ch->key, ch->left});
            if (ch->right) q.push({cd + ch->right->key - ch->key, ch->right});
        }
    }
    return ans;
}