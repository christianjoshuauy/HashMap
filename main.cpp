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
  hashMap->put(5, 65);
  cout << hashMap->get(5) << endl;
}