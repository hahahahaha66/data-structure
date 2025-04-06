#include <stdbool.h>
#include <string.h>
bool isAnagram(char* s, char* t) {
    int hash[128] = {0};
    int len_s = strlen(s), len_t = strlen(t);
    if (len_s != len_t) {
        return false;
    }
    for (int i = 0; i < len_s; i++) {
        hash[(unsigned char)s[i]]++;
        hash[(unsigned char)t[i]]--;
    }
    for (int i = 0; i < 128; i++) {
        if (hash[i] != 0) {
            return false;
        }
    }
    return true;
}
