#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    int age;
};

const char *DATA_FILE = "contacts.dat";

void add_contact() {
    struct Contact c;
    printf("Enter name: ");
    scanf("%49s", c.name);
    printf("Enter age: ");
    scanf("%d", &c.age);

    FILE *file = fopen(DATA_FILE, "a");
    if (!file) {
        printf("Error: could not open %s\n", DATA_FILE);
        return;
    }
    fprintf(file, "%s %d\n", c.name, c.age);
    fclose(file);
    printf("Contact added: %s, %d\n", c.name, c.age);
}

void view_contacts() {
    struct Contact c;
    FILE *file = fopen(DATA_FILE, "r");
    if (!file) {
        printf("No contacts found.\n");
        return;
    }

    printf("--- Contact List ---\n");
    while (fscanf(file, "%49s %d", c.name, &c.age) == 2) {
        printf("%s, %d\n", c.name, c.age);
    }
    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\n1. Add Contact\n2. View Contacts\n3. Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 3);

    return 0;
}
