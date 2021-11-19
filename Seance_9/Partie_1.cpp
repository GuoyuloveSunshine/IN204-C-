#include <initializer_list>
#include <iostream>

void print(std::initializer_list<int> Alist){
    for(auto it = std::begin(Alist); it != std::end(Alist); ++it) {
    std::cout << *it << ',';
    }
    std::cout <<std::endl;
}


template<class ...Args>
int number_of_args(Args... arguments){
    return 0;
}
template<class T, class ...Args>
int number_of_args(T first_argument, Args... arguments){
    return 1 + number_of_args(arguments...);
}

template<typename ...Types>
void print(Types... args) {
    std::cout << std::endl;
}
template<typename T, typename ... Types>
void print (T firstArg, Types ... args) {
    std::cout << firstArg << ",";
    print(args...);
}

int main(){
//    std::initializer_list<int> list_of_values = {1, 3, 4, 2 };
//    print(list_of_values);
//    std::cout << number_of_args(1, "e", 2.0, 'c') << "\n";
    print(1,"eee",2.0,'c');
    return 0;

}
