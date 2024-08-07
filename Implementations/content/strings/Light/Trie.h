#pragma once

/**
 * Description: insert int, query max xor with some int in the trie
 * Time: O(MXBIT)
 * Source: CF Algorithms Gym
 * Verification: https://vjudge.net/problem/Yosupo-set_xor_min
 */

#include "../../contest/template.hpp"

template<int SZ, int MXBIT> struct Trie {
	int nex[SZ][2], sz[SZ], num = 0; // num is last node in trie
	// change 2 to 26 for lowercase letters
	Trie() { memset(nex,0,sizeof nex); memset(sz,0,sizeof sz); }
	void ins(ll x, int a = 1) { // insert or delete
		int cur = 0; sz[cur] += a;
		R0F(i,MXBIT) {
			int t = (x>>i)&1;
			if (!nex[cur][t]) nex[cur][t] = ++num;
			sz[cur = nex[cur][t]] += a;
		}}
	ll max_xor(ll x) { // compute max xor
		if (!sz[0]) return -INF; // no elements in trie
		int cur = 0;
		R0F(i,MXBIT) {
			int t = ((x>>i)&1)^1;
			if (!nex[cur][t] || !sz[nex[cur][t]]) t ^= 1;
			cur = nex[cur][t]; if (t) x ^= 1LL<<i;
		}
		return x; }
	ll min_xor(ll x) { // compute min_xor
		if (!sz[0]) return INF; // no elements in trie
		int cur = 0, res = 0;
		R0F(i,MXBIT) {
			int t = (x>>i)&1;
			if (nex[cur][t] && sz[nex[cur][t]]) cur = nex[cur][t];
			else res |= 1 << i, cur = nex[cur][!t];
		}
		return res; }
};
