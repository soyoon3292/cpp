#include "MyList.h"
#include "UserData.h"
#include <cstring>
#include <iostream>
using namespace std;

#ifdef _WIN32
    #define DATA_FILE_NAME "Address_Win.dat"
#else
    #define DATA_FILE_NAME "Address_Mac.dat"
#endif

CMyList::CMyList(CMyNode *pHead) {
    m_pHead = pHead;
    loadList(DATA_FILE_NAME);
}

CMyList::~CMyList() {
    saveList(DATA_FILE_NAME);
    releaseList();
}

int CMyList::addNewNode(CMyNode *pNewNode) {
    // 같은 이름이 이미 존재하는지 확인한다.
    if(findNode(pNewNode->getKey()) != NULL) {
        delete pNewNode;

        return 0;
    }

    if(onAddNewNode(pNewNode)) {
        pNewNode->pNext = m_pHead->pNext;
        m_pHead->pNext = pNewNode;
        
        return 1;
    }

    return -1;
}

CMyNode* CMyList::findNode(const char* pszKey) {
    CMyNode *pTmp = m_pHead->pNext;

    while(pTmp != NULL) {
        if(strcmp(pTmp->getKey(), pszKey) == 0)
            return pTmp;

        // 다음 노드로 이동
        pTmp = pTmp->pNext;
    }

    // 일치하는 데이터를 찾지 못한 경우
    return NULL;
}

int CMyList::removeNode(const char* pszKey) {
    CMyNode *pPrevNode = m_pHead;
    CMyNode *pDelete = NULL;

    while(pPrevNode->pNext != NULL) {
        pDelete = pPrevNode->pNext;

        if(strcmp(pDelete->getKey(), pszKey) == 0) {
            pPrevNode->pNext = pDelete->pNext;
            delete pDelete;

            return 1;
        }
        
        pPrevNode = pPrevNode->pNext;
    }

    return 0;
}

void CMyList::releaseList(void) {
    CMyNode *pTmp = m_pHead->pNext;
    CMyNode *pDelete = NULL;

    while(pTmp != NULL) {
        pDelete = pTmp;
        pTmp = pTmp->pNext;

        delete pDelete;
    }

    m_pHead->pNext = NULL;
}

int CMyList::loadList(const char* pszFileName) {
    FILE *fp = NULL;
    CUserData user;

    fp = fopen(pszFileName, "rb");

    if(fp == NULL)
        return 0;

    releaseList();

    while(fread(&user, sizeof(CUserData), 1, fp))
        addNewNode(new CUserData(user.getName(), user.getPhone()));

    fclose(fp);

    return 0;
}

int CMyList::saveList(const char* pszFileName) {
    FILE *fp = NULL;
    CMyNode *pTmp = m_pHead->pNext;

    fp = fopen(pszFileName, "wb");

    if(fp == NULL) {
        cout << "ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다." << endl;
        cin.get();
        cin.get();
        
        return 0;
    }

    while(pTmp != NULL) {
        if(fwrite(pTmp, sizeof(CUserData), 1, fp) != 1)
            cout << "ERROR: " << pTmp->getKey() << "에 대한 정보를 저장하는 데 실패했습니다." << endl;

        pTmp = pTmp->pNext;
    }

    fclose(fp);

    return 1;
}

CMyIterator CMyList::makeIterator(void) {
    CMyIterator it;
    it.m_pCurrent = m_pHead->pNext;
    it.m_pHead = m_pHead->pNext;

    return it;
}

int CMyList::onAddNewNode(CMyNode* pNewNode) {
    return 1;
}