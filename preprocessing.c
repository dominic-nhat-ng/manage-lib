#include <stdio.h>
#include <stdlib.h>
#include "preprocessing.h"

void set_expiration_date(Reader_info *card)
{
    card->card_expiration_date.date = card->card_creation_date.date;
    card->card_expiration_date.month = card->card_creation_date.month;
    card->card_expiration_date.year = card->card_creation_date.year + 4;
}

static int calculate_days(Date start, Date end)
{
    return (end.year - start.year) * 365 + (end.month - start.month) * 30 + (end.date - start.date);
}

int calculate_fine(LoanTicket *ticket)
{
    int days_late = calculate_days(ticket->return_date_expected, ticket->return_date_actual);
    if (days_late > 0){
        return days_late * 5000;
    }
    else{
        return 0;
    }
}

int calculate_lost_book_fine(Book *book)
{
    return book->price*2;
}