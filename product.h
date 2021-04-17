typedef struct _product {
    char name[50]; //상품명
    int weight; //상품무게
    int price; //상품가격
    int stars; //별점
    int numStars; //별점개수
} Product;
int createProduct(Product *p); //상품을 추가하는 함수
int readProduct(Product p); //상품을 읽어오는 함수
int updateProduct(Product *p); //상품 정보를 업데이트하는 함수
int deleteProduct(Product *p); //상품 정보를 삭제하는 함수
