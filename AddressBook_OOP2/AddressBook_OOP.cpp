#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"

int main(int argc, char* argv[]) {
    CMyList DB(new CUserData);

    CUserInterface UI(DB);
    UI._run();

    return 0;
}