#pragma once
#include "MyNode.h"
#include "MyString.h"

// CMyNode 클래스의 파생 클래스로 변경
class CUserData : public CMyNode {
    public:
        CUserData(void);
        CUserData(const char* pszName, const char* pszPhone);
        ~CUserData(void);

        const char* getName(void) const { return strName.getString(); }
        const char* getPhone(void) const { return strPhone.getString(); }
        static int getUserDataCounter(void) { return nUserDataCounter; }

    protected:
        CMyString strName;    // 이름
        CMyString strPhone;   // 전화번호

        // pNext 멤버가 사라졌다!
        static int nUserDataCounter;

    public:
        // 순수 가상 함수들 정의
        virtual const char* getKey(void);
        virtual void printNode(void);

        CUserData(const char* pszName, const char* pszPhone);
};