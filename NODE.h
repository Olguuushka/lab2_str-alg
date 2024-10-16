#pragma once
using TInfo = char;
struct NODE
{
	TInfo info;
	NODE* left, * right;
	NODE(TInfo info = 0, NODE* ptr_left = nullptr, NODE* ptr_right = nullptr) :info(info), left(ptr_left), right(ptr_right) {};
	~NODE()
	{
		left = right = nullptr;
	}
};