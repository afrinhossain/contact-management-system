#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

int load_contacts(const char *filename, Contact **contacts);
void save_contacts(const char *filename, Contact **contacts, int contactCount);

#endif
