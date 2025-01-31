#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

bool checkListContent(ULListStr* list, const std::vector<std::string>& expected) {
    if (list->size() != expected.size()) {
        return false;
    }
    
    for (size_t i = 0; i < expected.size(); ++i) {
        if (list->get(i) != expected[i]) {
            return false;
        }
    }
    return true;
}

int main() {

  ULListStr dat;

  //testing ListInsert.BackThenFront 
  dat.push_back("bob");
	dat.push_front("fred");

  std::cout << "Size after pushing two elements: " << dat.size() << std::endl;  // Expected: 2
  std::cout << "Front element: " << dat.front() << std::endl; // Expected: "
  std::cout << "Back element: " << dat.back() << std::endl;

  // dat.push_front("1536");
  //   dat.push_front("1024");
  //   dat.push_front("768");
    //"768", "1024", "1536"

    // std::cout << "Size after pushing three elements: " << dat.size() << std::endl;  // Expected: 3
    // std::cout << "Front element: " << dat.front() << std::endl; // Expected: "three"
    // std::cout << "Back element: " << dat.back() << std::endl;

    // // Pop front and check state
    // dat.pop_front();
    // std::cout << "After 1 pop, front element: " << dat.front() << std::endl; // Expected: "two"
    // std::cout << "Size: " << dat.size() << std::endl;  // Expected: 2

    // dat.pop_front();
    // std::cout << "After 2 pops, front element: " << dat.front() << std::endl; // Expected: "one"
    // std::cout << "Size: " << dat.size() << std::endl;  // Expected: 1

    // dat.pop_front();
    // std::cout << "After 3 pops, is list empty? " << (dat.empty() ? "Yes" : "No") << std::endl; // Expected: Yes
    // std::cout << "Size: " << dat.size() << std::endl;  // Expected: 0

    // Test 3: Ensure we can add again after clearing
    // dat.push_front("new");
    // std::cout << "After adding 'new', front element: " << dat.front() << std::endl; // Expected: "new"
    // std::cout << "Size: " << dat.size() << std::endl;  


    // // Create a vector with test values
    // std::vector<std::string> contents{"768", "1024", "1536"};

    // // Create a list and insert the values at the front
    // ULListStr list;
    // for (const auto& str : contents) {
    //     list.push_front(str);  // Assuming push_front exists
    // }

    // // Check if the list contains the correct values
    // if (checkListContent(&list, { "1536", "1024", "768" })) {  
    //     std::cout << "Test passed: All elements are present and in the correct order." << std::endl;
    // } else {
    //     std::cout << "Test failed: List contents are incorrect." << std::endl;
    // }

    return 0;
}
