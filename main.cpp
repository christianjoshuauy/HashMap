#include <iostream>
#include "hashmap.h"

using namespace std;

int main(void)
{
  HashMap *hashMap = new HashMap();
  hashMap->put("apple", 5);
  hashMap->put("grape", 10);
  hashMap->put("fork", 16);
  hashMap->put("round", 1);   // collision
  hashMap->put("jungle", 39); // collision
  hashMap->put("road", 69);
  cout << hashMap->get("apple") << endl;
}