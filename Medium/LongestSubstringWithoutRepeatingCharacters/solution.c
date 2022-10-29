#include <stdio.h>

int contains(char* s, int start, int end, char c);

int lengthOfLongestSubstring(char * s){
    int size = sizeof(s) / sizeof(s[0]);
    int current_start = 0;
    int current_end = 0;
    int longest_substring_start = current_start;
    int longest_substring_end = current_end;
    int val;
    while (s[current_start] != '\0' && s[current_end] != '\0') {
        val = contains(s, current_start, current_end, s[current_end]);
        if (val >= 0) {
            current_start = val + 1;
        } else {
            current_end++;
            if (current_end - current_start > longest_substring_end - longest_substring_start) {
                longest_substring_start = current_start;
                longest_substring_end = current_end;
            }
        }
    }
    return longest_substring_end - longest_substring_start;
}


int contains(char* s, int start, int end, char c) {
    int i;
    for (i = start; i < end; i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}
