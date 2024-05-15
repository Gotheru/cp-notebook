#define PROBLEM "https://vjudge.net/problem/Kattis-stringmultimatching"
//
#include "../../content/contest/template.hpp"
// 
#include "../../content/strings/Light/AhoCorasickFixed.h"
//

void Gotheru::solve() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n) {
        vector<str> words(n); str S;
        cin.get();
        each(w, words) getline(cin, w);
        getline(cin, S);
        ACfixed<32, 96> ac(words);
        auto ans = ac.solve(S, n);
        each(q, ans) cout << q << '\n';
    }
}