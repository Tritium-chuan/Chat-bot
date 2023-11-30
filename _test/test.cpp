#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>

using namespace std;

char input[1000],output[10000];
string test;

void readChatMode(int &Code) {
    freopen("ChatMode.flag","r",stdin);
    cin >> Code;
    fclose(stdin);
    freopen("/dev/tty","r",stdin);
}

int ChatMode;

int main() {
    freopen("ChatMode.flag","r",stdin);
    cin >> ChatMode;
    cout << ChatMode <<'\n';
    fclose(stdin);
    freopen("/dev/tty","r",stdin);
    
    // while (true) {
    //     sleep(1);
    //     freopen("ChatMode.flag","r",stdin);
    //     cin >> ChatMode;
    //     cout << ChatMode <<'\n';
    //     fclose(stdin);
    //     freopen("/dev/tty","r",stdin);
    // }

    while(true) {
        sleep(1);
        readChatMode(ChatMode);
        cout << ChatMode <<'\n';
        if (ChatMode == 4) break;
    }
    return 0;
}