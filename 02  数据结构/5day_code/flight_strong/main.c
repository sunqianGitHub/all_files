#include <stdio.h>
#include "include/flight.h"

int main(void)
{
	welcome();
	help();

	int choice;
	Scanf("%d", &choice, 0, 6);

	linklist head = NULL;
	char flight_path[MAXLINE];

	while(1){

		switch(choice)
		{
		case 1: // read a file

			printf("input the file:");
			//scanf("%s", flight_path);
	
			linklist p;
			if((p=read_flight("flights")) != NULL){
			//if((p=read_flight(flight_path)) != NULL){
				head = p;
				show_all(p);
			}

			break;
		
		case 2: // Print flights info

			show_all(head);
			break;

		case 3: // Search a fights

			search(head);
			break;

		case 4: // Sort flisght info

			sort(head);
			break;

		case 5: // Modigy flisght info

			break;

		case 6: // Get help

			help();
			break;

		case 0: // quit

			printf("Bye-bye!\n");
			exit(0);
	
		default:
			break;

		} // swtich

		Scanf("%d", &choice, 0, 6);
	}

	return 0;
}
