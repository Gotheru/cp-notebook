#define PROBLEM "https://vjudge.net/problem/Yosupo-staticrmq"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/data-structures/static-range-queries/RMQ.h"
//
void Gotheru::solve() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vi a(N);
    F0R(i, N) cin >> a[i];
    RMQ<int> rmq;
    rmq.init(a);
    F0R(i, Q) {
        int L, R;
        cin >> L >> R;
        cout << rmq.query(L, R - 1) << '\n';
    }
}