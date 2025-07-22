#include <cs50.h>
#include <math.h>
#include <stdio.h>

int is_valid_card(long int cc_number);
string card_type(long int cc_number);

int main(void)
{
    long int user_card_input = get_long("Enter your card number: ");

    if (is_valid_card(user_card_input) == false)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("%s", card_type(user_card_input));
    }
}

int get_first_n_digits(long int cc_number, int n, long int digits_amount)
{
    long divisor = pow(10, digits_amount - n);
    return (cc_number / divisor);
}

string card_type(long int cc_number)
{
    int digits_amount = (int) log10(cc_number) + 1;
    int first_two_digits = get_first_n_digits(cc_number, 2, digits_amount);
    int first_four_digits = get_first_n_digits(cc_number, 4, digits_amount);
    int first_digit = get_first_n_digits(cc_number, 1, digits_amount);

    if (first_digit == 4 && (digits_amount == 16 || digits_amount == 19 || digits_amount == 13))
    {
        return "VISA\n";
    }
    else if ((first_two_digits == 34 || first_two_digits == 37) && digits_amount == 15)
    {
        return "AMEX\n";
    }
    else if ((first_two_digits >= 51 && first_two_digits <= 55) && digits_amount == 16)
    {
        return "MASTERCARD\n";
    }
    else
    {
        return "INVALID\n";
    }
}

int is_valid_card(long int cc_number)
{
    long int temp = cc_number; // used for calculations without affecting the original card number
    long int first = 0;
    long int second = 0;
    const int max_single_digit = 9;

    while (temp > 0)
    {
        first += temp % 10;
        temp /= 10;
        long int second_temp = ((temp % 10) * 2);
        if (second_temp > max_single_digit)
        {
            second += second_temp % 10;
            second_temp /= 10;
        }
        second += second_temp % 10;
        temp /= 10;
    }

    int result = (first + second);

    if ((result % 10) == 0) // credit card is valid if Luhn's algorithm provides 0
    {
        return true;
    }
    else
    {
        return false;
    }
}
