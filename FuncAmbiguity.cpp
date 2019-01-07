#include <iostream>
using namespace std;

void testFunc(int a) {
    cout << "testFunc(int)" << endl;
}

void testFunc(int a, int b = 10)
{
    cout << "testFunc(int, int)" << endl;
}

int main(int argc, char *argv[]) {
    // testFunc(5); // error: call of overloaded 'testFunc(int)' is ambiguous

    return 0;
}