#include <string>

using namespace std;

class HashMap
{
private:
  int *arr;
  unsigned int *hashes;
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
    hashes = new unsigned int[size];
    index = 0;
    // Initialize array with -1
    for (int i = 0; i < size; i++)
    {
      arr[i] = -1;
    }
  }
  void put(const string &key, int value)
  {
    unsigned int hash = keyToHashCode(key, 5);
    int idx = compressHash(hash);
    if (index >= size)
    {
      cout << "HashMap is Full";
    }
    // Linear probing
    // for (int i = 0; i < size; i++)
    // {
    //   if (arr[idx] == -1)
    //   {
    //     arr[idx] = value;
    //     hashes[idx] = hash;
    //     break;
    //   }
    //   idx = (idx + 1) % size;
    // }
    // index++;

    // Quadratic probing
    // for (int i = 0; i < size; i++)
    // {
    //   if (arr[idx] == -1)
    //   {
    //     arr[idx] = value;
    //     hashes[idx] = hash;
    //     break;
    //   }
    //   idx = (idx + i * i) % size;
    // }
    // index++;

    // Double hashing
    int idx2 = compressHash(keyToHashCode(key, 7));
    for (int i = 0; i < size; i++)
    {
      if (arr[idx] == -1)
      {
        arr[idx] = value;
        hashes[idx] = hash;
        break;
      }
      idx = (idx + i * idx2) % size;
    }
    index++;
  }
  int get(const string &key)
  {
    unsigned int hash = keyToHashCode(key, 5);
    int idx = compressHash(hash);

    // Finding using linear probing
    // for (int i = 0; i < size; i++)
    // {
    //   if (arr[idx] != -1 && hashes[idx] == hash)
    //   {
    //     return arr[idx];
    //   }
    //   idx = (idx + 1) % size;
    // }
    // return -1;

    // Finding using quadratic probing
    // for (int i = 0; i < size; i++)
    // {
    //   if (arr[idx] != -1 && hashes[idx] == hash)
    //   {
    //     return arr[idx];
    //   }
    //   idx = (idx + i * i) % size;
    // }
    // return -1;

    // Finding using double hashing
    int idx2 = compressHash(keyToHashCode(key, 7));
    for (int i = 0; i < size; i++)
    {
      if (arr[idx] != -1 && hashes[idx] == hash)
      {
        return arr[idx];
      }
      idx = (idx + i * idx2) % size;
    }
    return -1;
  }
};