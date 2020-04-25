#include <ios>
#include "Tree.h"

int main()
{

	Tree<int> my_tree;

	my_tree.add_node(5, my_tree.get_root());
	
	system("pause");
	return 0;
}