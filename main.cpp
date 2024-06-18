#include <iostream>
# include <string>
std::string email;
std::string emailLeft;
std::string emailRight;
std::string dictionaryLeft {"!#$%&'*+-/=?^_`{|}~ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789."};
std::string dictionaryRight {"-.ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};

int counterSL = 0;
int nummberSL (std::string email){
  for(int i = 0; i < email.length(); i++){  
    if(email[i] == '@'){  
       break;
       }
     ++counterSL;
  }
  return counterSL;
} 

int counterSR;
int nummberSR (std::string email, int counterSL){
  counterSR = email.length() - counterSL - 1;  
  return counterSR;
}


std::string shareLeft(std::string email, int nummberSL){
  emailLeft.resize(counterSL);
  for(int i = 0; i < email.length(); i++){
        if(email[i] == '@'){
          
      return  emailLeft;
    }   
    emailLeft[i] = email[i]; 
  } 
  return emailLeft;
}

  std::string shareRight(std::string email, int counterSR, int counterSL){
  emailRight.resize(counterSR);
  for(int i = 0; i < counterSR; i++){
    emailRight[i] = email[i+counterSL+1];  
  } 
  return  emailRight;
}

int counterCDL = 0;
bool counterCDLbool = false;
bool collationDictionaryLeft(std::string emailLeft){
  for(int i = 0; i < emailLeft.length(); ++i){ 
    for(int j = 0; j < dictionaryLeft.length(); ++j){
      if(dictionaryLeft[j] == emailLeft[i]){
       ++counterCDL;
      }
    }  
  }
  return counterCDL == emailLeft.length() ? counterCDLbool=true : counterCDLbool=false;
}


int counterCDR = 0;
bool counterCDRbool = false;
bool collationDictionaryRight(std::string emailRight){
  for(int i = 0; i < emailRight.length(); i++){ 
    for(int j = 0; j < dictionaryRight.length(); j++){
      if(dictionaryRight[j] == emailRight[i]){
       ++counterCDR;
      }
    }  
  }
  return counterCDR == emailRight.length() ? counterCDRbool = true : counterCDRbool = false;
}

bool preliminaryCheck(std::string email, int counterSL, int counterSR){
  int countera = 0; 
  for(int i = 0; i < email.length(); i++){
    if(email[i] == '@'){
      ++countera;
      if(countera > 1 || countera == 0){
        return false;
      }
    } else if(email[0] == '.' || email[email.length()-1] == '.'){
      return false;
    } else if (email[i] == '.' && email[i+1] == '.'){
      return false;
    } else if(counterSL>64 || counterSL<1 || counterSR>63 || counterSR<1){
      return false;
    } 
  }
  return true;
}
 
int main() {
  std::cout << "Hello! This program checks the correctness of the email\n";
  std::cout << "=======================================================\n"; 
  std::cout << "Input email: ";
  getline(std::cin, email); 
  nummberSL (email);
  nummberSR (email, counterSL);
  if(preliminaryCheck(email,counterSL, counterSR)==true){
  shareLeft(email, counterSL);
  shareRight(email, counterSR, counterSL);
  collationDictionaryLeft(emailLeft);
  collationDictionaryRight(emailRight);
    if(counterCDLbool == true && counterCDRbool == true){
      std::cout << "YES\n";
    } else {std::cout<<"NO\n";};
  }else {std::cout<<"No";}; 
}