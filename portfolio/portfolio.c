#include <stdio.h>
#include"Cards.h"
int main() {
	struct card data[1564];
	FILE *f;
	f = fopen("card.txt", "r");

	for (int i = 0; i<=1564; i++)
		fscanf(f, "%s %d %s %s %s %s", data[i].name, &data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category);
	fclose(f);


	for (int i = 0; i<=1564; i++)
		printf("%s %d %s %s %s %s\n", data[i].name, data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category);

	return 0;
}