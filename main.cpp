#include <iostream>
#include <stdio.h>
#include "Hash.h"

using namespace std;

int main() {
	char * elems[] = { (char *)"小红", (char *)"小花", (char *)"小白", (char *)"小明" };

	HashTable *hash = NULL;
	
	hash = initHash(MINSIZE);
	insertElement(hash, 1, elems[0]);
	insertElement(hash, 5, elems[1]);
	insertElement(hash, 10, elems[2]);
	insertElement(hash, 15, elems[3]);

	printHash(hash);
	system("pause");

	deleteElement(hash, 10);
	printHash(hash);

	DestoryHash(hash);
	
	return 0;
}