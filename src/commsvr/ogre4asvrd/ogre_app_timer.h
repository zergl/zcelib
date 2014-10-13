

#ifndef OGRE_APPLICATION_HANDLER_H_
#define OGRE_APPLICATION_HANDLER_H_

/****************************************************************************************************
class  Ogre_App_Timer_Handler APP的定时器Handler处理类
****************************************************************************************************/
class  Ogre_App_Timer_Handler : public  Server_Timer_Base
{

public:
    //
    Ogre_App_Timer_Handler();
protected:
    ~Ogre_App_Timer_Handler();

    //
    virtual int timer_timeout(const ZCE_Time_Value &time, const void *arg);

public:
    //设置错误重试的定时器
    int SetErrorRetryTimer();

public:
    //定时器ID,避免New传递,回收
    static const  int      OGRE_APP_TIME_ID[];
    //
    static const  int      STAT_TIME_INTERVAL = 30;
    //N秒以后尝试一次重新发送
    static const  int      RETRY_TIME_INTERVAL = 90;


};

#endif //_OGRE_APPLICATION_HANDLER_H_

