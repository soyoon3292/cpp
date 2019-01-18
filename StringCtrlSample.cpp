#include "MyString.h"
#include <iostream>
using namespace std;

// void testFunc(const CMyString &param) {
//     cout << param.getString() << endl;
// }

void testFunc(const CMyString &strParam) {
    cout << strParam << endl;
}

int main(int argc, char *argv[]) {
    // CMyString strData;
    // strData.setString("Hello");
    // cout << strData.getString() << endl;
    // testFunc(strData);
    // strData.setString("World!");
    // cout << strData.getString() << endl;

    // CMyString strData, strTest;
    // strData.setString("Hello");
    // strTest.setString("World");
    // // 복사 생성
    // CMyString strNewData(strData);
    // cout << strNewData.getString() << endl;
    // // 단순 대입 연산자 호출
    // strNewData = strTest;
    // cout << strNewData.getString() << endl;
    
    CMyString strData("Hello");
    cout << strData.getString() << endl; // clear

    ::testFunc(strData);
    ::testFunc(CMyString("World"));

    return 0;
}