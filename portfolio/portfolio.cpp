#include <stdio.h>
#include<string.h>
#include<Windows.h>
#include"Cards.h"

struct card data[1000];

void file() {
	FILE *f;
	f = fopen("card.txt", "r");
	for (int i = 0; i<1000; i++)
		fscanf(f, "%s %d %s %s %s %s", data[i].name, &data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category);
	fclose(f);
}

void search(){
	system("cls");
	file();
	while (1) {
		char input[50];
		printf("카드 이름을 입력해 주세요 : ");
		scanf("%s", input);
		for (int i = 0; i < 1000; i++) {
			if (strcmp(data[i].name, input) == 0) {
				printf("\n이름 : %s\n코스트 : %d\n직업 : %s\n등급 : %s\n종족 : %s\n카테고리 : %s\n\n", data[i].name, data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category);
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
	while (1) {
		int i = 0;
		printf("<<<< == 하스스톤 나만의 덱 만들기 == >>>>\n");
		printf("인벤과 같이 카드의 대한 상세정보를 가지고 있는 홈페이지와 같이 사용해주세요.\n\n");
		printf("1. 나만의 덱 만들기\n");
		printf("2. 나만의 덱 보기\n");
		printf("3. 카드 검색\n");
		printf("4. 종료\n:");
		scanf("%d", &i);
		switch (i) {
		case 3:search(); break;
		case 4:return 0;
		}
		system("cls");
	}
	return 0;
}