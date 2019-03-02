#include <iostream>
using namespace std;

int testFunc(int nParam) {
    cout << "Function Pointer: " << nParam << endl;

    return nParam;
}

int main(int argc, char* argv[]) {
    // 람다식 선언 및 정의
    auto func = [](int nParam) -> int {
        cout << "Lambda: " << nParam << endl;

        return nParam;
    };

    // 람다식 호출
    func(5);

    // 함수 포인터를 이용한 호출
    auto pfTest = testFunc;
    pfTest(10);

    return 0;
}