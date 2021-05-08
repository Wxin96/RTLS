#ifndef FQ512NetShowL_H
#define FQ512NetShowL_H
/*

//功能说明：使用网络IP协议，控制国际标准DMX512灯光设备
//当前版本：V1.0.0.6
修改说明：
    1，增加用开发包可 修改设备IP和 FQ512NetShow灯光网络号Net->SubNet->DMX512域等功能.
    2, 增加接收Art-Net数据包回调函接收功能。
    3，增加自适应降低CPU使用率功能。
    4，为了简单化，修改了2个回调函数，把4个指针参数 改为数值型。其他函数保持不变！！！
开发库有提供X64位和X32位版本，请正确选择
*/

#ifdef FQ512NetShow_DLL_API
#else
#define FQ512NetShow_DLL_API __declspec(dllimport)
#endif

#pragma         pack(1)
//size=71
//Poll指令查询，设备返回的信息结构体

typedef   struct   FQ512NetDevice_
{

    unsigned char SN[24];//序列号

    unsigned char IP[4];//设备IP
    unsigned char Mask[4];//掩码
    unsigned char Gate[4];//网关
    unsigned char RemoteIp[4];//远程IP,DMX-->NET用

    unsigned char OutUx[4];//DMX硬件口绑定输出DMX域（0~15）
    unsigned char InUx[4];//DMX硬件口绑定输入的DMX域（0~15）

    unsigned char NumDmxPorts;//V1.4版本前的盒子：设备总DMX口数（1~4）；V1.5版本后的盒子：高4位代表可DMX转net的总DMX域数,低4位代表可Net转DMX或SPI的总DMX域数
    unsigned char Net;//设备的FQ512Net网（0~127）
    unsigned char SubNet;//设备的FQ512Net子网（0~15）
    unsigned char WorkMode;	//工作模式:0=NET-->DMX;1=DMX-->NET（注：对V1.5以上的盒子才有效）

    unsigned char ShortName[18];//设备名
    unsigned char FireWareVer;//固件版本

}FQ512NetDevice;

#pragma   pack()

    //======================================
//指令宏定义
#define Set_WorkMode 0  //设置工作模式
        #define  WorkMode_NetToDmx 0//NET转DMX模式
        #define  WorkMode_DmxToNet 1//DMX转NET模式
#define Set_FQ512Net 1   //设置灯光网络号
#define Set_IPAddress 2  //设置设备IP

#define Set_OpUpdateAllDmxOut 3  //同步输出指令

#define Set_RecArtNetOnOff 50 //V1.5版本增加，可设置是否接受art-net信号功能，默认不接收
    #define RecArtNetOn 1//接收
    #define RecArtNetOff 0//不接收

#define Set_AutoSleep 51//设置自动降低CPU使用率，默认开
    #define AutoSleepOn 1//开 自适应降低CPU使用率
    #define AutoSleepOff 0//关闭，自适应降低CPU使用率

#define Set_ResetDevice 100  //复位设备
#define Set_ResetToFactory 101  //恢复出厂默认设置值
//====================================
//广播控制宏定义
#define Broadcast_NO             0  //无广播，只控制单个DMX域

#define Broadcast_DEVICE_ALLPORT 1  //对设备的所有DMX域端口广播
#define Broadcast_SUBNET_ALLUNI  2 //对FQ512Net的SubNet子网内广播
#define Broadcast_NET_ALLSUBNET  3 //对FQ512Net的Net大网广播
#define Broadcast_ALLNET         255 //对FQ512Net全部设备广播
//--------------------------------
//立即更新或缓存宏定义
#define  OUT_Update 1 //立即更新输出DMX
#define  OUT_Temp 0   //先缓存，无输出到DMX口

////IP模式设置
#define  Static_IPMode 0 //静态IP
#define  AutoArtNet_IPMode 1  //自动Art-Net IP模式

//***************************《开发包函数原型声明》*******************

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    //基本函数
    //1.初始化网络环境函数
    //程序开始，必须先初始化网络接口
    //返回值：0~9=默认选择的网卡序号；255=初始化网络接口失败！
    FQ512NetShow_DLL_API unsigned char  _stdcall Init_Net(void);//程序开始调用 初始化网络环境

    //2，指定要发送的目标设备IP地址函数
    //设置目标设备的IP地址，如：IP1=192，IP2=168，IP3=1，IP4=220----》发送目标设备IP:192.168.1.220
    FQ512NetShow_DLL_API void  _stdcall Set_RemoteIp(unsigned char Ip1,unsigned char Ip2,unsigned char Ip3,unsigned char Ip4);//设置发送目标IP地址，如：192.168.1.255

    //3,发送网络DMX512灯光数据包函数
    //发送网络灯光数据包
    // Net=网0~127，SuUni=子网0~15,Ux=域0~15,Updata=立即更新还是缓存，Broadcast=单播或广播模式，DmxChBuf=512字节的DMX512域通道值的缓存指针
    FQ512NetShow_DLL_API void _stdcall Send_FQ512Net_DmxPacket(unsigned char Net ,unsigned char SubUni ,unsigned char Ux ,unsigned char Update,unsigned char Broadcast,unsigned char* DmxChBuf);//发送网络FQ512Net灯光数据包

    //====================网卡设置和相关信息=======================

    //4,读取当前电脑总网卡数函数
    //返回当前电脑网卡总数：0~9
    FQ512NetShow_DLL_API unsigned char  _stdcall Get_Sum_NetCardNum(void);//读取当前电脑总网卡数

    //5,读取对应序号的网卡名和IP地址函数
    //返回指定网卡的IP地址，CardIndex=指定要读取的网卡索引号，CardName=返回的网卡名缓存指针
    FQ512NetShow_DLL_API unsigned long  _stdcall Get_NetCard_IpName(unsigned char CardIndex,char *CardName);//读取对应序号的网卡名和IP

    //6,读取当前选中的网卡序号函数
    //返回当前使用的网卡索引号： 0~9
    FQ512NetShow_DLL_API unsigned char  _stdcall Get_CurSel_NetCardIndex(void);//读取，当前选中的网卡序号

    //7,变更网卡函数
    //CardIndex=设置网卡的索引号 0~9
    FQ512NetShow_DLL_API unsigned char  _stdcall Set_Change_NetCard(unsigned char CardIndex);//如电脑有多网卡，选择1个连接设备的网卡

    //===========================简单快速查询是否有设备在线===========================

    //8,查询网络设备函数
    //查询网络是否有设备，可先用Set_RemoteIp（192，168，1，220）;函数指定目标设备IP或广播，发送查询
    FQ512NetShow_DLL_API void _stdcall Send_FQ512Net_Poll(void);//发送查询在线设备指令	(注：V1.0.0.4前的版本不清除设备连接状态)

    //9,读取是否有设备连接标志
    // 必须先调用函数Send_FQ512Net_Poll();查询，等待几毫秒，再读
    //返回当前网络是否有设备：1=有设备，0=无设备
    FQ512NetShow_DLL_API unsigned char  _stdcall IsHaveFQ512NetDevice(void);//必须先调用Send_FQ512Net_Poll后,等待几毫秒后再读取


    //=================================================================================

    //10,设备的特定操作指令函数
    //特定的操作设备操作指令
    //Cmd=操作命令，Param=参数 ，DataBuf=数据缓存指针
    FQ512NetShow_DLL_API unsigned short  _stdcall Set_FQ512Net_HardCommand(unsigned short Cmd,unsigned short Param,unsigned char *DataBuf);//设备特定配置函数

    //===============注册回调函数============

    //为了简单化，修改了2个回调函数，把4个指针参数 改为数值型。其他函数保持不变！！！

    //11,注册查询网络设备响应的处理回调函数，必须先根据各种开发语言注册函数原型
    //调用Send_FQ512Net_Poll()函数后，设备返回信息的回调处理函数，返回的设备信息可以参看C++的信息结构体。通过这函数返回的信息，可管理查询所有在线的设备信息。
    FQ512NetShow_DLL_API void   _stdcall SetFQ512NetReceiveCallBack(void (*FQ512NetRecProcess)(unsigned short Cmd,unsigned char* pDataBuf ,unsigned short Len));//发送Poll指令后，调用回调函数查询设备信息
    //12，注册接收Art-Net数据包的回调函数，必须先根据各种开发语言注册函数原型
    //注：必须 接 广州力当科技有限公司 的盒子 才可接收Art-Net信号！！ 网站：www.FQ512.com 淘宝店：https://shop68842091.taobao.com/
    //必须先调用函数Set_FQ512Net_HardCommand(Set_RecArtNetOnOff,RecArtNetOn,NULL);设置开art-net接收功能，且有设备我们的设备在线才有效
    FQ512NetShow_DLL_API void   _stdcall SetArtNetReceiveCallBack(void (*ArtNetRecProcess)(unsigned char Net,unsigned char SubUni,unsigned char* pDataBuf ));//暂时无效

    //===============================================

    //13,释放开发包资源函数
    //程序退出，释放资源
    FQ512NetShow_DLL_API void _stdcall ExitClean(void);//程序退出时调用，释放所有资源

    //14,开发库关于函数
    //关于开发库的相关信息
    FQ512NetShow_DLL_API void   _stdcall DisplayAbout(void );//显示dll版本等信息

#ifdef __cplusplus
}
#endif // __cplusplus

#endif
