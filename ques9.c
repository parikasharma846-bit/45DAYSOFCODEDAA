//9. Library Book Management
//• Store the book ID, title, author, total copies, and available copies using structures.
//• Create a menu-driven program to add and search for books, issue and return books, and display
//all books currently unavailable.
#include <stdio.h>

struct Book { // Define a structure to store book information
    int id;
    char title[50];
    char author[50];
    int totalCopies;
    int availableCopies;
};

int main() {
    struct Book b[50];
    int n = 0, choice, id, i, found;

    do {  // Loop until the user chooses to exit
        printf("\n--- LIBRARY MENU ---\n");  // Display the menu options
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Unavailable Books\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {  // Handle the user's choice using a switch statement

        case 1:
            printf("Enter Book ID: ");
            scanf("%d", &b[n].id);

            printf("Enter Title: ");
            scanf(" %[^\n]", b[n].title);

            printf("Enter Author: ");
            scanf(" %[^\n]", b[n].author);

            printf("Enter Total Copies: ");
            scanf("%d", &b[n].totalCopies);

            b[n].availableCopies = b[n].totalCopies;
            n++;

            printf("Book added successfully.\n");
            break;

        case 2:
            printf("Enter Book ID: ");
            scanf("%d", &id);
            found = 0;

            for (i = 0; i < n; i++) {
                if (b[i].id == id) {
                    printf("Title: %s\n", b[i].title);
                    printf("Author: %s\n", b[i].author);
                    printf("Available: %d\n", b[i].availableCopies);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book not found.\n");
            break;

        case 3:
            printf("Enter Book ID: ");
            scanf("%d", &id);

            for (i = 0; i < n; i++) {
                if (b[i].id == id) {
                    if (b[i].availableCopies > 0) {
                        b[i].availableCopies--;
                        printf("Book issued.\n");
                    } else {
                        printf("Book unavailable.\n");
                    }
                    break;
                }
            }
            break;

        case 4:
            printf("Enter Book ID: ");
            scanf("%d", &id);

            for (i = 0; i < n; i++) {
                if (b[i].id == id) {
                    if (b[i].availableCopies < b[i].totalCopies) {
                        b[i].availableCopies++;
                        printf("Book returned.\n");
                    } else {
                        printf("All copies are already available.\n");
                    }
                    break;
                }
            }
            break;

        case 5:
            printf("\nUnavailable Books:\n");

            for (i = 0; i < n; i++) {
                if (b[i].availableCopies == 0)
                    printf("%d - %s\n", b[i].id, b[i].title);
            }
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
