#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char*);

int main() {
    char text[] = "   A   \n              b \tc B  a\n";//"Ni Talar Bra Latin" "   A   \n              b \tc B  a\n"
    
    if (isPalindrome(text)) {
        printf("The text is a palindrome.\n\n");
    }
    else {
        printf("The text is not a palindrome.\n\n");
    }
    return 0;
}

// Oanvända förslag
  // Kopiera texten reverse:ad, jämför tecken för tecken
  // Kopiera texten reverse:ad, jämför med strcmp
bool isPalindrome(char *text) {
    // Loopa igenom kolla om första == sista, osv
    int j = strlen(text) - 1;
    
    for (int i = 0; i < j; ++i) {
        while (isspace(text[i])) {
            i++;
        }
        while (isspace(text[j])) {
            j--;
        }
        if (tolower(text[i]) != tolower(text[j--])) {
            return false;
        }
    }

    return true;
}
