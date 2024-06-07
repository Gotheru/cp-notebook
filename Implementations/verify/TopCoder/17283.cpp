#define PROBLEM "https://vjudge.net/problem/TopCoder-17283"
//
#include "../../content/contest/template.hpp"
//
#include "../../content/graphs/Advanced/LoopyNim.h"
//
class DoubleXorGame {
public:
    string solve(int N, vi X, vi Y, vi states) {
        vi outdeg(N);
        each(x, X) ++outdeg[x];
        int Nstates = (1 << N);
        LoopyNim G;
        G.init(Nstates);
        F0R(i, sz(X))
            F0R(msk, Nstates)
                if (msk & (1 << X[i]))
                    G.ae(msk, msk ^ (1 << X[i]) ^ (1 << Y[i]));

        F0R(i, N)
            if (!outdeg[i])
                F0R(msk, Nstates)
                    if (msk & (1 << i))
                        G.ae(msk, msk ^ (1 << i));

        G.calc();
        int loopy_state = -1, nim_value = 0;
        each(s, states) {
            if (G.val[s] == -1) {
                if (loopy_state != -1) return "draw";
                else loopy_state = s;
            } else {
                nim_value ^= G.val[s];
            }
        }
        if (loopy_state == -1) return nim_value ? "win" : "lose";
        for (int x : G.adj[loopy_state])
            if (G.val[x] == nim_value)
                return "win";
        return "draw";
    }
};