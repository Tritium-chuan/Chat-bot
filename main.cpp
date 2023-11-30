#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

void removeSubstring(string &mainStr, const string &toRemove) {
    int pos = mainStr.find(toRemove);

    while (pos != std::string::npos) {
        mainStr.erase(pos, toRemove.length());
        pos = mainStr.find(toRemove, pos);
    }
}

void setChatMode(int Code) {
    freopen("ChatMode.flag","w",stdout);
    cout << Code ;
    fclose(stdout);
    freopen("/dev/tty","w",stdout);
}

void readChatMode(int &Code) {
    freopen("ChatMode.flag","r",stdin);
    cin >> Code;
    fclose(stdin);
    freopen("/dev/tty","r",stdin);
}

time_t getModifiedTime(const char *filePath) {
    struct stat fileInfo;
    stat(filePath, &fileInfo);
    return fileInfo.st_mtime;
}

void textBuffer() {
    time_t lastModifiedTime = getModifiedTime("ChatMode.flag");
    while(true) {
        sleep(1);
        time_t currentModifiedTime = getModifiedTime("ChatMode.flag");
        if (currentModifiedTime != lastModifiedTime) break;
    }
}

string command1 = "./recorder.sh";
string command2 = "./speech-to-text.sh";
string command3 = "./text-to-speech.sh \"";
char tmpText[1000];
string command3tmp;
string inputText;
string outputText;
int ChatMode;

int main() {
// init
    ChatMode = 0;
    setChatMode(ChatMode);

    while(true) {
    // begin of the loop
        ChatMode = 1;
        cout << "Select input mode. Type 1: Audio; Type 2 + \"Text\".\n";
        int inType;
        cin >> inType;
        if(inType == 1) {
            setChatMode(ChatMode);

        // record audio
            system(command1.c_str());
            while(true) {
                sleep(1);
                readChatMode(ChatMode);
                if(ChatMode == 2) break;
            }

        // Speech to text
            system(command2.c_str());

        // Read input text
            freopen("input.txt","r",stdin);
            fgets(tmpText, 1000, stdin);
            inputText = string(tmpText);

        // Erase json symbols
            if (inputText.length() >= 13) {
                inputText.erase(0, 9);
                inputText.erase(inputText.length() - 4);
            }
            removeSubstring(inputText, "\\n");
            fclose(stdin);
            freopen("/dev/tty","r",stdin);
        }
        else {
            scanf("%[^\n]", tmpText);
            inputText = string(tmpText);
        }

        freopen("input.txt","w",stdout);
        cout << inputText;
        fclose(stdout);
        freopen("/dev/tty","w",stdout);

    // Wait for llama callback
        setChatMode(3);
        textBuffer();

    // Text to audio
        freopen("Output.txt","r",stdin);
        fgets(tmpText, 1000, stdin);
        fclose(stdin);
        freopen("/dev/tty","r",stdin);

        outputText = string(tmpText);
        command3tmp = command3 + outputText + "\"";

        system(command3tmp.c_str());
        cout << '\n';
    }

    return 0;
}