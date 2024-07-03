#pragma once

/**
 * Description: $D$-dimensional range increment and sum query with $2^D$ BITs, case $D=1$
 * Source: https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
 * Verification: CSES
 * Time: O(\log N)
 */

#include "BIT.h"

tcT> struct BITrange {
	V<BIT<T>> bit; // piecewise linear functions
	BITrange(int _N) : bit(2, _N) {}
	// let cum[x] = sum_{i=1}^{x}a[i]
	void upd(int hi, T val) { // add val to a[1..hi]
		// if x <= hi, cum[x] += val*x
		bit[1].add(1,val), bit[1].add(hi+1,-val); 
		// if x > hi, cum[x] += val*hi
		bit[0].add(hi+1,hi*val); 
	}
	void add(int lo,int hi,T val){add(lo-1,-val),add(hi,val);}
	T sum(int x) { return bit[1].sum(x)*x+bit[0].sum(x); } 
	T query(int x, int y) { return sum(y)-sum(x-1); }
}; 
