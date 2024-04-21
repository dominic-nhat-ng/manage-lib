#include <stdio.h>
#include <string.h>
#include "preprocessing.h"

void list_readers(Reader_info *readers, int num_readers)
{
    printf("========================================================\n");

    printf("List of readers:\n");
    printf("\n");
    for (int i = 0; i < num_readers; i++)
    {
        printf("Reader %d:\n", i + 1);
        printf("Reader code: %s\n", readers[i].reader_code);
        printf("Fullname: %s\n", readers[i].fullname);
        printf("ID card: %s\n", readers[i].id_card);
        printf("Birth date: %d/%d/%d\n", readers[i].birth_date.date, readers[i].birth_date.month, readers[i].birth_date.year);
        printf("\n");
    }
    printf("========================================================\n");
}

void add_reader(Reader_info *readers, int *num_readers)
{
    int c;
    printf("Enter reader code: ");
    scanf("%s", readers[*num_readers].reader_code);
    printf("Full name: ");
    while ((c = getchar()) != '\n' && c != EOF); // consume the newline left by scanf
    fgets(readers[*num_readers].fullname, sizeof(readers[*num_readers].fullname), stdin);
    readers[*num_readers].fullname[strcspn(readers[*num_readers].fullname, "\n")] = 0; // remove newline character
    printf("Enter ID card: ");
    scanf("%s", readers[*num_readers].id_card);
    printf("Enter birth date: ");
    scanf("%d/%d/%d", &readers[*num_readers].birth_date.date, &readers[*num_readers].birth_date.month, &readers[*num_readers].birth_date.year);
    (*num_readers)++;
}

void edit_reader(Reader_info *reader)
{
    printf("Enter new reader code: ");
    scanf("%s", reader->reader_code);
    printf("Enter new fullname: ");
    scanf("%s", reader->fullname);
    printf("Enter new ID card: ");
    scanf("%s", reader->id_card);
    printf("Enter new birth date: ");
    scanf("%d/%d/%d", &reader->birth_date.date, &reader->birth_date.month, &reader->birth_date.year);
}

// void delete_reader(Reader_info *readers, int *num_readers)
// {
//     for (int i = 0; i < *num_readers; i++)
//     {
//         if (strcmp(readers[i].id_card, id_card) == 0)
//         {
//             for (int j = i; j < *num_readers - 1; j++)
//             {
//                 readers[j] = readers[j + 1];
//             }
//             (*num_readers)--;
//             break;
//         }
//     }
// }