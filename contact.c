#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

void add_contact(const char *name, const char *email, const char *phone, Contact **contacts, int *contactCount) {
    if (*contactCount < MAX_CONTACTS) {
        Contact *newContact = (Contact *)malloc(sizeof(Contact));
        if (newContact == NULL) {
            perror("Error allocating memory for contact");
            exit(EXIT_FAILURE);
        }

        strncpy(newContact->name, name, MAX_NAME_LENGTH - 1);
        newContact->name[MAX_NAME_LENGTH - 1] = '\0';

        strncpy(newContact->email, email, MAX_EMAIL_LENGTH - 1);
        newContact->email[MAX_EMAIL_LENGTH - 1] = '\0';

        strncpy(newContact->phone, phone, MAX_PHONE_LENGTH - 1);
        newContact->phone[MAX_PHONE_LENGTH - 1] = '\0';

        contacts[*contactCount] = newContact;
        (*contactCount)++;
    } else {
        printf("Contact limit reached. Cannot add more contacts.\n");
    }
}

void display_contacts(Contact **contacts, int contactCount) {
    printf("Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Name: %s\n", contacts[i]->name);
        printf("Email: %s\n", contacts[i]->email);
        printf("Phone: %s\n", contacts[i]->phone);
        printf("-------------------\n");
    }
}

void free_contacts(Contact **contacts, int contactCount) {
    for (int i = 0; i < contactCount; i++) {
        free(contacts[i]);
    }
}
