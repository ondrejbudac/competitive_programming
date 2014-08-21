% project Euler 15 - Ondrej Budac
%
% Starting in the top left corner of a 2×2 grid, and only being able to 
% move to the right and down, there are exactly 6 routes to the bottom 
% right corner.
% How many such routes are there through a 20×20 grid?

% we choose which 20 moves, out of 40, are down.
M=20;
res = uint64(nchoosek(2*M,M));