struct fraction{
  static long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
  long long num,den;
  fraction():num(0),den(1){}
  fraction(long long n):num(n),den(1){}
  fraction(long long n,long long d):num(n),den(d){
    long long g=gcd(n,d);
    num/=g;den/=g;
    if(den<0){num=-num;den=-den;}
  }
  bool operator>(const fraction &f)const{return num*f.den>den*f.num;}
  bool operator<(const fraction &f)const{return num*f.den<den*f.num;}
  bool operator>=(const fraction &f)const{return num*f.den>=den*f.num;}
  bool operator<=(const fraction &f)const{return num*f.den<=den*f.num;}
  bool operator==(const fraction &f)const{return num*f.den==den*f.num;}
  bool operator!=(const fraction &f)const{return num*f.den!=den*f.num;}
  fraction operator-()const{return fraction(-num,den);}
  fraction &operator-=(const fraction &f){num=num*f.den-den*f.num;den*=f.den;return *this;}
  fraction &operator+=(const fraction &f){num=num*f.den+den*f.num;den*=f.den;return *this;}
  fraction &operator*=(const fraction &f){num*=f.num;den*=f.den;return *this;}
  fraction &operator/=(const fraction &f){num*=f.den;den*=f.num;return *this;}
  friend fraction operator+(const fraction&lhs,const fraction&rhs){return fraction(lhs)+=rhs;}
  friend fraction operator-(const fraction&lhs,const fraction&rhs){return fraction(lhs)-=rhs;}
  friend fraction operator*(const fraction&lhs,const fraction&rhs){return fraction(lhs)*=rhs;}
  friend fraction operator/(const fraction&lhs,const fraction&rhs){return fraction(lhs)/=rhs;}
  friend ostream& operator<<(ostream& os, const fraction& f){os<<f.num<<"/"<<f.den;return os;}
  friend istream& operator>>(istream& is, fraction& f){is>>f.num>>f.den;return is;}
};