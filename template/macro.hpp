#pragma once
#include <bits/stdc++.h>

#ifndef __COUNTER__
#define __COUNTER__ __LINE__
#endif

#define SELECT4(a, b, c, d, e, ...) e
#define SELECT3(a, b, c, d, ...) d
#define REP_1(a, c) for (ll REP_##c = 0; REP_##c < (ll)(a); ++REP_##c)
#define REP1(a) REP_1(a, __COUNTER__)
#define REP2(i, a) for (ll i = 0; i < (ll)(a); ++i)
#define REP3(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define REP4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (ll)(c))
#define rep(...) SELECT4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)
#define RREP_1(a, c) for (ll RREP_##c = (ll)(a) - 1; RREP_##c >= 0; --RREP_##c)
#define RREP1(a) RREP_1(a, __COUNTER__)
#define RREP2(i, a) for (ll i = (ll)(a) - 1; i >= 0; --i)
#define RREP3(i, a, b) for (ll i = (ll)(b) - 1; i >= (ll)(a); --i)
#define rrep(...) SELECT3(__VA_ARGS__, RREP3, RREP2, RREP1)(__VA_ARGS__)
#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)
#define INT(...)     \
    int __VA_ARGS__; \
    scan(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    scan(__VA_ARGS__)
#define STR(...)        \
    string __VA_ARGS__; \
    scan(__VA_ARGS__)
#define CHR(...)      \
    char __VA_ARGS__; \
    scan(__VA_ARGS__)
#define DBL(...)        \
    double __VA_ARGS__; \
    scan(__VA_ARGS__)
#define LD(...)     \
    ld __VA_ARGS__; \
    scan(__VA_ARGS__)
#define pb push_back
#define eb emplace_back