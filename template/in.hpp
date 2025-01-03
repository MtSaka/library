#pragma once
#include <unistd.h>
#include "alias.hpp"
#include "type-traits.hpp"
namespace fastio {
template <std::size_t BUFF_SIZE = 1 << 17, int decimal_precision = 16>
struct Scanner {
   private:
    template <typename, typename = void>
    struct has_scan : std::false_type {};
    template <class T>
    struct has_scan<T, decltype(std::declval<T>().scan(std::declval<Scanner&>()), (void)0)> : std::true_type {};
    int fd;
    char buffer[BUFF_SIZE + 1];
    int idx, sz;
    bool state;
    inline void load() {
        int len = sz - idx;
        if (idx < len) return;
        std::memcpy(buffer, buffer + idx, len);
        sz = len + read(fd, buffer + len, BUFF_SIZE - len);
        idx = 0;
        buffer[sz] = 0;
    }
    inline char cur() {
        if (idx == sz) load();
        if (idx == sz) {
            state = false;
            return '\0';
        }
        return buffer[idx];
    }
    inline void next() {
        if (idx == sz) load();
        if (idx == sz) return;
        idx++;
    }

   public:
    Scanner() : Scanner(0) {}
    explicit Scanner(int fd) : fd(fd), idx(0), sz(0), state(true) {}
    explicit Scanner(FILE* file) : fd(fileno(file)), idx(0), sz(0), state(true) {}

    inline char scan_char() {
        if (idx == sz) load();
        return (idx == sz ? '\0' : buffer[idx++]);
    }
    Scanner ignore(int n = 1) {
        if (idx + n > sz) load();
        idx += n;
        return (*this);
    }
    inline void skip_space() {
       
        if (idx == sz) load();
        while (('\t' <= cur() && cur() <= '\r') || cur() == ' ') {
            if (++idx == sz) load();
        }
    }
    void scan(char& a) {
        skip_space();
        a = scan_char();
    }
    void scan(std::string& a) {
        skip_space();
        a.clear();
        while (cur() != '\0' && (buffer[idx] < '\t' || '\r' < buffer[idx]) && buffer[idx] != ' ') {
            a += scan_char();
        }
    }
    template <std::size_t len>
    void scan(std::bitset<len>& a) {
        skip_space();
        if (idx + len > sz) load();
        rrep(i, len) a[i] = (buffer[idx++] != '0');
    }
    template <typename T, typename std::enable_if<is_int<T>::value && !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        skip_space();
        bool neg = false;
        if constexpr (std::is_signed<T>::value || std::is_same_v<T, __int128_t>) {
            if (cur() == '-') {
                neg = true;
                next();
            }
        }
        if (idx + 40 > sz && (idx == sz || ('0' <= buffer[sz - 1] && buffer[sz - 1] <= '9'))) load();
        a = 0;
        while ('0' <= buffer[idx] && buffer[idx] <= '9') {
            a = a * 10 + (buffer[idx++] & 15);
        }
        if constexpr (std::is_signed<T>::value || std::is_same<T, __int128_t>::value) {
            if (neg) a = -a;
        }
    }
    template <typename T, typename std::enable_if<std::is_floating_point<T>::value && !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        skip_space();
        bool neg = false;
        if (cur() == '-') {
            neg = true;
            next();
        }
        a = 0;
        while ('0' <= cur() && cur() <= '9') {
            a = a * 10 + (scan_char() & 15);
        }
        if (cur() == '.') {
            next();
            T n = 0, d = 1;
            for (int i = 0; '0' <= cur() && cur() <= '9' && i < decimal_precision; ++i) {
                n = n * 10 + (scan_char() & 15);
                d *= 10;
            }
            while ('0' <= cur() && cur() <= '9') next();
            a += n / d;
        }
        if (neg) a = -a;
    }

   private:
    template <std::size_t i, typename... Args>
    void scan(std::tuple<Args...>& a) {
        if constexpr (i < sizeof...(Args)) {
            scan(std::get<i>(a));
            scan<i + 1, Args...>(a);
        }
    }

   public:
    template <typename... Args>
    void scan(std::tuple<Args...>& a) {
        scan<0, Args...>(a);
    }
    template <typename T, typename U>
    void scan(std::pair<T, U>& a) {
        scan(a.first);
        scan(a.second);
    }
    template <typename T, typename std::enable_if<is_range<T>::value && !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        for (auto& i : a) scan(i);
    }
    template <typename T, typename std::enable_if<has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        a.scan(*this);
    }
    void operator()() {}
    template <typename Head, typename... Tail>
    void operator()(Head& head, Tail&... tail) {
        scan(head);
        operator()(std::forward<Tail&>(tail)...);
    }
    template <typename T>
    Scanner& operator>>(T& a) {
        scan(a);
        return *this;
    }
    explicit operator bool() const { return state; }
    friend Scanner& getline(Scanner& sc, std::string& a) {
        a.clear();
        char c;
        if ((c = sc.scan_char()) == '\0' || c == '\n') return sc;
        a += c;
        while ((c = sc.scan_char()) != '\0' && c != '\n') a += c;
        return sc;
    }
};
Scanner<> sc;
}  // namespace fastio
using fastio::sc;