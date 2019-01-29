#pragma once
#include "MyString.h"

class CMyStringEx : public CMyString {
    public:
        CMyStringEx();
        ~CMyStringEx();
        int find(const char* pszParam);
        int setString(const char* pszParam);
};