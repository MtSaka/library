#pragma once
#include "macro.hpp"
#include "alias.hpp"
#include "type-traits.hpp"

namespace fastio {
struct Pre {
    char buffer[10000][4];
    constexpr Pre() : buffer() {
        for (int i = 0; i < 10000; ++i) {
            int n = i;
            for (int j = 3; j >= 0; --j) {
                buffer[i][j] = n % 10 | '0';
                n /= 10;
            }
        }
    }
} constexpr pre;
template <std::size_t BUFF_SIZE = 1 << 17, bool debug = false>
struct Printer {
   private:
    template <typename, bool = debug, class = void>
    struct has_print : std::false_type {};
    template <class T>
    struct has_print<T, decltype(std::declval<T>().print(std::declval<Printer&>()), (void)0)> : std::true_type {};
    template <class T>
    struct has_print<T, true, decltype(std::declval<T>().debug(std::declval<Printer&>()), (void)0)> : std::true_type {};
    FILE* file;
    char buffer[BUFF_SIZE];
    int idx;
    std::size_t decimal_precision;

   public:
    Printer() : Printer((debug ? stderr : stdout)) {}
    explicit Printer(FILE* file) : file(file), idx(0), decimal_precision(16) {}
    ~Printer() {
        flush();
        if (file != stdout && file != stderr) fclose(file);
    }
    void set_decimal_precision(std::size_t n) { decimal_precision = n; }
    inline void print_char(char c) {
        if constexpr (!debug) {
            buffer[idx++] = c;
            if (idx == BUFF_SIZE) flush();
        }
    }
    inline void flush() {
        idx = fwrite(buffer, 1, idx, file);
        idx = 0;
    }
    void print(char a) {
        if constexpr (debug) print_char('\'');
        print_char(a);
        if constexpr (debug) print_char('\'');
    }
    void print(const char* a) {
        if constexpr (debug) print_char('"');
        for (; *a != '\0'; ++a) print_char(*a);
        if constexpr (debug) print_char('"');
    }
    template <std::size_t N>
    void print(const char (&a)[N]) {
        if constexpr (debug) print_char('"');
        for (auto i : a) print_char(i);
        if constexpr (debug) print_char('"');
    }
    void print(const std::string& a) {
        if constexpr (debug) print_char('"');
        for (auto i : a) print_char(i);
        if constexpr (debug) print_char('"');
    }
    template <std::size_t len>
    void print(const std::bitset<len>& a) {
        for (int i = len - 1; i >= 0; --i) print_char('0' + a[i]);
    }
    template <typename T, typename std::enable_if<is_int<T>::value && !has_print<T>::value>::type* = nullptr>
    void print(T a) {
        if (!a) {
            print_char('0');
            return;
        }
        if constexpr (is_signed_int<T>::value) {
            if (a < 0) {
                print_char('-');
                a = -a;
            }
        }
        if (idx + 40 >= BUFF_SIZE) flush();
        static char stk[40];
        int top = 40;
        while (a >= 10000) {
            int i = a % 10000;
            a /= 10000;
            top -= 4;
            std::memcpy(stk + top, pre.buffer[i], 4);
        }
        if (a >= 1000) {
            std::memcpy(buffer + idx, pre.buffer[a], 4);
            idx += 4;
        } else if (a >= 100) {
            std::memcpy(buffer + idx, pre.buffer[a] + 1, 3);
            idx += 3;
        } else if (a >= 10) {
            std::memcpy(buffer + idx, pre.buffer[a] + 2, 2);
            idx += 2;
        } else {
            buffer[idx++] = '0' | a;
        }
        std::memcpy(buffer + idx, stk + top, 40 - top);
        idx += 40 - top;
    }
    template <typename T, typename std::enable_if<std::is_floating_point<T>::value && !has_print<T>::value>::type* = nullptr>
    void print(T a) {
        if (a == infinity<T>::max() || a == infinity<T>::value()) {
            print("inf");
            return;
        }
        if (a == infinity<T>::min() || a == infinity<T>::mvalue()) {
            print("-inf");
            return;
        }
        if (std::isnan(a)) {
            print("nan");
            return;
        }
        if (a < 0) {
            print_char('-');
            a = -a;
        }
        T b = a;
        if (b < 1) {
            print_char('0');
        } else {
            std::string s;
            while (b >= 1) {
                s += (char)('0' | (int)std::fmod(b, 10.0));
                b /= 10;
            }
            for (auto i = s.rbegin(); i != s.rend(); ++i) {
                print_char(*i);
            }
        }
        print_char('.');
        for (std::size_t _ = 0; _ < decimal_precision; ++_) {
            a *= 10;
            print_char('0' | (int)std::fmod(a, 10.0));
        }
    }

   private:
    template <std::size_t i, typename... Args>
    void print(const std::tuple<Args...>& a) {
        if constexpr (i < sizeof...(Args)) {
            if constexpr (debug) print_char(',');
            print_char(' ');
            print(std::get<i>(a));
            print<i + 1>(a);
        }
    }

   public:
    template <typename... Args>
    void print(const std::tuple<Args...>& a) {
        if constexpr (debug) print_char('(');
        if constexpr (sizeof...(Args) != 0) {
            print(std::get<0>(a));
        }
        print<1, Args...>(a);
        if constexpr (debug) print_char(')');
    }
    template <typename T, typename U>
    void print(const std::pair<T, U>& a) {
        if constexpr (debug) print_char('(');
        print(a.first);
        if constexpr (debug) print_char(',');
        print_char(' ');
        print(a.second);
        if constexpr (debug) print_char(')');
    }
    template <typename T, typename std::enable_if<is_range<T>::value>::type* = nullptr>
    void print(const T& a) {
        if constexpr (debug) print_char('{');
        auto it = std::begin(a);
        if (it != std::end(a)) {
            print(*it);
            while (++it != std::end(a)) {
                if constexpr (debug) print_char(',');
                print_char(' ');
                print(*it);
            }
        }
        if constexpr (debug) print_char('}');
    }
    template <typename T, typename std::enable_if<has_print<T>::value && !debug>::type* = nullptr>
    void print(const T& a) {
        a.print(*this);
    }
    template <typename T, typename std::enable_if<has_print<T>::value && debug>::type* = nullptr>
    void print(const T& a) {
        a.debug(*this);
    }
    void operator()() {}
    template <typename Head, typename... Tail>
    void operator()(const Head& head, const Tail&... tail) {
        print(head);
        operator()(std::forward<const Tail&>(tail)...);
    }
    template <typename T>
    Printer& operator<<(const T& a) {
        print(a);
        return *this;
    }
    Printer& operator<<(Printer& (*f)(Printer&)) {
        return f(*this);
    }
};

Printer wt;
Printer<1 << 17, true> wtd;
}  // namespace fastio
using fastio::wt;
using fastio::wtd;
template <std::size_t BUFF_SIZE, bool debug>
fastio::Printer<BUFF_SIZE, debug>& endl(fastio::Printer<BUFF_SIZE, debug>& out) {
    out.print_char('\n');
    out.flush();
    return out;
}
template <std::size_t BUFF_SIZE, bool debug>
fastio::Printer<BUFF_SIZE, debug>& flush(fastio::Printer<BUFF_SIZE, debug>& out) {
    out.flush();
    return out;
}