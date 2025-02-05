#include <iostream>
#include "Header.h"

using namespace std;

TrieNode* getNewNode(void)
{
	struct TrieNode* pNode = new TrieNode;
	pNode->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;
	return pNode;
}

void insert(TrieNode*root, string key) 
{
	TrieNode* node = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!node->children[index])
			node->children[index] = getNewNode();
		
		node = node->children[index];
	}
	node->isEndOfWord = true;
}
void search(struct TrieNode* root, char buf[], int id, string prefix, string results [], int& count) // поиск префикса
{
    if (root->isEndOfWord)
    {
        buf[id] = '\0';
        results [count] = prefix + string(buf);
        count++; 
    }
    
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children [i])
        {
            buf[id] = 'a' + i; 
            search(root->children[i], buf, id + 1, prefix, results, count); 
        }
    }
}

bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

TrieNode* remove(TrieNode* root, string key, int depth)
{ 
    if (!root)
        return nullptr;
    if (depth == key.size()) {
        if (root->isEndOfWord)
            root->isEndOfWord = false;
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }
    return root;
}

int autocomplete(TrieNode* root, string prefix, string results []) // автозаполнение
{
    TrieNode* node = root;
    char buf[ALPHABET_SIZE];
    int count = 0; 

   for (int i = 0; i < prefix.length(); i++) {
        int index = prefix[i] - 'a';
        if (!node->children[index])
            return count; // Префикс не найден
        node = node->children[index];
    }
   search(node, buf, 0, prefix, results, count); 
   return count;  
}