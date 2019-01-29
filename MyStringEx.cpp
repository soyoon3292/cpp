#include "MyStringEx.h"
#include <cstring>
#include <iostream>
using namespace std;

CMyStringEx::CMyStringEx() {

}

CMyStringEx::CMyStringEx(const char* pszParam) : CMyString(pszParam) {
    
}

CMyStringEx::~CMyStringEx() {

}

int CMyStringEx::find(const char* pszParam) {
    if(getString() == NULL || pszParam == NULL)
        return -1;
    const char *pszResult = strstr(getString(), pszParam);
    if(pszResult == NULL)
        return -1;

    return pszResult - getString();
}

// int CMyStringEx::setString(const char* pszParam) {
//     int nResult;

//     if(strstr(pszParam, "멍멍이") != NULL)
//         nResult = CMyString::setString("착한 사람");
//     else
//         nResult = CMyString::setString(pszParam);

//     return nResult;
// }

void CMyStringEx::onSetString(char* pszData, int nLength) {
    if(strstr(pszData, "멍멍이") != NULL)
        strncpy(pszData, "*착한아들*", sizeof(char)* (nLength + 1));
}