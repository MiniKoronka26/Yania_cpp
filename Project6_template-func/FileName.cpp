#include <iostream>
using namespace std;

template<class T>/*
T sum(T a, T b) {
    return a + b;
}*/
T avarage(T* arr, int size) {
    T avarage = 0;
    for (int i = 0; i < size; i++) {
        avarage += arr[i];
    }
    return avarage / size;
}





int main() {

    
    /*int res = sum(3, 4);
    cout << res;
    
    cout << sum(3, 4) << "\n" << sum(3.15, 4.0);*/

    const int size = 5;
    int arr1[size] = { 1,2,3,4,5 };
    double arr2[size] = { 1.2, 2.3,3.4,4.5,5.6 };

    cout << avarage(arr1, size) << "\n" << avarage(arr2, size);









    return 0;
}