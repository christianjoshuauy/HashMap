#include <string>

using namespace std;

class HashMap
{
private:
  int *arr;
  int size;
  int index;
  unsigned int keyToHashCode(const string &key, int shift)
  {
    // convert the key to a hash code using cyclic shift
    unsigned int hash = 0;
    for (char ch : key)
    {
      hash = (hash << shift) | (hash >> (32 - shift)); // cyclic shift left by 5 bits
      hash += ch;                                      // add the ASCII of the character to the hash code
    }
    return hash;
  }

  int compressHash(unsigned int hash)
  {
    // compress the hash code using MAD compression
    int p = 541;      // prime number
    int a = 5, b = 7; // random numbers
    return (a * hash + b) % p % size;
  }

public:
  HashMap()
  {
    size = 10;
    arr = new int[size];
    index = 0;
    // Initialize array with -1
    for (int i = 0; i < size; i++)
    {
      arr[i] = -1;
    }
  }
  void put(const string &key, int value)
  {
    int index = compressHash(keyToHashCode(key, 5));
    // Linear probing
    for (int i = 0; i < size; i++)
    {
      if (arr[index] == -1)
      {
        arr[index] = value;
        break;
      }
      index = (index + 1) % size;
    }
    // Quadratic probing
  }
  int get(const string &key)
  {
    int index = compressHash(keyToHashCode(key, 5));
    // Finding using linear probing
    for (int i = 0; i < size; i++)
    {
      if (arr[index] != -1)
      {
        return arr[index];
      }
      index = (index + 1) % size;
    }
    return -1;
  }
};