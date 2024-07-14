// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/double_ended_priority_queue
#include "../../../template/template.hpp"
#include "../../../ds/heap/double-ended-priority-queue.hpp"

int main() {
    INT(n, q);
    vector<int> s(n);
    sc >> s;
    DoubleEndedPriorityQueue<int> deq(all(s));
    rep(q) {
        INT(t);
        if (t == 0) {
            INT(x);
            deq.push(x);
        } else if (t == 1) {
            print(deq.pop_min());
        } else {
            print(deq.pop_max());
        }
    }
}
