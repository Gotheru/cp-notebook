#pragma once

/**
 * Author: Ludo Pulles, chilli, Simon Lindholm
 * Date: 2019-01-09
 * License: CC0
 * Source: KACTL
 * Description: fft(a) computes $\hat f(k) = \sum_x a[x] \exp(2\pi i \cdot k x / N)$ for all $k$. N must be a power of 2.
   Useful for convolution:
   \texttt{conv(a, b) = c}, where $c[x] = \sum a[i]b[x-i]$.
   For convolution of complex numbers or more than two vectors: FFT, multiply
   pointwise, divide by n, reverse(start+1, end), FFT back.
   Rounding is safe if $(\sum a_i^2 + \sum b_i^2)\log_2{N} < 9\cdot10^{14}$
   (in practice $10^{16}$; higher for random inputs).
 * Time: O(N \log N) with $N = |A|+|B|$ ($\tilde 1s$ for $N=2^{22}$)
 */

#include "../../contest/template.hpp"
using cd = complex<db>;

void fft(V<cd>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static V<cd> R(2,1), rt(2,1);
    for (static int k = 2; k < n; k <<= 1) {
        R.rsz(n), rt.rsz(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        FOR(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    F0R(i,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    F0R(i,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k <<= 1)
        for (int i = 0; i < n; i += 2 * k) F0R(j, k) {
        // cd z = rt[j+k] * a[i+j+k]                        /// include-line
        auto x = (db*)&rt[j+k], y = (db*)&a[i+j+k];         /// exclude-line
        cd z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]); /// exclude-line
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
    }
}

vd conv(vd const& a, vd const& b) {
	if (!sz(a) || !sz(b)) return {};
	vd res(sz(a)+sz(b)-1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	V<cd> in(n), out(n);
	copy(all(a), begin(in));
	F0R(i,sz(b)) in[i].imag(b[i]);
	fft(in); each(x,in) x *= x;
	F0R(i,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
    F0R(i,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}