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
		printf("<<<< == �Ͻ����� ������ �� ����� == >>>>\n");
		printf("�κ��� ���� ī���� ���� �������� ������ �ִ� Ȩ�������� ���� ������ּ���.\n\n");
		printf("1. ������ �� �����\n");
		printf("2. ������ �� ����\n");
		printf("3. ī�� �˻�\n :");
		scanf("%d", &i);
		switch (i) {
		     
		}
		system("cls");
	}
	return 0;
}