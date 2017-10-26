%変数リスト
B=1.2;
delta_K=0.1;
delta_H=0.05;
theta=2;
low=0.05;
alpha=0.33;

a11 = (B + delta_K - delta_H)/alpha;
a21 = 1/theta*(delta_K*(1-theta)+low);
a31 = (1-alpha)/alpha*(delta_H - B - delta_K);

A = [a11 a21 a31]' ;
Slope_SS = [1 0 0; (alpha-theta)/theta 1 0; 0 -1 B];


%x= -10;
%y= 10;
%	if (x>0) & (y>0)
%		disp('x and y are positive');
%	elseif (x>0) | (y>0)
%		disp('x or y is positive');
%	else
%		disp('Neither x and y is positive');
%	end;
	
%x = 0;
%	for i = 0:100
%		x = x + i^2
%		if x > 100
%			disp(['x > 100 in loop' , num2str(i)])
%			break
%		end
%	end

