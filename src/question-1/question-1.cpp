#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <algorithm>   // std::find_first_of
#include <vector>

//find_first of returns an iterator to the first element in the range of (first1,last1)
//that matches any of the elements in first2,last2.
//If no such element is found, the function returns last1.


//Iterator returns position of the first element in fist vector
TEST_CASE("Iterator to be at the first vector if a match is made  ")
{
    std::vector<char> vowels  {'a' ,'e' ,'i', 'o' , 'u' };
    std::vector<char> Letters{'a' , 'b' , 'c' , 'd' , 'e' };

    auto iterator_ = find_first_of( vowels.begin(), vowels.end(), Letters.begin(), Letters.end() );

    CHECK(iterator_ == vowels.begin() );
}

//Find first of only iterates using the first vector to find a match in the second
TEST_CASE("Returned iterator does not contain the matched word for both containers/vectors ")
{
     std::vector<char> vowels  {'a' , 'e' , 'i' , 'o' , 'u' };
     std::vector<char> Letters  {'f' , 'd' , 'c' , 'b' , 'a' };

    auto iterator_ = find_first_of( vowels.begin(), vowels.end(), Letters.begin(), Letters.end() );
    /// matching case is  letter a
    // last position in letters
    CHECK_FALSE(iterator_ == Letters.end());


    SUBCASE( " Iterator still at the vowels.begin() ")
     {
         CHECK(iterator_ == vowels.begin() );
     }

}

//Iterator will be at the last position of the first range if no match is found
TEST_CASE("Iterator at the last position if no match is found ")
{
    std::vector<char> vowels  {'a' , 'e' , 'i' , 'o' , 'u' };
    std::vector<char> Letters  {'f' , 'd' , 'c' , 'b' , 'g' };

    auto iterator_ = find_first_of( vowels.begin(), vowels.end(), Letters.begin(), Letters.end() );
    /// matching case is  letter a
    // last position in letters
    CHECK( iterator_ == vowels.end() );

    SUBCASE(" iterator not at The end of Letters.end() ")
    {
        CHECK_FALSE(iterator_ == Letters.end());
    }
}


// For multiple matches it still returns iterator to the first element matched in second vector
TEST_CASE("Iterator still at the first position if multiple matches are found ")
{
     std::vector<char> vowels  {'a' , 'a' , 'a' , 'o' , 'u' };
     std::vector<char> Letters {'j' , 'k' , 'c' , 'a' , 'g' };

    auto iterator_ = find_first_of( vowels.begin(), vowels.end(), Letters.begin(), Letters.end() );
    /// matching case is  letter a
    /// should still be at first position
    CHECK( iterator_ == vowels.begin() );
}
