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

	//test CRUD
	for(int i = 0; i < 5; i ++) {
	      if(createProduct(&plist[i]) == 1) {
		      index ++;
		      count ++;
		      printf("=> createProduct %d번 정상 작동\n", i+1);
	      }
	}

	if(listProduct(plist, index) == 1)
		printf("=> listProduct 정상 작동 \n");	
	int no;
	printf("수정할 번호 선택 : ");
	scanf("%d", &no);
	if((no > 0)&&(no <= count)) {
		if(updateProduct(&plist[no-1]) == 1) 
			printf("updateProduct 정상 작동\n");
	} else {
		printf("번호가 잘못되었습니다. \n");
	}
	printf("삭제할 번호 선택 : ");
	scanf("%d", &no);
	if((no > 0)&&(no <= count)) {
		if(deleteProduct(&plist[no-1]) == 1) { 
			count --;
			printf("deleteProduct 정상 작동\n");
		}
	}
	else {
		printf("번호가 잘못되었습니다.\n");
	}

	printf("최종 제품 리스트입니다.\n");
	listProduct(plist, index);

	return 0;
}
