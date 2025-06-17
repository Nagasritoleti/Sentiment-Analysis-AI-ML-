#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

// Sample positive and negative keywords
const char *positiveWords[] = {"good", "happy", "great", "excellent", "love", "fantastic", "awesome", "amazing"};
const char *negativeWords[] = {"bad", "sad", "terrible", "hate", "worst", "awful", "poor", "disappointing"};

int countKeywords(const char *text, const char *keywords[], int keywordCount) {
    int count = 0;
    char temp[MAX_LEN];
    strcpy(temp, text);

    // Convert to lowercase for case-insensitive matching
    for (int i = 0; temp[i]; i++) {
        temp[i] = tolower(temp[i]);
    }

    // Check for each keyword
    for (int i = 0; i < keywordCount; i++) {
        if (strstr(temp, keywords[i]) != NULL) {
            count++;
        }
    }
    return count;
}

int main() {
    char input[MAX_LEN];

    printf("Enter a sentence for sentiment analysis:\n");
    fgets(input, MAX_LEN, stdin);

    int posCount = countKeywords(input, positiveWords, sizeof(positiveWords) / sizeof(positiveWords[0]));
    int negCount = countKeywords(input, negativeWords, sizeof(negativeWords) / sizeof(negativeWords[0]));

    printf("\nPositive matches: %d", posCount);
    printf("\nNegative matches: %d", negCount);

    if (posCount > negCount) {
        printf("\nSentiment: Positive\n");
    } else if (negCount > posCount) {
        printf("\nSentiment: Negative\n");
    } else {
        printf("\nSentiment: Neutral or Mixed\n");
    }

    return 0;
}
