#pragma once
#include "../template/template.hpp"

struct RollingHash {
   private:
    static constexpr ull MOD = (1ull << 61) - 1;
    static constexpr ull MASK31 = (1ull << 31) - 1;
    static ull calc_mod(ull a) {
        ull ret = (a & MOD) + (a >> 61);
        if (ret >= MOD) ret -= MOD;
        return ret;
    }
    static ull calc_mul(ull a, ull b) {
        i128 c = (i128)a * b;
        return calc_add(c & MOD, c >> 61);
    }
    static ull calc_add(ull a, ull b) {
        ull ret = a + b;
        if (ret >= MOD) ret -= MOD;
        return ret;
    }
    ull BASE;
    void init() {
        BASE = (1ull << 31) + (random_device()() & MASK31);
    }

   public:
    struct Hash {
       private:
        int n;
        ull BASE;
        vector<ull> inner_hash, power;

       public:
        template <typename T>
        Hash(ull base, const T& s) : BASE(base) {
            n = s.size();
            inner_hash.resize(n + 1);
            for (int i = 0; i < n; i++) inner_hash[i + 1] = calc_add(s[i], calc_mul(BASE, inner_hash[i]));
            power.resize(n + 1);
            power[0] = 1;
            for (int i = 0; i < n; i++) power[i + 1] = calc_mul(power[i], BASE);
        }
        ull get_hash(int l, int r) const {
            return calc_add(inner_hash[r], MOD - calc_mul(inner_hash[l], power[r - l]));
        }
        ull get_all() const {
            return inner_hash[n];
        }
        size_t size() const { return n; }
    };
    RollingHash() { init(); }
    template <typename T>
    Hash get_hash(const T& s) const { return Hash(BASE, s); }
    ull get_base() const { return BASE; }
    int lcp(const Hash& h1, const Hash& h2, int l1 = 0, int r1 = -1, int l2 = 0, int r2 = -1) {
        if (r1 == -1) r1 = h1.size();
        if (r2 == -1) r2 = h2.size();
        const int len = min(r1 - l1, r2 - l2);
        int ok = 0, ng = len + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) >> 1;
            if (h1.get_hash(l1, l1 + mid) == h2.get_hash(l2, l2 + mid))
                ok = mid;
            else
                ng = mid;
        }
        return ok;
    }
};
/**
 * @brief Rolling Hash(ローリングハッシュ)
 */