function J= costfunctionJ(x,y,theta)

m=size(x,1);
predictions = x*theta;
sqrerrors = (predictions-y).^2;


J=1/(2*m) * sum(sqrerrors);