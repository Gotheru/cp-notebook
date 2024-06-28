#pragma once

/**
 * Description: Generalized Euclidean algorithm. \texttt{euclid} and 
 	* \texttt{invGeneral} work for $A,B<2^{62}$. 
 * Source: KACTL
 * Time: O(\log AB)
 * Verification:
 	* https://vjudge.net/problem/CodeForces-633A
 */

#include "../../contest/template.hpp"

// ceil(a/b)
// ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); }
pl euclid(ll A, ll B) { // For A,B>=0, finds (x,y) s.t.
	// Ax+By=gcd(A,B), |Ax|,|By|<=AB/gcd(A,B)
	if (!B) return {1,0};
	pl p = euclid(B,A%B); return {p.s,p.f-A/B*p.s}; }
ll invGeneral(ll A, ll B) { // find x in [0,B) such that Ax=1 mod B
	pl p = euclid(A,B); assert(p.f*A+p.s*B == 1);
	return p.f+(p.f<0)*B; } // must have gcd(A,B)=1
ll numPositiveSols(ll A, ll B, ll C, bool strict) {
	// find number of (x,y) st Ax + By = C with x,y>=strict
	ll d = gcd(A, B);
	if (C % d) return 0;
	pl p = euclid(A, B); ll x = p.f, y = p.s;
	x *= C/d, y *= C/d;
	ll k1 = -x * d, k2 = y * d;
	if (k1 > 0) k1 = k1 / B + (k1 % B != 0);
	else k1 = k1 / B;
	if (k2 > 0) k2 = k2 / A;
	else k2 = -((-k2)/ A + (k2 % A != 0));
	ll ans = max(0LL, k2-k1+1);
	if (strict) ans -= ll(C%B==0) + ll(C%A==0);
	return ans; 
}