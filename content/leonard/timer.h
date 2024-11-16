/**
 * Author: Leonard Weininger
 * Date: 2024-11-15
 * License: CC0
 * Description: Timer. elapsed() gives time since last reset in seconds.
 */
#pragma once

#include <chrono>

struct Timer {
	chrono::high_resolution_clock::time_point t_begin;
	Timer() {
		t_begin = chrono::high_resolution_clock::now();
	}
	void reset() {
		t_begin = chrono::high_resolution_clock::now();
	}
	double elapsed() const {
		auto t_now = chrono::high_resolution_clock::now();
		return chrono::duration<double>(t_now - t_begin).count();
	}
} timer;
