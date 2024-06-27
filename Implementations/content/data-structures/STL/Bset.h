#pragma once

/**
 * Description: bitset of variable size. Careful since it's slower than std::bitset
 * Source: https://codeforces.com/blog/entry/129454
 * Usage: tr2::dynamic_bitset<> bs;
	* bs.is_subset_of(), bs.is_proper_subset_of(), bs.find_first(), bs.find_next(pos) 
 * Verification: https://vjudge.net/problem/AtCoder-abc258_g
 */

#include <tr2/dynamic_bitset>