//GenQueue.h
//Template file for the GenQueue class
#include "DoublyLinkedList.h"

//header
template <class T>
class GenQueue : public DoublyLinkedList<T>{
public:
  GenQueue();
  ~GenQueue();
  //Methods
  void Enqueue(T d);  //calls insertBack function
  T Dequeue();  //Calls removeFront function
  void printQueue();  //calls printList funcion
  T peek();
private:
};
//Implementation
template <class T>
GenQueue<T>::GenQueue(){
}

template <class T>
void GenQueue<T>::Enqueue(T d){
  this->insertBack(d);
}
template <class T>
T GenQueue<T>::Dequeue(){
  return this->removeFront();
}
template <class T>
void GenQueue<T>::printQueue(){
  this->printList();
}
template <class T>
T GenQueue<T>::peek(){
  return this->returnPos(0);
}
