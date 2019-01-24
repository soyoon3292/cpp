#pragma once
#include "MyString.h"

class CMyStringEx : public CMyString {
    public:
        int find(const char* pszParam);
};