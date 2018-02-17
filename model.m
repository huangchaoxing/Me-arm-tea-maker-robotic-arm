clear all
clc
l3=8.5;
l4=8;
A=[1 0 0 l4;
     0 1 0 0;
    0 0 1 0;
     0 0 0 1];
L1=Link([0 0 0 0],'modify');
%L2 = link([0 1 2 pi/2],'modify');
L2 = Link([0 0 0 pi/2],'modify');
L3 = Link([0 0 l3 0],'modify');
L4=Link([0 0 l4 0],'modify');
r = SerialLink([L1,L2,L3 L4])
figure(1)
q=[-0.61 1.36 -1.66 0];
plot(r,q)
grid on
hold on
T=r.fkine(q)

% s1=T(1,3);
% c1=-T(2,3);
% theta1=atan2(s1,c1)
% c23=-T(3,1);
% s23=-T(3,2);
% th23=atan2(s23,c23);
% 
% 
% c2=2*(T(2,4)+c1-8*s1*c23)/(17*s1);
% % c2=2*(T(1,4)-s1-8*c1*c23)/(17*c1);
% 
% s2=2*(T(3,4)+8*s23)/(-17);
% 
% theta2=atan2(s2,c2);
% if theta2<0
%     theta2=theta2+pi;
%  end
% theta3=acos(T(1,4)^2+T(2,4)^2+T(3,4)^2-1);
% 
%     theta3=-theta3
%     
% Q=[];
% Q(1)=theta1;
% Q(2)=theta2;
% Q(3)=theta3;
% Q(4)=0;
% figure(2)
% plot(r,Q)
% T1=r.fkine(Q)






% T03=T/A;
% theta=[];
% theta(4)=0;

% c2=sqrt(T03(1,4).^2+T03(2,4).^2)./l3;
% s2=[sqrt(1-c2.^2),-sqrt(1-c2.^2)];
% theta2=[];
% theta2(1)=atan2(s2(1),c2);
% theta2(2)=atan2(s2(2),c2);
% s1=-T03(1,3);
% c1=T03(2,3);
% theta(1)=atan2(s1,c1);
% phi=atan2(T03(2,4),T03(1,4));
% rou=sqrt(T(1,4).^2+T(2,4).^2);
% cosine=l3*c2./rou;
% sine=-sqrt(1-cosine.^2);
% theta(1)=atan2(sine,cosine)+phi;
% c2=T03(1,4)./(l3.*c1);
% s2=T03(3,4)./(-l3);
% theta(2)=atan2(s2,c2);

% theta(3)=atan2((T03(2,2)/(-s1)),T03(2,1)/s1)-theta(2);



% theta3=[];

% c23=T03(1,1);
% a=cos(theta(1));
% c23=c23./a;
% s23=[]
% s23=[sqrt(1-c23.^2),-sqrt(1-c23.^2)];
% theta3(1)=atan2(s23(1),c23)-theta2(1);
% theta3(2)=atan2(s23(2),c23)-theta2(1);
% theta3(3)=atan2(s23(1),c23)-theta2(2);
% theta3(4)=atan2(s23(2),c23)-theta2(2);
% Q=[];
% for i=1:2
%     theta(2)=theta2(i);
%     for j=1:4
%         theta(3)=theta3(j);
%         
%         Q=theta
%         
%     end
% end

% Q=theta
% % Q=r.ikine(T,[0 -pi/2 pi/4 0],[1 1 1 1 0 0])
% figure(2)
% plot(r,Q)
% grid on


