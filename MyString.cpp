#include "MyString.h"
#include <iostream>
#include <cstring>

CMyString::CMyString() : m_pszData(NULL), m_nLength(0) {
}

// 복사 생성자
CMyString::CMyString (const CMyString &rhs) : m_pszData(NULL), m_nLength(0) {
    this->setString(rhs.getString());
}

// 변환 생성자
CMyString::CMyString (const char* pszParam) : m_pszData(NULL), m_nLength(0) {
    setString(pszParam);
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

const char* CMyString::getString() const {
    return m_pszData;
}

void CMyString::release() {
    if(m_pszData != NULL)
        delete[] m_pszData;

    m_pszData = NULL;
    m_nLength = 0;
}

CMyString &CMyString::operator = (const CMyString &rhs) {
    // 자기 자신에 대한 대입이면 아무것도 하지 않는다.
    if(this != &rhs)
        this->setString(rhs.getString());

    return *this;
}

CMyString::operator const char*() const { return m_pszData; }