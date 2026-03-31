
class TrieNode {
public:
	char data;
	TrieNode**children;
	bool isend;

	TrieNode(char data) {
		this->data = data;
		children = new TrieNode*[26];
		isend = false;
		for(int i=0; i<26; i++) {
			children[i] = NULL;
		}
	}
};
class Solution {
public:
	void insertword(vector <string> &words, TrieNode* root) {

		for(auto i: words) {
			TrieNode* temp = root;
			for(int j = 0; j<i.length(); j++) {
				char ch = i.at(j);
				if(temp->children[i[j]-'a'] == NULL) {
					temp->children[i[j]-'a'] = new TrieNode(ch);
				}
				temp = temp->children[i[j]-'a'];
			}
			temp->isend = true;
		}
	}

	bool searchWord(string word, TrieNode* root) {
		//Write your code here;
		TrieNode* temp = root;
		for(auto i : word) {
			if(temp->children[i-'a'] == NULL)
				return false;
			temp = temp->children[i-'a'];
		}
		if(temp->isend == false)
			return false;
		return true;


	}
	void findWordsWithPrefix(TrieNode* node, string& prefix, vector<string>& suggestions) {
		if (node->isend) {
			suggestions.push_back(prefix); // Add the current prefix as a suggestion
		}

		// Recursively explore children nodes
		for (char ch = 'a'; ch <= 'z'; ++ch) {
			if (node->children[ch - 'a']) {
				prefix.push_back(ch); // Extend the prefix
				findWordsWithPrefix(node->children[ch - 'a'], prefix, suggestions);
				prefix.pop_back(); // Backtrack to previous prefix
			}
		}
	}

};
