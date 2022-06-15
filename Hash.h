#pragma once
#include <iostream>

using namespace std;

const int MINSIZE = 8;

//哈希表节点
typedef struct _ListNode {
	int key;//键值
	void *data;//数据(void *可表示多种类型指针)
	_ListNode *next;
}ListNode;

typedef ListNode* List;
//哈希表结构
typedef struct _Hash {
	int tableSize;
	List *ListFront;//指针指向表头节点数组的首地址int *lists;lists = new int[10];
}HashTable;

//哈希函数
int Hash(int key, int tableSize);
//初始化哈希表
HashTable* initHash(int tableSize);

//哈希表根据键值查找元素
ListNode * findElement(HashTable *hash, int key);

//哈希表插入元素 即键值对
void insertElement(HashTable *hash, int key, void* data);

//哈希表根据键值删除元素
void deleteElement(HashTable *hash, int key);

//哈希表销毁
void DestoryHash(HashTable *hash);

//哈希表元素打印
void printHash(HashTable *hash);
