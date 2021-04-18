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
		else if(menu == 2) {
			checker = listProduct(plist, index);
			if(checker == 1)
				printf("=> 상품 목록이 정상적으로 출력되었습니다.\n\n");
		}
		else if(menu == 3) {
			int no = selectNumber(plist, index);
			if(no > 0) {
				if(updateProduct(&plist[no-1]) == 1)
					printf("=> 제품이 성공적으로 수정되었습니다.\n\n");
			} else {
				printf("=> 제품 수정이 취소되었습니다.\n\n");
			}
		}
	}

	return 0;
}
