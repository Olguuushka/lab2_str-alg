#include <iostream>
#include<Windows.h>
#include <string>
#include<queue>
#include<fstream>
#include"TREE.h"

void task1(TREE root);
void task2(TREE root); 
void print(std::string message, TREE root);

int main()
{
	SetConsoleOutputCP(1251);
	std::ifstream file("data.txt");
	int choice{};
	TREE root;
	std::cout << "1.������ ����������\n2.������ ������������\n3.��������� ������\n";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		root = root.get_Build_Fformula(file);
		print("�������� ������", root);
		task1(root);
		print("���������� ������", root);
		break;
	}
	case 2:
	{
		root = root.get_Build_Fformula(file);
		print("�������� ������", root);
		task2(root);
		print("���������� ������", root);
		break;
	}
	default:
		break;
	}
	std::cin.get();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
void task1(TREE root)
{
	if (root.get_root())
	{
		root.get_check_replace();
		task1(root.get_root()->left);
		task1(root.get_root()->right);
	}
}
/////////////////////////////////////////////////////////////////////////////
void task2(TREE root)
{
	std::queue<Tree>q;
	TREE tmp;
	q.push(root.get_root());
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		tmp.get_check_replace();
		if (tmp.get_root()->left->info == '*')
			q.push(tmp.get_root()->left);
		if (tmp.get_root()->right->info == '*')
			q.push(tmp.get_root()->right);
	}
}
/////////////////////////////////////////////////////////////////////////////
void print(std::string message, TREE root)
{
	std::cout << '\t' << '<' << message << '>' << '\n';
	std::cout << root.get_Print_to_string() << '\n';
	root.get_Print();
	std::cout << "-----------------------------------------\n";

}

	
	
	




