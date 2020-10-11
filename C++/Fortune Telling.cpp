#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long int no_of_flowers, answer;
    cin>>no_of_flowers;

    unsigned long int sum_of_even_numbers = 0, sum_of_odd_numbers = 0, smallest_odd_number = 99999999;
    for(unsigned long int i = 1; i <= no_of_flowers; i++)
    {
        unsigned long int petals;
        cin>>petals;

        if(petals%2 == 0)
            sum_of_even_numbers += petals;
        else
        {
            sum_of_odd_numbers += petals;
            smallest_odd_number = min(smallest_odd_number, petals);
        }
    }

    if(sum_of_odd_numbers == 0)
        answer = 0;
    else
    {
        if(sum_of_odd_numbers%2 == 0)
            answer = sum_of_even_numbers + sum_of_odd_numbers - smallest_odd_number; //To keep the sum odd
        else if(sum_of_odd_numbers%2 == 1)
            answer = sum_of_even_numbers + sum_of_odd_numbers;
    }
    cout<<answer;
    return 0;
}

