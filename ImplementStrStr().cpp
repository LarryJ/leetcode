class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!*needle) // empty c_string
            return haystack;
        
        char* p = haystack;
        while(*p) {
            if(*p == *needle) {
                char* check1 = p;
                char* check2 = needle;
                while(*check1 && *check2 && *check1 == *check2) {
                    check1++;
                    check2++;
                }
                if(!*check2)
                    return p;
            }
            p++;
        }
        return NULL;
    }
};