#pragma once
#include <bits/stdc++.h>

#include "alias.hpp"
#include "macro.hpp"

struct IOSetup {
    IOSetup() {
        std::ios::sync_with_stdio(false);
        std::cout.tie(0);
        std::cout << std::fixed << std::setprecision(12);
        std::cerr << std::fixed << std::setprecision(12);
    }
};
template <typename F>
struct REC {
   private:
    F f;

   public:
    explicit constexpr REC(F&& f_) : f(std::forward<F>(f_)) {}
    template <typename... Args>
    constexpr auto operator()(Args&&... args) const {
        return f(*this, std::forward<Args>(args)...);
    }
};
template <typename T, typename Comp = std::less<T>>
struct compressor {
   private:
    std::vector<T> data;
    Comp cmp;
    bool sorted = false;

   public:
    compressor() : compressor(Comp()) {}
    compressor(const Comp& cmp) : cmp(cmp) {}
    compressor(const std::vector<T>& dat, const Comp& cmp = Comp()) : data(dat), cmp(cmp) {}
    compressor(std::vector<T>&& dat, const Comp& cmp = Comp()) : data(std::move(dat)), cmp(cmp) {}
    compressor(std::initializer_list<T> li, const Comp& cmp = Comp()) : data(li.begin(), li.end()), cmp(cmp) {}
    void push_back(const T& v) {
        assert(!sorted);
        data.push_back(v);
    }
    void push_back(T&& v) {
        assert(!sorted);
        data.push_back(std::move(v));
    }
    template <typename... Args>
    void emplace_back(Args&&... args) {
        assert(!sorted);
        data.emplace_back(std::forward<Args>(args)...);
    }
    void push(const std::vector<T>& v) {
        assert(!sorted);
        const int n = data.size();
        data.resize(v.size() + n);
        for (int i = 0; i < (int)v.size(); i++) data[i + n] = v[i];
    }
    void build() {
        assert(!sorted);
        sorted = 1;
        std::sort(data.begin(), data.end(), cmp);
        data.erase(unique(data.begin(), data.end(), [&](const T& l, const T& r) -> bool { return !cmp(l, r) && !cmp(r, l); }), data.end());
    }
    const T& operator[](int k) const& {
        assert(sorted);
        return data[k];
    }
    int get_index(const T& v) const {
        assert(sorted);
        return int(lower_bound(data.begin(), data.end(), v, cmp) - data.begin());
    }
    void press(std::vector<T>& v) const {
        assert(sorted);
        for (auto&& i : v) i = get_index(i);
    }
    std::vector<int> pressed(const std::vector<T>& v) const {
        assert(sorted);
        std::vector<int> ret(v.size());
        for (int i = 0; i < (int)v.size(); i++) ret[i] = get_index(v[i]);
        return ret;
    }
    int size() const {
        assert(sorted);
        return data.size();
    }
};