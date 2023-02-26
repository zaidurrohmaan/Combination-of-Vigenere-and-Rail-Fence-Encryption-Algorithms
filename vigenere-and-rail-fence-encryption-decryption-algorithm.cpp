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

int main() 
{
    cout << vigenereEncryption("COMPUTERSCIENCE", "MYKEY");
    cout << endl;
    cout << vigenereDecryption("OMWTSFCBWAUCXGC", "MYKEY");
    cout << endl;
    cout << railFenceEncryption("GEEKSFORGEEKS", 4);
    cout << endl;
    cout << railFenceDecryption("GOSEFRKESGEKE", 4);
}
