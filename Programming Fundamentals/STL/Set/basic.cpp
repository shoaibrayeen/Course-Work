

#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main(){
    set <int, greater <int> > temp;     // previous elements will be greater than current element
    temp.insert(40);
    temp.insert(30);
    temp.insert(60);
    temp.insert(20);
    temp.insert(50);
    temp.insert(50);        // only one 50 will be inserted in the set
    temp.insert(10);
    temp.erase(temp.begin(), temp.find(30));        // erase elements greater than 30
    
    set <int, greater <int> > :: iterator itr;
    cout << "\nThe 1st Set\t:\t";
    for (itr = temp.begin(); itr != temp.end(); ++itr) {      // printing set 1
        cout << '\t' << *itr;
    }
    cout << endl;
    
    set <int> temp2(temp.begin(), temp.end());        // Declaring 2nd set -> by default previous < current
    cout << "\nThe 2nd Set\t:\t";
    for (itr = temp2.begin(); itr != temp2.end(); ++itr){
        cout << '\t' << *itr;
    }
    cout << endl;
    temp2.erase(temp2.begin(), temp2.find(30));       // erase elements less than 30
    temp2.erase (50);                                 // erase 50

    cout << temp.size();                              // size of 1st set
    cout << "\nSize of 1st Set\t:\t" << endl;
    return 0;
    
}


/*
  Functions associated with Set:
  begin() – Returns an iterator to the first element in the set
  end() – Returns an iterator to the theoretical element that follows last element in the set
  size() – Returns the number of elements in the set
  max_size() – Returns the maximum number of elements that the set can hold
  empty() – Returns whether the set is empty
  pair <iterator, bool> insert(const g) – Adds a new element ‘g’ to the set
  iterator insert (iterator position, const g) – Adds a new element ‘g’ at the position pointed by iterator
  erase(iterator position) – Removes the element at the position pointed by the iterator
  erase(const g)- Removes the value ‘g’ from the set
  clear() – Removes all the elements from the set
  key_comp() / value_comp() – Returns the object that determines how the elements in the set are ordered (‘<‘ by default)
  find(const g) – Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end
  count(const g) – Returns 1 or 0 based on the element ‘g’ is present in the set or not.  
  lower_bound(const g) – Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set
  upper_bound(const g) – Returns an iterator to the first element that is equivalent to ‘g’ or definitely will go after the element ‘g’ in the set

*/
