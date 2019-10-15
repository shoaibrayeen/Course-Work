#include<iostream> 
using namespace std; 
  
class base { 
public: 
    void fun_1() { 
      cout << "base-1\n"; 
    } 
    virtual void fun_2() { 
      cout << "base-2\n";
    } 
    virtual void fun_3() { 
      cout << "base-3\n"; 
    } 
    virtual void fun_4() { 
      cout << "base-4\n"; 
    } 
}; 
  
class derived : public base { 
public: 
    void fun_1() { 
      cout << "derived-1\n"; 
    } 
    void fun_2() { 
      cout << "derived-2\n"; 
    } 
    void fun_4(int x) { 
      cout << "derived-4\n"; 
    } 
}; 
  
int main() { 
    base *p; 
    derived obj1; 
    p = &obj1; 
  
    // Early binding because fun1() is non-virtual 
    // in base 
    p->fun_1(); 
  
    // Late binding (RTP) 
    p->fun_2(); 
  
    // Late binding (RTP) 
    p->fun_3(); 
  
    // Late binding (RTP) 
    p->fun_4(); 
  
    // Early binding but this function call is 
    // illegal(produces error) becasue pointer 
    // is of base type and function is of 
    // derived class 
    //p->fun_4(5); 
}

//Output
/*
base-1
derived-2
base-3
base-4
*/

//Explanation
/*
Initially, we create a pointer of type base class and initialize it with the address of the derived class object. When we create an object of the derived class, the compiler creates a pointer as a data member of the class containing the address of VTABLE of the derived class.

Similar concept of Late and Early Binding is used as in above example. For fun_1() function call, base class version of function is called, fun_2() is overridden in derived class so derived class version is called, fun_3() is not overridden in derived class and is virtual function so base class version is called, similarly fun_4() is not overridden so base class version is called.
*/
