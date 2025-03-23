// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char* str) {
    unsigned int validWordsCount = 0;
    bool isInsideWord = false;
    bool containsDigits = false;

    for (; *str; ++str) {
        if (*str == ' ') {
            if (isInsideWord) {
                validWordsCount += !containsDigits;
                isInsideWord = false;
            }
        } else {
            if (!isInsideWord) {
                isInsideWord = true;
                containsDigits = false;
            }
            containsDigits |= (*str >= '0' && *str <= '9');
        }
    }

    if (isInsideWord) {
        validWordsCount += !containsDigits;
    }

    return validWordsCount;
}

unsigned int faStr2(const char* str) {
    unsigned int properCaseCount = 0;
    bool isInsideWord = false;
    bool isValidWord = false;
    bool isFirstLetter = true;

    while (*str) {
        const char c = *str;
        if (c != ' ') {
            if (!isInsideWord) {
                isInsideWord = true;
                isValidWord = (c >= 'A' && c <= 'Z');
                isFirstLetter = false;
            } else {
                if (isFirstLetter) {
                    isFirstLetter = false;
                } else {
                    isValidWord &= (c >= 'a' && c <= 'z');
                }
            }
        } else {
            if (isInsideWord) {
                properCaseCount += isValidWord;
                isInsideWord = false;
                isFirstLetter = true;
            }
        }
        ++str;
    }

    if (isInsideWord) {
        properCaseCount += isValidWord;
    }

    return properCaseCount;
}

unsigned int faStr3(const char* str) {
    unsigned int totalWords = 0;
    unsigned int totalLength = 0;
    unsigned int currentLength = 0;
    bool isInsideWord = false;

    for (; *str; ++str) {
        if (*str == ' ') {
            if (isInsideWord) {
                ++totalWords;
                totalLength += currentLength;
                isInsideWord = false;
            }
        } else {
            if (!isInsideWord) {
                isInsideWord = true;
                currentLength = 0;
            }
            ++currentLength;
        }
    }

    if (isInsideWord) {
        ++totalWords;
        totalLength += currentLength;
    }

    return totalWords ? (totalLength + totalWords / 2) / totalWords : 0;
}
