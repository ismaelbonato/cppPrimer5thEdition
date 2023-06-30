#include <iostream>

int main ()
{
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();

    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
}