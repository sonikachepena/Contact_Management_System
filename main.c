#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15

// Define the structure for a contact
struct Contact {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_LENGTH];
    char emailAddress[MAX_EMAIL_LENGTH];
};

// Global array to store contacts
struct Contact contacts[MAX_CONTACTS];
int numContacts = 0;  // Keeps track of the number of contacts in the array

// Function prototypes
void addContact();
void deleteContact();
void searchContact();
void displayContacts();

int main() {
    int choice;

    do {
        // Display menu options
        printf("\nContact Management System\n");
        printf("1. Add a new contact\n");
        printf("2. Delete a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void addContact() {
    if (numContacts < MAX_CONTACTS) {
        struct Contact newContact;
        printf("Enter first name: ");
        scanf("%s", newContact.firstName);
        printf("Enter last name: ");
        scanf("%s", newContact.lastName);
        printf("Enter phone number: ");
        scanf("%s", newContact.phoneNumber);
        printf("Enter email address: ");
        scanf("%s", newContact.emailAddress);

        contacts[numContacts++] = newContact;
        printf("Contact added successfully.\n");
    } else {
        printf("Cannot add more contacts. Maximum limit reached.\n");
    }
}

void deleteContact() {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter first name of contact to delete: ");
    scanf("%s", firstName);
    printf("Enter last name of contact to delete: ");
    scanf("%s", lastName);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].firstName, firstName) == 0 &&
            strcmp(contacts[i].lastName, lastName) == 0) {
            // Shift all subsequent elements one position to the left
            for (int j = i; j < numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            numContacts--;
            found = 1;
            printf("Contact deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void searchContact() {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter first name of contact to search: ");
    scanf("%s", firstName);
    printf("Enter last name of contact to search: ");
    scanf("%s", lastName);

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].firstName, firstName) == 0 &&
            strcmp(contacts[i].lastName, lastName) == 0) {
            printf("Contact found:\n");
            printf("First Name: %s\n", contacts[i].firstName);
            printf("Last Name: %s\n", contacts[i].lastName);
            printf("Phone Number: %s\n", contacts[i].phoneNumber);
            printf("Email Address: %s\n", contacts[i].emailAddress);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayContacts() {
    if (numContacts == 0) {
        printf("No contacts to display.\n");
    } else {
        printf("List of contacts:\n");
        for (int i = 0; i < numContacts; i++) {
            printf("%d. %s %s, %s, %s\n", i + 1, contacts[i].firstName, contacts[i].lastName,
                   contacts[i].phoneNumber, contacts[i].emailAddress);
        }
    }
}
