#define PROBLEM "https://vjudge.net/problem/Gym-102156D"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/combinatorial/MatroidIsect.h"
//
void Gotheru::solve() {
    int N, M;
    cin >> N;
    vi clr; vl nums;
    F0R(i, N) {
        ll x; cin >> x;
        clr.pb(i), nums.pb(x);
    }
    cin >> M;
    F0R(i, M) {
        int K; cin >> K;
        while (K--) {
            ll x; cin >> x;
            nums.pb(x), clr.pb(N + i);
        }
    }
    Xmat M1(nums);
    Cmat M2(clr);
    MatroidIsect<Xmat, Cmat> isect(M1, M2, sz(nums));
    vi ans = isect.solve();
    sort(all(ans));
    if (sz(ans) < N + M) cout << "-1\n";
    else FOR(i, N, N + M) cout << nums[ans[i]] << '\n';
}