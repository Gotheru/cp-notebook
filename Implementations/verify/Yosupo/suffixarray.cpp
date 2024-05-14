#define PROBLEM "https://vjudge.net/problem/Yosupo-suffixarray"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Light/SuffixArray.h"
//
void Gotheru::solve() {
    str S; cin >> S;
    SuffixArray SA;
    SA.init(S);
    cout << vi(1 + all(SA.sa)) << '\n';
}