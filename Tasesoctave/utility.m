% function　ファイル
% CRRA型効用関数

function y = utility(c,theta)

if theta == 1
	y = log(c);
else
	y = c.^(1-theta)/(1-theta);
end
