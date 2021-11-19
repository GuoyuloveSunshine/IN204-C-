#ifndef INTERVAL_HPP_INCLUDED
#define INTERVAL_HPP_INCLUDED
class interval_iterator;

class interval{
    private:
        int minValue;
        int maxValue;

    public:
        friend class interval_iterator;
        typedef interval_iterator const_iterator;
        const_iterator begin() const noexcept;
        const_iterator end() const noexcept;

        typedef int value_type;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        //Constructeur
        interval(int theMinValue, int theMaxValue) :
            minValue(theMinValue), maxValue(theMaxValue){};
        interval(const interval& anotherInterval):
            minValue(anotherInterval.minValue),
                    maxValue(anotherInterval.maxValue){};
        // Functions
        interval& operator = (const interval& anotherInterval){
            minValue = anotherInterval.minValue;
            maxValue = anotherInterval.maxValue;
            return *this;
        }
        size_type size() const{
            return (size_type)(maxValue - minValue);
        }
        int operator[](size_type anIndex) const{
            if (anIndex > size())
                throw std::out_of_range("Index out of range");
            return minValue + (int)anIndex;
        }
        bool operator == (const interval& anotherInterval) const{
            return anotherInterval.maxValue == maxValue &&
                anotherInterval.minValue == minValue;
        }
        bool operator != (const interval& anotherInterval) const{
            return anotherInterval.maxValue != maxValue ||
                anotherInterval.minValue != minValue;
        }
};

template<class inputIterator>
void print(inputIterator beginIt, inputIterator endIt){
    if(beginIt == endIt)
    {
        std::cout << "[]" << std::endl;
        return;
    }
    for(;;)
    {
        std::cout << *beginIt;
        beginIt++;
        if(beginIt == endIt)
            break;
        std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    return;
}


class interval_iterator: public std::iterator <std::forward_iterator_tag, int>{
    private:
        friend class interval;
        const interval* mInterval; // Référence à l'interval.
        int mCurrent; // la valeur courante dont on fait référence.

        interval_iterator(const interval& anInterval, int aCurrentValue) :
            mInterval(&anInterval), mCurrent(aCurrentValue) {};

    public:
        interval_iterator(const interval_iterator& anotherIterator):
            mInterval(anotherIterator.mInterval),
            mCurrent(anotherIterator.mCurrent) {};

        interval_iterator& operator = (interval_iterator& anotherIterator)
        {
            mInterval = anotherIterator.mInterval;
            mCurrent = anotherIterator.mCurrent;
            return *this;
        }

        const reference operator*() const{
            return reference(mCurrent);
        };
        const pointer operator->() const{
            return pointer(&mCurrent);
        };
        interval_iterator& operator++(){
            if(mCurrent <= mInterval->maxValue){
                mCurrent++;
                return *this;
            };
        };
        interval_iterator& operator++(int){
            interval_iterator it(*this); // Crée une copie de l'itérateur.
            ++(*this);          // Incrément l'itérateur courant en appellant
                                // l'opérateur iterator& operator()
            return it;
        };
        bool operator ==(const interval_iterator& another_iterator) const{
            return mCurrent == another_iterator.mCurrent &&
                *mInterval == *another_iterator.mInterval;
        };
        bool operator !=(const interval_iterator& another_iterator) const{
            return mCurrent != another_iterator.mCurrent ||
                *mInterval != *another_iterator.mInterval;
        };
        void swap(interval_iterator& anotherIterator){
            std::swap(mCurrent, anotherIterator.mCurrent);
            std::swap(mInterval, anotherIterator.mInterval);
        }

};

interval:: const_iterator begin() const noexcept{
    const_iterator pointer(this,minValue);
    return pointer;
};
interval:: const_iterator end() const noexcept{
    const_iterator pointer(this,maxValue);
    return pointer;
};

#endif // INTERVAL_HPP_INCLUDED
