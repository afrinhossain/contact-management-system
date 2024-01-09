#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"
#include "contact.h"

int load_contacts(const char *filename, Contact **contacts) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    int contactCount = 0;
    while (fscanf(file, "%49s %49s %14s", contacts[contactCount]->name,
                  contacts[contactCount]->email, contacts[contactCount]->phone) == 3) {
        Contact *newContact = (Contact *)malloc(sizeof(Contact));
        if (newContact == NULL) {
            perror("Error allocating memory for contact");
            exit(EXIT_FAILURE);
        }
        contacts[contactCount] = newContact;
        contactCount++;
    }

    fclose(file);
    return contactCount;
}

void save_contacts(const char *filename, Contact **contacts, int contactCount) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < contactCount; i++) {
        fprintf(file, "%s %s %s\n", contacts[i]->name, contacts[i]->email, contacts[i]->phone);
    }

    fclose(file);
}
