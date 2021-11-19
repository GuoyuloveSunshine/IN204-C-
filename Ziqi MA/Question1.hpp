#ifndef QUESTION1_HPP_INCLUDED
#define QUESTION1_HPP_INCLUDED
//Question 1.2
class rational{
    private:
        int numerator;
        int denominator;
    public:
        rational():numerator(0),denominator(1){};
    explicit rational(int anInteger):numerator(anInteger),denominator(1){};
    rational(int aNumerator,int aDenominator):numerator(aNumerator),demoninator(aDenominator){};
    rational(const rational &anotherRational):numerator(anotherRational.numeration),demoninator(anotherRational.denominator){};
    //Question 2.2
    int getNumerator() const{
        return numerator;
    }
    int getDenominator() const{
        return denominator;
    }
    //Question 3
    double (rational &Rational){
        return(double)numerator/denominator;
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

};


#endif // QUESTION1_HPP_INCLUDED
