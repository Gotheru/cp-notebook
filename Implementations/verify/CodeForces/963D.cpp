#define PROBLEM "https://vjudge.net/problem/CodeForces-963D"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Light/AhoCorasickFixed.h"
//
void Gotheru::solve() {
    str s;
    int n;
    cin >> s >> n;
    vi k(n);
    vs w(n);
    F0R(i, n) cin >> k[i] >> w[i];
    ACfixed<'a', 26> ac(w);
    auto ans = ac.solve(s, n);
    F0R(i, n) {
        if (sz(ans[i]) < k[i]) {
            cout << "-1\n";
            continue;
        }
        int best = sz(s);
        F0R(j, sz(ans[i]) - k[i] + 1) ckmin(best, ans[i][j + k[i] - 1] + sz(w[i]) - ans[i][j]);
        cout << best << '\n';
    }
}