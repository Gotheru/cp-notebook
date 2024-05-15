#define PROBLEM "https://vjudge.net/problem/Kattis-stringmultimatching"
//
#include "../../content/contest/template.hpp"
// 
#include "../../content/strings/Light/AhoCorasickUnfixed.h"
//

void Gotheru::solve() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n) {
        vs words(n); str S; vi idx; ACunfixed ac;
        cin.get();
        each(w, words) getline(cin, w);
        getline(cin, S);
        each(w, words) idx.pb(ac.add(w));
        ac.init();
        // traverse ac using S
        V<vi> times(sz(ac.d));
        int s = 0;
        F0R(i, sz(S))
            times[s = ac.nex(s, S[i])].pb(i);

        V<vi> g(sz(ac.d)); // g contains the rooted tree generated by the suffix links
        FOR(i, 1, sz(g)) {
            g[ac.d[i].link].pb(i);
        }

        V<vi> wanted(sz(g));
        V<set<int>> ans(n);

        F0R(i, n) wanted[idx[i]].pb(i);

        each(u, ac.bfs) {
            each(x, wanted[u])
                each(y, times[u])
                    ans[x].insert(y);
            each(v, g[u])
                each(x, wanted[u])
                    wanted[v].pb(x);
        }

        F0R(i, n) {
            each(x, ans[i]) cout << x - sz(words[i]) + 1 << ' ';
            cout << '\n';
        }
    }
}