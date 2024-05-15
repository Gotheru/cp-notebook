#define PROBLEM "https://vjudge.net/problem/UVA-10829"
//
#include "content/contest/template.hpp"
//
#include "content/strings/Light/SuffixArray.h"
//
void Gotheru::solve() {
    int t; cin >> t;
    FOR(tc,1,t+1) {
        int g; str s;
        cin >> g >> s;
        int n = sz(s);
        SuffixArray suf, pre;
        suf.init(s);
        reverse(all(s));
        pre.init(s);
        int ans = 0;
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len + g < n; i += len) {
                int l = i, r = i + len + g;
                int lcp = min(len, suf.getLCP(l, r));
                l = n - l - 1, r = n - r - 1;
                int lcs = min(len, pre.getLCP(r, l));
                ans += max(0, lcp + lcs - len);
            }
        }
        cout << "Case " << tc << ": " << ans << '\n';
    }
}
