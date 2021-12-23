/**
 * @brief Timer(タイマー)
*/
class Timer{
  chrono::high_resolution_clock::time_point start,end;
  double limit;
  public:
  Timer(){start=chrono::high_resolution_clock::now();}
  Timer(double l){start=chrono::high_resolution_clock::now();limit=l;}
  double get_time(){end=chrono::high_resolution_clock::now();return chrono::duration<double>(end-start).count();}
  bool is_over(){return get_time()>limit;}
  bool is_under(){return get_time()<=limit;}
  double get_limit(){return limit;}
  void set_limit(double l){limit=l;}
  void set_start(){start=chrono::high_resolution_clock::now();}
};