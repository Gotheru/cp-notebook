#define PROBLEM "https://vjudge.net/problem/Kattis-cordonbleu"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/Matching/Hungarian.h"
//
void Gotheru::solve() {
    int N, M;
    cin >> N >> M;
    vpi bottles(N), couriers(M);
    each(b, bottles) cin >> b.f >> b.s;
    each(c, couriers) cin >> c.f >> c.s;
    pi restaurant;
    cin >> restaurant.f >> restaurant.s;
    // Add N - 1 artificial couriers at the restaurant
    rep(N - 1) couriers.pb(restaurant);
    M += N - 1;
    V<vi> C(N, vi(M));
    auto dist = [](pi a, pi b) -> int { return abs(a.f - b.f) + abs(a.s - b.s); };
    F0R(i, N) F0R(j, M)
        C[i][j] = dist(bottles[i], couriers[j]) + dist(bottles[i], restaurant);
    cout << hungarian(C).back() << '\n';
}