template<typename T>
struct Matrix{
  vector<vector<T>>A;
  Matrix(){}
  Matrix(size_t n,size_t m):A(n,vector<T>(m,0)){}
  Matrix(size_t n):A(n,vector<T>(n,0)){};
  size_t height()const{return (A.size());}
  size_t width()const{return (A[0].size());}
  inline const vector<T>&operator[](int k)const{return A.at(k);}
  inline vector<T>&operator[](int k){return A.at(k);}
  static Matrix I(size_t n){
    Matrix mat(n);
    for(size_t i=0;i<n;i++)mat[i][i]=1;
    return mat;
  }
  Matrix &operator+=(const Matrix&B){
    const size_t n=height(),m=width();
    for(size_t i=0;i<n;i++)for(size_t j=0;j<m;j++)(*this)[i][j]+=B[i][j];
    return *this;
  }
  Matrix &operator-=(const Matrix&B){
    const size_t n=height(),m=width();
    for(size_t i=0;i<n;i++)for(size_t j=0;j<m;j++)(*this)[i][j]-=B[i][j];
    return *this;
  }
  Matrix &operator*=(const Matrix&B) {
    const size_t n=height(),m=B.width(),p=width();
    vector<vector<T>>C(n,vector<T>(m,0));
    for(size_t i=0;i<n;i++)for(size_t j=0;j<m;j++)for(size_t k=0;k<p;k++)C[i][j]+=(*this)[i][k]*B[k][j];
    A.swap(C);
    return *this;
  }
  Matrix &operator^=(long long k){
    Matrix B=Matrix::I(height());
    while(k>0){
      if(k&1)B*=*this;
      *this*=*this;
      k>>=1LL;
    }
    A.swap(B.A);
    return *this;
  }
  friend Matrix operator+(const Matrix&A,const Matrix&B){return Matrix(A)+=B;}
  friend Matrix operator-(const Matrix&A,const Matrix&B){return Matrix(A)-=B;}
  friend Matrix operator*(const Matrix&A,const Matrix&B){return Matrix(A)*=B;}
  friend Matrix operator^(const Matrix&A,const long long&k){return Matrix(A)^=k;}
  T determinant()const{
    Matrix b(*this);
    T ret=1;
    for(int i=0;i<(int)width();i++){
      int idx=-1;
      for(int j=i;j<(int)width();j++)if(b[j][i]!=0){idx=j;break;}
      if(idx==-1)return T(0);
      if(i!=idx){
        ret*=T(-1);
        swap(b[i],b[idx]);
      }
      ret*=b[i][i];
      T tmp=b[i][i];
      for(int j=0;j<(int)width();j++)b[i][j]/=tmp;
      for(int j=i+1;j<(int)width();j++){
        T now=b[j][i];
        for(int k=0;k<(int)width();k++)b[j][k]-=b[i][k]*now;
      }
    }
    return ret;
  }
};
/**
 * @brief Matrix(行列)
*/