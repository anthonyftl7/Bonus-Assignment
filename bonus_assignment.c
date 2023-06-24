#include <stdio.h>
#include <string.h>

void RecursivePermute(char str[], int k, int n) {
    if (k == n) {
        printf("%s\n", str);
    } else {
        for (int i = k; i <= n; i++) {
            if (i != k && str[i] == str[k]) {
                continue; // Skips duplicate characters
            }
            
            ExchangeCharacters(str, k, i);
            RecursivePermute(str, k + 1, n);
        }
        
        // Restore the original order of characters
        char temp = str[k];
        for (int i = k; i < n; i++) {
            str[i] = str[i + 1];
        }
        str[n] = temp;
    }
}