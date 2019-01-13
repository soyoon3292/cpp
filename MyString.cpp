#include "MyString.h"
#include <iostream>
#include <cstring>

CMyString::CMyString() : m_pszData(NULL), m_nLength(0) {
}

CMyString::~CMyString() {
    release();
}

int CMyString::setString(const char* pszParam) {
    release();
    if(pszParam == NULL)
        return 0;
    m_nLength = strlen(pszParam);
    if(m_nLength == 0)
        return 0;
    m_pszData = new char[m_nLength + 1];
    strncpy(m_pszData, pszParam, m_nLength);
    
    return m_nLength;
}

const char* CMyString::getString() {
    return m_pszData;
}

void CMyString::release() {
    if(m_pszData != NULL)
        delete[] this->m_pszData;

    m_pszData = NULL;
    m_nLength = 0;
}