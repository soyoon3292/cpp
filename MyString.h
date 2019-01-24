#pragma once

class CMyString {
    public:
        CMyString();
        // 복사 생성자
        CMyString(const CMyString &rhs);
        // 변환 생성자
        CMyString(const char* param);
        // 이동 생성자
        CMyString(CMyString &&rhs);
        ~CMyString();
        
    private:
        // 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
        char* m_pszData;
        // 저장된 문자열의 길이
        int m_nLength;
    
    public:
        int setString(const char* pszParam);
        // 멤버 읽기만 수행하므로 메서드를 상수화한다.
        const char* getString() const;
        void release();
        CMyString& operator=(const CMyString &rhs);
        operator const char* const();
        int getLength() const;
        int append(const char * pszParam);
        CMyString operator+(const CMyString &rhs);
        CMyString& operator+=(const CMyString &rhs);
        char& operator[](int nIndex);
        char operator[](int nIndex) const;
        int operator==(const CMyString &rhs);
        int operator!=(const CMyString &rhs);
};