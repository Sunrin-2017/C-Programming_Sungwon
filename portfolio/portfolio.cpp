#include <stdio.h>
#include<string.h>
#include<Windows.h>
#include"Cards.h"
//카드삭제기능 삽입
//내가 만든덱 txt파일로 저장해보기
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
		printf("아직 생성된 덱이 없습니다.\n");
		system("pause");
		return;
	}
	while (p != tail) {
		printf("%d. 이름 : %s   코스트 : %d   카드팩,모험 : %s   직업 : %s   등급 : %s   종류 : %s\n",i, p->name, p->cost, p->kind, p->work, p->grade, p->spell);
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
		printf("아직 생성된 덱이 없습니다!\n");
		return;
	}

	while (p != tail) {
		printf("%d. 이름 : %s   코스트 : %d   카드팩,모험 : %s   직업 : %s   등급 : %s   종류 : %s\n", i, p->name, p->cost, p->kind, p->work, p->grade, p->spell);
		p = p->Next;
		i++;
	}
	printf("\n");
}

void makemydeck() {
	system("cls");
	while (1) {
		char input[50];
		node *NewDeck = (node*)malloc(sizeof(node));
		node *p = head;
		printf("내 덱에 추가 할 카드이름을 입력하세요(종료는 '종료'를 입력하세요) : ");
		scanf("%s", input);
		while (p->Next != tail) {
			p = p->Next;
			if (strcmp(input, p->name) == 0) {
				if (p->num < 2) {
					p->num++;
					break;
				}
				else if (p->num == 2) {
					printf("\n넣을수 있는 동일 카드의 갯수는 2개 입니다.\n다른카드를 넣어 주세요.\n\n");
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
			else if (strcmp(input, "종료") == 0)return;
		}
		makemydeckprint();
	}
}

void search() {
	system("cls");
	while (1) {
		char input[50];
		printf("카드 이름을 입력해 주세요 : ");
		scanf("%s", input);
		for (int i = 0; i < 500; i++) {
			if (strcmp(data[i].name, input) == 0) {
				printf("\n이름 : %s\n코스트 : %d\n직업 : %s\n등급 : %s\n종족 : %s\n카테고리 : %s\n종류 : %s\n\n", data[i].name, data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category, data[i].spell);
				system("pause");
				return;
			}
		}
		if (strcmp(input, "종료") == 0) {
			return;
		}
		printf("\n검색결과가 없습니다.\n다시 입력해주세요.\n검색종료는 '종료'를 입력하세요\n\n");
		system("pause");
		system("cls");
	}
}

int main() {
	reset();
	file();
	while (1) {
		int i = 0;
		printf("<<<< == 하스스톤 나만의 덱 만들기 == >>>>\n\n");
		printf("인벤과 같이 카드의 대한 상세정보를 가지고 있는 홈페이지와 같이 사용해주세요.\n\n");
		printf("1. 나만의 덱 만들기\n");
		printf("2. 나만의 덱 보기\n");
		printf("3. 카드 검색\n");
		printf("4. 종료\n:");
		scanf("%d", &i);
		switch (i) {
		case 1:makemydeck(); break;
		case 2:mydeck(); break;
		case 3:search(); break;
		case 4:return 0;
		}
		system("cls");
	}
	return 0;
}