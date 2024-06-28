#define PROBLEM "https://vjudge.net/problem/CodeForces-633A"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/number-theory/Euclid/Euclid.h"
//
void Gotheru::solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll numSols = numPositiveSols(a, b, c, false);
    cout << (numSols ? "Yes\n" : "No\n");
}