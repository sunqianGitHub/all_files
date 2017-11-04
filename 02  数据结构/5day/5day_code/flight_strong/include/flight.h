#ifndef	__FLIGHT_H__
#define	__FLIGHT_H__

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "list.h"

#define NUMBER 10
#define ADDR 20
#define DATE 20
#define TIME 20
#define PRICE 10

#define MAXLINE 80

#define SEARCH(head, string, member) ({\
	title(); \
	linklist pos;\
	int count = 0; \
	list_for_each_entry(pos, &(head->list), list){ \
		if(strcmp(string, pos->info.member)) \
			continue; \
		show(pos); \
		count++; \
	} \
	if(count == 0) \
		printf("No such flight.\n"); \
	else \
		printf("***********************************" \
			"**********************************\n"); \
	})

#define SEARCH_TYPE(head, ch, member) do{ \
	title(); \
	linklist pos;\
	int count = 0; \
	list_for_each_entry(pos, &(head->list), list){ \
		if(ch != pos->info.member) \
			continue; \
		show(pos); \
		count++; \
	} \
	if(count == 0) \
		printf("No such flight.\n"); \
	else \
		printf("***********************************" \
			"**********************************\n"); \
	}while(0)

typedef	struct flight   
{	  
	char	number[NUMBER]; // Ticket number  e.g "A0001"

	char	depart_address[ADDR]; // Department  e.g "NewYork"
	char	arrive_address[ADDR]; // Destination

	char	date[DATE]; // Date of departure  e.g "2011.10.21"
	char	time[TIME]; // time of departure  e.g "08:30am"

	char	price[PRICE]; // e.g $1200.0
	char	type; // e.g 'A' (class A)
}datatype;

typedef struct node   
{		  
	datatype info;	   
	struct list_head list;
}node, *linklist;

void welcome(void);
void help(void);
void Scanf(const char *, int *, int, int);
FILE *Fopen(const char *, const char *);

linklist read_flight(const char *);

void title(void);
void show_all(linklist);
void show(linklist);

void search(linklist);
void sort(linklist);


#endif
