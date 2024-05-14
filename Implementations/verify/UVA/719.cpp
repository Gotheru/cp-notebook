#define PROBLEM "https://vjudge.net/problem/UVA-719"
//
#include "content/contest/template.hpp"
//
#include "content/strings/Light/LyndonFactor.h"
//
void Gotheru::solve() {
    int tc; cin >> tc;
    while (tc--) {
        str S; cin >> S;
        cout << minRotation(S) + 1 << '\n';
    }
}