clc; clear; close all;

s = tf('s');

g = 1.75/s;

[gm, pm] = margin(g)
figure(1);
margin(g); grid;

% Lag
% z1 = 0.72;
% p1 = 0.02555;
% 
% gclag = (s/z1 + 1)/(s/p1 + 1);
% 
% figure(2);
% margin(gclag*g); grid;

% Lead
desiredPm = 50

neededPm = desiredPm - pm

sqtZoP = tand((90-neededPm)/2)
sqtZP = 1.75;   % 0db crossover point

syms sz sp;
[solz, solp] = solve(sz/sp == sqtZoP^2, sz*sp == sqtZP^2, sz, sp)

z2 = 3.75;
p2 = 0.816;

kgm = 1;
k = sqtZoP;

gclead = kgm*k*((s/z2 + 1)/(s/p2 + 1));

figure(3);
margin(gclead*g); grid;

stepinfo(gclead*g/(1+gclead*g))