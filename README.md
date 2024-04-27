# Simple Password Manager

This is a simple command-line password manager written in C.
This project was developed as part of the ACES C-Project Demonstration.

## Team Members

- [Manish Pandey](https://github.com/manishpandey68)
- [Abhishek Singh](https://github.com/)
- [Shishir Aryal](https://github.com/)
- [Shishir Budhathoki](https://github.com/)

## Features

- **Add New Password**: Allow users to add new passwords, including the account type, username, and password.
- **View Stored Passwords**: Display all stored passwords along with their account types and usernames.
- **Update Password**: Enable users to update the username or password of an existing entry.
- **Delete Password**: Allow users to delete a password entry from the storage.
- **Save Passwords to File**: Implement functionality to save all passwords to a file for persistence.
- **Load Passwords from File**: Provide the ability to load previously saved passwords from a file on program startup.
- **Security Measures**: Implement basic security measures such as checking for maximum password count and file handling errors.

## File Structure

- `main.c`: Contains the main function and orchestrates the overall flow of the program.
- `passwordmanager.c`: Implements password management functionalities.
- `passwords.txt`: Stores the passwords in plain text format.


## Usage

### Cloning and Building the Code

To clone and build the password manager code, follow these steps:

1. **Clone the Repository:**

   ```bash
   https://github.com/manishpandey68/Simple-Password-Manager-in-C
   cd Simple-Password-Manager-in-C
   ```

2. **Build the Code:**
   Use the following command to compile the source files using `gcc`:

   ```bash
   gcc passwordmanager.c
   ```

3. **Run Code:**
   After successfully building the code, you can run the compiled executable:
   ```bash
   .\passwordmanager
   ```
   or if you're on Windows:
   ```bash
   passwordmanager.exe
   ```

## Basic Workflow

1. **Adding a New Password**:
   - Select option 1 from the menu to add a new password.
   - Enter the account type (e.g., Facebook, Instagram, Other).
   - Enter the username.
   - Enter the password.

2. **Viewing Stored Passwords**:
   - Select option 2 from the menu to view all stored passwords.
   - Passwords are displayed along with their index, account type, username, and password.

3. **Updating a Password**:
   - Select option 3 from the menu to update an existing password.
   - Enter the index of the password you want to update.
   - Enter the new username.
   - Enter the new password.

4. **Deleting a Password**:
   - Select option 4 from the menu to delete a password.
   - Enter the index of the password you want to delete.

5. **Saving Passwords to File**:
   - Select option 5 from the menu to save all passwords to a file named `passwords.txt`.
   - Passwords are saved in the format: `username:password`.

6. **Exiting the Program**:
   - Select option 6 from the menu to exit the program.

Remember to press any key to continue after each operation.
