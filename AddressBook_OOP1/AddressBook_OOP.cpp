#include "UserInterface.h"
#include "MyList.h"

int main(int argc, char* argv[]) {
    CMyList DB;

    CUserInterface UI(DB);
    UI._run();

    return 0;
}