// Given a string, find the length of the longest palindromic substring

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    
    for(int i=0; i<(str.length()/2); i++) {
        if(str.at(i) != str.at(str.length() - i -1))
            return false;
    }
    return true;
}

int brute_force(string s) {

    int n = s.length();
    int max = 0;

    for(int i=0; i<n; i++) {

        for(int j=i; j<n; j++) {

            if(isPalindrome(s.substr(i, j-i+1))) {
                if((j-i+1) > max)
                    max = j-i+1;
            }
        }
    }
    return max;
}

int expand_around_center(string s) {

    int n = s.length();
    int max = 0;

    for(int i=0; i<n; i++) {

        int a=i, b=i;
        while(a>=0 && b<n) {
            if(s.at(a) != s.at(b))
                break;
            a--;
            b++;
        }
        if(max < b-a-1)
            max = b-a-1;
    }

    for(int i=0; i<n-1; i++) {

        int a=i, b=i+1;
        while(a>=0 && b<n) {
            if(s.at(a) != s.at(b))
                break;
            a--;
            b++;
        }
        if(max < b-a-1)
            max = b-a-1;
    }

    return max;
}

int main() {

    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "\nLength of longest palindromic substring: " << expand_around_center(s);

    return 0;
}
