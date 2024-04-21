#include <stdio.h>
void list_readers(Reader_info *readers, int num_readers);
void add_reader(Reader_info *readers, int *num_readers);
void edit_reader(Reader_info *reader);
void delete_reader(Reader_info *readers, int *num_readers, char *id_card);