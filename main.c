#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int main() {

#ifdef DEBUG
	printf("***DEBUGGING MODE***\n");
#endif

	Product plist[10];
	int index = 0;
	int count = 0;
	int menu;
	int checker;

	while(1) {
		menu = selectMenu();
		if(menu == 0)
			break;
		else if(menu == 1) {
			checker = createProduct(&plist[index++]);
			count ++;
			if(checker == 1)
				printf("=> 제품이 성공적으로 등록되었습니다.\n\n");
		}
	}

	return 0;
}
