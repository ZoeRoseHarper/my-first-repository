#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;

typedef struct Node{
	ElementType data;
	struct Node  *next;
}Node, *LinkList;

LinkList createList(){
	LinkList L = (LinkList)malloc(sizeof(Node));
	L->next = NULL; 
	return L;
}

void printList(LinkList L){
	Node *p = NULL;
	p = L -> next;
	if(p != NULL){
		while(p != NULL){
			cout << p->data << " "; 
			p = p -> next;
		}
		cout << endl;
	} 	
}

int getLength(LinkList L){
	int count = 0;
	Node *p = L -> next;
	while(p != NULL){
		p = p -> next;
		count++;
	}
	return count;
}

void insertHead(LinkList L, ElementType x){
	LinkList s; 
	s = (LinkList)malloc(sizeof(Node));
	s -> data = x;
	s -> next = L -> next;
	L -> next = s;
}

void insertTail(LinkList L, ElementType x){
	LinkList pre = L;
	Node *p = NULL ;
	p = L -> next;
	while( p != NULL){
		pre = p;
		p = p -> next;
	}
	LinkList s;
	s=(LinkList)malloc(sizeof(Node));
	s -> data = x;
	s -> next = pre -> next;
	pre -> next = s; 
}

 int insertList(LinkList L, int i, ElementType x){
	LinkList new_list;
	LinkList p = L;
	int k = 0;
	while(p != NULL && k < i - 1){
		k++;
		p = p -> next;
	}
	if(p == NULL || i < 1) return 0;
	new_list = (LinkList)malloc(sizeof(Node));
	new_list->data = x;
	new_list->next=p->next;
	p->next=new_list;
	return 1;
}

Node* find(LinkList L, ElementType x){
	Node *p=NULL;
	p=L->next;
	while(p!=NULL&&p->data!=x){
		p=p->next;
	}
	return p;
}

Node* locate(LinkList L, int i){
	i--;
	LinkList p=L->next;
	int k=0;
	if(i < 0 || L -> next == NULL) return NULL;
	while(p != NULL && k < i){
		k++;
		p = p -> next;
	}
	if(k == i) return p;
	else return NULL;
}

int delNode(LinkList L, ElementType x){
	Node *pre = L;
	Node *p = L -> next;
	while(p != NULL && p -> data != x){
		pre = p;
		p = p -> next;
	}
	if(p == NULL) return 0;
	else{
		pre -> next=p -> next;
		free(p);
		return 1;
	}
}

int delNode(LinkList L, int i, ElementType *px){
	LinkList p=L;
	int k=0;
	while(p!=NULL && k<i-1){
		k++;
		p=p->next;
	}
	if(p==NULL || i<1 ||p->next==NULL)
		return 0;
	Node *mid=p->next;
	p->next=mid->next;
	*px=mid->data;
	free(mid);
	return 1;
}

void clearList(LinkList L){
	Node* n;
	Node* m=L->next;
	while(m!=NULL){
		n=m->next;
		free(m);
		m=n;
	}
	L->next=NULL;
}

void destroyList(LinkList L){
    LinkList c1;
    while(L->next!=NULL){
        c1=L->next;
        L->next=c1->next;
        free(c1);
    }
    L->next=NULL;
}

int main(){
	
    return 0;
}