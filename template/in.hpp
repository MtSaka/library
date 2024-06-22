#pragma once
#include "alias.hpp"
namespace fastio {
static constexpr int BUFF_SIZE = 1 << 17;
struct Scanner {
   private:
    FILE* file;
    char buffer[BUFF_SIZE];
    char *begin, *end, *ptr;

};
}  // namespace fastio