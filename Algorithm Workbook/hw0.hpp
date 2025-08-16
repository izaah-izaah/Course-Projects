//
//  hw0.hpp
//  pic10b
//
//  Created by Michael James Murray on 1/4/24.
//

#ifndef hw0_hpp
#define hw0_hpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Question 1: declaration max element function
// XXXX max_element(XXXX);
int max_element(vector<vector<int>> vect);

////Question 2: declaration pointer swap function
void pointer_swap(int*& one, int*& two);
//
// Question 3a: declaration caesar cipher function
 string caesar_cipher1(const string& message, int offset);

// Question 3b: declaration in-place caesar cipher function

string caesar_cipher2(const string message2, int offset2);


// Question 4: declaration of Undergrad class
class Undergrad{
private:
    int grade;
    
public:
    string name;
    size_t ID;
    Undergrad();
    Undergrad(string name, size_t ID, int grade);

    void update_grade(int newgrade);
    int get_grade() const;
    
   // Undergrad(const string name, const size_t id, int grade) : name(name),  ID(id), grade(grade){}

};

#endif /* hw0_hpp */
