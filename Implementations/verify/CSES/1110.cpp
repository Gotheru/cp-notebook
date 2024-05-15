#define PROBLEM "https://vjudge.net/problem/CSES-1110"
//
#include "content/contest/template.hpp"
//
#include "content/strings/Light/MinRotation.h"
//
void Gotheru::solve() {
    str s; cin >> s;
    int i = minRotation(s);
    cout << s.substr(i, sz(s) - i) << s.substr(0, i) << '\n';
}