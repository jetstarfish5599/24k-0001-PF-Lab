// Name:Masoom Khan Roll#24k-0001         LAB:7 Q:3
#include <stdio.h>

// functions for character checks
int is_alpha(char c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); }
int is_digit(char c) { return (c >= '0' && c <= '9'); }

// Valid check functions for name,email and number respectively
int validate_name(char name[]) {
    for (int i = 0; name[i] != '\0'; i++)
        if (!is_alpha(name[i]) && name[i] != ' ') return 0;
    return 1;
}

int validate_email(char email[]) {
    int at_found = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        char c = email[i];
        if (is_alpha(c) || is_digit(c) || c == '.' || c == '_' || c == '-') continue;
        if (c == '@' && !at_found) at_found = 1;
        else return 0;
    }
    return at_found;
}

int validate_phone(char phone[]) {
    for (int i = (phone[0] == '+' ? 1 : 0); phone[i] != '\0'; i++)
        if (!is_digit(phone[i]) && phone[i] != '-' && phone[i] != ' ') return 0;
    return 1;
}
//start main
int main() {
    // assign functional arrays
    char name[100], email[100], phone[100];

    // Input name
    printf("Enter your name: ");
    scanf("%99[^\n]%*c", name); 
    // Input email
    printf("Enter your email: ");
    scanf("%99s", email); 
    // Input phone number
    printf("Enter your phone number: ");
    scanf("%99s", phone); 
    // Validate inputs
    if (!validate_name(name))  printf("Invalid name.\n");
    else if (!validate_email(email))  printf("Invalid email.\n");
    else if (!validate_phone(phone))  printf("Invalid phone number.\n");
    else printf("All inputs are valid!\n");

    return 0;
}
