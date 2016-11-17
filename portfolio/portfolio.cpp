#include <stdio.h>
#include<string.h>
#include<Windows.h>
#include"Cards.h"
typedef struct LinkedList { //typedef는 별명을 선언해 주기위해 사용
	char name[50];
	int cost;
	char kind[50];
	char work[50];
	char grade[50];
	char spell[50];
	int num;
	struct LinkedList *Next;
}node;//node라는 별명을 가지는 LinkedList구조체 선언

struct card data[500];

node *head, *tail; // node형 포인터 변수 head, tail 선언

void reset() { //메모리 상에서 따로놀고 있는 두 변수를 이어주는 과정 이 과정중 초기화됨
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->Next = tail;
	tail->Next = NULL;
}

void file() { //파일을 읽어오는 함수 , 같은폴더 내 card.txt라는 파일에서 데이터를 읽어옴
	FILE *f;
	f = fopen("card.txt", "r");//파일을 읽어오기 권한으로 f 포인터 변수로 파일을 연다
	for (int i = 0; i < 500; i++)
		fscanf(f, "%s %d %s %s %s %s %s", data[i].name, &data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category, data[i].spell); //띄어쓰기로 인덱스를 구별해 각각의 구조체배열에 넣어준다
	fclose(f);//파일을 다 읽은 후에 열었던 파일을 닫는다
}

void mydeck() { // 연결리스트 내에 생성한 노드들을 차례차례 읽어오는 함수다
	system("cls");
	int i = 1;
	node *p = head->Next; //node형 포인터변수 p를 head다음에 있는 노드의 주소값을 저장한다
	if (p == tail) {
		printf("æ∆¡˜ ª˝º∫µ» µ¶¿Ã æ¯Ω¿¥œ¥Ÿ.\n");
		system("pause");
		return;
	}
	while (p != tail) { //p를 읽어 올때마다 다음 노드의 주소값을 받아옴에 따라 p의 주소값이 tail의 주소값이 아닐때 까지 while문이 돌도록 설계했다
		printf("%d. ¿Ã∏ß : %s   ƒ⁄Ω∫∆Æ : %d   ƒ´µÂ∆—,∏«Ë : %s   ¡˜æ˜ : %s   µÓ±ﬁ : %s   ¡æ∑˘ : %s\n", i, p->name, p->cost, p->kind, p->work, p->grade, p->spell);
		p = p->Next;
		i++;
	}
	printf("\n");
	system("pause");
}

void makemydeckprint() { // mydeck함수와 같은기능을 하지만 이 함수는 makemydeck함수에서 연결리스트에 노드를 추가할때마다 현재 추가된 카드들을 실시간으로 보여줄때 사용할 함수로 제작했다
	system("cls");
	int i = 1;
	node *p = head->Next; //node형 포인터변수 p를 head다음에 있는 노드의 주소값을 저장한다

	if (p == tail) {
		printf("æ∆¡˜ ª˝º∫µ» µ¶¿Ã æ¯Ω¿¥œ¥Ÿ!\n");
		return;
	}

	while (p != tail) {
		printf("%d. ¿Ã∏ß : %s   ƒ⁄Ω∫∆Æ : %d   ƒ´µÂ∆—,∏«Ë : %s   ¡˜æ˜ : %s   µÓ±ﬁ : %s   ¡æ∑˘ : %s\n", i, p->name, p->cost, p->kind, p->work, p->grade, p->spell);
		p = p->Next;
		i++;
	}
	printf("\n");
}

void removedeck() { //연결리스트 내의 존재하는 노드들중 input값에 입력된값과 비교해 이름이 input값과 같을경우 노드가 삭제되는 함수이다
	system("cls");
	char input[50];
	int select;
	printf("1. ƒ´µÂ º±≈√ªË¡¶\n2. ƒ´µÂ ∏µŒ ªË¡¶\n:");
	scanf("%d", &select);
	if (select == 1) { //1번 옵션을 선택 할시에 리스트내의 노드를 골라 삭제할수 있다
		printf("≥™∏∏¿« µ¶ø°º≠ ªË¡¶«œ∞Ì ΩÕ¿∫ ƒ´µÂ¿« ¿Ã∏ß¿ª ¿‘∑¬«œººø‰ : ");
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
	else if (select == 2) { //2번 함수를 실행할시 reset함수를 호출해 리스트를 초기화 시킨다
		reset();
	}
	else {
		printf("º±≈√«— ø…º«¿∫ ¡∏¿Á«œ¡ˆ æ Ω¿¥œ¥Ÿ. ¥ŸΩ√¿‘∑¬«ÿ¡÷ººø‰.");
	}
}

void makemydeck() { //구조체에서 입력한 값과 이름이 일치하는 카드를 불러와 링크드리스트내에 노드를 추가하는 함수이다.
	system("cls");
	while (1) {
		char input[50];
		node *NewDeck = (node*)malloc(sizeof(node)); //node형 사이즈만큼 malloc함수로 동적할당을 해 Newdeck 포인터 변수안에 주소값을 저장한다
		node *p = head; //p 변수에 head주소값을 저장ㅎ나다
		printf("≥ª µ¶ø° √ﬂ∞° «“ ƒ´µÂ¿Ã∏ß¿ª ¿‘∑¬«œººø‰(¡æ∑·¥¬ '¡æ∑·'∏¶ ¿‘∑¬«œººø‰) : ");
		scanf("%s", input);
		while (p->Next != tail) { //p의 인덱스 중 Next안의 주소값이 tail이 아닐때 까지 도는 while문이다.
			p = p->Next; //p의 인덱스중 Next를 다음 p의 주소를 불러오는 과정이다
			if (strcmp(input, p->name) == 0) { //이 과정을 돌면서 만약 p의 인덱스중 name의 값과 입력된값을 strcmp로 비교 했을때 0이 나올경우 p의 num인덱스에 1을 더한다.
				if (p->num < 2) {
					p->num++;
					break;
				}
				else if (p->num == 2) { //만약 검색을 했는데 그 인덱스의 num이 2일경우 더이상 추가가 안된다고 출력해주고 반복문을 다시 호출한다.(실제 하스스톤 덱을 생성할때 동일카드를 3장 이상 추가할 수 없기 때문에 만든기능이다)
					printf("\n≥÷¿ªºˆ ¿÷¥¬ µø¿œ ƒ´µÂ¿« ∞πºˆ¥¬ 2∞≥ ¿‘¥œ¥Ÿ.\n¥Ÿ∏•ƒ´µÂ∏¶ ≥÷æÓ ¡÷ººø‰.\n\n");
					system("pause");
					break;
				}
			}
		}
        // 노드 안에 구조체에서 찾아온 데이터를 넣는 과정이다
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
			else if (strcmp(input, "¡æ∑·") == 0)return; //종료를 입력하면 메인함수로 돌아가게끔 설정했다
		}
		makemydeckprint(); //실시간으로 만든 덱을 보기위해 덱을 넣을때마다 호출되는 함수이다
	}
}

void search() { // 구조체에서 카드이름을 검색해 카드의 상세정보를 보는 search함수이다. (연결리스트와는 연관되지 않은기능이다)
	system("cls");
	while (1) {
		char input[50];
		printf("ƒ´µÂ ¿Ã∏ß¿ª ¿‘∑¬«ÿ ¡÷ººø‰ : ");
		scanf("%s", input);
		for (int i = 0; i < 500; i++) { //500장의 카드데이터를 보유하고 있기때문에 500까지 반복하며 검색한다
			if (strcmp(data[i].name, input) == 0) { // 입력한 값과 for문이 돌며 찾은 구조체배열의 이름과 일치할경우 모든 데이터를 불러와 보여준다
				printf("\n¿Ã∏ß : %s\nƒ⁄Ω∫∆Æ : %d\n¡˜æ˜ : %s\nµÓ±ﬁ : %s\n¡æ¡∑ : %s\nƒ´≈◊∞Ì∏Æ : %s\n¡æ∑˘ : %s\n\n", data[i].name, data[i].cost, data[i].job, data[i].grade, data[i].tribe, data[i].category, data[i].spell);
				system("pause");
				return;
			}
		}
		if (strcmp(input, "¡æ∑·") == 0) {
			return;
		}
		printf("\n∞Àªˆ∞·∞˙∞° æ¯Ω¿¥œ¥Ÿ.\n¥ŸΩ√ ¿‘∑¬«ÿ¡÷ººø‰.\n∞Àªˆ¡æ∑·¥¬ '¡æ∑·'∏¶ ¿‘∑¬«œººø‰\n\n");
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
		printf("인벤과 같이 카드의 대한 정보를 많이가지고 있는 웹과 같이 사용하면 편리합니다.\n\n");
		printf("1. 나만의 덱 만들기\n");
		printf("2. 나만의 덱 보기\n");
		printf("3. 나만의 덱 삭제\n");
		printf("4. 카드 검색\n");
		printf("5. 종료\n:");
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
