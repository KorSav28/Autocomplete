#include <iostream>
#include <sstream>
#include "Header.h"

using namespace std;

int main () {
	TrieNode* root = getNewNode();

    string dictionary[MAX_WORDS] = { "cat", "call", "cult", "run", "rubbit", "dog", "dota", "dove", "duck", "zebra" };
    for (int i = 0; i < 10; i++) {
        insert(root, dictionary[i]);
    }

    string input;
    while (true) {
        cout << "Enter a prefix or 'ex' to stop: ";
        cin >> input;

        if (input == "ex") {
            break;
        }

        string results[MAX_WORDS];
        int count = autocomplete(root, input, results);
        if (count == 0) {
            cout << "Not found." << endl;
        }
        else {
            cout << "Variants:" << endl;
            for (int i = 0; i < count; i++) {
                cout << i + 1 << ". " << results[i] << endl;
            }
            cout << "Enter the number of variant: ";
            int choice;
            cin >> choice;

            if (choice > 0 && choice <= count) {
                cout << "Selected word: " << results[choice - 1] << endl;
            }
            else {
                cout << "Uncorrect choise. Please try again." << endl;
            }
        }
    }
    return 0; 
}