#pragma once

/**
 * Description: Stores disjoint intervals [a, b)
 * Time: O(\log N)
 * Source: @todo
 * Verification: @todo
 */

#include "../contest/template.hpp"

set<pi>::iterator addInterval(set<pi>& is, int L, int R) {
    if (L >= R) return is.end();
    auto it = is.lower_bound(mp(L,R)), bf = it;
    while (it != end(is) and it->f <= R)
        R = max(R, it->s), bf = it = is.erase(it);
    if (it != begin(is) and (--it)->s >= L)
        L = min(L, it->f), R = max(R, it->s), is.erase(it);
    return is.insert(bf, mp(L,R));
}
void removeInterval(set<pi>& is, int L, int R) {
    if (L >= R) return;
    auto it = addInterval(is, L, R);
    auto r2 = it->s;
    if (it->f == L) is.erase(it);
    else (int&)it->s = L;
    if (R != r2) is.emplace(R, r2);
}