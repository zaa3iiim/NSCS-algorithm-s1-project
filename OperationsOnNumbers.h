#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int sumOfDigits(int num)
{
	int sum = 0;

	while (num != 0)
	{
		sum += num % 10;
		num = num / 10;
	}
	return sum;
}

int reverseNumber(int num)
{

	int reversed_n = 0;

	while (num != 0)
	{
		reversed_n = reversed_n * 10 + num % 10;
		num /= 10;
	}
	return reversed_n;
}

bool isPalindrome(int num)
{
	int rev_num;
	rev_num = reverseNumber(num);
	return rev_num == num;
}

bool isPrime(int num)
{
	int i;

	for (i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int gcd(int a, int b)
{
	while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b)
{
	int lcm;
	lcm = a * b / gcd(a, b);
	return lcm;
}

long factorial(int n) {
    unsigned long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

bool isEven(int num)
{
	return num % 2 == 0;
}

void primeFactors(int num)
{
	int i = 2;

	while (num > 1)
	{
		if (num % i == 0)
		{
			// Keep dividing num by the factor i until it's no longer divisible
			while (num % i == 0)
			{
				num /= i;
				printf("%d ", i);
			}
		}
		i++; // Increment to the next potential factor
		// if i is not prime then we already divided by it least divisor after 1 so it won't divide the new num
	}
}

bool isArmstrong(int num)
{
	int digits, check = 0, save = num;
	digits = (int)log10(num) + 1;
	while (num != 0)
	{
		check = check + pow(num % 10, digits);
		num /= 10;
	}
	return check == save;
}

void fibonacciSeries(int num)
{
    if (num <= 0)
    {
        return;
    }

    int i, U_n, U_n2 = 1, U_n1 = 1;

    if (num >= 1)
    {
        printf("%d  ", U_n2);
    }

    if (num >= 2)
    {
        printf("%d  ", U_n1);
    }

    for (i = 3; i <= num; i++)
    {
        U_n = U_n2 + U_n1;
        printf("%d  ", U_n);
        U_n2 = U_n1;
        U_n1 = U_n;
    }
    printf("\n");
}

int sumDivisors(int num)
{
	int sum = 1, i;
	for (i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			sum += i;
			if (i != num / i)
			{ // Avoid adding the square root twice for perfect squares
				sum += num / i;
			}
		}
	}

	return sum;
}

bool isPerfect(int num)
{
	return num == sumDivisors(num);
}

bool isMagic(int num)
{
	while (num > 9)
	{
		num = sumOfDigits(num);
	}
	return num == 1;
}

bool isAutomorphic(int num)
{
	int square, digit_n = (int)log10(num) + 1; // Calculate the number of digits in the number
	square = num * num;						   // Calculate the square of the number

	// Check if the last digits of the square are equal to the original number
	return num == square % (int)pow(10, digit_n);
}

void toBinary(int num)
{
    if (num == 0)
    {
        printf("0\n");
        return;
    }

    char binary[32];
    int index = 0;

    while (num > 0)
    {
        binary[index++] = (num % 2) + '0';
        num /= 2;
    }

    for (int i = index - 1; i >= 0; i--)
    {
        printf("%c", binary[i]);
    }
    printf("\n");
}

bool isNarcissistic(int num)
{
	return isArmstrong(num);
}

double sqrtApprox(int num)
{
	double x1, x2;
	x2 = num;
	do
	{
		x1 = x2;
		x2 = (x1 + num / x1) / 2;
	} while (x1 - x2 > 0.0001);
	return x2;
}

double power(int base, int exp)
{
	double result = 1;
	int i, sign = 0;
	if (exp < 0)
	{
		exp *= -1;
		sign = -1;
	}
	for (i = 1; i <= exp; i++)
	{
		result *= base;
	}
	if (sign == -1)
	{
		result = 1 / result;
	}
	return result;
}

bool isHappy(int num)
{
	int sum = num, save = num, digit;
	while (sum > 9)
	{
		sum = 0;
		while (save > 0)
		{
			digit = save % 10;
			sum += digit * digit;
			save /= 10;
		}
		save = sum;
	}
	return sum == 7 || sum == 1; //  A number cannot be a happy number if, at any step, the sum of the square of digits obtained is a single-digit number except 1 or 7.
								 // This is because 1 and 7 are the only single-digit happy numbers
}

bool isAbundant(int num)
{
	return sumDivisors(num) > num;
}

bool isDeficient(int num)
{
	return !isAbundant(num);
}

int sumEvenFibonacci(int num)
{
	int i, U_n, U_n2 = 1, U_n1 = 1, sumEven = 0;
	for (i = 3; i <= num; i++)
	{
		U_n = U_n2 + U_n1;
		if (U_n % 2 == 0)
		{ // to only add even  terms
			sumEven += U_n;
		}
		U_n2 = U_n1;
		U_n1 = U_n;
	}
	return sumEven;
}

bool isHarshad(int num)
{
	return num % sumOfDigits(num) == 0;
}

unsigned long catalanNumber(int num) {
    if (num < 0) {
        return 0; // Catalan numbers are undefined for negative numbers
    }
    unsigned long numerator = factorial(2 * num);
    unsigned long denominator = factorial(num + 1) * factorial(num);
    return numerator / denominator;
}

void pascalTriangle(int num)
{
	int i, j, value;
	for (i = 0; i < num; i++)
	{
		value = 1;
		for (j = 0; j <= i; j++)
		{
			printf("%d ", value);
			value = value * (i - j) / (j + 1); // using the binomial coefficient
		}
		printf("\n");
	}
}

 long belNumber(int num)
{
	 long arr[num + 1]; // 1D array to store the current and previous row
	int i, j;

	// Initialize the first Bell number B(0) = 1
	arr[0] = 1;

	for (i = 1; i <= num; i++)
	{
		unsigned long prev = arr[0];
		arr[0] = arr[i - 1];

		for (j = 1; j <= i; j++)
		{
			unsigned long temp = arr[j];
			arr[j] = prev + arr[j - 1];
			prev = temp;
		}
	}

	// The Bell number is the first element of the last updated row
	return arr[0];
}

bool isKaprekar(int num)
{
    if (num == 1) return true; // 1 is a Kaprekar number

    long long square = (long long) num * num; // Compute square
    int numDigits = (int) log10(square) + 1;  // Count digits in square

    for (int d = 1; d < numDigits; d++)
    {
        long long divisor = (long long) pow(10, d);
        long long left = square / divisor;
        long long right = square % divisor;

        if (right > 0 && left + right == num)
        {
            return true; // Kaprekar number found
        }
    }

    return false; // Not a Kaprekar number
}

bool isSmith(int num)
{
	if (isPrime(num))
	{
		return false; // Smith numbers are composite
	}

	int digitSum = sumOfDigits(num); // Sum of digits of the original number
	int primeFactorDigitSum = 0;	 // Sum of digits of prime factors
	int i = 2;

	// Factorize the number and accumulate the digit sums of prime factors
	while (num > 1)
	{
		while (num % i == 0)
		{
			primeFactorDigitSum += sumOfDigits(i); // Add digit sum of the prime factor
			num /= i;
		}
		i++;
	}

	return digitSum == primeFactorDigitSum;
}

int sumOfPrimes(int num)
{
	int i, sum = 0;

	// Iterate through all numbers from 2 to num and sum up the primes
	for (i = 2; i <= num; i++)
	{
		if (isPrime(i))
		{
			sum += i;
		}
	}
	return sum;
}
