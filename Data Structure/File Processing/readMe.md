## Functions used in File Handling
### Function -> Operation
### open() -> To create a file
### close() -> To close an existing file
### get() ->  Read a single character from a file
### put() ->  write a single character in file.
### read() -> Read data from file
### write() ->  Write data into file.


### seekg() -> moves get pointer (input) to a specified location.
### seekp() -> moves put pointer (output) to a specified location.
### tellg() -> gives the current position of the get pointer.
### tellp() -> gives the current position of the put pointer.



### Function   ->   Operation
#### fout . seekg(0, ios :: beg) -> go to start
#### fout . seekg(0, ios :: cur) -> stay at current position
#### fout . seekg(0, ios :: end) -> go to the end of file
#### fout . seekg(m, ios :: beg) -> move to m+1 byte in the file
#### fout . seekg(m, ios :: cur) -> go forward by m bytes from the current position
#### fout . seekg(-m, ios :: cur) -> go backward by m bytes from the current position
#### fout . seekg(-m, ios :: end) -> go backward by m bytes from the end


### write and read object using read and write function
#### file.read ((char *)&V , sizeof (V));
#### file.write ((char *)&V , sizeof (V));
##### V is object here.
