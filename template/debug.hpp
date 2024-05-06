#pragma once
#include <bits/stdc++.h>

#include "alias.hpp"

template <typename T, typename = void>
struct is_specialize : std::false_type {};
template <typename T>
struct is_specialize<T, typename std::conditional<false, typename T::iterator, void>::type> : std::true_type {};
template <typename T>
struct is_specialize<T, typename std::conditional<false, decltype(T::first), void>::type> : std::true_type {};
template <typename T>
struct is_specialize<T, std::enable_if_t<std::is_integral<T>::value, void>> : std::true_type {};
inline void dump(const char& t) { std::cerr << t; }
inline void dump(const std::string& t) { std::cerr << t; }
inline void dump(const bool& t) { std::cerr << (t ? "true" : "false"); }
template <typename T, std::enable_if_t<!is_specialize<T>::value, std::nullptr_t> = nullptr>
inline void dump(const T& t) { std::cerr << t; }
template <typename T>
inline void dump(const T& t, std::enable_if_t<std::is_integral<T>::value>* = nullptr) {
    std::string tmp;
    if (t == infinity<T>::value || t == infinity<T>::max) tmp = "inf";
    if (std::is_signed<T>::value && (t == infinity<T>::mvalue || t == infinity<T>::min)) tmp = "-inf";
    if (tmp.empty()) tmp = std::to_string(t);
    std::cerr << tmp;
}
template <typename T, typename U>
inline void dump(const std::pair<T, U>&);
template <typename T>
inline void dump(const T& t, std::enable_if_t<!std::is_void<typename T::iterator>::value>* = nullptr) {
    std::cerr << "{";
    for (auto it = std::begin(t); it != std::end(t);) {
        dump(*it);
        std::cerr << (++it == t.end() ? "" : ",");
    }
    std::cerr << "}";
}
template <typename T, typename U>
inline void dump(const std::pair<T, U>& t) {
    std::cerr << "(";
    dump(t.first);
    std::cerr << ",";
    dump(t.second);
    std::cerr << ")";
}
inline void trace() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
inline void trace(Head&& head, Tail&&... tail) {
    dump(head);
    if (sizeof...(tail)) std::cerr << ",";
    trace(std::forward<Tail>(tail)...);
}
#ifdef ONLINE_JUDGE
#define debug(...) (void(0))
#else
#define debug(...)                        \
    do {                                  \
        std::cerr << #__VA_ARGS__ << "="; \
        trace(__VA_ARGS__);               \
    } while (0)
#endif