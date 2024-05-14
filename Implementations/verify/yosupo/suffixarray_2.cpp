#define PROBLEM "https://vjudge.net/problem/Yosupo-suffixarray"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Light/SuffixArrayLinear.h"
//
void Gotheru::solve() {
    str S; cin >> S;
    vi v(sz(S));
    F0R(i, sz(S)) v[i] = S[i] - 'a';
    cout << sa_is(v, 26) << '\n';
}