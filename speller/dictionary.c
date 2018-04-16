// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
    node;
    node *hashtable[26]; // initialize "head" of each linked list, 26 lists, one for each letter

int length = 0;

    int hash(char const *word)//hash words by first letter, gives us 26 hash tables, one for each letter using 0-25 as index
    {
        char firstLetter = word[0];
        int hash_in = tolower(firstLetter) - 'a'; //sets hash table index to ascii value of first letter (to lower case) - ascii for 'a' - returns 0-25
        return hash_in;
    }

// Returns true if word is in dictionary else false
bool check(const char *word)
{
int hash_index = hash(word); //find index for word in text
node *cursor = hashtable[hash_index]; //start cursor at head of appropriate linked list from hash table

while (cursor != NULL) //checks each word in list in hashtable to see if it matches input word from .txt file
{
    char *check_word = cursor->word;

    if(strcasecmp(word, check_word)==0) //returns true if found
    {
        return true;
    }
    else // moves to next node in linked list
    {
        cursor = cursor->next;
    }

}
    return false; //returns false if gets to last node in linked list without finding match
}

//FILE *file;
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

FILE *file = fopen(dictionary, "r");

if (file == NULL)
{
    unload();
    return false;
}

char word[LENGTH + 1];
//scan through each word in dictionary
while (fscanf(file, "%s", word) != EOF)
{
    length++;
    node *new_node = malloc(sizeof(node));
    //check if enough memory for new node
    if (new_node == NULL)
    {
        unload();
        return false;
    }
    else
    {
        strcpy(new_node->word, word);
    }

    int hash_index = hash(word);

        new_node->next = hashtable[hash_index];
        hashtable[hash_index] = new_node;

   	//printf("Inserting %s in hashtable %d \t", word, hash_index);
   	//printf("%i\n", length);
//pseudo code for loading dictionary
        //IF: unload and return false
        //ELSE: strcpy(new_node->word, word);
    //hashfunction: hashing new_node->word gives index of hashtable
    //insert new_node into proper linked list of hashtable
        //new_node->next = head;
        //head = new_node;
}
    //free(file);
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(length > 0)
    {
        return length;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    //free(file);

    for (int i = 0; i<26; i++)
    {
        node *head = hashtable[i];
        while (head != NULL)
        {
            node *next = head->next;
            free(head);
            head = next;
        }
        //return true;
    }
    return true;
}