int listProduct(Product *p, int index); //등록된 상품을 index만큼 보여주는 함수
void searchProductName(Product *p, int index); //상품 이름으로 검색하는 함수
void searchProductWeight(Product *p, int index); //상품 무게로 검색하는 함수
void searchProductPrice(Product *p, int index); //상품 가격대로 검색하는 함수
int saveData(Product *p, int index); //파일 저장 함수
int loadData(Product *p); //파일을 불러오는 함수
int selectMenu(); //메뉴를 선택하는 함수
