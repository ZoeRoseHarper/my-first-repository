#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;

typedef struct{
	ElementType *array; //存放数据的指针
    int length;	 		//已有数据个数
    int capacity;  		//容量
}SeqList;

SeqList* createList(int capacity){
    SeqList  *L = (SeqList*)malloc(sizeof (SeqList));
    L -> length = 0;
    L -> capacity = capacity;
    L -> array = (ElementType*)malloc(capacity * sizeof (ElementType));
    return L;
}

int isEmpty(SeqList *L){
    if(L -> length == 0)return 1;
    return 0;
}

void printList(SeqList *L){
	for(int i = 0; i < L -> length ; i++)printf("%d ", L -> array[i]);
	puts("");
}

int getLength(SeqList *L){
	return L -> length;
}

int insertList(SeqList *L, int i, ElementType x){
	if(i <1 || i > L -> length + 1 || L -> length == L -> capacity)return 0;
	for (int k = L -> length; k >= i; k--){
		L -> array[k] = L -> array[k - 1];
	}
	L -> array[i - 1] = x;
	L -> length++;
	return 1; 
}

int find(SeqList *L, ElementType x){
	for(int i = 0; i < L -> length; i++){
		if(L -> array[i] == x)return i + 1;
	}
	return -1;
}

int getElement(SeqList *L, int i, ElementType *p){
	if(i > L -> length || i < 1)return 0;
	*p = L -> array[i - 1];
	return 1;
}

int delElement(SeqList *L, int i, ElementType *p){
	if(i > L -> length || i < 1)return 0;
	*p = L -> array[i - 1];
	while(i < L -> length)L -> array[i - 1] = L -> array[i++];
	L -> length--;
	return 1;
}

void delRepeatElement(SeqList *L){
    if (L == NULL || L->length <= 1)return;
    int newSize = 1;
    for (int i = 1; i < L->length; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < newSize; j++) {
            if (L->array[i] == L->array[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            L->array[newSize++] = L->array[i];
        }
    }
    L->length = newSize;
}

void clearList(SeqList *L){
	if(L == NULL)return;
	L -> length = 0;
}

void mergeList(SeqList *LA, SeqList *LB, SeqList *LC){
	int i = 0, j = 0, k = 0;
	while(i < LA -> length && j < LB -> length){
		if(LA -> array[i] <= LB -> array[j]){
			LC -> array[k] = LA -> array[i];
			i++; k++;
		}
		else{
			LC -> array[k] = LB -> array[j];
			j++; k++;
		}
	}
	while(i < LA -> length){
		LC -> array[k] = LA -> array[i];
		i++; k++;
	}
	while(j < LB -> length){
		LC -> array[k] = LB -> array[j];
		j++; k++;
	}
	LC -> length = k;
	return;
}

void destroyList(SeqList *L){
	if(L == NULL)return;
	free(L -> array);
	free(L);
}

int main(){
    SeqList *L=createList(100);
    return 0;
}