#include <iostream>
using namespace std;

void testFunc1() {
    // 가장 마지막에 호출된 함수가 예외를 던진다.
    cout << "***testFunc1() - Begin***" << endl;
    throw 0;
    cout << "****testFunc1() - End****" << endl;
}

void testFunc2() {
    cout << "***testFunc2() - Begin***" << endl;
    testFunc1();
    cout << "****testFunc2() - End****" << endl;
}

void testFunc3() {
    cout << "***testFunc3() - Begin***" << endl;
    testFunc2();
    cout << "****testFunc3() - End****" << endl;
}

int main(int argc, char* argv[]) {
    try {
        testFunc3();
    }

    catch(...) {
        // 함수들을 반환하지 않고 스택이 즉시 풀려 흐름이 넘어온다.
        cout << "Exception handling" << endl;
    }

    return 0;
}