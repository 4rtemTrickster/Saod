#include "tree.h"
#include <vector>

int main()
{
	Tree<int> intTree;

	std::vector<int> arr = { 1, 2, 3, 4, 5, 6};


	for (auto element : arr)
		intTree.insert_node(element);

	TreeNode<int> *tmp = intTree.find_node(intTree.get_root(), 3);


	if(tmp == nullptr)
		std::cout << "Not found!" << std::endl;
	else
	{
		int serch = tmp->get_data();
		
		for (size_t i = 0; i < arr.size(); i++)
			if (arr[i] == serch)
				std::cout << i << std::endl;

	}



	system("pause");
	return 0;
}
