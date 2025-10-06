#include <iostream>
using namespace std;

void charIncr(int n){
   char c = 'A';
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      cout<<c;
    }
        c++;
          cout<<endl;
  }

}



int main(){

    int n;
    cin>>n;
    charIncr(n);

    return 0;
}