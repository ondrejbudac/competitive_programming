% project Euler 1 - Ondrej Budac
%
% If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
% Find the sum of all the multiples of 3 or 5 below 1000.

N = 1000;
a = false(1,N-1);
a(3:3:end) = true;
a(5:5:end) = true;
res = sum((1:999) .* a);
