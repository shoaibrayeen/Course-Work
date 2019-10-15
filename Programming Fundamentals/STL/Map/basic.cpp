
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main() {
  map <int, int> temp;
  temp.insert(pair <int, int> (1, 40));
  temp.insert(pair <int, int> (2, 30));
  temp.insert(pair <int, int> (3, 60));
  temp.insert(pair <int, int> (5, 50));
  temp.insert(pair <int, int> (10, 50));
  temp.erase(3);			// remove all elements with key = 3
  cout << "\nElements of Map\n";
  for (itr = temp.begin(); itr != temp.end(); ++itr) {
    cout  <<  '\t' << itr->first <<  '\t' << itr->second << '\n';
  }
  cout << endl;
  return 0;
}
/*
  Functions associated with Map:
  begin() – Returns an iterator to the first element in the map
  end() – Returns an iterator to the theoretical element that follows last element in the map
  size() – Returns the number of elements in the map
  max_size() – Returns the maximum number of elements that the map can hold
  empty() – Returns whether the map is empty
  pair insert(keyvalue,mapvalue) – Adds a new element to the map
  erase(iterator position) – Removes the element at the position pointed by the iterator
  erase(const g)- Removes the key value ‘g’ from the map
  clear() – Removes all the elements from the map
  key_comp() / value_comp() – Returns the object that determines how the elements in the map are ordered (‘<' by default)
  find(const g) – Returns an iterator to the element with key value ‘g’ in the map if found, else returns the iterator to end
  count(const g) – Returns the number of matches to element with key value ‘g’ in the map
  lower_bound(const g) – Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’ or definitely will not go before the element with key value ‘g’ in the map
  upper_bound(const g) – Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’ or definitely will go after the element with key value ‘g’ in the map
*/
