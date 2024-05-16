#define PROBLEM "https://vjudge.net/problem/UVA-10679"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Heavy/SuffixTree.h"
//
void Gotheru::solve() {
    int k; cin >> k;
    while (k--) {
        str s; cin >> s;
        SuffixTree sft; sft.init(s);
        int q; cin >> q;
        while (q--) {
            str t; cin >> t;
            cout << (sft.maxPre(t) == sz(t) ? 'y' : 'n') << '\n';
        }
    }
}