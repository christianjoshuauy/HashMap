#include <iostream>
#include "hashmap.h"

using namespace std;

int main(void)
{
  HashMap *hashMap = new HashMap();
  hashMap->put("apple", 5);
  hashMap->put("grape", 10);
  hashMap->put("fork", 16);
  hashMap->put("round", 1);
  hashMap->put("jungle", 39);
  hashMap->put("road", 69);
  cout << hashMap->get("jungle") << endl;
  // Linear Probing [-1,-1,-1,69,10,5,1,16,39,-1]
  // Quadratic Probing [-1,39,-1,69,10,5,1,16,-1,-1]
  // Double hash [39,-1,-1,69,10,5,1,16,-1,-1]
}