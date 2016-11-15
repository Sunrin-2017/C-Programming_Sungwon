#include <stdio.h>
#include<string.h>
#include<Windows.h>
#include"Cards.h"
//ī�������� ����
//���� ���給 txt���Ϸ� �����غ���
typedef struct LinkedList {
	char name[50];
	int cost;
	char kind[50];
	char work[50];
	char grade[50];
	char spell[50];
	int num;
	struct LinkedList *Next;
}node;

struct card data[500];

node *head, *tail;

void reset() {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->Next = tail;
	tail->Next = NULL;
}

void file() {
	FILE *f;
	f = fopen("card.txt", "r");
	for (int i = 0; i < 500; i++)
		fscanf(f, "%s %d %s %s %s %s %s", data[i].name, &data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category, data[i].spell);
	fclose(f);
}

void mydeck() {
	system("cls");
	int i = 1;
	node *p = head->Next;
	if (p == tail) {
		printf("���� ������ ���� �����ϴ�.\n");
		system("pause");
		return;
	}
	while (p != tail) {
		printf("%d. �̸� : %s   �ڽ�Ʈ : %d   ī����,���� : %s   ���� : %s   ��� : %s   ���� : %s\n", i, p->name, p->cost, p->kind, p->work, p->grade, p->spell);
		p = p->Next;
		i++;
	}
	printf("\n");
	system("pause");
}

void makemydeckprint() {
	system("cls");
	int i = 1;
	node *p = head->Next;

	if (p == tail) {
		printf("���� ������ ���� �����ϴ�!\n");
		return;
	}

	while (p != tail) {
		printf("%d. �̸� : %s   �ڽ�Ʈ : %d   ī����,���� : %s   ���� : %s   ��� : %s   ���� : %s\n", i, p->name, p->cost, p->kind, p->work, p->grade, p->spell);
		p = p->Next;
		i++;
	}
	printf("\n");
}

void removedeck() {
	system("cls");
	char input[50];
	int select;
	printf("1. ī�� ���û���\n2. ī�� ��� ����\n:");
	scanf("%d", &select);
	if (select == 1) {
		printf("������ ������ �����ϰ� ���� ī���� �̸��� �Է��ϼ��� : ");
		scanf("%s", input);
		node *p = head->Next;
		node *o = head;
		while (p != tail) {
			if (strcmp(p->name, input) == 0) {
				node*s = p->Next;
				free(p);
				o->Next = s;
				break;
			}
			p = p->Next;
			o = o->Next;
		}
	}
	else if (select == 2) {
		reset();
	}
	else {
		printf("������ �ɼ��� �������� �ʽ��ϴ�. �ٽ��Է����ּ���.");
	}
}

void makemydeck() {
	system("cls");
	while (1) {
		char input[50];
		node *NewDeck = (node*)malloc(sizeof(node));
		node *p = head;
		printf("�� ���� �߰� �� ī���̸��� �Է��ϼ���(����� '����'�� �Է��ϼ���) : ");
		scanf("%s", input);
		while (p->Next != tail) {
			p = p->Next;
			if (strcmp(input, p->name) == 0) {
				if (p->num < 2) {
					p->num++;
					break;
				}
				else if (p->num == 2) {
					printf("\n������ �ִ� ���� ī���� ������ 2�� �Դϴ�.\n�ٸ�ī�带 �־� �ּ���.\n\n");
					system("pause");
					break;
				}
			}
		}
		for (int i = 0; i < 500; i++) {
			if (strcmp(input, data[i].name) == 0) {
				strcpy(NewDeck->name, data[i].name);
				NewDeck->cost = data[i].cost;
				strcpy(NewDeck->kind, data[i].category);
				strcpy(NewDeck->work, data[i].job);
				strcpy(NewDeck->grade, data[i].grade);
				strcpy(NewDeck->spell, data[i].spell);
				NewDeck->num = 1;
				NewDeck->Next = tail;
				p->Next = NewDeck;
			}
			else if (strcmp(input, "����") == 0)return;
		}
		makemydeckprint();
	}
}

void search() {
	system("cls");
	while (1) {
		char input[50];
		printf("ī�� �̸��� �Է��� �ּ��� : ");
		scanf("%s", input);
		for (int i = 0; i < 500; i++) {
			if (strcmp(data[i].name, input) == 0) {
				printf("\n�̸� : %s\n�ڽ�Ʈ : %d\n���� : %s\n��� : %s\n���� : %s\nī�װ� : %s\n���� : %s\n\n", data[i].name, data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category, data[i].spell);
				system("pause");
				return;
			}
		}
		if (strcmp(input, "����") == 0) {
			return;
		}
		printf("\n�˻������ �����ϴ�.\n�ٽ� �Է����ּ���.\n�˻������ '����'�� �Է��ϼ���\n\n");
		system("pause");
		system("cls");
	}
}

int main() {
	reset();
	file();
	while (1) {
		int i = 0;
		printf("<<<< == �Ͻ����� ������ �� ����� == >>>>\n\n");
		printf("�κ��� ���� ī���� ���� �������� ������ �ִ� Ȩ�������� ���� ������ּ���.\n\n");
		printf("1. ������ �� �����\n");
		printf("2. ������ �� ����\n");
		printf("3. ������ �� ����\n");
		printf("4. ī�� �˻�\n");
		printf("5. ����\n:");
		scanf("%d", &i);
		switch (i) {
		case 1:makemydeck(); break;
		case 2:mydeck(); break;
		case 3:removedeck(); break;
		case 4:search(); break;
		case 5:return 0;
		}
		system("cls");
	}
	return 0;
}