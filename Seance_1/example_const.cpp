#include<iostream>
using namespace std;
/*
int findIndex(int theValue, const int* anArray, int theArrayLength)
{
    for(int i = 0; i < theArrayLength; i++)
    {
        if(anArray[i] == theValue)
            return i;
    }
    return -1;
}

int main()
{
    int array[] = {2, 3, 2, 4, 7, 3, 8 };
    cout << "Index du premier 3 dans le tableau: " << findIndex(3,array,7) << endl;
}
*/

int buggyFindIndex(int theValue, const int* anArray, int theArrayLength)
{
    for(int i = 0; i < theArrayLength; i++)
    {
        if(anArray[i] == theValue)
        {
            const_cast<int*>(anArray)[i] = 0;
            // converti anArray en int*, permettant de modifier les valeurs
            // pointées par anArray.
            return i;
        }
    }
    return -1;
}

//int main(){
//    int myarray[] = {2, 3, 2, 4, 7, 3, 8 };
//    cout << "Index du premier 3 dans le tableau: "<< buggyFindIndex(3,myarray,7) << endl;
//
//    size_t n = sizeof(myarray)/sizeof(myarray[0]);
//
//    // loop through the array elements
//    for (size_t i = 0; i < n; i++) {
//        cout << myarray[i] << ' ';
//    }
//    cout << endl;
//    return 0;
//}
