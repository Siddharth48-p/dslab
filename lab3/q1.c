/*Write a program to perform following string operations without using string
handling functions:
a.) length of the string
b.) string concatenation
c.) string comparison
d.) to insert a sub string
e.) to delete a substring*/
#include <stdio.h>
#include <stdlib.h>

// a) Find length of string
int length(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

// b) Concatenate str2 to str1
void concatenate(char str1[], char str2[], int maxSize)
{
    int i = 0, j = 0;
    while (str1[i] != '\0') i++;

    // Ensure it doesn't exceed buffer size
    while (str2[j] != '\0' && i < maxSize - 1)
    {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';
}

// c) Compare two strings
int compare(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// d) Insert substring into str at position pos
void insertSubstring(char str[], char sub[], int pos, int maxSize)
{
    int lenStr = length(str);
    int lenSub = length(sub);
    int i;

    if (pos < 0 || pos > lenStr || lenStr + lenSub >= maxSize)
    {
        printf("Invalid position or resulting string too long.\n");
        return;
    }

    for (i = lenStr; i >= pos; i--)
    {
        str[i + lenSub] = str[i];
    }

    for (i = 0; i < lenSub; i++)
    {
        str[pos + i] = sub[i];
    }
}

// e) Delete substring from pos of length lenDel
void deleteSubstring(char str[], int pos, int lenDel)
{
    int lenStr = length(str);
    if (pos < 0 || pos + lenDel > lenStr)
    {
        printf("Invalid position or length to delete.\n");
        return;
    }

    int i = pos;
    while (str[i + lenDel] != '\0')
    {
        str[i] = str[i + lenDel];
        i++;
    }
    str[i] = '\0';
}

// Utility to remove newline from fgets input
void trimNewline(char str[])
{
    int len = length(str);
    if (len > 0 && str[len - 1] == '\0')
    {
        str[len - 1] = '\0';
    }
}

// Utility to clear input buffer
void clearInputBuffer()
{
    while (getchar() != '\n');
}

int main(){

    char str1[100], str2[50];
    int pos, lenDel;

    // a) Length
    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);
    trimNewline(str1);
    printf("Length = %d\n\n", length(str1));

    // b) Concatenate
    printf("Enter string to concatenate: ");
    fgets(str2, sizeof(str2), stdin);
    trimNewline(str2);

    concatenate(str1, str2, sizeof(str1));
    printf("After concatenation: %s\n\n", str1);

    // c) Compare
    printf("Enter first string to compare: ");
    fgets(str1, sizeof(str1), stdin);
    trimNewline(str1);

    printf("Enter second string to compare: ");
    fgets(str2, sizeof(str2), stdin);
    trimNewline(str2);

    int cmp = compare(str1, str2);
    if (cmp == 0)
        printf("Strings are equal\n\n");
    else if (cmp < 0)
        printf("First string is less\n\n");
    else
        printf("First string is greater\n\n");

    // d) Insert substring
    printf("Enter main string: ");
    fgets(str1, sizeof(str1), stdin);
    trimNewline(str1);

    printf("Enter substring to insert: ");
    fgets(str2, sizeof(str2), stdin);
    trimNewline(str2);

    printf("Enter position to insert: ");
    scanf("%d", &pos);
    clearInputBuffer();

    insertSubstring(str1, str2, pos, sizeof(str1));
    printf("After insertion: %s\n\n", str1);

    // e) Delete substring
    printf("Enter string for deletion: ");
    fgets(str1, sizeof(str1), stdin);
    trimNewline(str1);

    printf("Enter position to delete from: ");
    scanf("%d", &pos);
    printf("Enter length of substring to delete: ");
    scanf("%d", &lenDel);

    deleteSubstring(str1, pos, lenDel);
    printf("After deletion: %s\n", str1);

    return 0;
}

