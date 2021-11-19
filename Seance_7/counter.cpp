#include "counter.hpp"

template<class charT, class charTraits>
std::basic_ostream<charT>& operator <<(std::basic_ostream<charT, charTraits>&aStream, const BaseCounter& aCounter){
    aStream << aCounter.get_classname() <<
        ", Counter: " << aCounter.counter << ", Max: " << aCounter.max << std::endl ;
    return aStream;
};

void testNext(BaseCounter& aCounter){
    for(int i = 0;i<20;i++){
        aCounter.next();
        std::cout<<aCounter;
    }

}

void testForwardCounter(ForwardCounter& aCounter){
    for(int i = 0 ; i < 20 ; i++){
        aCounter.increment();
        std::cout<<aCounter;
    }

}
