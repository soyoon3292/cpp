#include "MyStringEx.h"
#include <cstring>

CMyStringEx::CMyStringEx() {

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

int CMyStringEx::setString(const char* pszParam) {
    int nResult;

    if(strstr(pszParam, "멍멍이") != NULL)
        nResult = CMyString::setString("착한 사람");
    else
        nResult = CMyString::setString(pszParam);
        
    return nResult;
}