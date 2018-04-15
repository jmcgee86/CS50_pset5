// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#include "dictionary.h"

int length = 0;

    int hash(char const *word)
    //int hash(char word[1])
    {
        char firstLetter = word[0];
        int hash_in = firstLetter - 'a';
        return hash_in;
    }

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    //word = tolower(*word);
    if (word)
    {
        return true;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

FILE *file = fopen(dictionary, "r");
//create hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
    node;
    //node *head;
    node *hashtable[26];

char word[LENGTH + 1];
//scan through each word in dictionary
while (fscanf(file, "%s", word) != EOF)
{
    length++;
    node *new_node = malloc(sizeof(node));
    //check if enough memory for new node
    if (new_node == NULL)
    {
        //unload();//write function below to clear.
        return false;
    }
    else
    {
        strcpy(new_node->word, word);
    }


    int hash_index = hash(word);
    // {
    //     hash = new_node->word[0] - 'a';
    //     return hash;
    // }
//hashtable[hash]
//    node *head = NULL;
    //hashtable[hash]
   // new_node->next = *head;
   new_node->next = hashtable[hash_index];
   hashtable[hash_index] = new_node;
   	printf("Inserting %s in hashtable %d \t", word, hash_index);
   	printf("%i\n", length);


    //*head = new_node;






        //IF: unload and return false
        //ELSE: strcpy(new_node->word, word);
    //hashfunction: hashing new_node->word gives index of hashtable
    //insert new_node into proper linked list of hashtable
        //new_node->next = head;
        //head = new_node;
}
    //printf()
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
    return false;
}
