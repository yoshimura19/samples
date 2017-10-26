% Slide No.24 
% Plotting Many graphs

%変数
g = 0.05;
n = 0.1;
alpha = 0.33;
rho = 0.05;
delta = 0.4;

k = 0:0.01:1;
kplus = 1./((1+n).*(1+g).*(2+rho)).*(1-alpha).*k.^alpha;

plot(k,kplus,k,k)
legend ('transition','45 degree line')
xlabel('k_t')
ylabel('k_t+1')


subplot(1,2,1)
plot(k,kplus)	
title('transition')	
subplot(1,2,2)	
plot(k,k)	
title('45	degree	line')