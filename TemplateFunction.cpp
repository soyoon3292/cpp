#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

template<typename T>
T add(T a, T b) { return a + b; }

// 두 개의 변수가 모두 char* 형식이면 이 함수로 대체된다.
template< >
char* add(char *pszLeft, char *pszRight) {
    int nLenLeft = strlen(pszLeft);
    int nLenRight = strlen(pszRight);
    char *pszResult = new char[nLenLeft + nLenRight + 1];

    // 새로 할당한 메모리에 문자열을 복사한다.
    strncpy(pszResult, pszLeft, nLenLeft + 1);
    strncpy(pszResult + nLenLeft, pszRight, nLenRight + 1);

    return pszResult;
}

int main(int argc, char* argv[]) {
    int nResult = add<int>(3, 4);
    cout << nResult << endl;

    char *pszResult = add<char *>("Hello", "World");
    cout << pszResult << endl;
    delete[] pszResult;

    return 0;
}