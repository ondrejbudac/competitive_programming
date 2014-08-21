% project Euler 13 - Ondrej Budac
%
% Work out the first ten digits of the sum of the following (see pr13.in)
% one-hundred 50-digit numbers.

f = fopen('pr13.in');
c = textscan(f,'%s','delimiter','\n');
fclose(f);
c=cat(1,c{:}{:});
c = reshape(str2num(c(:)), size(c));
c = sum(c, 1);
c = flip(c,2);
c(60)=0;
while any(c>9)
    ind = find(c>9);
    pom = (c(ind) - mod(c(ind),10))/10;
    c(ind) = c(ind) - pom*10;
    c(ind+1) = c(ind+1) + pom;
end
endc = find(c, 1, 'last');
res = dot(c(endc-9:endc), (10.^(0:9)));