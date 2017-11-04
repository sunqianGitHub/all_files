#include <stdio.h>
#include "../include/flight.h"

void help(void)
{
	printf("\n======================"
		"===================\n");
	printf("[1]: Read a file.\t");
	printf("[2]: Print info.\n");
	printf("[3]: Search info.\t");
	printf("[4]: Sort info.\n");
	printf("[5]: Modify info.\t");
	printf("[6]: Help.\n");
	printf("[0]: Quit.\n");
	printf("========================"
		"================\n");
}

void welcome(void)
{
	printf("\n\tWelcome to Flights System");
}

void Scanf(const char *format, int *p, int low, int high)
{
	int ret;
	int ch;
	while((ret=scanf(format, p)) == 0 ||
		(ch=getchar()) != '\n' ||
		*p < low || *p > high){

		printf("Invalid input. please try again.\n");
		if(ret == 0)
			while(getchar() != '\n');
	}
}

FILE *Fopen(const char *path, const char *mode)
{
	FILE *fp;
again:
	fp = fopen(path, mode);

	if(fp == NULL && errno == EINTR)
		goto again;

	return fp;
}

linklist read_flight(const char *path)
{
	FILE *fp;
	fp = Fopen(path, "r+");
	if(fp == NULL){
		perror("Can't read the file");
		return NULL;
	}

	char buf[MAXLINE];
	char *delim = ",\t";
	char *p = NULL;

	linklist head = (linklist)malloc(sizeof(node));
	INIT_LIST_HEAD(&(head->list));

	int info_count = 0;
	while(1){
		if(fgets(buf, MAXLINE, fp) == NULL)
			break;

		p = strtok(buf, delim);
		linklist new = (linklist)malloc(sizeof(node));

		int i;
		for(i=1; p!=NULL; i++, p=strtok(NULL, delim)){
			switch(i)
			{
			case 1:
				strncpy(new->info.number, p, NUMBER);
				break;
			case 2:
				strncpy(new->info.depart_address, p, ADDR);
				break;
			case 3:
				strncpy(new->info.arrive_address, p, ADDR);
				break;
			case 4:
				strncpy(new->info.date, p, DATE);
				break;
			case 5:
				strncpy(new->info.time, p, TIME);
				break;
			case 6:
				strncpy(new->info.price, p, PRICE);
				break;
			case 7:
				new->info.type = *p;
				break;
			default:
				fprintf(stderr, "too many info items!\n");
				exit(0);
			}
		}

		// add the new node
		list_add(&(new->list), &(head->list));
		info_count++;
	}

	printf("read file successful! %d items"
		" have been read.\n", info_count);

	return head;
}

void title(void)
{
	printf("***********************************"
		"**********************************");

	printf("\nnumber");
	printf("\t\taddress");
	printf("\t\tdate\t     time");
	printf("\tprice");
	printf("\ttype\n");

	printf("-----------------------------------"
		"----------------------------------\n");
}

void show_all(linklist head)
{
	if(head == NULL){
		printf("\tNo Info.\n");
		return;
	}

	title();

	linklist pos;

	list_for_each_entry(pos, &(head->list), list){

		printf("%s", pos->info.number);

		printf("\t%s", pos->info.depart_address);
		printf(" --> %s", pos->info.arrive_address);

		printf("\t%s, ", pos->info.date);
		printf("%s", pos->info.time);
		printf("\t%s", pos->info.price);

		printf("\t%c\n", pos->info.type);
	}

	printf("***********************************"
		"**********************************\n");
}

void show(linklist head)
{
	if(head == NULL){
		printf("\tNo Info.\n");
		return;
	}

	printf("%s", head->info.number);

	printf("\t%s", head->info.depart_address);
	printf(" --> %s", head->info.arrive_address);

	printf("\t%s, ", head->info.date);
	printf("%s", head->info.time);
	printf("\t%s", head->info.price);

	printf("\t%c\n", head->info.type);

	return;
}

/*
void sort_number(linklist head)
{
	linklist p, q;

	list_for_each_entry(p, &(head->list), list){

		list_for_each_entry(q, &(head->list), list){

			if(strcmp(p->info.number, q->info.number) < 0)

			list_for_each_entry_prev(){

				
			}
		}
		
	}
}
*/
