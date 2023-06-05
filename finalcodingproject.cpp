//CSC-7 Team Hard Stuck College: Vigenere Cipher Decryption Final Project
//Hector Avina, Janelle Hamoy, Michael Hareu

#include <iostream>
#include <string>

using namespace std;

//This function will make all the letters in user message uppercase
void validateMsg (string &userMsg)
{
  for (int i = 0; i < userMsg.size(); i++)
  {
      if (islower(userMsg[i]))
        userMsg[i] = toupper(userMsg[i]);
  }
}

//This function will make all the letters in user key uppercase
//and lets the user replace invalid characters
void validateKey (string &userKey, string userMsg)
{
  for (int i = 0; i < userKey.size(); i++)
  {
    while (userKey[i] < 'A' || userKey[i] > 'z')
    {
      cout << endl;
      cout << "You have entered: '" << userKey[i] << "' in your key." << endl;
      cout << "This is an invalid character. Please only enter letters." << endl;
      cout << "Enter a valid letter you would like to replace '";
      cout << userKey[i] << "' with" << endl;
      cout << "ENTER HERE: ";
      cin >> userKey[i];
      cout << endl;
    }
    
    if (islower(userKey[i]))
      userKey[i] = toupper(userKey[i]);  
  }
}

//Creates new key to be same length as user message
//also inserts spaces into key where there are invalid characters in
//user message
string keyAdjustment (string &msg, string &key)
{
  string tmp = key;
  int keySize = key.size();
  int msgSize = msg.size();
  int i = 0;
    
  //Creating new key if key is smaller than message
  while (key.size() < msg.size())
  {
    key.push_back(key[i]);
    ++i;

    if (i == key.size())
      i = 0;
  }

  //Creating new key if key is bigger than the message
  while (key.size() > msg.size())
  {
    key.pop_back();
  }
  
  //inserting spaces into key
  for (int i = 0; i < msg.size(); i++)
  {
    if (msg[i] < 'A' || msg[i] > 'z')
      key[i] = ' ';
  }
  
  return key;
}

//Encryption
string encryptVigenere (string msg, string key, string newKey)
{
  int encryptedVal;
  string encryptedMsg = "";
  
  //implementation for encrypting! (yaaay)
  for (int i = 0; i < msg.size(); i++)
  {
    if (msg[i] < 'A' || msg[i] > 'z')
      ++i;
    else
    {
      encryptedVal = ((msg[i] + newKey[i]) % 26) + 65;   
      encryptedMsg.push_back(encryptedVal);
    }
  }

  return encryptedMsg; 
}

//Decryption
string decryptVigenere (string msg, string key, string newKey)
{
  int decryptedVal;
  string decryptedMsg = "";
  
  for (int i = 0; i < msg.size(); i++)
  {
    // skipping over special characters
    if (msg[i] < 'A' || msg[i] > 'Z')
      ++i;
    else
    {
      decryptedVal = ((msg[i] - newKey[i] + 26) % 26) + 65;
      decryptedMsg.push_back(decryptedVal);
    }
  }

  return decryptedMsg;
}

int main() {
  
  
  std::cout << ". 　　　。　　　　•　 　ﾟ　　。 　　. \n";
  std::cout << "　　　.　　　 　　.　　　　　。　　 。　. 　\n";
  std::cout << ".　　 。　　　　　 ඞ 。 . 　　 • 　　　　•\n";
  std::cout << "　　ﾟ　　 Blue was not An Impostor.　 。　.\n";
  std::cout << "　　'　　　     2 Impostors remain 　 　　。\n";
  std::cout << "　　ﾟ　　　.　　　. ,　　　　.　 .\n\n";


  //variables
  char userChoice;
  string userMsg;
  string userKey;
  string newKey;
  
  cout << "Welcome to team Hardstuck College's Vigenere Cipher\n";
  cout << "Decryption and Encryption Program!" << endl << endl;
  
  do {
    //prompting the user with a menu
    cout << "You have three options :" << endl;
    cout << "---------------------------------" << endl;
    cout << "Enter 1 for Encryption," << endl;
    cout << "Enter 2 for Decryption," << endl;
    cout << "Enter 3 to TERMINATE the program." << endl;
    cout << "---------------------------------" << endl;
    cout << "ENTER CHOICE HERE: " << endl;
    cin >> userChoice; 
    cin.ignore();
    cout << endl;
    
    while (userChoice < '1' || userChoice > '3')
    {
      cout << "You did not enter a valid choice. Enter a number" << endl;
      cout << "between 1 - 3: ";
      cin >> userChoice;
      cin.ignore();
      cout << endl;
    }

    //why are there errors in the comparrison thingy omg
    if (userChoice == '1')
    {
      cout << "Enter a message you would like to encrypt." << endl;
      cout << "ENTER MESSAGE HERE: ";
      getline(cin, userMsg);
      cout << endl;
      validateMsg(userMsg);
      
      cout << "Enter the key you would like to encrypt" << endl;
      cout << "your message with." << endl;
      cout << "ENTER KEY HERE: ";
      getline(cin, userKey);
      validateKey(userKey, userMsg);

      newKey = keyAdjustment(userMsg, userKey);

      //OUTPUT RESULTS
      cout << "New key: " << newKey << endl;
      string encryptedMsg = encryptVigenere(userMsg, userKey, newKey);
      cout << endl;
      cout << "Encrypted message: " << encryptedMsg << endl;
      cout << endl;
    } 
    else if (userChoice == '2')
    {
      cout << "Enter a message you would like to decrypt." << endl;
      cout << "ENTER MESSAGE HERE: ";
      getline(cin, userMsg);
      cout << endl;
      validateMsg(userMsg);

      cout << "Enter the key you would like to decrypt" << endl;
      cout << "your message with." << endl;
      cout << "ENTER KEY HERE: ";
      getline(cin, userKey);
      cout << endl;
      validateKey(userKey, userMsg);

      newKey = keyAdjustment(userMsg, userKey);
      
      //OUTPUT RESULTS
      cout << "New key: " << newKey << endl;
      string decryptedMsg = decryptVigenere(userMsg, userKey, newKey);
      cout << endl;
      cout << "Decrypted message: " << decryptedMsg << endl;
      cout << endl;
    }
  }
  while (userChoice != '3');

  cout << "Thank you for using this program!" << endl;
}
