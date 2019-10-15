#       _Project List_
# _______________________________________________________________
## 1. Implement a Linked lists that can be used to manage playlist for a media player.

## 2. Make a phase of a compiler using Hash Tables, for example consider creating a simple compiler symbol table using Hashing in C++ with functions like insert, lookup etc.

## 3. Simulate a scheduler using priority queues.

## 4. Implement a dictionary which gives the meaning of the word entered, and if the entered word is not present in the dictionary the application will say that the word is not found, and then will autosuggest words which are close to the entered word.

### Example: search for &quot;Orange&quot;
### Output: the word &quot;Orange&quot; was found with meaning &quot; a kind of fruit&quot; Search for &quot;Carn&quot;
### Output: the word &quot;carn&quot; was not found, Did u mean &quot;cart&quot;, &quot; card &quot;, &quot; carrot&quot;, &quot;carrom&quot;
### Data structure to use : The data structure to use here is trie. Which is almost specifically used for this purpose. It’s a tree data structure, where every node will have 26 children at the max representing alphabet letters, and leaf node will contain the whole string formed through the path from root to that node.

## 5. Make a dictionary using Trie trees with spell check or even for autocomplete

## 6. Implement versions of several different dictionary data structures, such as linked lists, binary trees, balanced binary search trees, and hash tables. Conduct experiments to assess the relative performance of these data structures in a simple application that reads a large text file and reports exactly one instance of each word that appears within it. This application can be efficiently implemented by maintaining a dictionary of all distinct words that have appeared thus far in the text and inserting/reporting each word that is not found. Write a brief report with your conclusions.

## 7. Visualization of any Data structure (discussed during lectures) of your choice in C++ using openGL.

## 8. Implement B+ tree that performs following operations:
- Take input from a file (only then try direct input from console)
- Insert new value into it
- Print the B+ tree
- Delete existing value

## 9. Implement a disk management system that performs following operations :
- Read a sector
- Check status of sector (free/busy/reserved etc)
- Write into a sector
- Get the location of sector
- Write/read/delete a file
- Get the file info (file name , file size, sector info , directory info)
- Permanent deletion/restoration of file
