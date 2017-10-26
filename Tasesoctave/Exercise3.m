% Exercise 3   
% OLG modelのストック収束を計算

%変数
g = 0.05;
n = 0.1;
alpha = 0.33;
rho = 0.05;
delta = 0.4;

k = 1000;    % 初期値
	for i = 1;1000
	 k_start=k;
	 k = 1/((1+n)*(1+g)*(2+rho))*(1-alpha)*k^alpha;
		if abs(k - k_start) < 10^(-6)
			break
		end
	end
disp(k)
