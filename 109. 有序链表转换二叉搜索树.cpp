#pragma warning(disable:4996)
#include<set>
#include<map>
#include<regex>
#include<sstream>
#include<iostream>
#include<stdio.h>
#include<list>
#include<cstdlib>
#include<stack>
#include<algorithm>
#include<math.h>
#include<thread>

using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
//19/10/13 Áè³¿
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		ListNode* _head = head;
		int n = 0;
		while (head)
		{
			head = head->next;
			++n;
		}
		return func(0, n - 1);
	}
	TreeNode* func(int le, int ri,ListNode*& head)
	{
		if (le > ri)
		{
			return nullptr;
		}
		int mi = le + (ri - le) / 2;
		TreeNode* left = func(le, mi - 1,head);
		TreeNode* root = new TreeNode(head->val);
		head = head->next;
		root->right = func(mi + 1, ri, head);
		return root;
	}
};
int main() {
}