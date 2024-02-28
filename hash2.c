// Distribution code for hash exercise
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define HASHTABLE_SIZE 1125

// Node structure for linked list
typedef struct node
{
    char word[45];
    struct node *next;
}
node;

// Hash function prototype
unsigned int hash(const char *word);

// Lookup function
bool lookup(const char* word, node* hashtable[])
{
    // TODO: Call hash function and store index in a variable

    // TODO: Use a for loop to traverse the linked list
    // TODO: Return true if found, false if not found
}


// Hash function (simple example)
unsigned int hash(const char *word)
{
    // Hash on sum of all letters
    int tally = 0;
    int j = 0;
    while (word[j] != '\0')
    {
        char letter = tolower(word[j]);
        tally += letter - 'a';
        j++;
    }
    return tally;
}

// Function to free memory
void free_hashtable(node *hashtable[])
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node *cursor = hashtable[i];
        while (cursor)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
}

int main(void)
{
    // Initialize hash table
    node *hashtable[HASHTABLE_SIZE] = {NULL};

    // Load words into the hash table (for example purposes)
    char *words[] = {"apple", "banana", "orange", "grape", NULL};
    for (int i = 0; words[i] != NULL; i++)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return 1;
        }
        strcpy(new_node->word, words[i]);
        unsigned int index = hash(words[i]);
        new_node->next = hashtable[index];
        hashtable[index] = new_node;
    }

    // Test 1: Search for the word "apple" (found)
    if (lookup("apple", hashtable))
    {
        printf("Word 'apple' found!\n");
    }
    else
    {
        printf("Word 'apple' not found.\n");
    }

    // Test 2: Search for the word "strawberry" (not found)
    if (lookup("strawberry", hashtable))
    {
        printf("Word 'strawberry' found!\n");
    }
    else
    {
        printf("Word 'strawberry' not found.\n");
    }

    // Free memory
    free_hashtable(hashtable);

}
