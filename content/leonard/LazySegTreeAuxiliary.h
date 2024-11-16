/**
 * Author: AtCoder
 * Date: 2024-06-09
 * License: CC0
 * Description: Structs and functions needed for LazySegTree.
 */
#pragma once

struct S {
	int val;
};
S e() {
	return S{0};
}
S op(S x, S y) {
	return S{x.val + y.val};
}
struct F {
	int add;
};
F id() {
	return F{0};
}
S mapping(F f, S x) {
	return S{x.val + f.add};
}
F composition(F f, F g) {
	return F{f.add + g.add};
}

