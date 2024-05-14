#define PROBLEM "https://vjudge.net/problem/Yosupo-runenumerate"
//
#include "content/contest/template.hpp"
//
#include "content/strings/Light/TandemRepeats.h"
//
void Gotheru::solve() {
    str S; cin >> S;
    auto a = tandem_repeats(S);
    each(t, a) t = {t[2], t[0], t[1] + 2 * t[2]};
    sort(all(a));
    V<AR<int,3>> res;
    set<pi> s;
    each(t, a) {
        if (s.count(mp(t[1], t[2]))) continue;
        s.insert(mp(t[1], t[2]));
        res.pb(t);
    }
    cout << sz(res) << '\n';
    each(t, res) F0R(i, 3) cout << t[i] << " \n"[i == 2];
}