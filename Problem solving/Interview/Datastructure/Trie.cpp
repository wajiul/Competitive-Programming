/*
Insert: O(n)
Search: O(n)
Delete: O(n * m)

***Initial root is not NULL for trie. 
***initially root = new Node()

*/
#ifndef ONLINE_JUDGE
#include "header.h"
#else
#include<bits/stdc++.h>
#endif

#ifdef LOCAL
#include "debug.h"
#else
#define dg(...) 42
#define dg_1(...) 42
#endif
using namespace std;
#define all(x) x.begin() , x.end()
#define clr(x , y) memset(x , y , sizeof x);
#define sz(x) (int)x.size()
using lint = long long int;
const int Mod = 1e9 + 7;
const lint inf = 1e18 + 10;

class Trie {
	private:
	const static int N = 26;
	struct Node {
		Node* link[N];
		bool EndOfWord = false;
	}*root;


	bool IsEmpty(Node *cur_node) {
		for(int i = 0;i < N;i++) {
			if(cur_node->link[i]) return false;
		}
		return true;
	}

	Node* Remove(Node *cur_Root, string s, int depth = 0) {
		if(!cur_Root) return NULL;
		if(depth == (int)s.size()) {
			if(root->EndOfWord) {
				root->EndOfWord = false;
			}
			if(IsEmpty(cur_Root)) {
				delete (cur_Root);
				cur_Root = NULL;
			}
			return cur_Root;
		}
		int index = s[depth]- 'a';
		cur_Root->link[index] = Remove(cur_Root->link[index], s, depth + 1);

		if(IsEmpty(cur_Root) && root->EndOfWord == false) {
			delete (cur_Root);
			cur_Root = NULL;
		}
		return cur_Root;
	}

	public:
	Trie() {
		root = new Node();
	}

	void Insert(string s) {
		Node *curPtr = root;
		for(char i : s) {
			if(curPtr->link[i - 'a'] == NULL) {
				curPtr->link[i - 'a'] = new Node();
			}
			curPtr = curPtr->link[i - 'a'];
		}
		curPtr->EndOfWord = true;
	}

	bool Search(string s) {
		Node *curPtr = root;
		for(char i : s) {
			if(curPtr->link[i - 'a'] == NULL) return false;
			curPtr = curPtr->link[i - 'a'];
		}
		return curPtr->EndOfWord;
	}
	bool PrefixSearch(string s) {
		Node *curPrt = root;
		for(char i : s) {
			if(curPrt->link[i - 'a'] == NULL) return false;
			curPrt = curPrt->link[i - 'a'];
		}
		return true;
	}
	void Delete(string s) {
		root = Remove(root, s, 0);
	}
};
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Trie t;
	t.Insert("abc");
	t.Insert("acd");
	t.Delete("acd");
	cout << t.Search("abc") << endl;
	cout << t.Search("acd") << endl;
	cout << t.PrefixSearch("bc") << endl;
}
