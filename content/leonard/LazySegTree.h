/**
 * Author: AtCoder
 * Date: 2024-06-09
 * License: CC0
 * Description: Segment tree with ability to add or set values of large intervals.
 * Time: O(\log N).
 */
#pragma once

#include <vector>

struct lazy_segtree {
	int n, log;
	vector<S> d;
	vector<F> lz;
	lazy_segtree(int _n) {
		n = 1;
		log = 0;
		while (n < _n) { n <<= 1; ++log; }
		d.assign(2 * n, e());
		lz.assign(n, id());
	}
	void set(int p, S x) {
		p += n;
		for (int i = log; i >= 1; i--) push(p >> i);
		d[p] = x;
		for (int i = 1; i <= log; i++) update(p >> i);
	}
	S sum(int l, int r) {
		l += n;
		r += n;
		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}
		S sml = e(), smr = e();
		while (l < r) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}
		return op(sml, smr);
	}
	void apply(int l, int r, F f) {
		l += n;
		r += n;
		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}
		{
			int l2 = l, r2 = r;
			while (l < r) {
				if (l & 1) all_apply(l++, f);
				if (r & 1) all_apply(--r, f);
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
		}
		for (int i = 1; i <= log; i++) {
			if (((l >> i) << i) != l) update(l >> i);
			if (((r >> i) << i) != r) update((r - 1) >> i);
		}
	}
	void update(int k) {
		d[k] = op(d[2 * k], d[2 * k + 1]);
	}
	void all_apply(int k, F f) {
		d[k] = mapping(f, d[k]);
		if (k < n) lz[k] = composition(f, lz[k]);
	}
	void push(int k) {
		all_apply(2 * k, lz[k]);
		all_apply(2 * k + 1, lz[k]);
		lz[k] = id();
	}
};
