### CSC7 Final Project - READ ME (Program Explanation)

Team Hard Stuck College: Vigenere Cipher Decryption Final Project

Team Members: Hector Avina, Janelle Hamoy, Michael Hareu

Date of Publish: June 4, 2023

Due Date: June 8, 2023

Team Hardstuck College was tasked to solve the Vigenere Cipher problem, which the tasks were:
1.Given the above description of the Vigenère cipher, create a C++ program that encrypt and
decrypts a message from the user.
2. Test the program to verify that the output is accurate. Assess program limitations.


The solution that we are implementing for the project is of course writing a C++ program in the website compiler IDE replit. But to solve this problem we are going to be using modular arithmetic implemented in the code to encrypt/decrypt what the user inputs. To encrypt/decrypt user input, the program will create a new key to match the length and formatting of the message by accessing the key variable (a string) as an array. By accessing the message and key as an array, the encryption/decryption process is done incrementally. To encrypt/decrypt, the decimal value of the characters are manipulated through addition, subtraction, and with the modulo function. As well as to attempt to handle characters that are not included in the alphabet, the program will detect those invalid characters. If those characters are detected in the key, the program will prompt the user to change the detected character. However in the message the user would like to encrypt/decrypt, the invalid characters will just be skipped in the encrypting/decrypting process. 

Some basic instructions is that the user is prompt
