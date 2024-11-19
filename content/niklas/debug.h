/**
 * Author: Niklas Leinert
 * Date: 2024-11-16
 * Description: Debug template.
 */
#pragma once

#ifdef LOCAL
void print() {cerr << ']' << endl;}
template<typename Head, typename... Tail> void print(Head H, Tail... T) {cerr << ' ' << H; if(sizeof...(T)) cerr << ','; print(T...); }
template<typename T> ostream& operator << (ostream& os, vector<T> v){os << "["; bool first = 1; for(auto x : v) {if(!first) os << ", "; os << x; first = 0;} os << "]"; return os;}
template<typename A, typename B> ostream& operator <<(ostream& os,pair<A, B> p) {return os << "(" << p.first << ", " << p.second << ")"; return os;}
template<typename A, typename B, typename C> ostream& operator << (ostream& os, tuple<A, B, C> a) {os << '(' << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ")"; return os;}
template<typename A, size_t S> ostream& operator << (ostream& os, array<A, S> a) {os << "["; bool first = 1; for(auto x : a) {if(!first) os << ", "; os << x; first = 0;} os << "]"; return os;}
template<typename A> ostream& operator << (ostream& os, set<A> s) {os << "["; bool first = 1; for(auto x : s) {if(!first) os << ", "; os << x; first = 0;} os << "]"; return os;}
template<typename A, typename B> ostream& operator << (ostream& os, map<A, B> m) {os << "["; bool first = 1; for(auto x : m) {if(!first) os << ", "; os << x; first = 0;} os << "]"; return os;}
#define dbg(...) cerr << '[' << #_VA_ARGS_ << ":", print(_VA_ARGS_);
#else
#define dbg(...)
#endif // LOCAL
