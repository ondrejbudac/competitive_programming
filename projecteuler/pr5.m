% project Euler 5 - Ondrej Budac
%
% 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
% What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

% For each prime p<20 we include p^k where k is maximal integer with
% p^k<=20
res=2^4*3^2*5*7*11*13*17*19;