#include <iostream>

using namespace std;


class complex
{
    private:
    double re;
    double im;

    public:

    // constructors

    complex (); // default constructor;
    complex (const double real,const double img );
    complex (double real);
    complex(const complex &rhs);


    double real() const;
    double imag() const;


    complex& operator = (const complex& );
    complex& operator =(const int &);

    complex& operator += (const complex&);
    complex& operator -= (const complex&);
    complex& operator *= (const complex&);
    complex& operator /= (const complex& );

    complex operator +(const complex &);
    complex operator -(const complex &);

    complex operator +(const complex &, const complex &);
    complex operator -(const complex &,const complex &);
    complex operator *(const complex , const complex &);
    complex operator /(const complex, const complex &);
};


complex:: complex(const double real,const double img ){
    complex cplex;
    cplex.re  =  re;
    cplex.im = im;

}


complex:: complex(double real){
    complex cplex;
    cplex.re  =  real;
    cplex.im = 0;

}

// osäker på den här constructor 
complex::complex(const complex &rhs){
    complex cplex;
    cplex.re = rhs.re;
    cplex.im = rhs.im;


}







// copy asign that takes a complex and a copy assign that takes a real (the imaginary part is set to zero)
complex& complex::operator =(const complex &c)
{
    this->re = c.real();
    this->im =  c.imag();
    return *this;
}


complex& complex::operator =(const int &x){
    this->re = x;
    this->im = 0;
    return *this;
}


complex& complex::operator +=(const complex &c ){   // read only
    this ->re = this->re + c.re;
    this -> im = this->im + c.im;
    return *this;
}


complex& complex::operator -=(const complex &c ){   // vi behöver ändra något i  vårat argument (ett complext tal) därför: const
    this -> re = this->re - c.re;
    this-> im = this->im - c.im;
    return *this;
}

complex& complex::operator *=(const complex &c ){   //
    this->re = (this->re * c.re) - (this->im * c.im );
    this->im = (this->re * c.im) + (this->im + c.re );
    return *this;
}


complex& complex::operator /=(const complex &c ) { //
    double denominator=(c.re * c.re) + (c.im * c.im);
    this-> re=(this->re*c.re)+(this->.im*c.im)/denominator;
    this-> im=((this->im*c.re)-(this->re *c.im))/denominator;
    return *this;  //
}


/// nonmember functions

complex operator+(const complex& c){ // return value  -  a copy of the argument,
    complex copy = c;
    return copy;
}




complex operator-(const complex& c){ // return value  -  a copy of the argument,
    complex copy= c;
    copy.re = -1*copy.real();   // ska jag istället använda  copy.real() och copy.img()  ?????
    copy.im = -1*copy.imag();
    return copy;
}




complex operator +(const complex& c1  , const complex& c2 ){
    complex resultat;

    resultat.re = c1.re + c2.re;
    resultat.im = c1.im + c2.im;
    return resultat;


}


complex operator -(const complex& c1  , const complex& c2 ){
    complex resultat;

    resultat.re = c1.real() - c2.real();
    resultat.im = c1.imag() - c2.imag();
    return resultat;

}


complex operator *(const complex& c1  , const complex& c2 ){
    complex resultat;

    resultat.re = (c1.real() * c2.real()) - (c1.imag() * c2.imag() );
    resultat.im = (c1.real() * c2.imag()) + (c1.imag() + c2.real() );

    return resultat;

}






int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}