#include "./SnakeGameTesting/SnakeGame.h" // Adjust the path to match the actual location of SnakeGame.h
#include "bits/stdc++.h"
using namespace std;

void getnumbers(int n)
{
    // Declare a vector to store
    // divisors
    vector<int> divisor;
 
    // store all divisors of number
    // in array
    for (int i = 2; i * i <= n; i++) {
 
        // store all the occurrence of
        // divisors
        while (n % i == 0) {
            divisor.push_back(i);
            n /= i;
        }
    }
 
    // check if n is not equals to -1
    // then n is also a prime factor
    if (n != 1) {
        divisor.push_back(n);
    }
 
    // Initialize the variables with 1
    int a, b, c, size;
    a = b = c = 1;
    size = divisor.size();
 
    for (int i = 0; i < size; i++) {
 
        // check for first number a
        if (a == 1) {
            a = a * divisor[i];
        }
 
        // check for second number b
        else if (b == 1 || b == a) {
            b = b * divisor[i];
        }
 
        // check for third number c
        else {
            c = c * divisor[i];
        }
    }
 
    // check for all unwanted condition
    if (a == 1 || b == 1 || c == 1
        || a == b || b == c || a == c) {
        cout << "-1" << endl;
    }
    else {
        cout << a << ' ' << b
             << ' ' << c << endl;
    }
}
 




// Function prototype
void printAllPrimeFactors(int num);

int main()
{


}




void printAllPrimeFactors(int num )
{

    // print the number of 2s that divide num 
  while( num % 2 == 0){
     cout << 2 << " " ; 
     num = num / 2 ;


  }

  // n must be odd at this point so we can skip.
  // one element note: (i = i + 2)
  for ( int i =3 ; i*i  <=num  ; i= i  + 2 ){
      
     while (num % i ==0 ){
       cout << i << " " ;
       num = num / i ; 


     }




    }
    if ( num > 2){
        cout << num << " " ;
     }

}



