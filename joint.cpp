#include <Servo.h>
float pi=3.14159;
float L3=8.5;
float L4=8.0;
Servo base,rArm,fArm,claw;
void setup(){
  base.attach(11);     // base 伺服舵机连接引脚11 舵机代号'b'
  delay(200);          // 稳定性等待
  rArm.attach(10);     // rArm 伺服舵机连接引脚10 舵机代号'r'
  delay(200);          // 稳定性等待
  fArm.attach(9);      // fArm 伺服舵机连接引脚9  舵机代号'f'
  delay(200);          // 稳定性等待
  claw.attach(6);      // claw 伺服舵机连接引脚6  舵机代号'c'
  delay(200);          // 稳定性等待
 pinMode(13, OUTPUT);
  initialize();
 delay(1000);
 delay(1000);
  Serial.begin(9600); 
  Serial.println("Welcome to Taichi-Maker Robot Arm Tutorial");   
}




void Ikne(float x,float y,float h)
 { if(y<0) 
   { y=y+1;}
  // if(y>0)
  // {y=y-1;}
  float r=sqrt(x*x+y*y)-7;
    h=h-2;
   if(sqrt(r*r+h*h)>(L3+L4))
    {  Serial.println("no solution");
       while(1);
      }
    float angle1;
    angle1 =atan(y/x)/pi*180;
    float theta1=angle1;

    float angle3;
    float cos3=r*r+h*h-(L3*L3+L4*L4);
           cos3=cos3/ (2*L3*L4);
   // Serial.println(cos3);
    angle3=-acos(cos3)/pi*180;
   // Serial.println(angle3);
    float theta3=angle3;

   float fi;
   float cosfi=(r*r+h*h+L3*L3-L4*L4)/(2*L3*sqrt(r*r+h*h));
   
   fi=acos(cosfi);
   // Serial.println(fi);
   float beta=atan(h/r);
    
   float angle2;
   if (angle3<0)
    {  angle2=beta+fi;
      }
   else {angle2=beta-fi;
        }
    float theta2=angle2/pi*180;
          angle2=theta2;

          
   delay(10);
    Drive_base(theta1);
    delay(500);
    Drive_rArm(theta2);
    delay(500);
    Drive_fArm(theta3);
 /*  Serial.println("theta1");
   Serial.println(theta1);
   Serial.println("theta1 in radius");
   Serial.println(angle1/180*pi);
   Serial.println("theta2");
   Serial.println(theta2);
   Serial.println("theta2 in radius");
   Serial.println(angle2/180*pi);
   Serial.println("theta3");
   Serial.println(theta3);
   Serial.println("theta3 in radius");
   Serial.println(angle3/180*pi);*/
  }
 



void loop()
{ 
 
char serialCmd;
  if(Serial.available() > 0)

 { serialCmd=Serial.read();
  Serial.print("serialCmd = ");
  Serial.print(serialCmd);  
  int X;
  int Y;
  X=(int)serialCmd;
  while(Serial.available() > 0)
  Serial.read();//清空缓存
  delay(30);
serialCmd=Serial.read();
  Y=(int)serialCmd;
  X=X-2;//补偿误差
  Y=Y-2;//补偿误差
 // Serial.println(x);
 // Serial.println(Y);
 // int coordinate = Serial.parseInt(); 
 
 //实际泡茶
  claw.write(45);
 delay(300);
 Ikne(10,2,2);
 delay(1000);
 // Ikne(15,5,2);
  delay(500);
  Serial.println("pick up the tea bag");
  claw.write(100);
  
  
 // for(int j=1;j<=20;j++)
 // {delay(1000);}
 delay(1000);
 delay(1000);
 delay(1000);
 Ikne(10,2,8);
  Serial.println("go to the cup");
  Ikne(X,-Y,7);
 // delay(100);
 delay(1000);
 Ikne(X,-Y,5);
/* int RearState;
 RearState=rArm.read();
 rArm.write(RearState+5);//往下放*/
 delay(1000);
 Ikne(X,-Y,3);
 delay(1000);
 //Ikne(X,-Y,2);
 delay(500);
 Serial.println("wait for a while");
 waiting();
 int ForwardState;
 ForwardState=fArm.read();
 Serial.println("up and down");
  updown(X,-Y);
    
 delay(300);
 //initialize();
 //dump();
 initialize();
 delay(1000); //实际泡茶

  
  
  //Ikne(X,-Y,4);
  delay(1000);

 }
}





void Drive_base(float theta)
     { float Pose=theta+90;
       
        
                   //base.write(Pose);




                  float fromPos = base.read();
      
       
      if (fromPos <= Pose){  //如果“起始角度值”小于“目标角度值”
        for (float i=fromPos; i<=Pose; i++){
          base.write(i);
          delay (15);
        }
      } else {  //否则“起始角度值”大于“目标角度值”
        for (float i=fromPos; i>=Pose; i--){
          base.write(i);
          delay (15);
        }
      }
        
     }
void Drive_rArm(float theta)
     { float Pose=180-theta;
      
                     //rArm.write(Pose);
                     float fromPos = rArm.read();
      
       
      if (fromPos <= Pose){  //如果“起始角度值”小于“目标角度值”
        for (float i=fromPos; i<=Pose; i++){
          rArm.write(i);
          delay (15);
        }
      } else {  //否则“起始角度值”大于“目标角度值”
        for (float i=fromPos; i>=Pose; i--){
          rArm.write(i);
          delay (15);
        }
      }
                  
      }

 void Drive_fArm(float theta)
     {  //theta=-theta;
        //int Pose=90-theta;
       // fArm.write(Pose);
       theta=-theta;
       float Pose,currentrArmPose;
           currentrArmPose=rArm.read();
           Pose=270-theta-currentrArmPose;
          
                 //  fArm.write(Pose);
                 float fromPos = fArm.read();
      
       
      if (fromPos <= Pose){  //如果“起始角度值”小于“目标角度值”
        for (float i=fromPos; i<=Pose; i++){
          fArm.write(i);
          delay (15);
        }
      } else {  //否则“起始角度值”大于“目标角度值”
        for (float i=fromPos; i>=Pose; i--){
          fArm.write(i);
          delay (15);
        }
      }
             
                 
      }

void Drive_claw(float theta)
     {  claw.write(theta);
      }
int Get_theta3(float r_pose,float f_pose)
{    float theta3;
     theta3=270-(r_pose+f_pose);
     return theta3;
  }


void updown(int x,int y)
{   /*  int fromPos=rArm.read();
      int fromPosf=fArm.read();
     int Pose=fromPos-10;
      
   
         for (float i=fromPos; i>=Pose; i--){
          rArm.write(i);
          fArm.write(fromPosf+10);
          delay (5);
        }
     delay(10);
     fromPos=rArm.read();
     Pose=fromPos+10;
  
            for (float i=fromPos; i<=Pose; i++){
          rArm.write(i);
          fArm.write(fromPosf);
          delay (5);
        } 
      
     delay(100);*/
   for(int i=1;i<=5;i++)
   {Ikne(x,y,5);
   
   Ikne(x,y,3);
   delay(100);
   }
}

void waiting()

{
  for(int i=1;i<=15;i++)
  {delay(1000);
    }
  
  }

void dump()
{ int fdumppose=75;
   fArm.write(fdumppose);
   delay(500);
   delay(1000);
   int rdumppose=100;
   rArm.write(rdumppose);
   delay(500);
   delay(1000);
   Ikne(11,6,2);
   delay(300);
   claw.write(30);
   delay(300);
   initialize();
  
  }

 void initialize()
 {
    base.write(90); 
  delay(10);
  fArm.write(90); 
  delay(10);
  rArm.write(90); 
  delay(10);
  claw.write(100);  
  delay(2000); }
  
