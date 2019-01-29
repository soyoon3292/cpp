#include <iostream>
using namespace std;

void testFunc1(int nParam) { }
void testFunc2(int nParam) { }

int main(int argc, char* argv[]) {
    int nInput = 0;
    cin >> nInput;
    void(*pfTest)(int) = NULL;

    if(nInput > 10)
        pfTest = testFunc1;

    else
        pfTest = testFunc2;
    
    pfTest(10);

    return 0;
}