#pragma once
#include "MyString.h"

class CMyStringEx : public CMyString {
    public:
        CMyStringEx();
        CMyStringEx(const char* pszParam);
        ~CMyStringEx();
        int find(const char* pszParam);
        int setString(const char* pszParam);
};