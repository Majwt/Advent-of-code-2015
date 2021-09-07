#include <bits/stdc++.h>

using namespace std;
size_t divSum(size_t num)
{
    // Final result of summation of divisors
    size_t result =(num*10);
    if (num == 1) // there will be no proper divisor
        return result;
    // find all divisors which divides 'num'
    for (size_t i = 1; i != num; i++)
    {
        // if 'i' is divisor of 'num'
        // cout << sqrt(num) << endl;
        if (num % i == 0)
        {
            
            // if both divisors are same then add
            // it only once else add both

                // result += (i + num / i)*10;
                result += (i*10);
        }
    }

    // Add 1 to the result as 1 is also a divisor
    return result;
}
int main()
{
    for (size_t i = 1; i < 10; i++)
    {
        size_t sum = divSum(i);
        if (sum >=0) {
            cout << i << " " << sum << endl;
            
        }
    }
     
    // for (size_t num = 100000; num != 100000000; num++)
    // {
    //     int tot = 0;
    //     /* code */
    //     // cout << num <<"\t";
    //     for (size_t i = 1; i != num+1; i++)
    //     {
    //         if (num % i == 0)
    //         {
    //             // cout << i << " ";
    //             tot += (i*10);
    //         }
            
    //     }
    //     if (tot >= 36000000) {
    //         cout << num << "\t" << tot << endl;
    //         break;
    //     }
    // }
    return 0;
}