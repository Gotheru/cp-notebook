#pragma once

/**
 * Description: bitset of variable size. Careful since it's slower than std::bitset
 * Source: https://codeforces.com/blog/entry/129454
 * Usage: \texttt{#include <tr2/dynamic_bitset> ... tr2::dynamic_bitset<>}
 	* Has nice functions as \texttt{is_subset_of()}, \texttt{is_proper_subset_of()},
	* \texttt{find_first()}, \texttt{find_next(pos)}.
 * Verification: https://vjudge.net/problem/AtCoder-abc258_g
 */

#include <tr2/dynamic_bitset>