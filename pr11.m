% project Euler 11 - Ondrej Budac
%
% What is the greatest product of four adjacent numbers in the same 
% direction (up, down, left, right, or diagonally) in the given 
% (see pr11.in) 20×20 grid?

A=dlmread('pr11.in');
m1 = max(max(A(1:end-3,:) .* A(2:end-2,:) .* A(3:end-1,:) .* A(4:end,:)));
m2 = max(max(A(:,1:end-3) .* A(:,2:end-2) .* A(:,3:end-1) .* A(:,4:end)));
m3 = max(max(A(1:end-3,1:end-3) .* A(2:end-2,2:end-2) .* A(3:end-1,3:end-1) .* A(4:end,4:end)));
m4 = max(max(A(1:end-3,4:end) .* A(2:end-2,3:end-1) .* A(3:end-1,2:end-2) .* A(4:end,1:end-3)));
res = max([m1, m2, m3, m4]);