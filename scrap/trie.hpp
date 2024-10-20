#pragma once
#include "../template/template.hpp"

template <size_t CHAR_SIZE = 26, char BASE = 'a'>
struct Trie {
    struct Node {
        array<int, CHAR_SIZE> next;
        int idx;
        char key;
        Node(char key) : key(key), idx(-1) { next.fill(-1); }
    };
    vector<Node> nodes;
    Trie(char c = '$') : nodes(1, Node(c)) {}
    
};