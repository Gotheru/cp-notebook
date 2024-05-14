#define PROBLEM "https://vjudge.net/problem/CSES-1113"
// 
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Light/ReverseBW.h"
//
void Gotheru::solve() {
    cin.tie(0)->sync_with_stdio(0);
    str s; cin >> s;
    cout << reverseBW(s) << '\n';
}