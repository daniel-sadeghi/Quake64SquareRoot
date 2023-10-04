/**
 * Calculates the square root. Only accepts positive floating points (including 0)
 *
 * This algorithm is entirely based on the quake inverse square root algorithm, just converted to 64 bit and instead of using -1/2log_2(x) for the inverse
 * square root, we are using 1/2log_2(x) for the square root. Using just a single iteration of Newton's method already makes this algorithm 2ns faster (~15%)
 * and substantially more accurate than using the original quake inverse square root algorithm then inverting the output. A second newton's iteration will
 * result in similar speed to the quake inverse square root while gaining an improved accuracy that blows it out of the water.
 *
 * Compared to cmath's system sqrt, this algorithm is ~1ns slower and inaccurate.
 *
 *
 * Curious enough, the initial guess by both this algorithm and the inverted quake_sqrt algorithm actually trades blows with each other in speed and accuracy.
 * It seems that the bigger performance gain here comes from the fact that the newton's method formula for the square root is simpler and thus requires fewer
 * arithmetic operations than the original quake inverse square root algorithm.
 *
 **/

#include <bit>
#include <limits>
#include <cstdint>
#include <iostream>

/* //TODO: Rewrite algorithm in "proper" C++ by using std::bit_cast()
double sqrt(double x) {
    double const y = std::bit_cast
    //0xFFBD1DF4DD8D0E7
}
*/

double quakeSqrt64(double x) {
    if (x == 0)
        return 0;

    double y = x;
    uint64_t i = *(uint64_t *)&y;       //bit cast to 64 bit integer
    i = 0x1FF7A3BEA91D9CF0 + (i >> 1);  //Magic first approximation of square root
    y = *(double*)&i;                   //bit cast back to a double
    y = 0.5 * (y + x/y);                //one iteration of newton's method
    y = 0.5 * (y + x/y);                //second iteration
    return y;
}

int main()
{
    std::cout << quakeSqrt64(2.153) << std::endl;

    return 0;
}
