#include <stdio.h>
#include "../include/flight.h"

void search(linklist head)
{
	if(head == NULL){
		printf("\tNo Info.\n");
		return;
	}

	printf("\n======================"
		"===================\n");
	printf("[1]: By De Addr.\t");
	printf("[2]: By Ar Addr.\n");
	printf("[3]: By Date.\t\t");
	printf("[4]: By Time.\n");
	printf("[5]: By Number.\t\t");
	printf("[6]: By Price.\n");
	printf("[7]: By Type.\n");
	printf("========================"
		"================\n");

	char buf[MAXLINE];

	int choice;
	Scanf("%d", &choice, 0, 7);

	switch(choice)
	{
	case 5:
		printf("number:(A0010)");
		scanf("%s", buf);
		SEARCH(head, buf, number);
		break;
	case 1:
		printf("depart address:(ShenZhen)");
		scanf("%s", buf);
		SEARCH(head, buf, depart_address);
		break;
	case 2:
		printf("arrive address:(BeiJing)");
		scanf("%s", buf);
		SEARCH(head, buf, arrive_address);
		break;
	case 3:
		printf("date:(2011.12.13)");
		scanf("%s", buf);
		SEARCH(head, buf, date);
		break;
	case 4:
		printf("time:(14:50pm)");
		scanf("%s", buf);
		SEARCH(head, buf, time);
		break;
	case 6:
		printf("price:($100.0)");
		scanf("%s", buf);
		SEARCH(head, buf, price);
		break;
	case 7:
		printf("type:(A-C)");
		char c;
		scanf("%c", &c);
		//Scanf("%c", (int *)buf, 'A', 'C');
		SEARCH_TYPE(head, c, type);
		break;
	default:
		printf("invalid input.");
	}
}
