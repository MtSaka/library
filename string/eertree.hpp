template <class Key>
struct Eertree {
    struct Node {
       private:
        int id;
        int sl;
        int l;
        int p;
        map<Key, int> ch;

       public:
        Node(int idx, int suffix_link, int len, int par) : id(idx), sl(suffix_link), l(len), p(par) {};
        int suffix_link() const { return sl; }
        int get_child(Key c) const {
            auto it = ch.find(c);
            return (it == ch.end() ? -1 : it->second);
        }
        int len() const { return l; }
        int par() const { return p; }
        int idx() const { return id; }
        void set_child(const Key& c, int nxt) {
            ch[c] = nxt;
        }
    };
    int idx;
    vector<Node> nodes;
    vector<Key> vec;
    Eertree() {
        idx = 1;
        nodes = {Node(0, -1, -1, -1), Node(1, 0, 0, 0)};
    }
    int find_suffix(int id) {
        const int pos = (int)vec.size() - 1;
        while (true) {
            if (id < 0) return 0;
            const int opp_pos = pos - 1 - nodes[id].len();
            if (opp_pos >= 0 && vec[opp_pos] == vec[pos]) return id;
            id = nodes[id].suffix_link();
        }
    }
    template <class F>
    int add_char(const Key& c, const F& f) {
        vec.eb(c);
        idx = find_suffix(idx);
        int ch = nodes[idx].get_child(c);
        if (ch < 0) {
            const int nxt_idx = nodes.size();
            const int new_len = nodes[idx].len() + 2;
            int new_suffix_par = find_suffix(nodes[idx].suffix_link());
            int new_suffix_link = nodes[new_suffix_par].get_child(c);
            if (new_suffix_link < 0) new_suffix_link = 1;
            nodes[idx].set_child(c, nxt_idx);
            nodes.push_back(Node(nxt_idx, new_suffix_link, new_len, idx));
            idx = nxt_idx;
        } else {
            idx = ch;
        }
        f(idx);
        return idx;
    }
    int add_char(const Key& c) {
        return add_char(c, [](int) {});
    }
    template <typename Cont, class F>
    vector<int> add_string(const Cont& s, const F& f) {
        vector<int> res;
        for (auto& e : s) {
            res.eb(add_char(e));
        }
        return res;
    }
    template <typename Cont>
    vector<int> add_string(const Cont& s) {
        return add_string(s, [](int) {});
    }
    int distinct_palindrome() const { return nodes.size() - 2; }
};
/**
 * @brief Eertree
 */