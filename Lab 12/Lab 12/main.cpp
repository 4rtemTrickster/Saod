#include <iostream>
#include "AVLtree.h"

int main()
{
	bstree my_tree;
	nodeptr root = nullptr;

	setlocale(LC_ALL, "Ru");

	my_tree.insert(60,root);
	my_tree.insert(1, root);
	my_tree.insert(50, root);
	my_tree.insert(75, root);
	my_tree.insert(250, root);
	my_tree.insert(350, root);
	my_tree.insert(450, root);
	my_tree.insert(550, root);
	my_tree.insert(650, root);
	my_tree.insert(3, root);
	my_tree.insert(48, root);
	my_tree.insert(24, root);

	std::cout << root->element << std::endl;

	int tmp =  root->element *= root->element;

	my_tree.del(tmp, root);

	my_tree.inorder(root);

	system("pause");
	return 0;
}