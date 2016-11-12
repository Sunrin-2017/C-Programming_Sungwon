#include <stdio.h>
#include<string.h>
#include<Windows.h>
#include"Cards.h"
void search(){
	char input[50];
	scanf("%s", input);
}
int main() {
	struct card data[1000];
	FILE *f;
	f = fopen("card.txt", "r");
	for (int i = 0; i<1000; i++)
		fscanf(f, "%s %d %s %s %s %s", data[i].name, &data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category);
	fclose(f);
	while (1) {
		int i = 0;
		printf("<<<< == 하스스톤 나만의 덱 만들기 == >>>>\n");
		printf("인벤과 같이 카드의 대한 상세정보를 가지고 있는 홈페이지와 같이 사용해주세요.\n\n");
		printf("1. 나만의 덱 만들기\n");
		printf("2. 나만의 덱 보기\n");
		printf("3. 카드 검색\n :");
		scanf("%d", &i);
		switch (i) {
		     
		}
		system("cls");
	}
	return 0;
}