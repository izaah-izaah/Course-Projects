#include "findnum.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
/*
Checking if the current test of the pointer search was a success T||F
 */


class Tester {
    public:
        bool test(int* got, int* expected);  //checks the 2 numbers using pointers

    private:
    
        size_t test_num = 1; // double threshhold 1.0 -> 1024.0
    

};



bool Tester::test(int* got, int* expected) {
    cout << "====  Test case " << test_num << "  ====" << endl;
    
    bool success = true;
    
    // NO POINTER VERSION
if (expected == nullptr) {
        if (got != expected) {
            cout << "Not passed yet. Keep trying!" << endl;
            cout << "        Got: " << *got << endl;
            cout << "   Expected: " << "nullptr" << endl;
            success = false;
            cout << endl;
        }
    }
    
    //WRONG POINTER VERSION
    else if (got != expected) {
        cout << "Not passed yet. Keep trying!" << endl;
        cout << "        Got: " << *got << " with address " << got << endl;
        cout << "   Expected: " << *expected << " with address " << expected << endl;
        success = false;
        cout << endl;
    }
    if (success) {
        cout << "Passed." << endl << endl;
    }
    
    test_num++;//iterates through the number of cases in the main.CPP main()
    
    return success; // recursive call
}


int main() {

    Tester tester;
    
    bool all_passed = true;
    
    
    
    // Test case 1
    int a1[] = {-5, 0, 1, 2, -3, 20, 15};
    
   //parameters needed - array.name, size#elements, number to find
    int* p1 = find_num(a1, 7, -3);
    
    //test pointer 1 (p1) in array 1 (a1)
    bool test_case_passed = tester.test(p1, &a1[4]);
    
    all_passed = test_case_passed && all_passed; //run through the block recursion

    
    
    
    // cases for |new int|
    
    // Test case 2 --- making the entire array a pointer
    int* a2 = new int[5]{1, 1, 1, 1, 1};
    int* p2 = find_num(a2, 5, 1); //new *got array

    test_case_passed = tester.test(p2, &a2[0]);
    all_passed = test_case_passed && all_passed;

    
    // Test case 3
    int* a3 = new int[1]{-1};
    int* p3 = find_num(a3, 1, -2); //right size wrong number
   
    ////checking for matching pointers even if the value "does not exist"
    test_case_passed = tester.test(p3, nullptr);
    all_passed = test_case_passed && all_passed;
    
    
    
    
    
    // Test case 4
    int a4[] = {-1, -2, -3, -4, -5};//pointer to the first element 
    int* p4 = find_num(a4, 5, -5);
    
    test_case_passed = tester.test(p4, &a4[4]); //checks the nnumber in pass by address
    all_passed = test_case_passed && all_passed;
    
    
    // Test case 5
    int a5[] = {5, 4, 3, 2, 1}; 
    int* p5 = find_num(a5, 5, 5);
    
    test_case_passed = tester.test(p5, &a5[0]);
    all_passed = test_case_passed && all_passed;
    
    
    if (all_passed) {
        cout << "Hooray, you passed all tests!" << endl;
    }
    
    

}
