#include <stdio.h>
#include <stdlib.h>

void menu1(void);
void menu2(void);
void menu3(void);

int main(void)
{
      int n,m;
      while(1){
main_menu:
	    system("clear");
	    menu1();
	    printf("请选择:");
	    scanf("%d",&n);
	    switch(n){
		  case 1:
			system("clear");
			menu2();
			printf("请选择:");
			scanf("%d",&m);
			switch(m){
			      case 1:
				    break;
			      case 2:
				    break;
			      case 3:
				    goto main_menu;

			}
		  case 2:
			system("clear");
			menu3();
			printf("请选择:");
			scanf("%d",&m);
			switch(m){
			      case 1:
				    break;
			      case 2:
				    break;
			      case 3:
				    goto main_menu;
			}
		  case 3:
			printf("欢迎下次使用! Bye-bye\n");
			exit(1);
	    }
      }

      return 0;
}
