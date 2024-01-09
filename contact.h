#ifndef CONTACT_H
#define CONTACT_H

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void add_contact(const char *name, const char *email, const char *phone, Contact **contacts, int *contactCount);
void display_contacts(Contact **contacts, int contactCount);
void free_contacts(Contact **contacts, int contactCount);

#endif
