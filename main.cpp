#include <iostream>
#include "hashmap.h"

using namespace std;

int main(void)
{
  HashMap *hashMap = new HashMap();
  hashMap->put("apple", 5);
  cout << hashMap->get("apple") << endl;
}