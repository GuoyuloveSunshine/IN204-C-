#include <iostream>
#include <vector>

#include"simple_sort.hpp"
#include"simple_sort_general.hpp"

void test_simple(){
    using namespace monomorphic;

    std::vector<int> values;
    populate_with_randoms(values, 10, 1, 10);
    print_vector(values);
    simple_sort(values);
    print_vector(values);
}
void test_general(){
    using namespace generic;

    std::vector<int> values;
    populate_with_randoms(values, 10, 20, 40);
    print_vector(values);
    simple_sort(values);
    print_vector(values);

    std::vector<float> floatValues;
    populate_with_randoms(floatValues, 10, 20.0, 40.0);
    print_vector(floatValues);
    simple_sort(floatValues);
    print_vector(floatValues);

    std::vector<char> charValues;
    populate_with_randoms(charValues, 10, 'A', 'Z');
    print_vector<char>(charValues);
    simple_sort(charValues);
    print_vector(charValues);

}

void test_string(){
    using namespace generic;
    std::vector<std::string> a_string;
    populate_with_randoms(a_string, 10, 10, 20);
    print_vector(a_string);
    simple_sort(a_string);
    print_vector(a_string);

}

void test_sort(){
    std::vector<int> a_array;
    generic::populate_with_randoms(a_array, 10, 1, 10);
    generic::print_vector(a_array);
    std::cout << "\n";
    generic::simple_sort(a_array);
    generic::print_vector(a_array);
    std::cout << "\n";
    generic::simple_sort<int, generic::lower_traits<int>>(a_array);
    generic::print_vector(a_array);
}


int main()
{
    //test_simple();
    //test_general();
    //test_string();
    test_sort();
    return 0;
}
