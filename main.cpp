#include <string>
#include "SimpleVector.h"

using namespace std;
int main()
{
    SimpleVector<int> v1(30);
    SimpleVector<string> v2;

    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(1);

    v2.push_back("apple");
    v2.push_back("crayon");
    v2.push_back("banana");

    cout << "v1: " << endl;
    v1.print();
    v1.sortData();
    cout << "v1 after sort: " << endl;
    v1.print();

    cout << "v2: " << endl;
    v2.print();
    v2.sortData();
    cout << "v2 after sort: " << endl;
    v2.print();

    return 0;
}