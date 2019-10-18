#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string eShift(string s, int val){
  int len=s.length();
  string answer;
  for (int i=0; i< len; ++i){
    int alpha;
    if ((islower(s[i]) == false) && (isupper(s[i]) == false)) {
      answer+= s[i]; 
    }
    else if (isupper(s[i])){
      alpha=65;
      int ind= int(((s[i]+val -alpha)%26) +alpha);
      answer+= char(ind);
    }else{
      alpha =97;
      int ind= int(((s[i]+val -alpha)%26) +alpha);
      answer+= char(ind);
    }
  }
  return answer;
}


string dShift(string s, int val){
  int len=s.length();

  string answer;
  for (int i=0; i< len; ++i){
    int alpha;
    if ((islower(s[i]) == false) && (isupper(s[i]) == false)) {
      answer+= s[i]; 
    }
    else if (isupper(s[i])){
      alpha=90;
      int ind= int(((s[i]-val -alpha)%26) +alpha);
      answer+= char(ind);
    }else{
      alpha =122;
      int ind= int(((s[i]-val -alpha)%26) +alpha);
      answer+= char(ind);
    }
  }
  return answer;
}




bool isNumeric(string input){ 
  for (int i = 0; i < input.length(); i++){ 
    if (false==isdigit(input[i])) {
      return false;
    }
  }
  return true; 
} 

bool isSameStr(string input1, string input2){ 
  if (input1.length() != input2.length()){
    return false;
  }
  else{
    for (int i = 0; i < input1.length(); i++){ 
      if (input1[i] != input2[i]) {
        return false; 
      }
    }
    return true; 
  }
} 

int main(int argc, char *argv[]){
  int numOfArgs = argc -1;
  string direction;


  if (numOfArgs == 2){
    direction = argv[2]; 

  }
  // cout << direction<< endl;


  if (numOfArgs == 0){
    for(int i=0; i >= 0; i++){

      string input;
      string mid;
      string output;
      int ajaira;

      getline(cin, input);
      int inputLen = input.length();

      int key;
      for (int j=0; j < inputLen; j++){
        if ((input[j] == 100) || (input[j] == 101)) {
          mid = input.substr((1+j), inputLen);
          ajaira = mid.length();
          key =input[j];
          break;
        }
        else if ((input[j] == 113)){
          return 0;
        }
      }

      if (key == 101){ 
        output = eShift(mid, 3);
      }else if (key== 100){
        output = dShift(mid, 3);
      }
      if (!(output.empty())) {
        cout << output << endl;

      }else if (((input[inputLen -1]== 100)||(input[inputLen -1]== 101)) &&
                (mid.empty())){
        cout << "" << endl;
      }
    }

    return 0;
  }
  //////
  //  bool bl= (isNumeric(argv[1]));
  //  cout << bl << endl;

  else if (((numOfArgs == 2) && (isNumeric(argv[1])) && 
            (("right"==direction))) 
           ||
           ((numOfArgs == 1) && (isNumeric(argv[1])))
          )   {

    int value;
    (istringstream(argv[1]) >> value);
    for(int i=0; i >= 0; i++){

      string input;
      string mid;
      string output;
      int ajaira;

      getline(cin, input);
      int inputLen = input.length();

      int key;
      for (int j=0; j < inputLen; j++){
        if ((input[j] == 100) || (input[j] == 101)) {
          mid = input.substr((1+j), inputLen);
          ajaira = mid.length();
          key =input[j];
          break;
        }
        else if ((input[j] == 113)){
          return 0;
        }
      }

      if (key == 101){ 
        output = eShift(mid, value);
      }else if (key== 100){
        output = dShift(mid, value);
      }
      if (!(output.empty())) {
        cout << output << endl;

      }else if (((input[inputLen -1]== 100)||(input[inputLen -1]== 101)) &&
                (mid.empty())){
        cout << "" << endl;
      }
    }

    return 0;
  }
  /////////////

  else if (((numOfArgs == 2) && (isNumeric(argv[1])) && 
            (("left"==direction))) 
          )   {

    int value;
    (istringstream(argv[1]) >> value);
    for(int i=0; i >= 0; i++){

      string input;
      string mid;
      string output;
      int ajaira;

      getline(cin, input);
      int inputLen = input.length();

      int key;
      for (int j=0; j < inputLen; j++){
        if ((input[j] == 100) || (input[j] == 101)) {
          mid = input.substr((1+j), inputLen);
          ajaira = mid.length();
          key =input[j];
          break;
        }
        else if ((input[j] == 113)){
          return 0;
        }
      }

      if (key == 101){ 
        output = dShift(mid, value);
      }else if (key== 100){
        output = eShift(mid, value);
      }
      if (!(output.empty())) {
        cout << output << endl;

      }else if (((input[inputLen -1]== 100)||(input[inputLen -1]== 101)) &&
                (mid.empty())){
        cout << "" << endl;
      }
    }

    return 0;
  }










  //////////////
  else{
    string zero="0";
    int value;
    (istringstream(argv[1]) >> value);
    value =value -(value%1);

    //cout<< value <<endl;
    // for argument value being invalid, i.e., less than 0, or greater than 25


    if (( value <0) ||(value >25)){
      cerr <<"ERROR: Incorrect shift value" << endl;
      return -1;
    }
    // for making sure first argument is only numeric
    string value_str = argv[1];
    if ((zero.compare(argv[1]) != 0) && (value == 0)) {
      cerr <<"ERROR: first argument must be an int value" << endl;
      return -1;
    }
    if (numOfArgs > 2){
      cerr <<"ERROR: Incorrect direction (only left or right allowed)." << endl;
      return -1;
    }
    for(int i=0; i >= 0; i++){

      string input;
      string mid;
      string output;
      int ajaira;

      getline(cin, input);
      int inputLen = input.length();

      int key;
      for (int j=0; j < inputLen; j++){
        if ((input[j] == 100) || (input[j] == 101)) {
          mid = input.substr((1+j), inputLen);
          ajaira = mid.length();
          key =input[j];
          break;
        } 
        else if ((input[j] == 113)){
          return 0;
        }
      }

      if (key == 101){ 
        output = eShift(mid, 3);
      }else if (key== 100){
        output = dShift(mid, 3);
      }
      if (!(output.empty())) {
        cout << output << endl;

      }else if (((input[inputLen -1]== 100)||(input[inputLen -1]== 101)) &&
                (mid.empty())){
        cout << "" << endl;
      }
    }
    return 0;
  }
}
