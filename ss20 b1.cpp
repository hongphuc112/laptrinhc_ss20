#include <stdio.h>
#include <string.h>

typedef struct {
    char bookId[20];
    char title[100];
    char author[50];
    float price;
    char category[50];
} Book;

void inputBookInfo(Book books[], int *count);
void displayBooks(Book books[], int count);
void addBookAtPosition(Book books[], int *count);
void deleteBookById(Book books[], int *count);
void updateBookById(Book books[], int count);
void sortBooksByPrice(Book books[], int count, int pick);
void searchBookByTitle(Book books[], int count);

int main() {
    Book books[100];
    int count = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach.\n");
        printf("2. Hien thi thong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo ma sach.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep sach theo gia (tang/giam).\n");
        printf("7. Tim sach theo ten sach.\n");
        printf("8. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputBookInfo(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                addBookAtPosition(books, &count);
                break;
            case 4:
                deleteBookById(books, &count);
                break;
            case 5:
                updateBookById(books, count);
                break;
            case 6: {
                int pick;
                printf("1-Tang: \n");
                printf("2-Giam: \n");
                printf("Lua chon cua ban: ");
                scanf("%d", &pick);
                sortBooksByPrice(books, count, pick);
                break;
            }
            case 7:
                searchBookByTitle(books, count);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);
    return 0;
}

void inputBookInfo(Book books[], int *count) {
    printf("Nhap so luong sach: ");
    scanf("%d", count);
    for (int i = 0; i < *count; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", books[i].bookId);
        printf("Ten sach: ");
        getchar();
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = 0;
        printf("Tac gia: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;
        printf("Gia tien: ");
        scanf("%f", &books[i].price);
        printf("The loai: ");
        getchar();
        fgets(books[i].category, sizeof(books[i].category), stdin);
        books[i].category[strcspn(books[i].category, "\n")] = 0;
    }
}

void displayBooks(Book books[], int count) {
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < count; i++) {
        printf("\nSach %d:\n", i + 1);
        printf("Ma sach: %s\n", books[i].bookId);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].category);
    }
}

void addBookAtPosition(Book books[], int *count) {
    if (*count >= 100) {
        printf("Khong the them sach. Danh sach da du.\n");
        return;
    }
    int position;
    printf("Nhap vi tri muon them (0-%d): ", *count);
    scanf("%d", &position);
    if (position < 0 || position > *count) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = *count; i > position; i--) {
        books[i] = books[i - 1];
    }
    printf("Nhap thong tin sach moi:\n");
    printf("Ma sach: ");
    scanf("%s", books[position].bookId);
    printf("Ten sach: ");
    getchar();
    fgets(books[position].title, sizeof(books[position].title), stdin);
    books[position].title[strcspn(books[position].title, "\n")] = 0;
    printf("Tac gia: ");
    fgets(books[position].author, sizeof(books[position].author), stdin);
    books[position].author[strcspn(books[position].author, "\n")] = 0;
    printf("Gia tien: ");
    scanf("%f", &books[position].price);
    printf("The loai: ");
    getchar();
    fgets(books[position].category, sizeof(books[position].category), stdin);
    books[position].category[strcspn(books[position].category, "\n")] = 0;
    (*count)++;
}

void deleteBookById(Book books[], int *count) {
    char bookId[20];
    printf("Nhap ma sach muon xoa: ");
    scanf("%s", bookId);
    int flag = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(books[i].bookId, bookId) == 0) {
            flag = 1;
            for (int j = i; j < *count - 1; j++) {
                books[j] = books[j + 1];
            }
            (*count)--; 
            printf("Da xoa sach co ma %s.\n", bookId);
            break;
        }
    }
    if (flag==-1) {
        printf("Khong tim thay sach co ma %s.\n", bookId);
    }
}

void updateBookById(Book books[], int count) {
    char bookId[20];
    printf("Nhap ma sach muon cap nhat: ");
    scanf("%s", bookId);
    int flag = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].bookId, bookId) == 0) {
            flag = 1;
            printf("Nhap thong tin moi cho sach:\n");
            printf("Ten sach: ");
            getchar();
            fgets(books[i].title, sizeof(books[i].title), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = 0;
            printf("Tac gia: ");
            fgets(books[i].author, sizeof(books[i].author), stdin);
            books[i].author[strcspn(books[i].author, "\n")] = 0;
            printf("Gia tien: ");
            scanf("%f", &books[i].price);
            printf("The loai: ");
            getchar();
            fgets(books[i].category, sizeof(books[i].category), stdin);
            books[i].category[strcspn(books[i].category, "\n")] = 0;
            printf("Cap nhat thanh cong.\n");
            break;
        }
    }
    if (flag==-1) {
        printf("Khong tim thay sach co ma %s.\n", bookId);
    }
}

void sortBooksByPrice(Book books[], int count, int pick) {
    if (pick != 1 && pick != 2) {
        printf("Lua chon khong hop le\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (pick == 1) {
                if (books[i].price > books[j].price) {
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            } else if (pick == 2) {
                if (books[i].price < books[j].price) {
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }
    printf("Sap xep thanh cong.\n");
}

void searchBookByTitle(Book books[], int count) {
    char title[100];
    printf("Nhap ten sach muon tim: ");
    getchar();
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;

    int flag = -1;
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, title) != NULL) {
            if (flag==-1) {
                printf("\nKet qua tim kiem:\n");
            }
            flag = 1;
            printf("\nMa sach: %s\n", books[i].bookId);
            printf("Ten sach: %s\n", books[i].title);
            printf("Tac gia: %s\n", books[i].author);
            printf("Gia tien: %.2f\n", books[i].price);
            printf("The loai: %s\n", books[i].category);
        }
    }
    if (flag==-1) {
        printf("Khong tim thay sach phu hop.\n");
    }
}

