#include <iostream>
using namespace std;

int testFunc(int nParam1, int nParam2 = 2) {
    return nParam1 * nParam2;
}
// int testFunc(int nParam1 = 2, int nParam2) { // error: default argument missing for parameter 2 of testFunc(int, int)
//     return nParam1 * nParam2;
// }

int main(int argc, char *argv[]) {
    cout << testFunc(10) << endl;
    cout << testFunc(10, 5) << endl;
    // cout << testFunc() << endl; // error: too few argument to function testFunc(int, int)

    return 0;
}