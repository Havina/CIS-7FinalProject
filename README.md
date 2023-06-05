### CIS-7 Final Project - READ ME (Program Explanation)

Team Hard Stuck College: Vigenere Cipher Decryption Final Project

Team Members: Hector Avina, Janelle Hamoy, Michael Hareu

Date of Publish: June 4, 2023

Due Date: June 8, 2023

Team Hardstuck College was tasked to solve the Vigenere Cipher problem, which the tasks were:
1.Given the above description of the Vigenère cipher, create a C++ program that encrypt and
decrypts a message from the user.
2. Test the program to verify that the output is accurate. Assess program limitations.


The solution that we are implementing for the project is of course writing a C++ program in the website compiler IDE replit. But to solve this problem we are going to be using modular arithmetic implemented in the code to encrypt/decrypt what the user inputs. To encrypt/decrypt user input, the program will create a new key to match the length and formatting of the message by accessing the key variable (a string) as an array. By accessing the message and key as an array, the encryption/decryption process is done incrementally. To encrypt/decrypt, the decimal value of the characters are manipulated through addition, subtraction, and with the modulo function. As well as to attempt to handle characters that are not included in the alphabet, the program will detect those invalid characters. If those characters are detected in the key, the program will prompt the user to change the detected character. However in the message the user would like to encrypt/decrypt, the invalid characters will just be skipped in the encrypting/decrypting process. 

The program begins with prompting the user with three options which are “Enter 1 for Encryption, Enter 2 for Decryption, Enter 3 to TERMINATE the program”. Option 1 is for encrypting a message that the user inputs, with their own key as well. Code gives the user their own encrypted message. Option 2 decrypts the message from option 1 based on what the user’s message as well as the key they used in order to successfully decrypt the message. Option 3 just terminates the program once they are done with the code and are satisfied with their encryptions/decryptions.
