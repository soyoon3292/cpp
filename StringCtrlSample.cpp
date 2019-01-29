#include "MyStringEx.h"
#include <iostream>
using namespace std;

// void testFunc(const CMyString &param) {
//     cout << param.getString() << endl;
// }

// void testFunc(const CMyString &strParam) {
//     // cout << strParam << endl;
//     cout << strParam.operator const char* const << endl;
//     cout << CMyString("World").operator const char* const << endl;
// }

// CMyString testFunc() {
//     CMyString strTest("testFunc() return");
//     cout << strTest << endl;

//     return strTest;
// }

// void testFunc(const CMyString &strParam) {
//     cout << strParam[0] << endl;
//     cout << strParam[strParam.getLength() - 1] << endl;
//     cout << strParam[20] << endl;
// }

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
    
    // CMyString strData("Hello");
    // cout << strData.getString() << endl;
    // ::testFunc(strData);
    // ::testFunc(CMyString("World"));

    // // 이름 없는 임시 객체가 만들어진다.
    // testFunc();

    // CMyString strLeft("Hello"), strRight("World"), strResult;
    // strResult = strLeft + strRight;
    // cout << strResult << endl;
    // cout << strLeft << endl;
    // strLeft += CMyString("World");
    // cout << strLeft << endl;

    // CMyString strParam("HelloWorld");
    // cout << strParam << endl;
    // testFunc(strParam);
    // CMyString a("Hello");
    // testFunc(a);
    // for(int i = 0; i < 10; ++i) {
    //     a[i] = 65 + i;
    //     cout << a[i] << endl;
    // }
    // testFunc(a);
    // CMyString c("Hello");
    // if(strParam == c)
    //     cout << "Same" << endl;
    // else
    //     cout << "Different" << endl;
    // c = CMyString("ABCDEFGHIJ");
    // if(a != c)
    //     cout << "Different" << endl;
    // else
    //     cout << "Same" << endl;

    // CMyStringEx strTest;
    // strTest.setString("I am a boy.");
    // cout << strTest << endl;
    // int nIndex = strTest.find("am");
    // cout << "Index: " << nIndex << endl;

    CMyStringEx strTest;

    // 문자열이 필터링되어 대체되는 경우
    strTest.setString("멍멍이 아들");
    cout << strTest << endl;

    // 필터링되지 않는 경우
    strTest.setString("Hello");
    cout << strTest << endl;

    return 0;
}