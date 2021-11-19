#include <chrono>
#include <iostream>
#include <utility>

template<typename ...Types>
void print(Types... args) {
    std::cout << std::endl;
}
template<typename T, typename ... Types>
void print (T firstArg, Types ... args) {
    std::cout << firstArg << ",";
    print(args...);
}

constexpr long double factorial(int n){
    return n == 0 ? 1 : (n * factorial(n - 1));
}

std::pair<std::chrono::high_resolution_clock::duration, int> estimate_factorial_time(int n){
    // Code pour lancer le chronomètre
    auto fac_start = std::chrono::high_resolution_clock::now();
    int result = factorial(n);
    // Code pour calculer le temps écoulé
    auto fac_end = std::chrono::high_resolution_clock::now();
    // Retourner la paire contenant le résultat et le temps passé.
    return std::make_pair(fac_end-fac_start, result);
}


template<class Function, typename...T>
auto estimate_function_time(Function function, T... argument){
	auto starting_time = std::chrono::high_resolution_clock::now();
	auto result = function(argument...);
	auto elasped_time = std::chrono::high_resolution_clock::now() - starting_time;
	return std::make_pair(elasped_time, result);
}

template<class numericalT>
constexpr numericalT power_by_int(numericalT x, int y)
{
    numericalT result = (numericalT)1.0;
    while (y-- > 0)
      result *= x;
    return result;
}


template<class Function, class ... Args>
long long mean_function_time(int number_of_runs, Function function, Args... arguments){
    long long temps;
    for(int i = 0;i< number_of_runs; i++){
        auto one_resultat = estimate_function_time(function,arguments...);
        temps += one_resultat.first.count();
    }
    long long moyen_t = temps/(long long)number_of_runs;
//    std::cout << temps << std::endl;
//    std::cout << number_of_runs << std::endl;
    return moyen_t;
}

template<int value, int power>
struct constant_value{
    static constexpr long double constant() { constexpr auto result = power_by_int(value, power); return result; }
};
int main(){
//    //Partie 2-1
//    auto p1 = estimate_factorial_time(5);
//    print(p1.first.count(),p1.second);

//    //Partie 2-2
//    auto p2 = estimate_function_time(power_by_int<long double>, 1.0002, 10000000);
//    std::cout << "1. Computing 1.02^1000000=" << p2.first.count()<< "Le temps pour calculation: "
//        << (long)p2.second << " ticks.\n";
//
//    long long temps_moyen = mean_function_time(10,power_by_int<long double>, 1.0002, 10000000);
//    std::cout << "10. Computing 1.02^1000000=" << p2.first.count()<< "Le temps pour calculation: "
//        << temps_moyen << " ticks.\n";

//    // Partie 3_1
//    auto fn =  estimate_function_time(factorial, 100);
//    std::cout << "Computing fact(100)= " << fn.second << " in " << fn.first.count() << " ticks.\n";
//    auto pw = estimate_function_time(power_by_int<long double>, 1.0002, 1000000);
//    std::cout << "Computing 1.02^1000000=" << pw.second << " in " << pw.first.count() << " ticks.\n";

//    //Partie 3_2
//    auto factorial_100 = []() { return factorial(100); };
//    auto fn = estimate_function_time(factorial_100);
//    std::cout << "Computing fact(100)=" << fn.second << " in " << fn.first.count() << " ticks.\n";
//
//    auto power_10002_100000 = []() { return power_by_int<long double>(1.0002, 100000); };
//    auto pw = estimate_function_time(power_10002_100000);
//    std::cout << "Computing 1.02^1000000=" << pw.second << " in " << pw.first.count() << " ticks.\n";

//    //Partie 3_3
//    auto factorial_100 = []() { constexpr auto res = factorial(100); return res; };
//    auto fn = estimate_function_time(factorial_100);
//    std::cout << "Computing fact(100)=" << fn.second << " in " << fn.first.count() << " ticks.\n";
//
//    auto power_10002_100000 = []() { constexpr auto res = power_by_int<long double>(1.0002, 100000); return res; };
//    auto pw = estimate_function_time(power_10002_100000);
//    std::cout << "Computing 1.02^1000000=" << pw.second << " in " << pw.first.count() << " ticks.\n";

    //Partie 3_4

    auto pw_c = estimate_function_time(constant_value<2, 100>::constant);
    std::cout << "Computing 2^100=" << pw_c.second << " in " << pw_c.first.count() << " ticks.\n";
    return 0;
}
