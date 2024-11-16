/**
 * Author: https://cp-algorithms.com/algebra/linear-diophantine-equation.html
 * Date: 2024-11-16
 * Description: Finds two integers $x$ and $y$, such that $ax+by=c$.
 * Or returns false if no solution exists.
 */
#pragma once

#include <euclid.h>

bool diophantine(ll a, ll b, ll c, ll &x, ll &y) {
	ll g = euclid(abs(a), abs(b), x, y);
	if (c % g) return false;
	x *= c / g;
	y *= c / g;
	if (a < 0) x = -x;
	if (b < 0) y = -y;
	return true;
}

