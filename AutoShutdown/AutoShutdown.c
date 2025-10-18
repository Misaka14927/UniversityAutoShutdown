#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define OFFLINE 2300  //熄灯时间  

int getTime();
int time2Second();
int countDown();

//二十四小时制度的本地时间
int getTime() {
    time_t rawtime;
    struct tm *timeinfo;
    
    // 获取当前时间
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    // 计算时间数值：小时 * 100 + 分钟
    int timeValue = timeinfo->tm_hour * 100 + timeinfo->tm_min;
    
    return timeValue;
}
//时间转化为秒（貌似复杂了
int time2Second (int  inputTime){
    int inputHour = inputTime /100 ;
    int inputMins = inputTime - (inputHour * 100);
   
    return (inputMins * 60 + inputHour * 3600) ;
}
//倒计时秒
int countDown (){
    int target , current;

    target  =  time2Second(  OFFLINE  );
    current =  time2Second( getTime() );

    target  =  target - current ;
    

    return target ;         
}

int main (){
    char command[50] ;

    sprintf(command, "shutdown -s -t %d", countDown());
    system(command);

    return 0 ;
}