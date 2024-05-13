#define PROBLEM "https://open.kattis.com/problems/stringmatching"
//
#include "../../../content/contest/template.hpp"
//
#include "../../../content/strings/Light/KMP.h"
//
void Gotheru::solve() {
    str A, B;
    while ((getline(cin, A), cin) && (getline(cin, B), cin)) {
        cout << getOc(A, B) << '\n';
    }
}