#ifndef TRIE_H
#define TRIE_H

#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;
const int MAX_WORDS = 100;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string);
void search(struct TrieNode* root, char buf[], int id, string prefix, string results[], int& count);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, string, int depth = 0);
int autocomplete(TrieNode* root, string prefix, string results[]); 
#endif
