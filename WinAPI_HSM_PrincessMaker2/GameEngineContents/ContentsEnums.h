#pragma once

enum class PM2RenderOrder
{
	BackGround,
	BackGroundObj,
	TitleLogo,
	CaptionBox,
	Map,
	Contents,
	Olive,
	Menu0,
	Menu0_Button,
	Menu0_StatusGauge,
	Menu0_StatusGauge_1,
	Menu0_StatusGauge_2,
	Menu0_StatusGauge_3,
	Menu0_Display_Effect,
	Menu0_Display_Shadow,
	Menu0_Display,
	Menu1,
	Menu1_Button,
	Menu1_StatusGauge,
	Menu1_StatusGauge_1,
	Menu1_StatusGauge_2,
	Menu1_StatusGauge_3,
	Menu1_Display_Effect,
	Menu1_Display_Shadow,
	Menu1_Display,
	Dialog,
	Dialog_Display,
	MugShotFrame,
	MugShot,
	MousePoint
};


enum class PM2ActorOrder
{
	BackGround,
	BackGroundObj,
	TitleLogo,
	CaptionBox,
	Map,
	Contents,
	Olive,
	Menu0,
	Menu0_Button,
	Menu0_StatusGauge,
	Menu0_StatusGauge_1,
	Menu0_StatusGauge_2,
	Menu0_StatusGauge_3,
	Menu0_Display_Effect,
	Menu0_Display_Shadow,
	Menu0_Display,
	Menu1,
	Menu1_Button,
	Menu1_StatusGauge,
	Menu1_StatusGauge_1,
	Menu1_StatusGauge_2,
	Menu1_StatusGauge_3,
	Menu1_Display_Effect,
	Menu1_Display_Shadow,
	Menu1_Display,
	Dialog,
	Dialog_Display,
	MugShotFrame,
	MugShot,
	MousePoint
};

enum class PM2CollisionOrder
{
	BackGround,
	BackGroundObj,
	TitleLogo,
	CaptionBox,
	Map,
	Contents,
	Olive,
	Menu0,
	Menu0_Button,
	Menu0_StatusGauge,
	Menu0_StatusGauge_1,
	Menu0_StatusGauge_2,
	Menu0_StatusGauge_3,
	Menu0_Display_Effect,
	Menu0_Display_Shadow,
	Menu0_Display,
	Menu1,
	Menu1_Button,
	Menu1_StatusGauge,
	Menu1_StatusGauge_1,
	Menu1_StatusGauge_2,
	Menu1_StatusGauge_3,
	Menu1_Display_Effect,
	Menu1_Display_Shadow,
	Menu1_Display,
	Dialog,
	Dialog_Display,
	MugShotFrame,
	MugShot,
	MousePoint
};

enum class IconCode
{
	//����
	���,
	������,
	ö���ܰ�,
	ö�����,
	���ö��,
	�̽�����,
	���浵,
	�����ǰ�,
	�����ǰ�,
	��Ű���ǰ�,

	//��
	���װ���,
	��罽����,
	ö����,
	�̽�������,
	��ũ����,

	//������
	����ȯ,
	��ź,
	����,
	����,
	å,
	����,
	�����ǹ���,
	�����ܻ��Ǹ�,
	�Ǹ������Ʈ,
	��ʽ������,
	ĥ���Ǻ��,
	������Ǵ�,
	�巡�����̻�,
	�ξ��Ǵ���,
	��������,
	��Ȥ�����,
	�ູ�ǻ�����,
	�ͺ����ǹ���,
	�ض����Ǿ�,
	�����Ǻ�,
	����������,
	�����ǹ���,
	�հ��Ǻ���,
	����ũ,
	��������,//??
	���丮,//??
	�����ǲ�,

	//�Ƿ�
	���,
	�Ϻ�,
	����,
	���巹��,
	��ũ�巹��,
	���׵巹��,
	���õ巹��,
	�汹�Ƿκ�,
	��ĭ,
	�Ǹ��ǵ巹��,
	���Ƿ���Ÿ��,

	//����
	�ڿ�����,
	�ù���,
	����,
	������,
	�˼�,
	������,
	����,
	����,
	�̼�,
	����,

	//�Ƹ�����Ʈ
	������,
	���̺���,
	����,
	����,
	�������,
	������,
	�̿��,
	������,
	��ɲ�,
	������,
	��������,
	����,
	���������,
	���������,

	//�޽�
	�������_���λ긲����,
	�����ൿ,
	��Ĳ��,
	��ȣ,
	���,
	����,

	//������
	������,
	�Ƿ���,
	��ȭ��,
	����,

	//��ȣ��
	�¾��_��,
	�޽�_����,
	ȭ����_������,
	������_��ť��,
	�񼺽�_������,
	�ݼ���_��ʽ�,
	�伺��_����,
	õ�ռ���_��󴩽�,
	�ؿռ���_��ƪ,
	��ռ���_�ϵ���,

	//�������
	���λ縷����,
	������������,
	�Ϻκ�������,

	//����
	�ҷ�����,
	��������,
	���ֻ���,

	//�����������
	����ǿ���,
	ǳ��ȯ

};

enum class StatusName
{
	Null = -1,
	
	ü��,
	�ٷ�,
	����,
	��ǰ,
	����,
	������,
	�ž�,
	����,
	������,
	��Ʈ����,

	������,
	�������,
	���ݷ�,
	����,

	������,
	�������,
	����,
	�׸���,

	�米��,
	���ǹ���,
	����,
	ȭ��,

	������,
	�丮,
	û�Ҽ�Ź,
	��ǰ,

	����,
	ü��,
	����,
	�㸮,
	������,

	�θ�,

	��,
	���ڰ���,
	�ƹ�������,
	�������,
	���ͻ�����,
	�����׾˹�Ƚ��,
	�����̺�ƮȽ��,
};

enum class BloodType
{
	Null = -1,
	A,
	B,
	O,
	AB
};

enum class Zodiac
{
	Null = -1,
	�����ڸ�,
	�����ڸ�,
	������ڸ�,
	���ڸ�,
	Ȳ���ڸ�,
	�ֵ����ڸ�,
	���ڸ�,
	�����ڸ�,
	ó���ڸ�,
	õĪ�ڸ�,
	�����ڸ�,
	����ڸ�
};

enum class PatronGod
{
	Null = -1,
	�¾��_�� = 87,
	�޽�_����,
	ȭ����_������,
	������_��ť��,
	�񼺽�_������,
	�ݼ���_��ʽ�,
	�伺��_����,
	õ�ռ���_��󴩽�,
	�ؿռ���_��ƪ,
	��ռ���_�ϵ���,
};

enum class Diet
{
	��������_�ʴ´�,
	��·��_ưư�ϰ�,
	������_���̷�,
	���̾�Ʈ_��Ų��
};