#include <iostream>
using namespace std;

void testFunc(int nParam) {
    cout << nParam << endl;
}

int main(int argc, char *argv[]) {
    testFunc(10);
    testFunc(5.5);

    return 0;
}