template<class T>
struct Matrix {
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
    for(int i=0;i<n;i++)mat[i][i]=1;
    return mat;
  }
  Matrix &operator+=(const Matrix&B){
    const size_t n=height(),m=width();
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)(*this)[i][j]+=B[i][j];
    return *this;
  }
  Matrix &operator-=(const Matrix&B){
    const size_t n=height(),m=width();
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)(*this)[i][j]-=B[i][j];
    return *this;
  }
  Matrix &operator*=(const Matrix&B) {
    const size_t n=height(),m=B.width(),p=width();
    vector<vector<T>>C(n,vector<T>(m,0));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<p;k++)C[i][j]+=(*this)[i][k]*B[k][j];
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
  Matrix operator+(const Matrix&B)const{return Matrix(*this)+=B;}
  Matrix operator-(const Matrix&B)const{return Matrix(*this)-=B;}
  Matrix operator*(const Matrix&B)const{return Matrix(*this)*=B;}
  Matrix operator^(const long long&k)const{return Matrix(*this)^=k;}
};
/**
 * @brief Matrix(行列)
*/