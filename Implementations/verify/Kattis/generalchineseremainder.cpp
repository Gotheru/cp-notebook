#define PROBLEM "https://vjudge.net/problem/Kattis-generalchineseremainder"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/number-theory/Euclid/CRT.h"
//
void Gotheru::solve() {
    int T; cin >> T;
    while (T--) {
        ll a, n, b, m;
        cin >> a >> n >> b >> m;
        auto ans = CRT(mp(a, n), mp(b, m));
        if (ans.f == -1) cout << "no solution\n";
        else cout << ans.f << ' ' << ans.s << '\n';
    }
}