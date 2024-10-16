#include"NODE.h"
#include<string>
using Tree = NODE*;
struct TREE
{
private:
	Tree root;
	//Функция построения дерева
	Tree Build_Fformula(std::ifstream& file)
	{
		char c = file.get();
		Tree t = new NODE();
		if (c >= '0' && c <= '9')
			t->info = c;
		else
		{
			t->left = Build_Fformula(file);
			t->info = file.get();
			t->right = Build_Fformula(file);
			c = file.get();
		}
		return t;
	}
	//Функция печати дерева
	void Print(Tree root, int level)
	{
		if (root)
		{
			Print(root->right, level + 1);
			for (int i{ 0 }; i <= level; ++i)
				std::cout << ' ' << '\t';
			std::cout << root->info << '\n';
			Print(root->left, level + 1);
		}
	}
	//Функция копии фрагмента дерева
	Tree copy(const Tree& root)
	{
		Tree result = nullptr;
		if (root)
		{
			result = new NODE(root->info);
			result->left = copy(root->left);
			result->right = copy(root->right);
		}
		return result;
	}
	//Функция создания формулы на основе дерева
	std::string Print_to_string(const Tree& t)
	{
		std::string result{};
		if (!t->left && !t->right)
			result += t->info;
		else
		{
			result = '(' + Print_to_string(t->left) + t->info + Print_to_string(t->right) + ')';
		}

		return result;
	}
	//Функция проверки и перестановки
	void check_replace()
	{
		if (root->info == '*')
		{
			if (root->left->info == '+' || root->left->info == '-')//если первый вариант формулы
			{
				root->info = root->left->info;
				Tree f3 = root->right;
				root->right = new NODE('*',root->left->right,copy(f3));
				root->left->info = '*';
				/*root->right->left = root->left->right;
				root->left->right = copy(f3);*/
				root->right->right = f3;

			}
			if (root->right->info == '+' || root->right->info == '-')
			{
				root->info = root->right->info;
				Tree f3 = root->left;
				root->left = new NODE('*', root->right->left, copy(f3));
				root->right->info = '*';
				/*root->left->left = copy(f3);
				root->left->right = root->right->left;*/
				root->right->left = f3;
				
			}
		}
	}

public:

	TREE(Tree root = nullptr) :root(root) {};

	Tree get_root() 
	{
		return root;
	}

	Tree get_Build_Fformula(std::ifstream&file)
	{
		return Build_Fformula(file);
	}

	void get_Print()
	{
		Print(root, 0);
	}

	Tree get_copy()
	{
		return copy(root);
	}

	std::string get_Print_to_string()
	{
		return Print_to_string(root);
	}

	void get_check_replace() 
	{
		check_replace();
	}
};

