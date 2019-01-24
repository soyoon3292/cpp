#include "MyStringEx.h"
#include <cstring>


int CMyStringEx::find(const char* pszParam) {
    if(getString() == NULL || pszParam == NULL)
        return -1;
    const char *pszResult = strstr(getString(), pszParam);
    if(pszResult == NULL)
        return -1;

    return pszResult - getString();
}