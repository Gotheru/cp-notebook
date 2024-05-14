#pragma once
/**
 * Description: Used only once. Burrows-Wheeler Transform appends 
 	* \# to a string, sorts the rotations of the string in increasing order, 
	* and constructs a new string that contains the last character 
	* of each rotation. This function reverses the transform.
 * Time: O(N\log N)
 * Source: GeeksForGeeks
 * Verification: https://vjudge.net/problem/CSES-1113
 */
#include "../../contest/template.hpp"

str reverseBW(str t) {
	vi nex(sz(t)); iota(all(nex),0);
	stable_sort(all(nex),[&t](int a,int b){return t[a]<t[b];});
	str ret; for (int i = nex[0]; i; ) 
		ret += t[i = nex[i]];
	return ret;
}