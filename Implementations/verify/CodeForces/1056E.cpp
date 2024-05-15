#define PROBLEM "https://vjudge.net/problem/CodeForces-1056E"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/strings/Light/HashRange.h"
//
void Gotheru::solve() {
    str S, T;
    cin >> S >> T;
    HashRange HR;
    HR.add(T);
    int N = sz(S), M = sz(T);
    int N0 = count(all(S), '0');
    int N1 = N - N0;
    int ans = 0;
    FOR(R0, 1, M) {
        if ((M - R0 * N0) % N1) continue;
        int R1 = (M - R0 * N0) / N1;
        if (R1 <= 0) break;
        bool found0 = false, found1 = false, ok = true;
        H h0, h1;
        for (int i = 0, j = 0; i < N && ok; ++i) {
            if (S[i] == '0') {
                if (!found0) h0 = HR.hash(j, j + R0 - 1), found0 = true;
                else if (h0 != HR.hash(j, j + R0 - 1)) ok = false;
            } else {
                if (!found1) h1 = HR.hash(j, j + R1 - 1), found1 = true;
                else if (h1 != HR.hash(j, j + R1 - 1)) ok = false;
            }
            j += (S[i] == '0' ? R0 : R1);
        }
        ok &= h0 != h1;
        ans += ok;
    }
    cout << ans << '\n';
}