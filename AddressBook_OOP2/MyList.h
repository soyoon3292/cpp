#pragma once
#include "MyNode.h"
#include "MyIterator.h"

// 노드 클래스에 대한 알림 선언
class CMyNode;

class CMyList {
    public:
        CMyList(CMyNode *pHead);
        ~CMyList(void);

    protected:
        void releaseList(void);
        CMyNode *m_pHead;

    public:
        CMyNode* findNode(const char* pszKey);
        int addNewNode(CMyNode *pNewNode);
        int removeNode(const char* pszNane);
        int loadList(const char* pszFileName);
        int saveList(const char* pszFileName);

        // 열거자를 생성한다.
        CMyIterator makeIterator(void);

        // 데이터가 추가될 때마다 호출되는 가상 함수
        virtual int onAddNewNode(CMyNode* pNewNode);
};