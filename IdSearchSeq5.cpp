#include <iostream>
using namespace std;

int nData = 100;

namespace TEST {
    int nData = 200;
}

using namespace TEST;

int main(int argc, char *argv[]) {
    cout << nData << endl; // error: reference to 'nData' is ambiguous

    return 0;
}