#define PROBLEM "https://vjudge.net/problem/SPOJ-MSUBSTR"
//
#include "content/contest/template.hpp"
//
#include "content/strings/Light/Manacher.h"
//
void Gotheru::solve() {
    int tc; cin >> tc;
    while (tc--) {
        str S; cin >> S;
        vi v = manacher(S);
        int ans = *max_element(all(v));
        int times = count(all(v), ans);
        cout << ans << ' ' << times << '\n';
    }
}