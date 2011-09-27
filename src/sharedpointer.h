#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H

#include <iostream>

class ReferenceCounter{
  unsigned int kReferences;
public:
  ReferenceCounter();
  void addReference();
  int releaseReference();
};

template < typename Type >  class SP{
private:
  Type *pointer; // actual raw-pointer
  ReferenceCounter *references;
public:
  operator Type*(){ return pointer;}

  // empty pointer
  SP() : pointer(0), references(new ReferenceCounter()){ 
    references->addReference();
  };
  //pointer with a value
  SP(Type* raw) : pointer(raw), references(new ReferenceCounter()){ 
    references->addReference();
  };
  // copy constructor
  SP(const SP<Type>& sp) : pointer(sp.pointer), references(sp.references){ 
    references->addReference();
  };
  ~SP(){
    std::cout << "deleting reference" << std::endl;
    if(references->releaseReference() == 0){
      delete pointer;
      delete references;
    }
  }    
  Type* operator->(){
    return pointer;
  }
  Type& operator*(){
    return *pointer;
  }
  SP<Type>& operator = (const SP<Type> &sp){
    if(this != &sp){
      if(references->releaseReference() == 0){
	delete pointer;
	delete references;
      }
      pointer = sp.pointer;
      references = sp.references;
      references->addReference();
    }
    return * this;
  }
  bool operator ==(Type *i ){
    return pointer == i;
  }
  bool operator !=(Type *i ){
    return pointer != i;
  }
};



#endif
