#include <iostream>
using namespace std;

// int main(int argc, char *argv[]) {
//     string name;
//     cout << "이름 : ";
//     cin >> name;

//     auto age(0);
//     cout << "나이 : ";
//     cin >> age;

//     cout << "나의 이름은 " << name << "이고, " << age << "살입니다." << endl;

//     return 0;
// }


// int main(int argc, char *argv[]) {
//     char *arr = new char[12];

//     delete[] arr;

//     return 0;
// }


// void swap(int &a, int &b);
// int main(int argc, char *argv[]) {
//     int a = 10, b = 20;

//     cout << a << ' ' << b << endl;

//     swap(a, b);

//     cout << a << ' ' << b << endl;

//     return 0;
// }

// void swap(int &a, int &b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }


int main(int argc, char *argv[]) {
    int aList[5] = {30, 20, 10, 50, 40};
    int temp;

    for(int i = 0; i < 5; i++) {
        for(int j = 1; j < 5; j++) {
            // if(aList[j-1] < aList[j])
            //     swap(aList[j-1], aList[j]);
            if(aList[j-1] > aList[j])
                swap(aList[j-1], aList[j]);
        }
    }
    for(auto n : aList)
        cout << n << ' ';
    cout << endl;

    return 0;
}
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}