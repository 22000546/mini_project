#ifndef _product_h
#define _product_h

#include <stdio.h>
#include <string.h>
#include "product.h"

int createProduct(Product *p){
    printf("이름 : ");
    scanf("%s", p->name);
    getchar();
    printf("무게 : ");
    scanf("%d", &p->weight);
    printf("가격 : ");
    scanf("%d", &p->price);
    printf("별점 : ");
    scanf("%d", &p->stars);
    printf("별점 수 : ");
    scanf("%d", &p->numStars);
    return 1;
}

int readProduct(Product p){
    printf("이름 : %s\t", p.name);
    printf("무게 : %d\t", p.weight);
    printf("가격 : %d\t", p.price);
    printf("별점(별점 수) : %d(%d)\t", p.stars, p.numStars);
    printf("\n");
    return 1;
}

int updateProduct(Product *p){
    printf("이름 : ");
    scanf("%s", p->name);
    getchar();
    printf("무게 : ");
    scanf("%d", &p->weight);
    printf("가격 : ");
    scanf("%d", &p->price);
    printf("별점 : ");
    scanf("%d", &p->stars);
    printf("별점 수 : ");
    scanf("%d", &p->numStars);
    return 1;
}

int deleteProduct(Product *p){
    strcpy(p->name, "noname");
    p->weight = 0;
    p->price = 0;
    p->stars = 0;
    p->numStars = 0;
    return 1;
}

#endif
