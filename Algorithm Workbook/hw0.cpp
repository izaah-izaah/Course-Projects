//
//  hw0.cpp
//  pic10b
//
//  Created by Michael James Murray on 1/4/24.
//
#include <iostream>
#include <string>
#include <vector>
#include "hw0.hpp"
using namespace std;

// Question 1: max element function
int max_element(vector<vector<int>> vmax){
    ////first it is the vector of vectors that gets counted to see if it is empty
    ///     then we check the elements of the said chosen vector to see if those are empty
    ///
    if (vmax.size() ==  0 || vmax[0].size() == 0){
        return -1;
    }
    
    
    int  maxes = vmax[0][0];
 
    
    for (size_t i = 0; i != vmax.size(); ++i){
  
        for (size_t j = 0; j != vmax[i].size(); ++j){
            
            if (vmax[i][j] > maxes) {
                maxes = vmax[i][j];
            }
        }
    }
    return maxes;
}

// Question 2: pointer swap function
void pointer_swap(int*& one, int*& two){
    int* x = one;
    int* y = two;
    two = x;
    one = y;

     int temp = *one;
    *one = *two;
    *two = temp;

}

// Question 3a: caesar cipher function

string caesar_cipher1(const string& text, int offsetchar) {
    // Initialize the output string with the input text
    string output = text;
    
    // Define the alphabet used for the cipher
    const string alphabet = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    
    // Ensure the offsetchar is within the size of the alphabet
    offsetchar %= alphabet.size();
    
    // Adjust the offset for negative values
    if (offsetchar < 0) {
        offsetchar += alphabet.size();
    }
    
    // Iterate through each character in the input text
    for (size_t i = 0; i < text.size(); ++i) {
        char& currentChar = output[i]; // Get a reference to the current character
        
        // Check if the character is printable or a space
        if (isprint(currentChar) || currentChar == ' ') {
            // Find the position of the current character in the alphabet
            size_t pos = alphabet.find(currentChar);
            
            // If the character is found in the alphabet
            if (pos != string::npos) {
                // Apply the offset to shift the character
                pos = (pos + offsetchar) % alphabet.size();
                
                // Update the character in the output string with the shifted character from the alphabet
                currentChar = alphabet[pos];
            }
        }
    }
    
    // Return the encoded text
    return output;
}



// string caesar_cipher1(const string& text, int offsetchar){
//
//    string output = text;
//    const string alphabet = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
//
//
//     offsetchar %= alphabet.size();
//
//     // Adjust the offset for negative values
//        if (offsetchar < 0) {
//            offsetchar += alphabet.size();
//        }
//     string printed;
//
//     // Iterate through each character in the input text
//         for (size_t i = 0; i < text.size(); ++i) {
//             char& currentChar = output[i]; // Get a reference to the current character
//
//             // Check if the character is printable or a space
//             if (isprint(currentChar) || currentChar == ' ') {
//                 // Find the position of the current character in the alphabet
//                 size_t pos = alphabet.find(currentChar);
//
//                 // If the character is found in the alphabet
//                 if (pos != std::string::npos) {
//                     // Apply the offset to shift the character
//                     pos = (pos + offsetchar) % alphabet.size();
//
//                     // Update the character in the output string with the shifted character from the alphabet
//                     currentChar = alphabet[pos];
//                    }
//                }
//                 printed.push_back(currentChar);
//            // output.swap(&currentChar);
//            }
//return printed;
//}
//
//string caesar_ciper1(const string& text, int offsetchar){
//
//    string output = text;
//    const string alphabet = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
//
//
//    if (offsetchar > alphabet.size() || offsetchar < -alphabet.size()){
//                offsetchar %= alphabet.size();
//            }
////    if (offsetchar < 0){
////        offsetchar = abs(offsetchar);
////    }
//
//    for (size_t i = 0; i < text.size(); ++i){
//        size_t pos = alphabet.find(text[i]);
//        pos += offsetchar;
//       // output[i] += alphabet[pos];
//        output.push_back(alphabet[pos]);
////        if (offsetchar < 0){
////            //do the minus down the alphabet
////            pos += offsetchar;
////            output[i] += alphabet[pos];
////        }
//        //if (text[i] == alphabet[i]){
//           // string found = &text[i];
//           // output.push_back(found);
//         //   output[text[i]] += offsetchar;
//       // }
//    }
//    return output;
//}

//if (message[". "])
// do capital


// Question 3b: in-place caesar cipher function
//string caesar_cipher2(const string& message2, int offset2){
//    
//    
//
//}




// Question 4: member functions of Undergrad class
//Undergrad(string name, size_t ID, int grade): name(name), ID(ID), grade(grade){}

Undergrad::Undergrad(){
    string name = "Test";
   size_t ID = 0;
    int grade = 0;
}
Undergrad::Undergrad(string name, size_t ID, int grade){}

 int Undergrad::get_grade() const{
     if (grade < 0 || grade > 100){
         cout << "Grade is not valid, must be between 0 and 100." << endl;
         return 0;
     }
         return grade;
}


void Undergrad::update_grade(int newgrade){
    
    if (newgrade < 0 || newgrade > 100){
        cout << "Grade is not valid, must be between 0 and 100." << endl;
    }
    else{
        grade = newgrade;
    }
}

