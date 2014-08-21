% project Euler 9 - Ondrej Budac
%
% A Pythagorean triplet is a set of three natural numbers, a < b < c, 
% for which, a^2 + b^2 = c^2
% For example, 32 + 42 = 9 + 16 = 25 = 52.
% There exists exactly one Pythagorean triplet for which a + b + c = 1000.
% Find the product abc.

N = 1000;
for a=1:N
  for b=1:N
    if a^2+b^2-(N-a-b)^2 == 0
      res = a*b*(N-a-b);
    end
  end
end

