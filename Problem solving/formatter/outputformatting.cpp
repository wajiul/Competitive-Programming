#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include <fstream>
#include<conio.h>
using namespace std;

int main(int argc, char* argv[]){
  string input,output;
  input = argv[1];
  output = argv[2];
  string line;
  ifstream file(input);
  int len = 0;
  vector<string> a, b;
  if(file.is_open()) {
    while(getline(file, line)){
      a.push_back(line);
      len++;
    }
  }
  file.close();
  ifstream file2("out");
  if(file2.is_open()) {
    while(getline(file2,line)) {
      b.push_back(line);
    }
  }
  file2.close();
  cout.setf(ios::left);
  for(int i = 0; i < 33; i++) cout <<" _";
  cout << '\n';
  cout << "|";
  cout.width(28);
  cout <<"     Output";
  cout << "|      Expected " << '\n';
  cout << "|";
  for(int i = 0; i < 33; i++) {
        if(i == 14) cout << "|";
    else cout << "_ ";
  }

  cout << '\n' << "|"<<'\n';
  for(int i = 0; i < len; i++) {
    cout <<"| ";
    cout.width(27);
    cout << a[i];
    cout <<"| ";
    cout.width(27);
    cout << b[i];
    cout << '\n';
  }
  cout << "|";
  for(int i = 0; i < 33; i++) {
    cout << "_ ";
  }
  cout << '\n';
}
