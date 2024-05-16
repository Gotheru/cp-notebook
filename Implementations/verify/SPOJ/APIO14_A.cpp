#define PROBLEM "https://vjudge.net/problem/SPOJ-APIO14_A"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Heavy/PalTree.h"
//
void Gotheru::solve() {
    str s; cin >> s;
    PalTree t;
    each(c, s) t.addChar(c);
    t.numOc();
    ll ans = 0;
    each(node, t.d) ckmax(ans, ll(node.oc) * ll(node.len));
    cout << ans << '\n';
}