//#include "Complex.hpp"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
//    Complex I(0.0, 1.0);
//    I.print();
//    cout<<endl<<"-------------------------------"<<endl;
//    Complex Q(3.3,-8.0);
//    Q.print();
//    cout<<endl<<"-------------------------------"<<endl;
//    Complex complexValue = Q - I;
//    complexValue.print();
//    cout<<endl<<"-------------------------------"<<endl;
//    Complex complex2 = 5.5 - I;
//    complex2.print();
//    cout<<endl<<"-------------------------------"<<endl;
//    Q +=I;
//    Q.print();
//    cout<<endl<<"-------------------------------"<<endl;
//    Q -=I;
//    Q.print();
//    cout<<endl<<"-------------------------------"<<endl;
//    Complex res = Q*I;
//    cout<<"Multiplier: ";
//    res.print();
//    cout<<endl<<"-------------------------------"<<endl;
//    Complex res2 = Q/I;
//    cout<<"Diviser: ";
//    res2.print();
//    cout<<endl<<"-------------------------------"<<endl;
//    cout<< Q;

    istringstream aStream("3.4 + i 5.6");
    char c1 = aStream.get();

    string ele = "";
    string moins = "";
    bool ImagiPart = false;
    double real;
    double ima;
    while (c1!= EOF){
        if(c1!=' '){
//            cout<< c1;
            ele = ele+c1;
        }
        else{
            if(aStream.get() =='+' ||aStream.get() =='-'){
                    real = stod(ele);
                    cout<<real<<endl;
                    int pos = aStream.tellg();
                    aStream.seekg(pos-1);

            }
            else if (ele =="-"){
                string moins = "-";
            }
            else if(ele == "i"){
                ImagiPart = true;
            }
            ele = "";
        }
        c1 = aStream.get();
    }
    if (ImagiPart){
        cout<<"12312"<<endl;
        ima = stod(moins+ele);
    }
    cout <<real <<","<<ima<<endl;

    return 0;

}
