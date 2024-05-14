#define PROBLEM "https://vjudge.net/problem/UVA-10679"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Light/AhoCorasickUnfixed.h"
//
void Gotheru::solve() {
    cin.tie(0)->sync_with_stdio(0);
    int tc; cin >> tc;
    while (tc--) {
        str S; cin >> S;
        int N; cin >> N;
        vs v(N);
        each(x, v) cin >> x;
        ACunfixed ac;
        vi idx;
        each(x, v) idx.pb(ac.add(x));
        ac.init();
        int s = 0;
        vi vis(sz(ac.d), false);
        each(c, S) vis[s = ac.nex(s, c)] = 1;
        ROF(i, 1, sz(ac.bfs))
            vis[ac.d[ac.bfs[i]].link] |= vis[ac.bfs[i]];
        F0R(i, N) cout << (vis[idx[i]] ? 'y' : 'n') << '\n';
    }
}