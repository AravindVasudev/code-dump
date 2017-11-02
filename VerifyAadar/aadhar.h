#pragma once

#include <string>
#include <algorithm>

namespace Aadhar {
    // The multiplication table
    const int verhoeff_d[10][10]  = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 0, 6, 7, 8, 9, 5},
        {2, 3, 4, 0, 1, 7, 8, 9, 5, 6},
        {3, 4, 0, 1, 2, 8, 9, 5, 6, 7},
        {4, 0, 1, 2, 3, 9, 5, 6, 7, 8},
        {5, 9, 8, 7, 6, 0, 4, 3, 2, 1},
        {6, 5, 9, 8, 7, 1, 0, 4, 3, 2},
        {7, 6, 5, 9, 8, 2, 1, 0, 4, 3},
        {8, 7, 6, 5, 9, 3, 2, 1, 0, 4},
        {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
    };
    
        // The permutation table
    const int verhoeff_p[8][10]= {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 5, 7, 6, 2, 8, 3, 0, 9, 4},
        {5, 8, 0, 3, 7, 9, 6, 1, 4, 2},
        {8, 9, 1, 6, 0, 4, 3, 5, 2, 7},
        {9, 4, 5, 3, 1, 2, 6, 8, 7, 0},
        {4, 2, 8, 6, 5, 7, 3, 9, 0, 1},
        {2, 7, 9, 3, 8, 0, 6, 4, 1, 5},
        {7, 0, 4, 6, 9, 1, 3, 2, 5, 8}
    };

    //The inverse table
    const int verhoeff_inv[] = {0, 4, 3, 2, 1, 5, 6, 7, 8, 9};

    bool is_aadhar_valid(std::string aadhar_number) {
        // Remove spaces
        aadhar_number.erase(std::remove_if(aadhar_number.begin(), aadhar_number.end(), isspace), aadhar_number.end());
    
        // Check length
        if (aadhar_number.length() != 12) {
          return false;
        }
      
        int c = 0;
        const int length = aadhar_number.length();
      
        for (int i = 0; i < length; i++) {
          c = verhoeff_d[c][verhoeff_p[(i % 8)][aadhar_number[length - i - 1] - '0']];
        }
      
        return c == 0;
    }
};