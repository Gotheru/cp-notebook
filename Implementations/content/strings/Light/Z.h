/**
 * Description: \texttt{f[i]} is the max \texttt{len} such that 
 	* \texttt{s.substr(0,len) == s.substr(i,len)}
 * Time: O(N)
 * Source: http://codeforces.com/blog/entry/3107
 * Verification: https://judge.yosupo.jp/problem/zalgorithm
 */
#pragma once

#include "../../contest/template.hpp"

vi z(str s) {
	int N = sz(s), L = 1, R = 0; s += '#';
	vi ans(N); ans[0] = N; 
	FOR(i,1,N) {
		if (i <= R) ans[i] = min(R-i+1,ans[i-L]);
		while (s[i+ans[i]] == s[ans[i]]) ++ans[i];
		if (i+ans[i]-1 > R) L = i, R = i+ans[i]-1;
	}
	return ans;
}
vi getPrefix(str a, str b) { // find prefixes of a in b
	vi t = z(a+b); t = vi(sz(a)+all(t)); 
	each(u,t) ckmin(u,sz(a));
	return t;
}
