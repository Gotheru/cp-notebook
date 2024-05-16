#define PROBLEM "https://open.kattis.com/problems/proteinsyntes"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Light/HashRange.h"
//
void Gotheru::solve() {
    int N, M;
    cin >> N;
    str S;
    cin >> S;
    unordered_map<int,set<H>> sizes;
    cin >> M;
    F0R(i, M) {
        str T; cin >> T;
        HashRange HR;
        HR.add(T);
        sizes[sz(T)].insert(HR.hash(0, sz(T) - 1));
    }
    HashRange HR;
    HR.add(S);
    vi dp(N + 1, INF);
    dp.bk = 0;
    R0F(i, N) {
        each(p, sizes) {
            if (i + p.f > N) break;
            if (p.s.count(HR.hash(i, i + p.f - 1)))
                ckmin(dp[i], 1 + dp[i + p.f]);
        }
    }
    cout << dp[0] << '\n';
}