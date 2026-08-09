#include <string>
#include <algorithm> // For swap()

using namespace std;

class Solution {
public:
    // Helper function to keep our main code clean
    bool isVowel(char c) {
        c = tolower(c); // Handle uppercase vowels like 'A' or 'E'
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            
            // 1. Skip consonants on the left
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            
            // 2. Skip consonants on the right
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            
            // 3. The Swap Rule! 
            // If we found a vowel on both sides, swap them.
            if (left < right) {
                swap(s[left], s[right]);
                
                // Move inward to find the next pair
                left++;
                right--;
            }
        }
        
        return s;
    }
};