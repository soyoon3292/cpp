#include "MyList.h"
#include <cstring>
#include <iostream>
using namespace std;

#define DATA_FILE_NAME "Address.dat"

CMyList::CMyList(void) {
    loadList(DATA_FILE_NAME);
}

CMyList::~CMyList() {
    saveList(DATA_FILE_NAME);
    releaseList();
}

int CMyList::addNewNode(const char* pszName, const char* pszPhone) {
    CUserData *pNewUser = NULL;

    // 같은 이름이 이미 존재하는지 확인한다.
    if(findNode(pszName) != NULL)
        return 0;

    pNewUser = new CUserData;
    strncpy(pNewUser->szName, pszName, sizeof(pNewUser->szName));
    strncpy(pNewUser->szPhone, pszPhone, sizeof(pNewUser->szPhone));
    pNewUser->pNext = NULL;

    pNewUser->pNext = m_Head.pNext;
    m_Head.pNext = pNewUser;
    
    return 1;
}

void CMyList::printAll(void) {
    CUserData *pTmp = m_Head.pNext;
    while(pTmp != NULL) {
        cout << "[" << pTmp << "] " << pTmp->szName << "\t" << pTmp->szPhone << " [" << pTmp->pNext << "]" << endl;
    
        pTmp = pTmp->pNext;
    }
    cin.get();
    cin.get();
}

CUserData* CMyList::findNode(const char* pszName) {
    CUserData *pTmp = m_Head.pNext;
    while(pTmp != NULL) {
        if(strcmp(pTmp->szName, pszName) == 0)
            return pTmp;

        // 다음 노드로 이동
        pTmp = pTmp->pNext;
    }

    // 일치하는 데이터를 찾지 못한 경우
    return NULL;
}

int CMyList::removeNode(const char* pszName) {
    CUserData *pPrevNode = &m_Head;
    CUserData *pDelete = NULL;

    while(pPrevNode->pNext != NULL) {
        pDelete = pPrevNode->pNext;

        if(strcmp(pDelete->szName, pszName) == 0) {
            pPrevNode->pNext = pDelete->pNext;
            delete pDelete;

            return 1;
        }
        
        pPrevNode = pPrevNode->pNext;
    }

    return 0;
}

void CMyList::releaseList(void) {
    CUserData *pTmp = m_Head.pNext;
    CUserData *pDelete = NULL;

    while(pTmp != NULL) {
        pDelete = pTmp;
        pTmp = pTmp->pNext;

        delete pDelete;
    }

    m_Head.pNext = NULL;
}

int CMyList::loadList(const char* pszFileName) {
    FILE *fp = NULL;
    CUserData user;

    fp = fopen(pszFileName, "rb");

    if(fp == NULL)
        return 0;

    releaseList();

    while(fread(&user, sizeof(CUserData), 1, fp))
        addNewNode(user.szName, user.szPhone);

    fclose(fp);

    return 0;
}

int CMyList::saveList(const char* pszFileName) {
    FILE *fp = NULL;
    CUserData *pTmp = m_Head.pNext;

    fp = fopen(pszFileName, "wb");

    if(fp == NULL) {
        cout << "ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다." << endl;
        cin.get();
        cin.get();
        
        return 0;
    }

    while(pTmp != NULL) {
        if(fwrite(pTmp, sizeof(CUserData), 1, fp) != 1)
            cout << "ERROR: " << pTmp->szName << "에 대한 정보를 저장하는 데 실패했습니다." << endl;

        pTmp = pTmp->pNext;
    }

    fclose(fp);

    return 1;
}