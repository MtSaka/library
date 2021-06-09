#include<bits/stdc++.h>
using namespace std;
class dynamic_bitset {
    using unsigned_bits_t = std::make_unsigned_t<bits_t>;
    public:
        explicit dynamic_bitset() {}
        explicit dynamic_bitset(const index_t n) {
            _bits.assign(outer_index(n) + 1, ALL_0);
        }
        inline index_t size() const {
            return index_t(_bits.size()) * BLOCK_SIZE;
        }
        dynamic_bitset& operator|=(const dynamic_bitset& other) {
            ensure_size(other.size());
            int siz = other._bits.size();
            for (int i = 0; i < siz; ++i) {
                _bits[i] |= other._bits[i];
            }
            cut_leading_zeros();
            return *this;
        }
        dynamic_bitset& operator&=(const dynamic_bitset& other) {
            ensure_size(other.size());
            int siz = other._bits.size();
            for (int i = 0; i < siz; ++i) {
                _bits[i] &= other._bits[i];
            }
            _bits.erase(_bits.begin() + siz, _bits.end());
            cut_leading_zeros();
            return *this;
        }
        dynamic_bitset& operator^=(const dynamic_bitset& other) {
            ensure_size(other.size());
            int siz = other._bits.size();
            for (int i = 0; i < siz; ++i) {
                _bits[i] ^= other._bits[i];
            }
            cut_leading_zeros();
            return *this;
        }
        dynamic_bitset& operator<<=(const index_t shamt) {
            if (size() == 0) return *this;
            int ishamt = outer_index(shamt);
            int lshamt = inner_index(shamt);
            if (lshamt) {
                ensure_size(size() + shamt);
                int rshamt = BLOCK_SIZE - lshamt;
                int siz = _bits.size();
                for (int i = siz - 1; i > ishamt; --i) {
                    _bits[i] = (_bits[i - ishamt] << lshamt) | (_bits[i - ishamt - 1] >> rshamt);
                }
                _bits[ishamt] = _bits[0] << lshamt;
                std::fill(_bits.begin(), _bits.begin() + ishamt, ALL_0);
            } else {
                _bits.insert(_bits.begin(), ishamt, ALL_0);
            }
            cut_leading_zeros();
            return *this;
        }
        dynamic_bitset& operator>>=(const index_t shamt) {
            int ishamt = outer_index(shamt);
            if (ishamt >= _bits.size()) {
                _bits.clear();
                return *this;
            }
            int rshamt = inner_index(shamt);
            if (rshamt) {
                int lshamt = BLOCK_SIZE - rshamt;
                int sz = _bits.size();
                for (int i = 0; i + ishamt + 1 < sz; ++i) {
                    _bits[i] = (_bits[i + ishamt] >> rshamt) | (_bits[i + ishamt + 1] << lshamt);
                }
                _bits[sz - ishamt - 1] = _bits[sz - 1] >> rshamt;
                _bits.erase(_bits.end() - ishamt, _bits.end());
            } else {
                _bits.erase(_bits.begin(), _bits.begin() + ishamt);
            }
            cut_leading_zeros();
            return *this;
        }
        dynamic_bitset operator|(const dynamic_bitset& other) {
            return dynamic_bitset(_bits) |= other;
        }
        dynamic_bitset operator&(const dynamic_bitset& other) {
            return dynamic_bitset(_bits) &= other;
        }
        dynamic_bitset operator^(const dynamic_bitset& other) {
            return dynamic_bitset(_bits) ^= other;
        }
        dynamic_bitset operator<<(const index_t shamt) {
            return dynamic_bitset(_bits) <<= shamt;
        }
        dynamic_bitset operator>>(const index_t shamt) {
            return dynamic_bitset(_bits) >>= shamt;
        }
        bool operator[](const index_t n) const {
            if (n >= size()) return false;
            return (_bits[outer_index(n)] >> inner_index(n)) & 1;
        }
        void set(const index_t n, bool val = true) {
            if (not val and n >= size()) return;
            if (val) {
                ensure_size(n + 1);
                _bits[outer_index(n)] |= ONE << inner_index(n);
            } else {
                _bits[outer_index(n)] &= ~(ONE << inner_index(n));
            }
        }
        void flip(const index_t n) {
            ensure_size(n + 1);
            _bits[outer_index(n)] ^= ONE << inner_index(n);
        }
        friend std::ostream& operator<<(std::ostream &out, const dynamic_bitset &bs) {
            std::string res;
            for (auto it = bs._bits.rbegin(); it != bs._bits.rend(); ++it) {
                unsigned_bits_t bits = *it;
                for (int j = BLOCK_SIZE - 1; j >= 0; --j) {
                    res += char('0' + ((bits >> j) & 1));
                }
            }
            out << res;
            return out;
        }
    private:
        static constexpr unsigned int BLOCK_SIZE = std::numeric_limits<unsigned_bits_t>::digits;
        static constexpr unsigned int LOG_BLOCK_SIZE = __builtin_ctz(BLOCK_SIZE);       
        static constexpr unsigned_bits_t ONE = unsigned_bits_t(1);
        static constexpr unsigned_bits_t ALL_0 = unsigned_bits_t(0);
        static constexpr unsigned_bits_t ALL_1 = ~unsigned_bits_t(0);
        std::vector<unsigned_bits_t> _bits;
        dynamic_bitset(const std::vector<unsigned_bits_t> &bits) : _bits(bits) {}
        static constexpr unsigned int outer_index(index_t k) {
            return k >> LOG_BLOCK_SIZE;
        }
        static constexpr unsigned int inner_index(index_t k) {
            return k & (BLOCK_SIZE - 1);
        }
        void ensure_size(const index_t n) {
            int old_size = _bits.size();
            int new_size = outer_index(n == 0 ? n : n - 1) + 1;
            if (new_size > old_size) {
                _bits.resize(new_size, ALL_0);
            }
        }
        void cut_leading_zeros() {
            while (_bits.size() and _bits.back() == ALL_0) _bits.pop_back();
        }
};
