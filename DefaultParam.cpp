#include <iostream>
using namespace std;


int testFunc(int = 10);
// nParam 매개변수의 디폴트 값은 10이다.
int testFunc(int nParam) {
    return nParam;
}

int main(int argc, char *argv[]) {
    // 호출자가 실인수를 기술하지 않았으므로 디폴트 값을 적용한다.
    cout << testFunc() << endl;

    // 호출자가 실인수를 확정했으므로 디폴트 값을 무시한다.
    cout << testFunc(20) << endl;

    return 0;
}