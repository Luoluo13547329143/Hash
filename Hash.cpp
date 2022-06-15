#include "Hash.h"

int Hash(int key, int tableSize)
{
	return (key % tableSize);
}

HashTable * initHash(int tableSize)
{
	HashTable *hash = NULL;

	if (tableSize <= 0) {
		tableSize = MINSIZE;
	}

	//分配空间
	hash = new HashTable;
	//判断是否分配成功
	if (!hash) {
		cout << "哈希表内存分配失败" << endl;
		return NULL;
	}

	hash->tableSize = tableSize;
	//表头分配内存
	hash->ListFront = new List[tableSize];
	
	if (!hash->ListFront) {
		cout << "哈希表表头内存分配失败" << endl;
		delete hash;
		return NULL;
	}

	for (int i = 0; i < tableSize; i++) {
		hash->ListFront[i] = new ListNode;
		if (!hash->ListFront[i]) {
			cout << "哈希表个别表头内存分配失败" << endl;
			delete[] hash->ListFront;
			delete hash;
			return NULL;
		}
		else {
			memset(hash->ListFront[i], 0, sizeof(ListNode));//全部置0
		}
	}

	return hash;
}

ListNode * findElement(HashTable * hash, int key)
{
	ListNode *node = NULL;
	int i = Hash(key, hash->tableSize);

	node = hash->ListFront[i]->next;

	while (node != NULL && node->key != key) {
		node = node->next;
	}
	return node;
}

void insertElement(HashTable * hash, int key, void * data)
{
	//求出插入哈希桶的下标
	int i = Hash(key, hash->tableSize);

	//查询其中是否已经存在相同的元素
	ListNode *e = findElement(hash, key);
	if (e == NULL) {
		//生成元素
		ListNode *node = new ListNode;
		node->data = data;
		node->key = key;
		//前插法插入
		node->next = hash->ListFront[i]->next;
		hash->ListFront[i]->next = node;
	}
	else {
		cout << "哈希表中存在冲突" << endl;
		system("pause");
	}
}

void deleteElement(HashTable * hash, int key)
{
	ListNode *tem = NULL;//表示要删除元素的上一个
	ListNode *dElement = NULL;
	//根据键查找到哈希桶表头
	int i = Hash(key, hash->tableSize);
	tem = hash->ListFront[i];
	dElement = hash->ListFront[i]->next;

	while (dElement != NULL && dElement->key != key) {
		tem = dElement;
		dElement = dElement->next;
	}

	if (dElement) {//为真说明存在元素
		tem->next = dElement->next;
		delete dElement;
	}
}

void DestoryHash(HashTable * hash)
{
	if (!hash) return;

	ListNode *tem = NULL, *dElement = NULL;

	for (int i = 0; i < hash->tableSize; i++) {
		dElement = hash->ListFront[i]->next;
		while (dElement) {
			tem = dElement->next;
			delete dElement;
			dElement = tem;
		}
		delete hash->ListFront[i];
	}
	delete[] hash->ListFront;
	
	delete hash;
	
}

void printHash(HashTable * hash)
{
	if (!hash) return;
	ListNode *tem = NULL, *dElement = NULL;

	for (int i = 0; i < hash->tableSize; i++) {
		dElement = hash->ListFront[i]->next;
		while (dElement) {
			tem = dElement->next;
			cout << "[" << i << "]" << (const char *)dElement->data;
			dElement = tem;
		}
	}
}
