#include <iostream>
#include <cstring>
#include "UserData.h"
using namespace std;

int CUserData::nUserDataCounter = 0;

CUserData::CUserData(void) {
    memset(szName, 0, sizeof(szName));
    memset(szPhone, 0, sizeof(szPhone));

    nUserDataCounter++;
}

CUserData::CUserData(const char* pszName, const char* pszPhone) {
    memset(szName, 0, sizeof(szName));
    memset(szPhone, 0, sizeof(szPhone));

    strncpy(szName, pszName, sizeof(szName));
    strncpy(szPhone, pszPhone, sizeof(szPhone));
    
    nUserDataCounter++;
}

CUserData::~CUserData(void) {
    nUserDataCounter--;
}

const char* CUserData::getKey(void) {
    return szName;
}

void CUserData::printNode(void) {
#ifdef _DEBUG
    cout << "[" << this << "] " << szName << "\t" << szPhone << " [" << getNext() << "]" << endl;
#else
    cout << szName << "\t" << szPhone << endl;
#endif 
}