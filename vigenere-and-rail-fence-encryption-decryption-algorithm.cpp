#include <bits/stdc++.h>
using namespace std;

string vigenereEncryption(string plainText, string key){
  
  string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int pLen = plainText.length();
  int kLen = key.length();
  string cipherText = "";
  
  int c;
  
  for(int i=0; i<pLen; i++){
    c = ( (plainText[i] - 'A') + (key[i % kLen] - 'A') ) % 26;
    cipherText += alphabets[c];
  }
  
  return cipherText;
}

string vigenereDecryption(string cipherText, string key){
  
  string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int cLen = cipherText.length();
  int kLen = key.length();
  string plainText = "";
  
  int p;
  
  for(int i=0; i<cLen; i++){
    p = ( (cipherText[i] - 'A') - (key[i % kLen] - 'A') + 26) % 26;
    plainText += alphabets[p];
  }
  
  return plainText;
}

string railFenceEncryption(string plainText, int key){
  
  int len = plainText.length();
  
  char rail[key][len];
  
  for(int i=0; i<key; i++){
    for(int j=0; j<len; j++){
      rail[i][j] = '\n';
    }
  }
  
  int row = 0, col = 0;
  bool dirDown = false;
  
  for(int i=0; i<len; i++){
    
    if(row == 0 || row == key-1){
      dirDown = !dirDown; 
    }
    
    rail[row][col] = plainText[i];
    
    col++;
    if(dirDown) row++;
    else row--;
  }
  
  string cipherText = "";
  
  for(int i=0; i<key; i++){
    for(int j=0; j<len; j++){
      if(rail[i][j] != '\n'){
        cipherText += rail[i][j];
      }
    }
  }
  
  return cipherText;
  
}

string railFenceDecryption(string cipherText, int key){
  
  int len = cipherText.length();
  
  char rail[key][len];
  
  for(int i=0; i<key; i++){
    for(int j=0; j<len; j++){
      rail[i][j] = '\n';
    }
  }
  
  int row = 0, col = 0;
  bool dirDown = false;
  
  for(int i=0; i<len; i++){
    
    if(row == 0 || row == key-1){
      dirDown = !dirDown; 
    }
    
    rail[row][col] = '*';
    
    col++;
    if(dirDown) row++;
    else row--;
  }
  
  int indeks = 0;
  for(int i=0; i<key; i++){
    for(int j=0; j<len; j++){
      if(rail[i][j] == '*' and indeks < len){
        rail[i][j] = cipherText[indeks];
        indeks++;
      }
    }
  }
  
  row = 0, col = 0;
  dirDown = false;
  string plainText = "";
  
  for (int i=0; i< len; i++){
        
    if(row == 0 || row == key-1){
      dirDown = !dirDown;
    }
 
    if (rail[row][col] != '*')
      plainText += rail[row][col];
     
      col++;
      dirDown?row++: row--;
    }
  
  return plainText;
}

void userInterface(){
  cout << "\nWhat would you do?";
  cout << "\n1 -> Encrypt";
  cout << "\n2 -> Decrypt";
  cout << "\n3 -> Exit\n";
  
  int n;
  cin >> n;
  
  if(n == 1){
    cout << "\nInput the message you want to encrypt:\n";
    string plainText;
    cin >> plainText;
    
    cout << "\nInput the key text to encrypt the message using Vigenere algorithm:\n";
    string keyText;
    cin >> keyText;
    
    cout << "\nInput the key number to encrypt the message using Rail Fence algorithm:\n";
    int keyNumber;
    cin >> keyNumber;
    
    cout << "\nEncrypted message: ";
    cout << railFenceEncryption(vigenereEncryption(plainText, keyText), keyNumber) << endl;
    
    userInterface();
  }
  else if(n == 2){
    cout << "\nInput the message you want to decrypt:\n";
    string cipherText;
    cin >> cipherText;
    
    cout << "\nInput the key number to decrypt the message:\n";
    int keyNumber;
    cin >> keyNumber;
    
    cout << "\nInput the key text to decrypt the message:\n";
    string keyText;
    cin >> keyText;
    
    cout << "\nDecrypted message: ";
    cout << vigenereDecryption(railFenceDecryption(cipherText, keyNumber), keyText) << endl;
    
    userInterface();
  }
  else if(n == 3){
    cout << "\nYou're exited from the program";
  }
  else{
    userInterface();
  }
}

int main() 
{
    cout << "\nWELCOME TO VIGENERE AND RAIL FENCE ENCRYPTOR DECRYPTOR PROGRAM" << endl;
    cout << "==============================================================\n";
    
    userInterface();
}
