#include <iostream>
#include <cstring>
#include "UserData.h"
using namespace std;

int CUserData::nUserDataCounter = 0;

CUserData::CUserData(void) {
    strName.setString(NULL);
    strPhone.setString(NULL);

    nUserDataCounter++;
}

CUserData::CUserData(const char* pszName, const char* pszPhone) {
    strName.setString(NULL);
    strPhone.setString(NULL);

    strName.setString(pszName);
    strPhone.setString(pszPhone);
    
    nUserDataCounter++;
}

CUserData::~CUserData(void) {
    nUserDataCounter--;
}

const char* CUserData::getKey(void) {
    return strName.getString();
}

void CUserData::printNode(void) {
#ifdef _DEBUG
    cout << "[" << this << "] " << strName << "\t" << strPhone << " [" << getNext() << "]" << endl;
#else
    cout << szName << "\t" << szPhone << endl;
#endif 
}