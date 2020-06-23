/*
 * Puzzle Link: https://www.hackerrank.com/challenges/swap-nodes-algo/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search&h_r=next-challenge&h_v=zen
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <unordered_map>
#include <math.h>
#define INF 0x7FFFFFFF
#define INFL 0x7FFFFFFFFFFFFFFF
typedef std::pair<int, int> ipair;
using namespace std;

struct node {
	node * left = nullptr;
	node * right = nullptr;
	int id;
	node (int i) :id(i){};
};
unordered_map<int , node *>tree;
void insert(int i, int left , int right){
	if (tree.find(i) == tree.end())
		tree[i] = new node(i);
	if (left > 0){
		if (tree.find(left) == tree.end()) tree[left] = new node(left);
		tree[i]->left = tree[left];
	}
	if (right > 0){
		if (tree.find(right) == tree.end()) tree[right] = new node(right);
		tree[i]->right = tree[right];
	}
}
void inorderTraverse(node * n){
	if (n == nullptr) return;
	inorderTraverse(n->left);
	cout << n->id << " ";
	inorderTraverse(n->right);
}
void swap(node * n){
	auto temp = n->left;
	n->left = n->right;
	n->right = temp;
}
void swap(node * n, int depth, int h){
	if (n == nullptr) return;
	if ((depth % h) == 0) swap(n);
	swap(n->left, depth+1, h);
	swap(n->right, depth+1, h);
}
int main() {
	int n; cin >> n;
	node root(1);
	tree[1] = &root;
	int i = 1;
	while (n --){
		int a, b; cin >> a >> b;
		insert(i, a, b);
		i++;
	}
	int queries; cin >> queries;
	while (queries--){
		int query; cin >> query;
		swap(&root, 1, query);
		inorderTraverse(&root);
		cout << endl;
	}
	
}
