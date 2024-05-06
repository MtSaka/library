#pragma once
#include <bits/stdc++.h>

#include "macro.hpp"

template <std::size_t size>
struct int_least {
    static_assert(size <= 128, "size must be less than or equal to 128");
    using type = typename std::conditional<
        size <= 8, std::int_least8_t,
        typename std::conditional<
            size <= 16, std::int_least16_t,
            typename std::conditional<
                size <= 32, std::int_least32_t,
                typename std::conditional<size <= 64, std::int_least64_t, __int128_t>::type>::type>::type>::type;
};
template <std::size_t size>
using int_least_t = typename int_least<size>::type;
template <std::size_t size>
struct uint_least {
    static_assert(size <= 128, "size must be less than or equal to 128");
    using type = typename std::conditional<
        size <= 8, std::uint_least8_t,
        typename std::conditional<
            size <= 16, std::uint_least16_t,
            typename std::conditional<
                size <= 32, std::uint_least32_t,
                typename std::conditional<size <= 64, std::uint_least64_t, __uint128_t>::type>::type>::type>::type;
};
template <std::size_t size>
using uint_least_t = typename uint_least<size>::type;
template <typename T>
using double_size_int = int_least<std::numeric_limits<T>::digits * 2 + 1>;
template <typename T>
using double_size_int_t = typename double_size_int<T>::type;
template <typename T>
using double_size_uint = uint_least<std::numeric_limits<T>::digits * 2>;
template <typename T>
using double_size_uint_t = typename double_size_uint<T>::type;
template <typename T>
using double_size = typename std::conditional<std::is_signed<T>::value, double_size_int<T>, double_size_uint<T>>::type;
template <typename T>
using double_size_t = typename double_size<T>::type;
