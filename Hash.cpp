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

	//����ռ�
	hash = new HashTable;
	//�ж��Ƿ����ɹ�
	if (!hash) {
		cout << "��ϣ���ڴ����ʧ��" << endl;
		return NULL;
	}

	hash->tableSize = tableSize;
	//��ͷ�����ڴ�
	hash->ListFront = new List[tableSize];
	
	if (!hash->ListFront) {
		cout << "��ϣ���ͷ�ڴ����ʧ��" << endl;
		delete hash;
		return NULL;
	}

	for (int i = 0; i < tableSize; i++) {
		hash->ListFront[i] = new ListNode;
		if (!hash->ListFront[i]) {
			cout << "��ϣ������ͷ�ڴ����ʧ��" << endl;
			delete[] hash->ListFront;
			delete hash;
			return NULL;
		}
		else {
			memset(hash->ListFront[i], 0, sizeof(ListNode));//ȫ����0
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
	//��������ϣͰ���±�
	int i = Hash(key, hash->tableSize);

	//��ѯ�����Ƿ��Ѿ�������ͬ��Ԫ��
	ListNode *e = findElement(hash, key);
	if (e == NULL) {
		//����Ԫ��
		ListNode *node = new ListNode;
		node->data = data;
		node->key = key;
		//ǰ�巨����
		node->next = hash->ListFront[i]->next;
		hash->ListFront[i]->next = node;
	}
	else {
		cout << "��ϣ���д��ڳ�ͻ" << endl;
		system("pause");
	}
}

void deleteElement(HashTable * hash, int key)
{
	ListNode *tem = NULL;//��ʾҪɾ��Ԫ�ص���һ��
	ListNode *dElement = NULL;
	//���ݼ����ҵ���ϣͰ��ͷ
	int i = Hash(key, hash->tableSize);
	tem = hash->ListFront[i];
	dElement = hash->ListFront[i]->next;

	while (dElement != NULL && dElement->key != key) {
		tem = dElement;
		dElement = dElement->next;
	}

	if (dElement) {//Ϊ��˵������Ԫ��
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
