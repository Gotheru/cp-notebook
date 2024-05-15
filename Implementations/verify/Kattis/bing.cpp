#define PROBLEM "https://vjudge.net/problem/Kattis-bing"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Light/TrieAlpha.h"
//
void Gotheru::solve() {
    int N; cin >> N;
    TrieAlpha<5000000> T;
    while (N--) {
        str S; cin >> S;
        T.ins(S, 1);
        int cur = 0;
        F0R(i, sz(S)) cur = T.nex[cur][S[i]-'a'];
        cout << T.sz[cur] - 1 << '\n';
    }
}