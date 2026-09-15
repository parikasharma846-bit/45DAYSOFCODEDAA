//10. ATM Transaction System
//• Create a menu-driven program to check balance, deposit money, withdraw money, and exit.
//• Prevent a withdrawal when the balance is insufficient.
//• Maintain and display the last five transactions.

#include <stdio.h>

int main() {
    float balance = 1000.0, amount;
    int choice, count = 0, i;
    char transactions[5][50];

    do {
        printf("\n--- ATM MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Last 5 Transactions\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Balance = %.2f\n", balance);
            break;

        case 2:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            balance += amount;

            if (count < 5) {
                sprintf(transactions[count], "Deposited %.2f", amount);
                count++;
            }

            printf("Money deposited successfully.\n");
            break;

        case 3:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= balance) {
                balance -= amount;

                if (count < 5) {
                    sprintf(transactions[count],
                            "Withdrawn %.2f", amount);
                    count++;
                }

                printf("Withdrawal successful.\n");
            } else {
                printf("Insufficient balance!\n");
            }
            break;

        case 4:
            printf("\n--- LAST FIVE TRANSACTIONS ---\n");

            if (count == 0) {
                printf("No transactions.\n");
            } else {
                for (i = 0; i < count; i++)
                    printf("%d. %s\n", i + 1, transactions[i]);
            }
            break;

        case 5:
            printf("Thank you for using ATM.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}