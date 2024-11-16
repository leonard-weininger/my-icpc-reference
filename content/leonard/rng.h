/**
 * Author: Leonard Weininger
 * Date: 2024-11-15
 * License: CC0
 * Description: Random numbers.
 */
#pragma once

#include <chrono>
#include <random>

struct Rng {
	mt19937 mt;
	Rng(unsigned long long seed = 1) {
		mt.seed(seed);
	}
	int next(int a, int b) {
		return a + ((1LL * (b - a + 1) * mt()) >> 32);
	}
	double next_double(double a = 0.0, double b = 1.0) {
		return a + (b - a) * ((mt() + 0.5) / 4294967296.0);
	}
	template<typename T> void shuffle(T first, T last) {
		for (int i = (last - first - 1); i > 0; --i) {
			swap(*(first + next(0, i)), *(first + i));
		}
	}
} rng(chrono::steady_clock::now().time_since_epoch().count());
