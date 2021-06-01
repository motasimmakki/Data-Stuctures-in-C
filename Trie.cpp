#include<iostream>
#include<stdlib.h>
using namespace std;

struct createTrieNode{
	char alpha;
	createTrieNode* letters[26];
	bool wordEnd;
}typedef createTrieNode;

createTrieNode* createTrie(){
	createTrieNode* trie = (createTrieNode*)malloc(sizeof(createTrieNode));
	trie->alpha = '\n';
	for(int i = 0; i < 26; i++)
		trie->letters[i] = NULL;
	trie->wordEnd = false;
	
	return trie;
}

bool insertStr(createTrieNode* trie, string str){
	createTrieNode* temp = trie;

	for(int i = 0; i < str.length(); i++){
		if(temp->letters[str[i] - 'a'] == NULL){
			temp->letters[str[i] - 'a'] = createTrie();
			temp->letters[str[i] - 'a']->alpha = str[i];

			if(i == str.length()-1)
				temp->letters[str[i] - 'a']->wordEnd = true;

		}
		temp = temp->letters[str[i] - 'a'];
	}

	return true;
}

bool searchStr(createTrieNode* trie, string str){
	createTrieNode* temp = trie;

	for(int i = 0; i < str.length(); i++){
		if(temp->letters[str[i] - 'a'] != NULL){
			temp = temp->letters[str[i] - 'a'];
			if(i == str.length()-1 && (temp->wordEnd))
				return true;
		}
	}
	return false;
}

bool deleteStr(createTrieNode* trie, string str){
	createTrieNode* temp = trie;

	for(int i = 0; i < str.length(); i++){
		if(temp->letters[str[i] - 'a'] != NULL){
			temp = temp->letters[str[i] - 'a'];
			if(i == str.length()-1 && (temp->wordEnd)){
				temp-> wordEnd = false;
				return true;
			}
		}
	}
	return false;
}

void runInsertQueries(createTrieNode* trie, string insertQueries[], int lenOfInsertQueries){
	cout<< "\nInsert Queries :"<< endl;
	for(int i = 0; i < lenOfInsertQueries; i++){
		if(insertStr(trie, insertQueries[i]))
			cout<< insertQueries[i]<< " : Inserted Successfully !"<< endl;
		else
			cout<< insertQueries[i]<< " : NOT Inserted !"<< endl;
	}
}

void runSearchQueries(createTrieNode* trie, string searchQueries[], int lenOfSearchQueries){
	cout<< "\nSearch Queries :"<< endl;
	for(int i = 0; i < lenOfSearchQueries; i++){
		if(searchStr(trie, searchQueries[i]))
			cout<< searchQueries[i]<< " : Found Successfully !"<< endl;
		else
			cout<< searchQueries[i]<< " : NOT Found !"<< endl;
	}
}

void runDeleteQueries(createTrieNode* trie, string deleteQueries[], int lenOfDeleteQueries){
	cout<< "\nDelete Queries :"<< endl;
	for(int i = 0; i < lenOfDeleteQueries; i++){
		if(deleteStr(trie, deleteQueries[i]))
			cout<< deleteQueries[i]<< " : Deleted Successfully !"<< endl;
		else
			cout<< deleteQueries[i]<< " : NOT Deleted (NOT Found) !"<< endl;
	}
}

int main(){
	createTrieNode* trie = createTrie();

	string insertQueries[] = {"abc", "abccc"};
	int lenOfInsertQueries = sizeof(insertQueries)/sizeof(insertQueries[0]);

	string searchQueries[] = {"abc", "abd", "abccc", "abcc"};
	int lenOfSearchQueries = sizeof(searchQueries)/sizeof(searchQueries[0]);

	string deleteQueries[] = {"abc", "ajk"};
	int lenOfDeleteQueries = sizeof(deleteQueries)/sizeof(deleteQueries[0]);

	runInsertQueries(trie, insertQueries, lenOfInsertQueries);
	runSearchQueries(trie, searchQueries, lenOfSearchQueries);
	runDeleteQueries(trie, deleteQueries, lenOfDeleteQueries);

	return 0;
}