#include "TreeClass/tree.h"
#include <vector>

int main()
{
	Tree<int> intTree;

	std::vector<int> arr = { 1, 2, 3, 9, 6, 15};


	for (auto element : arr)
		intTree.insert_node(element);

	intTree.inorder_walk(intTree.get_root());

	intTree >> std::cin;

	std::cout << std::endl;

	intTree << std::cout;


	system("pause");
	return 0;
}
