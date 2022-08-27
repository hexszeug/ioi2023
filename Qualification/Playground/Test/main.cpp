#include <iostream>

using namespace std;

int main()
{
    int *arr[10];
    cout << arr << " " << *arr << " " << **arr << " " << *arr[0];
    return 0;
}
