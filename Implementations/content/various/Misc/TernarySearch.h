#pragma once

/**
 * Description: solve for min on functions which are strictly decreasing then strictly increasing
 * Time: O(\log_3{N})
 * Source: gthr
 * Verification: @todo
 */

#include "../../contest/template.hpp"

db eval(db x);

db ternary(db l, db r) {
    if (abs(r-l) <= 1e-9) return (l+r)/2;
    db l1 = (2*l+r)/3, r1 = (l+2*r)/3;
    return eval(l1) < eval(r1) ? ternary(l,r1) : ternary(l1,r);
}