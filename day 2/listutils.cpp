#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node* next;
};

void init(Node* node)
{
	node->val = 0;
	node->next = NULL;
}

void show(Node* root)
{
	Node* cur = root;
	while (cur->next != NULL)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

void pushNode(Node* root, Node* node)
{
	Node* cur = root;
	while (cur->next != NULL)
		cur = cur->next;

	cur->next = new Node;
	init(cur->next);
	cur->val = node->val;
}

void rShiftList(Node* root,int n)
{
	for (int i = 0; i < n; i++)
	{
		Node* cur = root;
		int num = cur->val;
		int x[2];

        x[0] = cur->next->val;
        cur->next->val = cur->val;
        cur->val = 0;

        int j =0;

		while (cur->next->next != NULL)
		{
            if(j%2 == 0 ){
                cur = cur->next;
                x[1] = cur->next->val;
                cur->next->val = x[0];
            }else{
                cur = cur->next;
                x[0] = cur->next->val;
                cur->next->val = x[1];
            }
            j++;
		}
	}
}

bool testrShiftList()
{
	Node* root = new Node;

	init(root);
	pushNode(root, new Node{ 1 });
	pushNode(root, new Node{ 2 });
	pushNode(root, new Node{ 3 });
	pushNode(root, new Node{ 4 });
	pushNode(root, new Node{ 5 });
	
	//show(root);//для тестов
	show(root);
	rShiftList(root, 3);
	//show(root);
	return (root->val == 0 && root->next->val == 0 && root->next->next->val == 0 && root->next->next->next->val == 1 && root->next->next->next->next->val == 2);


}

static void runTest(bool (*testFunction)(), const string& testName)
{
	if (testFunction() == 1)
		std::cout << "Test " << testName << " - OK" << std::endl;
	else
		std::cout << "Test " << testName << " - FAIL" << std::endl;
}

int main()
{
	runTest(testrShiftList, "lRoundShiftTest");

}
