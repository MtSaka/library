#pragma once
template<class S,S (*op)(S,S),S (*e)()>
struct disjoint_sparse_table{
  private:
  vector<vector<S>>table;
  vector<int>log_table;
};
/**
 * @brief Disjoint Sparse Table
 */