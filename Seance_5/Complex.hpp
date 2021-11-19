#ifndef COMPLEX_INCLUDED
#define COMPLEX_INCLUDED
#include <iostream>
#include <math.h>
using namespace std;
class Complex{
    friend Complex operator * (int, const Complex&);
    friend Complex operator * (double, const Complex&);
    friend Complex operator * (const Complex&, int);
    friend Complex operator * (const Complex&, double);
    friend Complex operator + (double, const Complex&);
    friend Complex operator - (double, const Complex&);
    template<class charT, class charTraits>
    friend std::basic_ostream<charT>& operator <<(std::basic_ostream<charT, charTraits>& aStream, const Complex& aValue);
private:
    double mRealPart;
    double mImaginaryPart;
public:
    Complex(double aReal):mRealPart(aReal),mImaginaryPart(0){};
    Complex(float aReal): mRealPart(aReal),mImaginaryPart(0){};
    Complex(int aReal) : mRealPart((double)aReal), mImaginaryPart(0.0) {};
    Complex(unsigned int aReal) : mRealPart((double)aReal), mImaginaryPart(0.0) {};
    Complex(double aReal, double Imaginary):mRealPart(aReal),mImaginaryPart(Imaginary){};
    Complex(const Complex &ele):mRealPart(ele.mRealPart),mImaginaryPart(ele.mImaginaryPart){};
    ~Complex(){};
    void print() const{
        if(mRealPart!= 0){
            cout << mRealPart;
            if (mImaginaryPart > 0){
                cout << "+" <<mImaginaryPart <<"*I";
            }
            else if (mImaginaryPart < 0){
                cout <<mImaginaryPart <<"*I";
            }

        }
        else{
            cout<<mImaginaryPart<< "*I"<<endl;
        }

    }
    static Complex get_from_real_imaginary(double ele_real,double ele_imag){
        return Complex(ele_real,ele_imag);
    }
    static Complex get_from_polar(double rho,double theta){
        return Complex(rho*cos(theta),rho*sin(theta));
    }
    Complex operator + (const Complex& aRightValue) const{
        Complex result = *this;
        result.mRealPart += aRightValue.mRealPart;
        result.mImaginaryPart += aRightValue.mImaginaryPart;
        return result;
    }
	Complex operator - (const Complex& aRightValue) const{
        Complex result = *this;
        result.mRealPart -= aRightValue.mRealPart;
        result.mImaginaryPart -= aRightValue.mImaginaryPart;
        return result;
	}
	Complex operator + (double aRightValue) const{
        Complex result = *this;
        result.mRealPart += aRightValue;
        return result;
    }
	Complex operator - (double aRightValue) const{
        Complex result = *this;
        result.mRealPart -= aRightValue;
        return result;
    }
    Complex& operator += (const Complex& aRightValue){
        *this = *this + aRightValue;
        return *this;
    }
	Complex& operator -= (const Complex& aRightValue){
        *this = *this - aRightValue;
        return *this;
	}
    Complex operator * (const Complex& aRightValue) const{
        return Complex(mRealPart * aRightValue.mRealPart - mImaginaryPart * aRightValue.mImaginaryPart,
            mRealPart * aRightValue.mImaginaryPart + mImaginaryPart * aRightValue.mRealPart);
    }
	Complex operator / (const Complex& aRightValue) const{
        double squareNorm = aRightValue.mRealPart * aRightValue.mRealPart
            + aRightValue.mImaginaryPart * aRightValue.mImaginaryPart;
        return *this *Complex(aRightValue.mRealPart / squareNorm,
                    -aRightValue.mImaginaryPart / squareNorm);
    }
    double isdouble(const std::string &s){
        char *end = 0;
        double val = s.strtod(s.c_str(),&end);
        if(end )
    }
    template<class charT, class charTraits>
    std::basic_istream<charT>& operator >>(std::basic_istream<charT, charTraits>&aStream, Complex& aValue){
        char c1 = aStream.get();
        string ele="";
        while (c1!= EOF){
            if(c1!=' '){
    //            cout<< c1;
                ele = ele+c1;
            }
            else{
                if(aStream.peek() =='+' ||aStream.peek() =='-'){
                    aValue.mRealPart = strtod(ele);
                }
                if(ele == "+")
                cout<< ele;
                ele = "";
            }

            c1 = aStream.get();
        }
        cout <<ele;
    };

    template<class charT, class charTraits>
    void option_inverse(std::basic_ostream<charT, charTraits>&aStream){
        char s = aStream.get();
        while (s!=EOF){
            string ele="";
            while(s!=' '){
            ele = ele+s;

            }
        }
    }


};

template<class charT, class charTraits>
std::basic_ostream<charT>& operator <<(std::basic_ostream<charT, charTraits>&aStream, const Complex& aValue){
    aStream << aValue.mRealPart <<" + i " << aValue.mImaginaryPart;
    return aStream;
};

Complex operator + (double aLeftValue,Complex & aRightValue){
    return aRightValue + aLeftValue;
}

Complex operator - (double aLeftValue, Complex & aRigheValue){
    Complex result(aLeftValue,0.0);
    return result - aRigheValue;
}
inline Complex operator * (int theLeftValue, const Complex& theRightValue)
{
    return Complex(theLeftValue * theRightValue.mRealPart,
        theRightValue.mImaginaryPart);
}
inline Complex operator * (const Complex& theLeftValue, int theRightValue)
{
    return Complex(theLeftValue.mRealPart * theRightValue,
        theLeftValue.mImaginaryPart);
}
inline Complex operator * (double theLeftValue, const Complex& theRightValue)
{
    return Complex(theLeftValue * theRightValue.mRealPart,
        theRightValue.mImaginaryPart);
}
inline Complex operator * (const Complex& theLeftValue, double theRightValue)
{
    return Complex(theLeftValue.mRealPart * theRightValue,
        theLeftValue.mImaginaryPart);
}
#endif // COMPLEX_INCLUDED
