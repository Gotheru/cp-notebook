#define PROBLEM "https://vjudge.net/problem/Yosupo-set_xor_min"
//
#include "content/contest/template.hpp"
//
#include "content/strings/Light/Trie.h"
//
void Gotheru::solve() {
    Trie<20000000, 30> T;
    set<int> S;
    int Q;
    cin >> Q;
    while (Q--) {
        int type, x;
        cin >> type >> x;
        if (type == 0 && S.ins(x).s) T.ins(x);
        else if (type == 1 && S.erase(x)) T.ins(x, -1);
        else if (type == 2) cout << T.min_xor(x) << '\n';
    }
}