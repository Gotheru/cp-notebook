#pragma once
/**
 * Description: Aho-Corasick for fixed alphabet. For each prefix, 
 	* stores link to max length suffix which is also a prefix.
	* solve() returns a list with all appearances of the words of v in s
 * Time: O(N\sum)
 * Source: https://vjudge.net/solution/47771157
	* https://codeforces.com/contest/710/problem/F
	* https://codeforces.com/contest/1207/problem/G
 * Verification:
 	* https://vjudge.net/problem/Kattis-stringmultimatching
	* https://vjudge.net/problem/CodeForces-963D
 */
#include "../../contest/template.hpp"

template<char A, size_t ASZ> struct ACfixed {
	struct Node { AR<int, ASZ> to; int link; vpi endsHere; bool end; int terminal; };
	V<Node> d{{}};
	vi bfs;
	ACfixed(vector<str> v) { // Initialize with patterns
		F0R(i, sz(v)) ins(v[i], i);
		pushLinks();
	}
	void ins(str& s, int i) {
		int v = 0;
		each(C,s) {
			int c = C-A;
			if (!d[v].to[c]) d[v].to[c] = sz(d), d.eb();
			v = d[v].to[c];
		}
		d[v].end = true;
		d[v].endsHere.eb(i, sz(s));
	}
	void pushLinks() {
		d[0].link = -1;
		queue<int> q; q.push(0);
		while (sz(q)) {
			int v = q.ft; q.pop(); bfs.pb(v);
			d[v].terminal = d[v].link == -1 ? 0 : d[d[v].link].end ? d[v].link : d[d[v].link].terminal;
			each(x, d[d[v].terminal].endsHere) d[v].endsHere.pb(x); 
			F0R(c,ASZ) {
				int u = d[v].to[c]; if (!u) continue;
				d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
				q.push(u);
			}
			if (v) F0R(c,ASZ) if (!d[v].to[c])
				d[v].to[c] = d[d[v].link].to[c];
		}
	}
	V<vi> solve(str s, int n) {
		V<vi> ans(n);
		int cur = 0;
		F0R(i, sz(s)) {
			cur = d[cur].to[s[i] - A];
			each(p, d[cur].endsHere) ans[p.f].pb(i - p.s + 1);
		}
		return ans;
	}
};
