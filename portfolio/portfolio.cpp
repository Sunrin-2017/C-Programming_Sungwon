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
		printf("ī�� �̸��� �Է��� �ּ��� : ");
		scanf("%s", input);
		for (int i = 0; i < 1000; i++) {
			if (strcmp(data[i].name, input) == 0) {
				printf("\n�̸� : %s\n�ڽ�Ʈ : %d\n���� : %s\n��� : %s\n���� : %s\nī�װ� : %s\n\n", data[i].name, data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category);
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
	while (1) {
		int i = 0;
		printf("<<<< == �Ͻ����� ������ �� ����� == >>>>\n");
		printf("�κ��� ���� ī���� ���� �������� ������ �ִ� Ȩ�������� ���� ������ּ���.\n\n");
		printf("1. ������ �� �����\n");
		printf("2. ������ �� ����\n");
		printf("3. ī�� �˻�\n");
		printf("4. ����\n:");
		scanf("%d", &i);
		switch (i) {
		case 3:search(); break;
		case 4:return 0;
		}
		system("cls");
	}
	return 0;
}