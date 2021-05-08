#ifndef FQ512NetShowL_H
#define FQ512NetShowL_H
/*

//����˵����ʹ������IPЭ�飬���ƹ��ʱ�׼DMX512�ƹ��豸
//��ǰ�汾��V1.0.0.6
�޸�˵����
    1�������ÿ������� �޸��豸IP�� FQ512NetShow�ƹ������Net->SubNet->DMX512��ȹ���.
    2, ���ӽ���Art-Net���ݰ��ص������չ��ܡ�
    3����������Ӧ����CPUʹ���ʹ��ܡ�
    4��Ϊ�˼򵥻����޸���2���ص���������4��ָ����� ��Ϊ��ֵ�͡������������ֲ��䣡����
���������ṩX64λ��X32λ�汾������ȷѡ��
*/

#ifdef FQ512NetShow_DLL_API
#else
#define FQ512NetShow_DLL_API __declspec(dllimport)
#endif

#pragma         pack(1)
//size=71
//Pollָ���ѯ���豸���ص���Ϣ�ṹ��

typedef   struct   FQ512NetDevice_
{

    unsigned char SN[24];//���к�

    unsigned char IP[4];//�豸IP
    unsigned char Mask[4];//����
    unsigned char Gate[4];//����
    unsigned char RemoteIp[4];//Զ��IP,DMX-->NET��

    unsigned char OutUx[4];//DMXӲ���ڰ����DMX��0~15��
    unsigned char InUx[4];//DMXӲ���ڰ������DMX��0~15��

    unsigned char NumDmxPorts;//V1.4�汾ǰ�ĺ��ӣ��豸��DMX������1~4����V1.5�汾��ĺ��ӣ���4λ�����DMXתnet����DMX����,��4λ�����NetתDMX��SPI����DMX����
    unsigned char Net;//�豸��FQ512Net����0~127��
    unsigned char SubNet;//�豸��FQ512Net������0~15��
    unsigned char WorkMode;	//����ģʽ:0=NET-->DMX;1=DMX-->NET��ע����V1.5���ϵĺ��Ӳ���Ч��

    unsigned char ShortName[18];//�豸��
    unsigned char FireWareVer;//�̼��汾

}FQ512NetDevice;

#pragma   pack()

    //======================================
//ָ��궨��
#define Set_WorkMode 0  //���ù���ģʽ
        #define  WorkMode_NetToDmx 0//NETתDMXģʽ
        #define  WorkMode_DmxToNet 1//DMXתNETģʽ
#define Set_FQ512Net 1   //���õƹ������
#define Set_IPAddress 2  //�����豸IP

#define Set_OpUpdateAllDmxOut 3  //ͬ�����ָ��

#define Set_RecArtNetOnOff 50 //V1.5�汾���ӣ��������Ƿ����art-net�źŹ��ܣ�Ĭ�ϲ�����
    #define RecArtNetOn 1//����
    #define RecArtNetOff 0//������

#define Set_AutoSleep 51//�����Զ�����CPUʹ���ʣ�Ĭ�Ͽ�
    #define AutoSleepOn 1//�� ����Ӧ����CPUʹ����
    #define AutoSleepOff 0//�رգ�����Ӧ����CPUʹ����

#define Set_ResetDevice 100  //��λ�豸
#define Set_ResetToFactory 101  //�ָ�����Ĭ������ֵ
//====================================
//�㲥���ƺ궨��
#define Broadcast_NO             0  //�޹㲥��ֻ���Ƶ���DMX��

#define Broadcast_DEVICE_ALLPORT 1  //���豸������DMX��˿ڹ㲥
#define Broadcast_SUBNET_ALLUNI  2 //��FQ512Net��SubNet�����ڹ㲥
#define Broadcast_NET_ALLSUBNET  3 //��FQ512Net��Net�����㲥
#define Broadcast_ALLNET         255 //��FQ512Netȫ���豸�㲥
//--------------------------------
//�������»򻺴�궨��
#define  OUT_Update 1 //�����������DMX
#define  OUT_Temp 0   //�Ȼ��棬�������DMX��

////IPģʽ����
#define  Static_IPMode 0 //��̬IP
#define  AutoArtNet_IPMode 1  //�Զ�Art-Net IPģʽ

//***************************������������ԭ��������*******************

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    //��������
    //1.��ʼ�����绷������
    //����ʼ�������ȳ�ʼ������ӿ�
    //����ֵ��0~9=Ĭ��ѡ���������ţ�255=��ʼ������ӿ�ʧ�ܣ�
    FQ512NetShow_DLL_API unsigned char  _stdcall Init_Net(void);//����ʼ���� ��ʼ�����绷��

    //2��ָ��Ҫ���͵�Ŀ���豸IP��ַ����
    //����Ŀ���豸��IP��ַ���磺IP1=192��IP2=168��IP3=1��IP4=220----������Ŀ���豸IP:192.168.1.220
    FQ512NetShow_DLL_API void  _stdcall Set_RemoteIp(unsigned char Ip1,unsigned char Ip2,unsigned char Ip3,unsigned char Ip4);//���÷���Ŀ��IP��ַ���磺192.168.1.255

    //3,��������DMX512�ƹ����ݰ�����
    //��������ƹ����ݰ�
    // Net=��0~127��SuUni=����0~15,Ux=��0~15,Updata=�������»��ǻ��棬Broadcast=������㲥ģʽ��DmxChBuf=512�ֽڵ�DMX512��ͨ��ֵ�Ļ���ָ��
    FQ512NetShow_DLL_API void _stdcall Send_FQ512Net_DmxPacket(unsigned char Net ,unsigned char SubUni ,unsigned char Ux ,unsigned char Update,unsigned char Broadcast,unsigned char* DmxChBuf);//��������FQ512Net�ƹ����ݰ�

    //====================�������ú������Ϣ=======================

    //4,��ȡ��ǰ����������������
    //���ص�ǰ��������������0~9
    FQ512NetShow_DLL_API unsigned char  _stdcall Get_Sum_NetCardNum(void);//��ȡ��ǰ������������

    //5,��ȡ��Ӧ��ŵ���������IP��ַ����
    //����ָ��������IP��ַ��CardIndex=ָ��Ҫ��ȡ�����������ţ�CardName=���ص�����������ָ��
    FQ512NetShow_DLL_API unsigned long  _stdcall Get_NetCard_IpName(unsigned char CardIndex,char *CardName);//��ȡ��Ӧ��ŵ���������IP

    //6,��ȡ��ǰѡ�е�������ź���
    //���ص�ǰʹ�õ����������ţ� 0~9
    FQ512NetShow_DLL_API unsigned char  _stdcall Get_CurSel_NetCardIndex(void);//��ȡ����ǰѡ�е��������

    //7,�����������
    //CardIndex=���������������� 0~9
    FQ512NetShow_DLL_API unsigned char  _stdcall Set_Change_NetCard(unsigned char CardIndex);//������ж�������ѡ��1�������豸������

    //===========================�򵥿��ٲ�ѯ�Ƿ����豸����===========================

    //8,��ѯ�����豸����
    //��ѯ�����Ƿ����豸��������Set_RemoteIp��192��168��1��220��;����ָ��Ŀ���豸IP��㲥�����Ͳ�ѯ
    FQ512NetShow_DLL_API void _stdcall Send_FQ512Net_Poll(void);//���Ͳ�ѯ�����豸ָ��	(ע��V1.0.0.4ǰ�İ汾������豸����״̬)

    //9,��ȡ�Ƿ����豸���ӱ�־
    // �����ȵ��ú���Send_FQ512Net_Poll();��ѯ���ȴ������룬�ٶ�
    //���ص�ǰ�����Ƿ����豸��1=���豸��0=���豸
    FQ512NetShow_DLL_API unsigned char  _stdcall IsHaveFQ512NetDevice(void);//�����ȵ���Send_FQ512Net_Poll��,�ȴ���������ٶ�ȡ


    //=================================================================================

    //10,�豸���ض�����ָ���
    //�ض��Ĳ����豸����ָ��
    //Cmd=�������Param=���� ��DataBuf=���ݻ���ָ��
    FQ512NetShow_DLL_API unsigned short  _stdcall Set_FQ512Net_HardCommand(unsigned short Cmd,unsigned short Param,unsigned char *DataBuf);//�豸�ض����ú���

    //===============ע��ص�����============

    //Ϊ�˼򵥻����޸���2���ص���������4��ָ����� ��Ϊ��ֵ�͡������������ֲ��䣡����

    //11,ע���ѯ�����豸��Ӧ�Ĵ���ص������������ȸ��ݸ��ֿ�������ע�ắ��ԭ��
    //����Send_FQ512Net_Poll()�������豸������Ϣ�Ļص������������ص��豸��Ϣ���Բο�C++����Ϣ�ṹ�塣ͨ���⺯�����ص���Ϣ���ɹ����ѯ�������ߵ��豸��Ϣ��
    FQ512NetShow_DLL_API void   _stdcall SetFQ512NetReceiveCallBack(void (*FQ512NetRecProcess)(unsigned short Cmd,unsigned char* pDataBuf ,unsigned short Len));//����Pollָ��󣬵��ûص�������ѯ�豸��Ϣ
    //12��ע�����Art-Net���ݰ��Ļص������������ȸ��ݸ��ֿ�������ע�ắ��ԭ��
    //ע������ �� ���������Ƽ����޹�˾ �ĺ��� �ſɽ���Art-Net�źţ��� ��վ��www.FQ512.com �Ա��꣺https://shop68842091.taobao.com/
    //�����ȵ��ú���Set_FQ512Net_HardCommand(Set_RecArtNetOnOff,RecArtNetOn,NULL);���ÿ�art-net���չ��ܣ������豸���ǵ��豸���߲���Ч
    FQ512NetShow_DLL_API void   _stdcall SetArtNetReceiveCallBack(void (*ArtNetRecProcess)(unsigned char Net,unsigned char SubUni,unsigned char* pDataBuf ));//��ʱ��Ч

    //===============================================

    //13,�ͷſ�������Դ����
    //�����˳����ͷ���Դ
    FQ512NetShow_DLL_API void _stdcall ExitClean(void);//�����˳�ʱ���ã��ͷ�������Դ

    //14,��������ں���
    //���ڿ�����������Ϣ
    FQ512NetShow_DLL_API void   _stdcall DisplayAbout(void );//��ʾdll�汾����Ϣ

#ifdef __cplusplus
}
#endif // __cplusplus

#endif
