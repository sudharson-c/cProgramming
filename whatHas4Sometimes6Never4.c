"""
	The program should accept a word and should return an integer that would be an apt solution for the given logic:
	What = 3
	someTimes = 6
	never = 4
	before = 5
	
	Input Format:
	A string should be entered
	Constraints:
	The input should be of the datatype 'string'. 
	The input should consist of only alphabets (A-Z)or(a-z).
	No special characters or digits are allowed

	Output Format
	The output should be of type integer

	Sample Input 0
	What
	Sample Output 0
	4
		
	Sample Input 1
	SOMETIMES
	Sample Output 1
	6
		
	Sample Input 2
	never
	Sample Output 2
	4
"""

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countUniqueCharacters(char *word) {
    int characters[26] = {0};
    for (int i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            char lowercaseChar = tolower(word[i]);
            characters[lowercaseChar - 'a'] = 1;
        }
    }

    int uniqueCount = 0;
    for (int i = 0; i < 26; i++) {
        if (characters[i] == 1) {
            uniqueCount++;
        }
    }

    return uniqueCount;
}

int main() {
    char word[100];
    scanf("%s", word);

    int result = countUniqueCharacters(word);
    printf("%d\n", result);

    return 0;
}
