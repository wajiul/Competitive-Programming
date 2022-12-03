
/*
Insert: log(n)
top: O(1)
pop: log(n)

Heapify: It is the process of crating a heap tree from an array. Time complexity O(n)
Heapify(int i): takes log(n) time.
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
const int N = 2e6;

template<typename T>
class Heap {
	private:
	vector<T> tree;
	int parent(int i) {
		return (i - 1)/2;
	}
	void Heapify(int i) {
		int largest = i;
		int l = 2*i + 1;
		int r = 2*i + 2;
		if(l < (int)tree.size() && tree[l] > tree[r])  {
			largest = l;
		}
		if(r < (int)tree.size() && tree[r] > tree[l]) {
			largest = r;
		}
		if(largest != i) {
			swap(tree[i], tree[largest]);
			Heapify(largest);
		}
	}

	public:

	void Insert(T v) {
		tree.push_back(v);
		int i = (int)tree.size() - 1;
		while(i != 0 && tree[parent(i)] < tree[i]) {
			swap(tree[i], tree[parent(i)]);
			i = parent(i);
		}
	}
	T top() {
		return tree[0];
	}
	void pop() {
		tree[0] = tree.back();
		tree.pop_back();
		Heapify(0);
	}
};
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Heap<int> h;
	h.Insert(3);
	h.Insert(9.97);
	h.Insert(4.90);
	h.Insert(1);
	h.Insert(10);
	h.Insert(0);
	cout << h.top() << endl;
	h.pop();
	cout << h.top() << endl;
}

