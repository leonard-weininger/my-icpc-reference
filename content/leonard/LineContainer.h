/**
 * Author: Leonard Weininger
 * Date: 2024-11-18
 * License: CC0
 * Description: Add lines of the form $y = mx + b$ and query the maximum $f(x)$ over all lines. Lines must be inserted in non-decreasing order of slope. Query positions must also be in non-decreasing order. If numbers are big use \_\_int128\_t for multiplications.
 * Time: O(1).
 */
#pragma once

struct Line {
	ll m, b;
	ll operator[] (ll x) {
		return m * x + b;
	}
	pair<ll, ll> intersect(Line o) {
		return {o.b - b, m - o.m};
	}
};

struct LineContainer {
	vector<Line> hull;
	int l = 0, r = 0;
	void add_line(Line f) {
		while (r - l >= 2) {
			auto [a, b] = hull[r - 2].intersect(hull[r - 1]);
			auto [c, d] = hull[r - 1].intersect(f);
			if (b * c <= a * d) --r;
			else break;
		}
		if (r == (int) hull.size()) hull.push_back(f);
		else hull[r] = f;
		++r;
	}
	ll query(int x) {
		while (r - l >= 2 && hull[l][x] < hull[l + 1][x]) ++l;
		return (l == r ? -1e18 : hull[l][x]);
	}
};
