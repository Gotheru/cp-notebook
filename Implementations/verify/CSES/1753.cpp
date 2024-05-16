#define PROBLEM "https://vjudge.net/problem/CSES-1753"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Heavy/SuffixAutomaton.h"
//
void Gotheru::solve() {
    str s, t;
    cin >> s >> t;
    SuffixAutomaton sfa; sfa.init(s); sfa.genIlnk();
    cout << sz(sfa.allOccur(t)) << '\n';
}