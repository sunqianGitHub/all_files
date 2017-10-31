#include <stdio.h>
#include "../include/flight.h"

void sort_number(linklist head)
{
	linklist p, q, tmp;

	show_all(head);
			p = list_entry(head->list.next, node, list);
			q = list_entry(p->list.next, node, list);


			linklist pp = list_entry(p->list.prev, node, list);
			linklist pq = list_entry(q->list.prev, node, list);

			list_move(&(q->list), &(pp->list));
			list_move(&(p->list), &(pq->list));
	show_all(head);
/*
	list_for_each_entry(p, &(head->list), list){

		q = p;

		while(q != head){

//printf("%s\n", q->info.number);
			q = list_entry(q->list.next, node, list);
//printf("%s\n", p->info.number);
//printf("%s\n", q->info.number);
	
			if(p->info.number > q->info.number){
				linklist pp = list_entry(p->list.prev, node, list);
				linklist pq = list_entry(q->list.prev, node, list);
	
				list_move(&(q->list), &(pp->list));
				list_move(&(p->list), &(pq->list));
	
				tmp = q;
				q = p;
				p = tmp;
			}

			show_all(head);
			sleep(1);
		}	
	}
*/
}

void sort(linklist head)
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

	int choice;
	Scanf("%d", &choice, 1, 7);

	switch(choice)
	{
	case 5:
		sort_number(head);
		//show_all(head);
		break;
/*
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
*/
	default:
		printf("invalid input.");
	}
}
