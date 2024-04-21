#include <stdio.h>
#include <string.h>
#include "preprocessing.h"
#include "reader_management.h"

int main()
{
    Reader_info readers[100];
    int num_readers = 0;

    add_reader(readers, &num_readers);

    while(1)
    {
        printf("1. List readers\n");
        printf("2. Add reader\n");
        printf("3. Edit reader\n");
        printf("4. Delete reader\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            list_readers(readers, num_readers);
            break;
        case 2:
            add_reader(readers, &num_readers);
            break;
        case 3:
            edit_reader(readers);
            break;
        case 4:
            // delete_reader(readers, &num_readers);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}