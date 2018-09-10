// William Lu
// Systems pd4
// Work01 -- If you're feeling rusty, apply eul.
// 2018-09-12

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int multiple_3_5(){
	int sum = 0;
    int i;
    for (i = 0; i < 1000; i ++){
    	if (i % 3 == 0 || i % 5 == 0){
    		sum += i;
		}
	}
	return sum;
}

bool is_prime(long num){
	int ctr;
	for (ctr = 2; ctr < pow(num, 0.5); ctr ++)
		if (num % ctr == 0)
			return false;
	return true;
}

int smallest_multiple(int num){
	int arr[num];
	int i, j, product = 1;
	for (i = 0; i < num; i ++)
		arr[i] = i + 1;
	for (i = 2; i < num; i ++)
		if (is_prime(i)){
			bool divisible = false;
			for (j = 0; j < num; j ++)
				if (arr[j] % i == 0)
					divisible = true;
			while (divisible){
				product *= i;
				for (j = 0; j < num; j ++)
					if (arr[j] % i == 0)
						arr[j] /= i;
				divisible = false;
				for (j = 0; j < num; j ++)
					if (arr[j] % i == 0)
						divisible = true;
			}
		}
	for (i = 0; i < num; i ++)
		product *= arr[i];
	return product;
}

int sum_square_diff(int num){
	int sum_of_square = 0, square_of_sum = 0;
	int i;
	for (i = 1; i <= num; i ++){
		sum_of_square += i * i;
		square_of_sum += i;
	}
	square_of_sum *= square_of_sum;
	return square_of_sum - sum_of_square;
}

int even_fibonacci(){
	int sum = 0;
	int left = 1, right = 2;
	int temp;
	while (right <= 4000000){
		if (right % 2 == 0)
			sum += right;
		temp = left;
		left = right;
		right += temp;
	}
	return sum;
}

int max_prime_factor(long num){
	if (is_prime(num))
		return num;
	int div;
	for (div = 2; div < num; div ++)
		if (num % div == 0)
			return max_prime_factor(num / div);
}

bool is_palindrome(int num){
	int ctr, copy0 = num, copy1 = num;
	for (ctr = 0; copy0 >= 1; ctr ++)
		copy0 /= 10;
	int arr[ctr];
	for (ctr = 0; copy1 >= 1; ctr ++){
		arr[ctr] = copy1 % 10;
		copy1 /= 10;
	}
	int backward = 0, size = sizeof(arr) / sizeof(arr[0]);
	for (ctr = 0; ctr < size; ctr ++)
		backward = backward * 10 + arr[ctr];
	return num == backward;
}

int palindrome_product(){
	int product, i, j;
	for (i = 999; i >= 100; i --)
		for (j = 999; j >= i; j --){
			product = i * j;
			if (is_palindrome(product))
				return product;
		}
	return -1;
}

int main(){
    printf("%d\n", multiple_3_5());
    printf("%d\n", smallest_multiple(20));
    printf("%d\n", sum_square_diff(100));
    printf("%d\n", even_fibonacci());
    printf("%d\n", max_prime_factor(600851475143));
    printf("%d\n", palindrome_product());
    return 0;
}
