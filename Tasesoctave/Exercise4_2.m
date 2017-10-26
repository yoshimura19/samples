% Exercise4
% ソローモデルのダイナミクスをプロット

%変数
g = 0.05;
n = 0.1;
alpha = 0.33;
rho = 0.05;
delta = 0.4;

%s = 0.3;
%k=0:0.01:0.1;
%kplus = s*k.^alpha - (n + g + delta).*k;

s=0.3;
for i=1:3 
	k=0:0.001:1;
	kplus = s*k.^alpha - (n + g + delta).*k;

plot(k,kplus,k,k)
hold on
	s = s + 0.3
end 
title('transition')
xlabel('kt')
ylabel('f(x)')
