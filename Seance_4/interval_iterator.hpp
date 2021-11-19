#ifndef INTERVAL_ITERATOR_HPP_INCLUDED
#define INTERVAL_ITERATOR_HPP_INCLUDED

#include "interval.hpp"
class interval_iterator
	: public std::iterator <std::forward_iterator_tag, int>
{
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
        return mCurrent;
	};
	const pointer operator->() const{
        return &mInterval;
	};
	interval_iterator& operator++(){
        if(mCurrent <= mInterval.maxValue){
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

#endif // INTERVAL_ITERATOR_HPP_INCLUDED
