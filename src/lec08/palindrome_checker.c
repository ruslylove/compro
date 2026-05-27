#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(const char str[]) {
    int left  = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    char test1[] = "racecar";
    char test2[] = "hello";
    printf("\"%s\" is a palindrome? %s\n", test1, is_palindrome(test1) ? "Yes" : "No");
    printf("\"%s\" is a palindrome? %s\n", test2, is_palindrome(test2) ? "Yes" : "No");
    return 0;
}
