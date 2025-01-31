#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
int main() {

  ULListStr dat;

  /*
  //testing push_back, push_front, get, size
  dat.push_back(7);
  dat.push_front(8);
  dat.push_back(9);
  std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << std::endl;
  // prints: 8 7 9
  std::cout << dat.size() << std::endl; 
  */

  /*
  //testing push_back and push_front 
  dat.push_back("bob");
	dat.push_front("fred");

  std::cout << "size after pushing two elements: " << dat.size() << std::endl;  // Expected: 2
  std::cout << "Front element: " << dat.front() << std::endl; // Expected: "
  std::cout << "Back element: " << dat.back() << std::endl;
  */

  /*
  //testing push_front, size, front, and back
  dat.push_front("1536");
  dat.push_front("1024");
  dat.push_front("768");
  //"768", "1024", "1536"

  std::cout << "Size after pushing three elements: " << dat.size() << std::endl;  // Expected: 3
  std::cout << "Front element: " << dat.front() << std::endl; // Expected: "three"
  std::cout << "Back element: " << dat.back() << std::endl;
  */

  /*
  //Testing pop front 
  dat.push_back("one");
  dat.push_back("two");
  dat.push_back("three");
  dat.pop_front();
  std::cout << "After 1 pop, front element: " << dat.front() << std::endl; // Expected: "two"
  dat.pop_front();
  std::cout << "After 2 pops, front element: " << dat.front() << std::endl; // Expected: "one"
  std::cout << "Size: " << dat.size() << std::endl;  // Expected: 1
  */

  /*
  //Testing pop_back
  dat.push_back("one");
  dat.push_back("two");
  dat.push_back("three");
  dat.pop_back();
  std::cout << "After 1 pop, back element: " << dat.back() << std::endl; // Expected: "two"
  dat.pop_back();
  std::cout << "After 2 pops, back element: " << dat.back() << std::endl; // Expected: "one"
  std::cout << "Size: " << dat.size() << std::endl;  // Expected: 1
  */

  //Everything used at the same time
  dat.push_back("a");
  dat.push_back("b");
  dat.push_back("c");
  dat.pop_back();
  std::cout << "last element?: " << dat.back() << std::endl;
  dat.push_front("0");
  dat.push_front("1");
  dat.pop_front();
  std::cout << "first element?: " << dat.front() << std::endl;
  std::cout << "Size: " << dat.size() << std::endl;
  std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << std::endl;

  return 0;
}
