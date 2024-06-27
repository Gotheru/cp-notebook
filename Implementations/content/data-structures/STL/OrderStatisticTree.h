/**
 * Description: A set (not multiset!) with support for finding the $n$'th
   * element, and finding the index of an element. Change \texttt{null\_type} to get a map.
 * Time: O(\log N)
 * Source: KACTL
   * https://codeforces.com/blog/entry/11080
 * Verification: many
 */

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tcT> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order

/**
int atMost(Tree<pi>& T, int r) { 
	return T.ook({r,MOD}); }
int getSum(Tree<pi>& T, int l, int r) { 
	return atMost(T,r)-atMost(T,l-1); }
*/
