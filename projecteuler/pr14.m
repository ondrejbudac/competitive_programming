% project Euler 14 - Ondrej Budac
%
% Which starting number of the Collatz sequence, under one million, 
% produces the longest chain?

% we assume that the limits of integer representation is never reached,
% which is true (tested)

Nmax = 10^6;

clen = zeros(1,Nmax);
clen(1) = 1;
for N = Nmax: -1: 1
  if clen(N) == 0
    iters = N; i = 1;
    while (iters(i) > Nmax) || clen(iters(i)) == 0
      if mod(iters(i),2) == 0
        iters(i+1) = iters(i)/2;
      else
        iters(i+1) = 3*iters(i)+1;
      end
      i = i+1;
    end
    ind = find(iters <= Nmax);
    clen(iters(ind)) = clen(iters(end))+ (numel(iters)-ind);
  end
end
[~,res] = max(clen);
