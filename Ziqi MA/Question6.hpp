#ifndef QUESTION6_HPP_INCLUDED
#define QUESTION6_HPP_INCLUDED

template<typename T = int64_t>
class rational{
    private:
        T numerator;
        T denominator;
    public:
        rational():numerator(0),denominator(1){};
    explicit rational(T anInteger):numerator(anInteger),denominator(1){};
    rational(T aNumerator,T aDenominator):numerator(aNumerator),denominator(aDenominator){};
    rational(const rational &anotherRational):numerator(anotherRational.numerator),denominator(anotherRational.denominator){};
    //Question 2.2
    T getNumerator() const{
        return numerator;
    }
    T getDenominator() const{
        return denominator;
    }
    //Question 3
    double get_value(){
        return (double) numerator/denominator;
    }

    //Question 4.1
    bool operator == (const rational& Rational) const{
        if(numerator==Rational.numerator && denominator==denominator.denominator){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator != const rational& Rational) const{
        if(numerator!=Rational.numerator || denominator!=denominator.denominator){
            return true;
        }
        else{
            return false;
        }
    }

    //Question 5
    rational operator + (const rational& Rational) const{
        rational result = *this;
        rational temp = *this
        result.numerator = temp.numerator*Rational.denominator +temp.denominator*Rational.numerator;
        result.denominator += temp.denominator*Rational.denominator;
        return result;
    }
    rational operator - (const rational& Rational) const{
        rational result = *this;
        rational temp = *this
        result.numerator = temp.numerator*Rational.denominator -temp.denominator*Rational.numerator;
        result.denominator += temp.denominator*Rational.denominator;
        return result;
    }
    rational operator * (const rational& Rational) const{
        rational result = *this;
        result.numerator = result.numerator*Rational.numerator;
        result.denominator += result.denominator*Rational.denominator;
        return result;
    }
    rational operator / (const rational& Rational) const{
        rational result = *this;
        result.numerator = result.numerator*Rational.denominator;
        result.denominator += result.denominator*Rational.numerator;
        return result;
    }
    //Question 6.3.3
    rational operator *(const rational<T> anIntergerValue){

    }

    template<class charT,class traits, class T>
    friend std::basic_ostream<charT,traits>&operator <<(std::basic_ostream<charT,traits>&astream,rational<T> theRational);

};
//Question 7

template<class charT,class traits, class T>
inline std::basic_ostream<charT,traits>&operator <<(std::basic_ostream<charT,traits>&astream,rational<T> theRational){
    if(theRational.denominator==0){
        aStream<<"inf";
    }
    else if(theRational.nominator==0){
        aStream << theRational.nominator

    }
    else{
        aStream<<theRational.nominator << "/"<<theRational.denominator
    }
};

#endif // QUESTION6_HPP_INCLUDED
