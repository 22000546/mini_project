#ifndef _MANAGER_H
#define _MANAGER_H
#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int listProduct(Product *p, int index){
    printf("****** 상품 목록 ******\n");
    for(int i = 0; i < index; i ++) {
    	if(p[i].price == 0)
		continue;
	printf("%d : ", i+1);
        readProduct(p[i]);
    }    
    printf("\n");
    return 1;
}

void searchProductName(Product *p, int index) {
	int searchcnt = 0;
	char search[50];

	getchar();
	printf("검색하고 싶은 상품의 이름을 입력해주세요. \n");
	printf("이름 : ");
	scanf("%[^\n]s", search);
	for(int i = 0; i < index; i ++) {
		if(strstr(p[i].name, search)) {
			readProduct(p[i]);
			searchcnt ++;
		}
	}
	if(searchcnt == 0)
		printf("\n%s\n에 대한 검색 결과가 없습니다.\n", search);
}

void searchProductWeight(Product *p, int index) {
	int searchcnt = 0;
	int search;

	printf("검색하고 싶은 상품의 무게 범위를 선택해주세요. \n");
	printf("1(0~100)\t2(101~200)\t3(201~300)\t4(301~400)\t... : ");
	scanf("%d", &search);
	for(int i = 0; i < index; i ++) {
		if((p[i].weight > (search-1)*100)&&(p[i].weight <= search*100)) {
			readProduct(p[i]);
			searchcnt ++;
		}
	}
	if(searchcnt == 0)
		printf("\n검색 결과가 없습니다.\n");
}

void searchProductPrice(Product *p, int index) {
	int searchcnt = 0;
	int search;

	printf("검색하고 싶은 상품의 가격대를 선택해주세요. \n");
	printf("1(0~10000)\t2(10001~20000)\t3(20001~300)\t4(30001~40000)\t... : ");
	scanf("%d", &search);
	for(int i = 0; i < index; i ++) {
		if((p[i].price > (search-1)*10000)&&(p[i].price <= search*10000)) {
			readProduct(p[i]);
			searchcnt ++;
		}
	}
	if(searchcnt == 0)
		printf("\n검색 결과가 없습니다.\n");
}

int saveData(Product *p, int index) {
	FILE *fp = fopen("product.txt", "wt");
	for(int i = 0; i < index; i ++) {
		if(strcmp(p[i].name, "noname") == 0)
			continue;
		fprintf(fp, "%s %d %d %d %d\n", p[i].name, p[i].weight, p[i].price, p[i].stars, p[i].numStars);
	}
	fclose(fp);
	return 1;
}

int loadData(Product *p) {
	int i;
	FILE *fp = fopen("product.txt", "rt");
	for(i = 0; i < 50; i ++){
		fscanf(fp, "%s", p[i].name);
		if(feof(fp))
			break;
		fscanf(fp, "%d %d %d %d", &p[i].weight, &p[i].price, &p[i].stars, &p[i].numStars);
	}
	fclose(fp);
	printf("파일을 성공적으로 로딩했습니다.\n\n");
	return i;
}

int selectMenu() {
	int menu;
	printf("\n=============== MENU LIST ===============\n");
	printf("1. 상품 추가\n");
	printf("2. 상품 보기\n");
	printf("3. 상품 정보 업데이트\n");
	printf("4. 상품 삭제\n");
	printf("5. 상품 이름으로 검색\n");
	printf("6. 상품 무게로 검색\n");
	printf("7. 상품 가격으로 검색\n");
	printf("8. 상품 리스트 저장\n");
	printf("9. 상품 리스트 로드\n");
	printf("0. 프로그램 종료\n");
	printf("=========================================\n");
	printf("\n=> 원하는 메뉴의 번호를 입력해주십시오.\n");
	scanf("%d", &menu);
	return menu;
}

int selectNumber(Product *p, int index) {
	int num;
	listProduct(p, index);
	printf("원하는 번호를 선택해주세요. (취소 : 0)\n");
	scanf("%d", &num);
	return num;
}

#endif
