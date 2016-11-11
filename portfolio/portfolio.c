#include <stdio.h>
#include"Cards.h"
int main() {
	struct card data[4];
	FILE *f;
	f = fopen("db.txt", "r");

	for (int i = 0; i<4; i++)
		fscanf(f, "%s %d %s %s %s %s", data[i].name, &data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category);
	fclose(f);




	for (int i = 0; i<4; i++)
		printf("%s %d %s %s %s %s\n", data[i].name, data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category);

	return 0;
}