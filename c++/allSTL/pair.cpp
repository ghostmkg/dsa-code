#include <iostream>
using namespace std;

int main() {
 pair<int, int> p1 = {2,6};
  cout<<p1.first<<" "<<p1.second;
  cout<<endl;
  pair<int, char> p2 = {3, 'g'};
  cout<<p2.first<<" "<<p2.second;
  cout<<endl;
  pair<pair<int, string>,int > p3 = {{4,"astitva"}, 8};
  cout<<p3.first.second;
  return 0;
}