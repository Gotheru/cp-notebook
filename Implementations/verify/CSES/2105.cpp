#define PROBLEM "https://vjudge.net/problem/CSES-2105"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Heavy/SuffixAutomaton.h"
//
void Gotheru::solve() {
    str s; cin >> s;
    SuffixAutomaton sfa;
    sfa.init(s);
    cout << sfa.numDistinct2() - 1 << '\n';
}