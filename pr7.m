% project Euler 7 - Ondrej Budac
%
% By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
% What is the 10 001st prime number?

l = primes(200000);
res = l(10001);