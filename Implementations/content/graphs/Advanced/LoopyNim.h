#pragma once

/**
 * Description: Computes nim values on a DAG with cycles using Smith's rule. 
   * Each state is either non-loopy (in which case \texttt{val[i]} contains its nim value) 
   * or is loopy (in which case \texttt{val[i] = -1}). 
   * The sum of two loopy states is a draw. 
   * The sum of a loopy state with a non-loopy state with some nim value is a win 
   * if the loopy state can advance to a non-loopy state with the same nim value
   * in one move.
 * Time: O(M\sqrt M)
 * Source: Winning Ways Ch 12
 * Verification:
 	* https://vjudge.net/problem/TopCoder-17283 
 */

#include "../../contest/template.hpp"

struct LoopyNim {
	int N; V<vi> adj, radj; vi val;
	void init(int _N) { N = _N; adj.rsz(N), radj.rsz(N); }
	void ae(int x, int y) { adj[x].pb(y), radj[y].pb(x); }
	void calc() {
		val = vi(N,-1); // nim value, or -1 if it doesn't have one
		vb inf(N); // whether nim value is definitely infinite
		for (int v = 0, flag = 1; flag; ++v) {
			flag = 0;
			vi lef(N); F0R(y,N) if (val[y] == -1) for (int x: radj[y]) ++lef[x];
			vb has_v(N); // for all i with val[i] == -1, whether it can go to v
			auto cand = [&](int x) { return !inf[x] && val[x] == -1 && !has_v[x]; };
			queue<int> q; F0R(x,N) if (cand(x) && lef[x] == 0) q.push(x);
			auto sub = [&](int x) {
				if (cand(x)) {
					--lef[x]; assert(lef[x] >= 0);
					if (lef[x] == 0) q.push(x);
				}
			};
			while (sz(q)) {
				int x = q.ft; q.pop(); if (!cand(x)) continue;
				val[x] = v; flag |= 1;
				for (int y: radj[x]) if (val[y] == -1 && !has_v[y]) {
					has_v[y] = 1;
					for (int z: radj[y]) sub(z);
				}
			}
			F0R(i,N) inf[i] = inf[i]|!has_v[i];
		}
	}
};