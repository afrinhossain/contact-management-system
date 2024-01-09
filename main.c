#include <stdio.h>
#include "contact.h"
#include "file_operations.h"

int main() {
    // Create an array to hold contacts
    Contact *contacts[MAX_CONTACTS];
    int contactCount = 0;

    // Load contacts from file
    contactCount = load_contacts("contacts.txt", contacts);

    // Example usage of contact and file operations
    add_contact("John Doe", "john.doe@email.com", "123-456-7890", contacts, &contactCount);
    add_contact("Jane Smith", "jane.smith@email.com", "987-654-3210", contacts, &contactCount);

    // Display all contacts
    display_contacts(contacts, contactCount);

    // Save contacts to file
    save_contacts("contacts.txt", contacts, contactCount);

    // Free allocated memory
    free_contacts(contacts, contactCount);

    return 0;
}