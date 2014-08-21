% project Euler 4 - Ondrej Budac
%
% A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
% Find the largest palindrome made from the product of two 3-digit numbers.

ndigit = 3;
base = 10;

limits = [base^(ndigit-1), base^ndigit-1];

% create all possible products
[X,Y] = meshgrid(limits(1):limits(2), limits(1):limits(2));
M = X.*Y;
clear X Y;

% we assume that the palindrome we search has maximum number of digits
% and we reverse all the values in M
orig = M;
rev=zeros(size(M));
for i=1:2*ndigit
  rev=base*rev+mod(orig,base);
	orig=floor(orig/base);	
end
res = max(M(M==rev));

