/*
 * recursion.h
 *
 *  Created on: 10/09/2015
 *      Author: pperezm
 */

#ifndef RECURSION_H_
#define RECURSION_H_

#include "exception.h"
#include <iostream>

//Complejidad: O(n) porque la i incrementa en 1
long sum_seq(int n) {
	int sum = 0;
	for(int i = 0; i <= n; i++) {
		sum+=i;
	}
	return sum;
}

//Complejidad: O(n) porque la n decrementa en 1
long sum_rec(int n) {
	if(n<=1){
		return n;
	} else {
		return n+sum_rec(n-1);
	}
}

//Complejidad: O(n) porque la i incrementa en 1
long fact_seq(int n) {
	int fact = 1;
	for(int i = 1; i <= n; i++) {
		fact*=i;
	}
	return fact;
}

//Complejidad: O(n) porque la n decrementa en 1
long fact_rec(int n) {
	if (n <= 1) {
		return n;
	} else {
		return n*fact_rec(n - 1);
	}
	return 0;
}

//Complejidad: O(n) porque la i incrementa en 1
long fib_seq(int n) {
	int a = 1;
	int b = 1;
	for(int i = 2;i < n; i++){
		int c = b;
		b = a+b;
		a = c;
	}
	return b;
}

//Complejidad: O(n) porque la n decrementa en 1
long fib_rec(int n) {
	if(n <= 2){
		return 1;
	} else {
		return fib_rec(n-1)+fib_rec(n-2);
	}
	return 0;
}

long gcd_seq(long a, long b) {
	int res = 1;
	while (a % b > 0){
		res = a % b;
		a = b;
		b = res;
	}
	return b;
}

long gcd_rec(long a, long b) {
	if(a % b == 0) {
		return a;
	} else {
		return gcd_seq(b, a % b);
	}
	
}

bool find_seq(int arr[], int size, int val) {

	for(int i = 0; i < size; i++){
		if (arr[i] == val) {
			return true;
		}
	}

	return false;
}

bool find_rec(int arr[], int low, int high, int val) {

	

	return false;
}

int max_seq(int arr[], int size) {
	return 0;
}

int max_rec(int arr[], int low, int high) {
	return 0;
}

int unimodal_seq(int arr[], int size) {
	return 0;
}

int unimodal_rec(int arr[], int low, int high) {
	return 0;
}

int unimodal_rec(int arr[], int size) {
	return 0;
}

int bs_seq(int arr[], int size, int val) {
	return 0;
}

int bs_aux(int arr[], int low, int high, int val) {
	return 0;
}

int bs_rec(int arr[], int size, int val) {
	return 0;
}
#endif /* RECURSION_H_ */
