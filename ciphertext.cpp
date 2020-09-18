#include<bits/stdc++.h> using namespace std;
string plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; string encoder(string key) {
string encoded = ""; bool arr[26] = {0};
for (int i=0; i<key.size(); i++) { if(key[i] >= 'A' && key[i] <= 'Z') {
if (arr[key[i]-65] == 0) { encoded += key[i];
arr[key[i]-65] = 1;
}

}
else if (key[i] >= 'a' && key[i] <= 'z'){
if (arr[key[i]-97] == 0){ encoded += key[i] - 32;
arr[key[i]-97] = 1;
}

}
}

for (int i=0; i<26; i++) { if(arr[i] == 0) {
arr[i]=1;
encoded += char(i + 65);

}
}

return encoded;
 
}
string cipheredIt(string msg, string encoded) { string cipher="";
for (int i=0; i<msg.size(); i++) {
if (msg[i] >='a' &&msg[i] <='z'){ int pos = msg[i] - 97;
cipher += encoded[pos];

}
else if (msg[i] >='A' &&msg[i] <='Z') { int pos = msg[i] - 65;
cipher += encoded[pos];

 
}
else{


}
}
 



cipher += msg[i];
 

return cipher;
}

string decipheredIt(string msg, string encoded){ map <char,int> enc;
for(int i=0; i<encoded.size(); i++) { enc[encoded[i]]=i;
}
string decipher="";
for (int i=0; i<msg.size(); i++) {
if (msg[i] >='a' &&msg[i] <='z') { int pos = enc[msg[i]-32]; decipher += plaintext[pos];
}
 
else if(msg[i] >='A' &&msg[i] <='Z') { int pos = enc[msg[i]];
decipher += plaintext[pos];

 
}
else{


}
}
 



decipher += msg[i];
 

return decipher;
}

int main() {
string key, message; int ch;
key = "EveryOneKnows"; cout<<"\n"<<key;
string encoded = encoder(key); cout<<"\nEnter Message: ";getline(cin,message);
cout<<"Enter your choice \n1. Encryption \n2. Decryption \n"; cin>>ch;
if(ch==1){
cout<<"\nMessage before Ciphering : " << message; cout<<"\nCipheredText : "<<cipheredIt(message,encoded);
}
else if(ch==2){
cout<<"\nMessage before Deciphering : " << message; cout<<"\nDecipheredText : "<<decipheredIt(message,encoded);;
}
return 0;

}

