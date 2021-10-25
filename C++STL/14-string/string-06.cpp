#include <iostream>
#include <string>
#include <unordered_map>

/***
 * Challenge:
 *
 * You are given two phrases (sequences of words, consisting of alphabetical letters, separated by space characters)
 *
 * Your job is to detect if they have the same "pattern".
 *
 * For example:
 *
 * "cat cat dog"     is a match for     "red red blue"
 * "cat dog cat"     is a match for     "red blue red"
 * "cat cat dog"     is a match for     "dog dog cat"
 * "cat cat dog"     is not a match for "dog cat cat"
 * "cat cat dog cat" is not a match for "red red blue blue"
 * "cat cat dog dog" is a match for     "red red blue blue"
 * "cat cat dog cat" is a match for     "red red blue red"
 */

/*** Your code here, include any standard library that you like etc. ***/

/*
key: value
cat : red
dog : blue
*/

bool is_match(std::string a, std::string b) {
   std::unordered_map<std::string, std::string> hashMapA;
   std::unordered_map<std::string, std::string> hashMapB;
  
   size_t cur_pos_a = 0, cur_pos_b = 0;
   size_t prev_pos_a = 0, prev_pos_b = 0;
   if (a.length() == 0 && b.length() == 0) return true;
   if (a.length() == 0 || b.length() == 0) return false;
  
   while (true) {
     std::string a_word;
     std::string b_word;
     cur_pos_a = a.find(" ", prev_pos_a);
     if (cur_pos_a == std::string::npos) {
       a_word = a.substr(prev_pos_a);
       a_word = a_word.substr(0, a_word.length());
     } else {
       a_word = a.substr(prev_pos_a, cur_pos_a - prev_pos_a); // word
     }

     cur_pos_b = b.find(" ", prev_pos_b);
     if (cur_pos_b == std::string::npos) {
        b_word = b.substr(prev_pos_b);
        b_word = b_word.substr(0, b_word.length());
     } else {
       b_word = b.substr(prev_pos_b, cur_pos_b - prev_pos_b);
     }

     if (hashMapA.find(a_word) != hashMapA.end()) { // Present
       if (hashMapA[a_word] != b_word) // Not match
       {
         return false;
       }
     } else { // Not present
       hashMapA[a_word] = b_word;
     }

     if (hashMapB.find(b_word) != hashMapB.end()) {
         if (hashMapB[b_word] != a_word) return false;
     } else {
         hashMapB[b_word] = a_word;
     }
     prev_pos_a = cur_pos_a + 1; //  +1 for comma
     prev_pos_b = cur_pos_b + 1; //  +1 for comma
     if (cur_pos_a == std::string::npos || cur_pos_b == std::string::npos) break;
   }
  
   // Check if a or b has any remaining words
   return cur_pos_a == cur_pos_b;
}

/*** Tests of your solution ***/

void test_case(std::string a, std::string b, bool expected) {
  std::cout << "is_match(\"" << a << "\", \"" << b << "\") == " << std::boolalpha << expected << ": ";
  std::cout.flush();
  if (expected == is_match(a, b)) {
    std::cout << "OK" << std::endl;
  } else {
    std::cout << "!" << std::endl;
  }
}

int main() 
{
  test_case("cat", "red", true);
  test_case("cat", "blue", true);
  test_case("dog", "red", true);
  test_case("dog", "blue", true);
  test_case("cat cat", "red red", true);
  test_case("cat cat", "red blue", false);
  test_case("cat dog", "red blue", true);
  test_case("cat cat", "red red", true);
  test_case("cat dog", "blue blue", false);
  test_case("cat cat dog", "red red blue", true);
  test_case("cat dog cat", "red blue red", true);
  test_case("cat cat dog cat", "red red blue red", true);
  test_case("cat cat dog", "dog dog cat", true);
  test_case("cat cat dog", "dog cat cat", false);
  test_case("cat cat dog", "red red blue blue", false);
  test_case("cat cat dog cat", "red red blue blue", false);
  test_case("cat cat dog dog", "red red blue blue", true);
  test_case("dog dog cat cat", "red red blue blue", true);
  test_case("dog dog cat cat", "cat cat dog dog", true);
  test_case("dog cat dog cat", "turquoise magenta turquoise magenta", true);
}
