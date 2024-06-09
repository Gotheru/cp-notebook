#pragma once

/**
 * Description: Persistent meldable heap.
 * Time: O(\log N) per meld
 * Memory: O(\log N) per meld
 * Source:
 	* nor (https://judge.yosupo.jp/submission/87297)
 	* https://en.wikipedia.org/wiki/Leftist_tree
 * Verification: See Kth Walk
 */

#include "../contest/template.hpp"

tcTU> struct LeftistHeap {
    using self_t = LeftistHeap<T, U>;
    int rank; T key; U value;
    self_t *left, *right;
    LeftistHeap(int rank_, T key_, U value_, self_t* left_,
                self_t* right_)
        : rank{rank_}, key{key_}, value{value_}, left{left_}, right{right_} {}
    inline static deque<LeftistHeap> alloc;
    static self_t* insert(LeftistHeap* a, const T k, const U v) {
        if (not a or k < a->key) {
            alloc.emplace_back(1, k, v, a, nullptr);
            return &alloc.back();
        }
        auto l = a->left, r = insert(a->right, k, v);
        if (not l or r->rank > l->rank) swap(l, r);
        alloc.emplace_back(r ? r->rank + 1 : 0, a->key, a->value, l, r);
        return &alloc.back();
    }
};