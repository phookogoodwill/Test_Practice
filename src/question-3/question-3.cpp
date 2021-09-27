#include<iostream>
#include <vector>
#include <algorithm>    // std::transform
#include <cmath>        // std::sqrt
#include <numeric>      // std::accumulate


using namespace std;
int Square_(int x) {  return (x*x); }


int main()
{
     vector<int>  first{1, 2, 3, 4, 5};
     vector<int>  second;

     second.resize( first.size() );

    // Apply Square function to all elements of first vector
    //store them in second vector

    std::transform(first.begin() , first.end() , second.begin(), Square_ );

    // all values in second vector nd store it to sum
    auto sum = accumulate(second.begin() , second.end() ,0 );
    auto average = sum / second.size();
    auto rms_value = sqrt(average);

    cout<<rms_value;


    return 0;
}
