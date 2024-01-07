#include <stdio.h>
#include <stdlib.h>

// Function declarations
void copy_two_char_array(char first[30], char second[30]);
void registration();
void menu();
void userLogin();
void login_checking(char l_email[30], char l_pass[20]);
void my_privilege(int user_id);
int compare_two_char_array(char first[30],char second[30]);
int size_of_charArray(char arr[30]);
int isEmail(char email[30]);
int isStrongPassword(char password[20]);
void user_info_change(int user_id);

// Global variables
int g_user_count = 0;
int g_login_check = -1;

// Structure declaration
struct User {
    int user_id;
    char user_name[30];
    char user_email[30];
    char user_pass[20];
    int phone_number;
    char address[50];
    int postal_code;
};

// Array to store user data, adjusted to allow up to 5 users
struct User user_data[5];

// Main function
int main() {
    menu();
    return 0;
}

// Main menu function
void menu() {
    while (1) {
        int option = 0;
        printf("\nWelcome to our System!\n");
        printf("Press 1 to Login \nPress 2 to Register \nPress 3 to Exit \nEnter:");

        if (scanf("%d", &option) != 1) {
            while (getchar() != '\n'); // Clear the input buffer
            printf("\nPlease Enter a Number!\n");
            continue;
        }

        switch (option) {
            case 1:
                userLogin();
                break;
            case 2:
                if (g_user_count < 5) {
                    registration();
                } else {
                    printf("\nMaximum number of users reached.\n");
                }
                break;
            case 3:
                printf("\nThanks for using our system!\n");
                exit(0);
            default:
                printf("\nSomething is Wrong. Try Again!\n");
        }
    }
}

// User registration function
#define MAX_USERS 5
void registration() {
    char r_username [30];
    char r_user_email [30];
    char r_user_password [20];
    int r_user_phone_number = 0;
    char r_address [30];
    int r_postal_code = 0;

    printf("\nThis is Registration Option for the users.\nDon't forget, the maximum user is 5.\n");
    for (int i = 0; i < MAX_USERS ; i++) {

        if (g_user_count >= MAX_USERS) {
            printf("Maximum number of users reached. \n Registration is closed.\n");
            break;
        }

        printf("\nRegistration Number: %d\n", i + 1);
        printf("Enter your username to register:");
        scanf(" %[^\n]", r_username);

        printf("Enter your email to register:");
        scanf(" %[^\n]", r_user_email);

        if (isEmail(r_user_email)) {
            printf("Email already exists. Please choose a different email.\n");
            i--;
            continue;
        }

        printf("Enter your password to register:");
        scanf(" %[^\n]", r_user_password);

        if (!isStrongPassword(r_user_password)) {
            printf("Password is not strong enough.\nPassword must be at least 6 Characters.\n"
                   "Please use a Combination of Capital letters, Small letters, Numbers and Special Characters.\n");
            i--;
            continue;
        }

        printf("Enter your phone number to register:");
        scanf(" %d", &r_user_phone_number);

        printf("Enter your Address to Register:");
        scanf(" %[^\n]",&r_address);

        printf("Enter your Postal code to Register:");
        scanf("%d",&r_postal_code);

        // Store registration data in the user_data array
        copy_two_char_array(user_data[g_user_count].user_name, r_username);
        copy_two_char_array(user_data[g_user_count].user_email, r_user_email);
        copy_two_char_array(user_data[g_user_count].user_pass, r_user_password);
        user_data[g_user_count].phone_number = r_user_phone_number;
        copy_two_char_array(user_data[g_user_count].address,r_address);
        user_data[g_user_count].postal_code = r_postal_code;
        user_data[g_user_count].user_id = g_user_count;
        g_user_count++;
    }

    // Output all registrations
    printf("\nAll Registrations:\n");
    for (int i = 0; i < g_user_count; i++) {
        printf("\nRegistration: %d\n", i + 1);
        printf("Username: %s\n", user_data[i].user_name);
        printf("Email: %s\n", user_data[i].user_email);
        printf("Password: %s\n", user_data[i].user_pass);
        printf("Phone Number: %d\n", user_data[i].phone_number);
        printf("Address : %s\n",user_data[i].address);
        printf("Postal Code: %d\n",user_data[i].postal_code);
    }
}

// Function to check if an email already exists
int isEmail(char email[30]) {
    for (int i = 0; i < g_user_count; i++) {
        if (compare_two_char_array(user_data[i].user_email, email)) {
            return 1; // Email already exists
        }
    }
    return 0; // Email does not exist
}

// Function to check if a password is strong
int isStrongPassword(char password[20]) {
    int hasCapital = 0;
    int hasSmall = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    int passwordLength = size_of_charArray(password);

    // Check the length of the password
    if (passwordLength < 6) {
        return 0; // Password is not strong enough
    }

    for (int i = 0; i < passwordLength; i++) {
        char ch = password[i];

//        // Check for capital letters
//        if (ch >= 'A' && ch <= 'Z') {
//            hasCapital = 1;
//        }

        // Check for capital letters (ASCII values: A-Z)
        if (ch >= 65 && ch <= 90) {
            hasCapital = 1;
        }

//        // Check for small letters
//        if (ch >= 'a' && ch <= 'z') {
//            hasSmall = 1;
//        }

        // Check for small letters (ASCII values: a-z)
        if (ch >= 97 && ch <= 122) {
            hasSmall = 1;
        }

//        // Check for numbers from 0 to 9
//        if (ch >= '0' && ch <= '9') {
//            hasNumber = 1;
//        }

        // Check for numbers (ASCII values: 0-9)
        if (ch >= 48 && ch <= 57) {
            hasNumber = 1;
        }

        // Check for special characters
//        if (ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%'
//        || ch == '^' || ch == '&' || ch == '*' || ch == '?' || ch == '_') {
//            hasSpecialChar = 1;
//        }

        // Check for special characters using ASCII values
        if ((ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126)) {
            hasSpecialChar = 1;
        }

    }

    return (hasCapital && hasSmall && hasNumber && hasSpecialChar);
}


// User login function
void userLogin() {
    char l_email[30];
    char l_password[20];

    if(g_user_count == 0){
        printf("\nNo users are registered. Please register first!\n");
        menu();
        return;
    }

    printf("\nLogin to your account!\n");
    printf("Enter your email:");
    scanf(" %[^\n]", l_email);
    printf("Enter your password:");
    scanf(" %[^\n]", l_password);

    login_checking(l_email, l_password);

    if (g_login_check != -1) {
        printf("\nLogin successful!\nYour ID is %d.\n", g_login_check);
        my_privilege(g_login_check);
    } else {
        printf("\nLogin failed!\n");
        menu();
    }
}

// Check user login credentials
void login_checking(char l_email[30], char l_pass[20]) {
    g_login_check = -1;

    for (int i = 0; i < g_user_count; i++) {
        if (compare_two_char_array(user_data[i].user_email, l_email) == 1 &&
            compare_two_char_array(user_data[i].user_pass, l_pass) == 1) {
            g_login_check = user_data[i].user_id;
            break;
        }
    }
}

// Function to display user privileges after successful login
void my_privilege(int user_id) {
    printf("Welcome, %s!\n", user_data[user_id].user_name);
    printf("Your Phone Number is %d.\n", user_data[user_id].phone_number);

    int m_option = -1;
    printf("\nWhat you want to do!\n");
    printf("Press 0 to Exit.\nPress 1 to Menu.\nPress 2 to Change User Information.\nEnter:");

    scanf("%d", &m_option);

    switch (m_option) {
        case 0:
            exit(1);
            break;
        case 1:
            menu();
            break;
        case 2:
            user_info_change(user_id);
            break;
        default:
            printf("Invalid Option Number:\n");
            my_privilege(user_id);
    }
}

// Function to change user information
void user_info_change(int user_id) {
    int change_option = 0;
    char new_value[30]; //Temporary array to store new values

    printf("\nPress 1: To change Name.\nPress 2: To change Email.\n");
    printf("Press 3: To change Password.\nPress 4: To change PhoneNumber.\n");
    printf("Press 5: To change Address.\nPress 6: To change PostCode.\n");
    printf("Press 7: For your privilege.\nEnter:");
    scanf("%d", &change_option);

    switch (change_option) {
        case 1: {
            printf("To change name:\n");
            printf("This is your user name: %s\n", user_data[user_id].user_name);

            printf("Enter your new user name:");
            scanf(" %[^\n]", new_value);

            copy_two_char_array(user_data[user_id].user_name, new_value);
            printf("This is your new user name: %s\n", user_data[user_id].user_name);
            break;
        }
        case 2: {
            printf("To change email:\n");
            printf("This is your email: %s\n", user_data[user_id].user_email);

            printf("Enter your new email:");
            scanf(" %[^\n]", new_value);

            copy_two_char_array(user_data[user_id].user_email, new_value);
            printf("This is your new email: %s\n", user_data[user_id].user_email);
            break;
        }
        case 3:{
            printf("To change password:\n");
            printf("This is your password: %s\n", user_data[user_id].user_pass);

            printf("Enter your new password:");
            scanf(" %[^\n]", new_value);

            copy_two_char_array(user_data[user_id].user_pass, new_value);
            printf("Password changed successfully!\n");
            break;
        }
        case 4: {
            printf("To change phone number:\n");
            printf("This is your phone number: %d\n", user_data[user_id].phone_number);

            printf("Enter your new phone number:");
            scanf(" %d", &user_data[user_id].phone_number);
            printf("This is your new phone number: %d\n", user_data[user_id].phone_number);
            break;
        }
        case 5: {
            printf("To change address:\n");
            printf("This is your address: %s\n", user_data[user_id].address);

            printf("Enter your new address:");
            scanf(" %[^\n]", new_value);

            copy_two_char_array(user_data[user_id].address, new_value);
            printf("This is your new address: %s\n", user_data[user_id].address);
            break;
        }
        case 6: {
            printf("To change postal code:\n");
            printf("This is your postal code: %d\n", user_data[user_id].postal_code);

            printf("Enter your new postal code:");
            scanf("%d", &user_data[user_id].postal_code);
            printf("This is your new postal code: %d\n", user_data[user_id].postal_code);
            break;
        }
        case 7: {
            my_privilege(user_id); // Go back to user privileges
            break;
        }
        default:
            printf("Invalid Option Number:\n");
            user_info_change(user_id);
    }
}

// Function to copy one character array to another
void copy_two_char_array(char first[30], char second[30]) {
    int i = 0;
    while (second[i] != '\0' && i < 30) {
        first[i] = second[i];
        i++;
    }
}

// Function to compare two character arrays for equality
int compare_two_char_array(char first[30],char second[30]){

    int size1 = size_of_charArray(first);
    int size2 = size_of_charArray(second);
    int sameCount = 0;
    if( size1 == size2){
        for(int i = 0; i < size1; i++){

            if(first[i] == second[i]){
                sameCount++;
            }
        }
    }
    if(size1 == sameCount){
        return 1;
    } else{
        return 0;
    }
}

// Function to calculate the size or length of a character array
int size_of_charArray(char arr[30]){
    int size = 0;
    for(int i = 0; i < 30 ; i++){

        if(arr[i] == '\0'){
            break;
        }
        size++;
    }

    return size;
}
