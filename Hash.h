#pragma once
#include <iostream>

using namespace std;

const int MINSIZE = 8;

//��ϣ��ڵ�
typedef struct _ListNode {
	int key;//��ֵ
	void *data;//����(void *�ɱ�ʾ��������ָ��)
	_ListNode *next;
}ListNode;

typedef ListNode* List;
//��ϣ��ṹ
typedef struct _Hash {
	int tableSize;
	List *ListFront;//ָ��ָ���ͷ�ڵ�������׵�ַint *lists;lists = new int[10];
}HashTable;

//��ϣ����
int Hash(int key, int tableSize);
//��ʼ����ϣ��
HashTable* initHash(int tableSize);

//��ϣ����ݼ�ֵ����Ԫ��
ListNode * findElement(HashTable *hash, int key);

//��ϣ�����Ԫ�� ����ֵ��
void insertElement(HashTable *hash, int key, void* data);

//��ϣ����ݼ�ֵɾ��Ԫ��
void deleteElement(HashTable *hash, int key);

//��ϣ������
void DestoryHash(HashTable *hash);

//��ϣ��Ԫ�ش�ӡ
void printHash(HashTable *hash);
