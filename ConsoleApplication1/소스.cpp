
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>
#include"Product.h"
typedef struct LinkedList {
	char name[100];
	int price;
	int num;
	int barcode;
	struct LinkedList *newpro;
}node;

struct product list[10] = {
	{ "Do it HTML,CSS",28000,9788997390250 },
	{ "Do it �ȵ���̵�",28000,9788997390847 },
	{ "LG Gram",2000000,9788997390251 },
	{ "MSI GT73", 3500000,9788926113356 },
	{ "Samsung Metal Series9", 2200000,9788931551167 },
	{ "���̼� 5�� ���̺�", 1000,8808739000108 },
	{ "�ƺ�����",1400000,8858741718423 },
	{ "�ƺ����� 2016",2500000,6945795380026 },
	{ "�������� �ڷᱸ��",32000,9788989345022 },
	{ "��������",8000,8801117544614 },
};

node*head, *tail;

void main();

void reset() {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->newpro = tail;
	tail->newpro = NULL;
}

void insertprint() {
	system("cls");
	int sum = 0;
	node *p = head->newpro;
	if (p == tail) {
		printf("���� ������ �����ϴ�.\n");
		return;
	}
	while (p != tail) {
		printf("%s\t  %d��\t  %d��\n", p->name, p->price, p->num);
		sum += p->price*p->num;
		p = p->newpro;
	}
	printf("\n");
	printf("�� �հ� : %d��\n", sum);
}
void printLinkedList() {
	system("cls");
	int sum = 0;
	int input;
	node *p = head->newpro;
	if (p == tail) {
		printf("���� ������ �����ϴ�.\n");
		system("pause");
		return;
	}
	while (p != tail) {
		printf("%s\t  %d��\t  %d��\n", p->name, p->price, p->num);
		sum += p->price*p->num;
		p = p->newpro;
	}
	printf("\n");
	printf("�� �հ� : %d��\n", sum);
	printf("���� �ݾ� : ");
	scanf("%d", &input);
	if (sum > input) {
		printf("���� �ݾ� : %d��\n", sum - input);
	}
	else if (sum < input) {
		printf("�Ž����� : %d��\n", input - sum);
	}
	reset();
	system("pause");
}


void insertnode() {
	system("cls");
	while (1) {
		int barcode;
		node *Newnode = (node*)malloc(sizeof(node));
		node *p = head;
		scanf("%d", &barcode);
		while (p->newpro != tail) {
			p = p->newpro;
			if (p->barcode == barcode) {
				p->num++;
				break;
			}
		}
		for (int i = 0; i < (sizeof(list) / sizeof(product)); i++) {
			if (list[i].barcode == barcode && list[i].barcode != p->barcode) {
				strcpy(Newnode->name, list[i].name);
				Newnode->price = list[i].price;
				Newnode->barcode = list[i].barcode;
				Newnode->newpro = tail;
				Newnode->num = 1;
				p->newpro = Newnode;

			}
			else if (barcode == 1) return;
		}
		insertprint();
	}
}
void deletenode() {
	int barcode;
	scanf("%d", &barcode);
	node *p = head->newpro;
	node *o = head;
	while (p != tail) {
		if (p->barcode == barcode && p->num == 1) {
			node*s = p->newpro;
			free(p);
			o->newpro = s;
			break;
		}
		else if (p->barcode == barcode && p->num > 1) {
			p->num--;
			break;
		}
		p = p->newpro;
		o = o->newpro;
	}
}
void main() {
	reset();
	while (1) {
		system("cls");
		int select;
		printf("POS �ý���\n\n");
		printf("1. ���ڵ� ����\n");
		printf("2. ���� ����\n");
		printf("3. ����\n");
		printf("4. ��� ����Ʈ\n:");
		scanf("%d", &select);
		switch (select) {
		case 1:insertnode(); break;
		case 2:deletenode(); break;
		case 3:printLinkedList(); break;
		case 4: {
			insertprint();
			system("pause");
		}
		}
	}
}