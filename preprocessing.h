#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int date;
    int month;
    int year;
} Date;

typedef struct
{
    char reader_code[10];
    char fullname[30];
    char id_card[20];
    Date birth_date;
    int gender;
    char email[30];
    char address[50];
    Date card_creation_date;
    Date card_expiration_date;
} Reader_info;

typedef struct
{
    char book_code[10];
    char book_name[50];
    char author[30];
    char publisher[30];
    char book_type[20];
    int year_publish;
    int price;
    int number_of_books;
} Book;

typedef struct
{
    Reader_info reader_info; 
    Date borrow_date;
    Date return_date_expected;
    Date return_date_actual;
    Book borrowed_books[10];
} LoanTicket; 

void set_expiration_date(Reader_info *card);
// int calculate_days(Date start, Date end);
int calculate_fine(LoanTicket *ticket);
int calculate_lost_book_fine(Book *book);