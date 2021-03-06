#pragma once
#include "..\WorldDefine\RoleDefine.h"
struct tagFashionEvent;
struct tagNS_SynTotalStrength;

struct tagChangeFashionEvent;
struct tagNS_RoleClearAttPoint;
struct tagNS_SyncStartVipTime;
class LocalPlayer;
const DWORD BUTTON_DELAY_MS = 3000;	/*< 按钮按下延迟,单位:毫秒 */
const int MAX_PLAYER_RESIST = 1000;
const int MIN_PLAYER_RESIST = -1000;

enum EDisplayProperty
{
	EDP_Physique = 0,	// 筋骨
	EDP_Strength = 1,	// 劲力
	EDP_Pneuma   = 2,		// 元气
	EDP_InnerForce = 3,	// 内力

	EDP_F_End = 4,		//F计划划分线

	EDP_Agility = 4,	// 身法
	EDP_Technique = 5,  // 技力
	
	EDP_End = 5,
};

enum EDisplayPropertyEx
{
	EDPE_WeaponDamage = 0,		// 最小武器伤害，todo 最大武器伤害
	EDPE_WuHun = 1,		// 法器伤害
	EDPE_ArmDefine = 2,		// 护甲防御
	EDPE_MeleeDamage = 3,			// 物理攻击
	EDPE_MagicDamage = 4,			// 法术攻击
	EDPE_MeleeDefine = 5,			// 物理防御
	EDPE_MagicDefine = 6,			// 法术防御
	EDPE_DamageSkill = 7,			// 精准
	EDPE_DefineSkill = 8,		// 灵巧
	EDPE_MoveSpeed = 9,			// 移动速度
	EDPE_Toughness = 10,		// 耐力
	EDPE_Energy = 11,			// 活力
	EDPE_Luck = 12,				// 幸运
	EDPE_InternalInjury = 13,	// 内伤
	EDPE_Morality = 14,			// 道德

	EDPE_JiaShen = 15,			// 伤害加深
	EDPE_JianMian = 16,			// 伤害减免
	EDPE_DiKang = 17,			// 伤害抵抗
	EDPE_QiangHua = 18,			// 控制效果强化

	EDPE_Regain_Addtion = 19,			// 灵力
	EDPE_Crit_Rate = 20,			// 额外暴击率
	EDPE_Crit_Amount = 21,			// 额外暴击量

	EDPE_Ele_Injery =	22,	// 元素伤害
	EDPE_Ele_Pierce = 23,		// 元素穿透
	EDPE_Ele_Res = 24,	// 元素抗性
	EDPE_Ignore_Attack = 25,	// 无视攻击
	EDPE_Ignore_Defend = 26,	// 无视防御

	EDPE_Mana_combustion		=	27,		// 法力燃烧
	EDPE_Mana_combustion_resistance			=	28,		// 法力燃烧抵抗
	EDPE_ExDamage			=	29,		// 额外伤害
	EDPE_ExJiaCheng		=	30,		// 额外加成
	EDPE_Ren						=	31,						//韧性
	EDPE_Crit_Resist				=	32,		// 暴击抵消
	EDPE_rebound						=	33,		// 固定反弹
	EDPE_rebound_ratio					=	34,		// 反弹比例
	EDPE_rebound_immune				=	35,		// 反弹减免
	EDPE_slow_up					=	36,		// 减速伤害强化

	EDPE_End,
	EDPE_WeaponDamage0,		// 武器伤害最大值
	EDPE_WuHun0,			// 武魂修正值
	EDPE_ArmDefine0,		// 护甲防御修正值
	EDPE_MoveSpeed0,		// 移动速度修正值
	EDPE_Morale0,			// 士气修正值
	EDPE_InternalInjury0,	// 内伤修正值
	EDPE_Luck0,				// 福缘修正值
	EDPE_Energy0,			// 活力最大值
	EDPE_Toughness0,		// 持久力修正值
	EDPE_MeleeDamage0,		// 外功攻击修正值
	EDPE_MeleeDefine0,		// 外功防御修正值
	EDPE_MagicDamage0,		// 内功攻击修正值
	EDPE_MagicDefine0,		// 内功防御修正值
	EDPE_DamageSkill0,		// 攻击技巧修正值
	EDPE_DefineSkill0,		// 防御技巧修正值
	EDPE_Morality0,			// 道德修正值
	EDPE_Health0,			// 体力最大值
	EDPE_Power0,			// 真气最大值
	//EDPE_WeaponDamage,		// 武器伤害最小值
	//EDPE_WuHun,				// 武魂
	//EDPE_ArmDefine,			// 护甲防御
	//EDPE_MoveSpeed,			// 移动速度
	//EDPE_Morale,			// 士气
	//EDPE_InternalInjury,	// 内伤
// 	EDPE_WeaponDamage0,		// 武器伤害最大值
// 	EDPE_WuHun0,			// 武魂修正值
// 	EDPE_ArmDefine0,		// 护甲防御修正值
// 	EDPE_MoveSpeed0,		// 移动速度修正值
// 	EDPE_Morale0,			// 士气修正值
// 	EDPE_InternalInjury0,	// 内伤修正值
	//EDPE_Luck,				// 福缘
	//EDPE_Feature,			// 仪容
	//EDPE_Command,			// 统御
	//EDPE_Energy,			// 活力
	//EDPE_Morality,			// 道德
	//EDPE_Cultivate,			// 修为
	//EDPE_Luck0,				// 福缘修正值
	//EDPE_Feature0,			// 仪容修正值
	//EDPE_Command0,			// 统御修正值
	//EDPE_Energy0,			// 活力最大值
	//EDPE_Morality0,			// 道德修正值
	//EDPE_Cultivate0,		// 修为修正值
	//EDPE_Health,			// 体力
	//EDPE_Power,				// 真气
	//EDPE_Toughness,			// 持久力
	//EDPE_MeleeDamage,		// 外功攻击
	//EDPE_MeleeDefine,		// 外功防御
	//EDPE_MagicDamage,		// 内功攻击
	//EDPE_MagicDefine,		// 内功防御
	//EDPE_DamageSkill,		// 攻击技巧
	//EDPE_DefineSkill,		// 防御技巧
	//EDPE_Hit,				// 命中
	//EDPE_Dodge,				// 躲闪
	//EDPE_Health0,			// 体力最大值
	//EDPE_Power0,			// 真气最大值
// 	EDPE_Toughness0,		// 持久力修正值
// 	EDPE_MeleeDamage0,		// 外功攻击修正值
// 	EDPE_MeleeDefine0,		// 外功防御修正值
// 	EDPE_MagicDamage0,		// 内功攻击修正值
// 	EDPE_MagicDefine0,		// 内功防御修正值
// 	EDPE_DamageSkill0,		// 攻击技巧修正值
// 	EDPE_DefineSkill0,		// 防御技巧修正值
	//EDPE_Hit0,				// 命中修正值
	//EDPE_Dodge0,			// 躲闪修正值
	//EDPE_Weary,             // 疲劳值
	//EDPE_End,
	//
};

enum EDisplayResist
{
	EDR_BleedResist,		// 出血伤害减免
	EDR_BruntResist,		// 冲击伤害减免
	EDR_BangResist,			// 重击伤害减免
	EDR_PoisonResist,		// 毒性伤害减免
	EDR_ThinkerResist,		// 心智伤害减免
	EDR_InjuryResist,		// 内损伤害减免
	EDR_OrdinaryResist,		// 普通伤害减免

	EDR_End,
};

enum EDisplayTemporary
{
	EDT_Origin_Health,		// 原始体力
	EDT_Origin_Power,		// 原始真气
	EDT_Origin_ExDamge,		// 原始外功攻击
	EDT_Origin_ExDefine,	// 原始外功防御
	EDT_Origin_InDamage,	// 原始内功攻击
	EDT_Origin_InDefine,	// 原始内功防御
	EDT_Origin_DmgSkill,	// 原始攻击技巧
	EDT_Origin_DefSkill,	// 原始防御技巧
	EDT_Origin_Hit,			// 原始命中
	EDT_Origin_Dodge,		// 原始躲闪
	EDT_Origin_Toughness,	// 原始持久力

	EDT_Origin_End,
};

const DWORD ORDINARY_COLOR = Color4ub(255, 243, 236, 164);// 原始颜色
const DWORD MINUS_RED_COLOR = Color4ub(255, 247, 3, 15);// 减益时的红色
const DWORD PLUS_GREEN_COLOR = Color4ub(255, 194, 246, 58);// 增益时的绿色
#define GETTRUECOLOR(n) (0 > n ? MINUS_RED_COLOR : \
	( 0 < n ? PLUS_GREEN_COLOR : ORDINARY_COLOR))

class NetSession; 
class ActiveProgress;
/** class	StateFrame
	brief	状态界面模块
	remarks 显示和管理玩家当前各个属性信息
*/ 
class StateFrame :
	public GameFrame
{
public:
	StateFrame(void);
	~StateFrame(void);
	
	virtual BOOL Init(GameFrameMgr* pMgr, GameFrame* pFather, DWORD dwParam);
	virtual BOOL Destroy();
	virtual BOOL ReloadUI();
	virtual VOID Update();
	virtual BOOL EscCancel();

	VOID UpdatePalyerAtt();

	VOID AlignAttEXShowWnd();
	
private:

	DWORD OnGameEvent(tagGameEvent* pGameEvent);

	DWORD OnMsgClearPoint(tagMsgBoxEvent* pGameEvent);
	DWORD EventHandler(tagGUIEvent* pEvent);

	DWORD OnNetSynTotalStrength(tagNS_SynTotalStrength *pNetCmd, DWORD);
	

	VOID UpdateAttribute(ERoleAttribute eType);
	
	VOID SetPlayerName(LPCTSTR szName);
	VOID SetPlayerLevel(INT nLevel);
	VOID SetPlayerClass(LPCTSTR szClass);
	VOID SetPlayerGuild(LPCTSTR szGuild);

	VOID SetPlayerOverplus(INT nValue);
	VOID SetBiddenPoint(ERoleAttribute eType, INT nValue);
	VOID AddPreBidPoint(ERoleAttribute eType, INT nInc);
	VOID RemoveBidPoint();
	VOID UpdateBidAttribute();

	VOID SetPlayerAtt(EDisplayProperty eType, INT nValue, DWORD dwColor = ORDINARY_COLOR);
	VOID SetPlayerAttEx(EDisplayPropertyEx eType, INT nValue, DWORD dwColor = ORDINARY_COLOR);
	VOID SetPlayerResist(EDisplayResist eType, INT nValue);

	VOID SendNetBidAtt();

	ERoleAttribute TransBtn2Att(EDisplayProperty eType);

    // 外功伤害减免加成
    int CalExAttackResist(int src);
    // 内功伤害减免加成
    int CalInAttackResist(int src);

	DWORD NetRoleClearAttPoint(tagNS_RoleClearAttPoint* pNetCmd, DWORD);
	DWORD OnNS_SyncStartVipTime(tagNS_SyncStartVipTime* pNetCmd, DWORD);
	

	VOID UpdateSettingsOfLocalPlayer(LocalPlayer* plp);

	float GetWearyUpperLimit();
private:
	TSFPTrunk<StateFrame>		m_Trunk;
	TObjRef<GUISystem>			m_pGUI;
	TObjRef<Util>				m_pUtil;
	TObjRef<GameFrameMgr>		m_pFrameMgr;
	TObjRef<NetSession>		    m_pSession;

	// GUI控件
    GUIWnd*                     m_pWndState;
	GUIWnd*						m_pWnd;
	GUIWnd*						m_pWndFather;
	GUIStatic*					m_pStcAtt[EDP_F_End];	//1级属性，加点
	GUIStatic*					m_pStcAttEx[EDPE_End];	//2级属性还有抗性
	//GUIStatic*					m_pStcResPic[EDR_End];
	//GUIStatic*					m_pStcResValue[EDR_End];
	GUIStatic*					m_pStcOverplus;
	GUIStatic*					m_pStcOverplusText;//"剩余点数"文字
	GUIButton*					m_pBtnAtt[EDP_F_End];
	GUIFrameMutex*				m_pFmSuitOpt;
	GUIPushButton*				m_pPbnDisplayAtt;
	GUIPushButton*				m_pPbnDisplayEquip;
	GUIPushButton*				m_pPbnDisplayFashion;
	GUIStatic*					m_pStcPlayerName;
	GUIStatic*					m_pStcPlayerGuild;
	GUIStatic*					m_pStcPlayerLevel;
	GUIStatic*					m_pStcPlayerClass;
	GUIStatic*				    m_pStcAttWeary;     //疲劳属性窗口控件
	GUIStatic*				    m_pStcAttWearyFont; //疲劳值字体显示控件
	GUIProgress*		        m_pProPlayerWeary;  //疲劳显示条 
	GUIButton*					m_pBtnSure;
	GUIButton*					m_pBtnCancel;
	GUIButton*					m_pBtnCleanPoints;	//洗点
	GUIWnd*						m_pWndAtt;
	GUIWnd*						m_pWndAttEx;
	GUIWnd*						m_pWndAttIn;

	GUIWnd*						m_pWndRes;
	GUIButton*					m_pBtnDetail;

	GUIWnd*						m_pWndAttExShow;	// 属性扩展窗口
	GUIButton*					m_pBtnAttExShow;	// 属性扩展按钮
	GUIButton*					m_pBtnAttExShowClose;	// 属性扩展关闭按钮

	bool						m_isSwappingSuitPattern;
	bool                        m_bIsClick;

	// 临时数据
	INT							m_Temporary[EDT_Origin_End];
	INT							m_nPreBid[X_ERA_ATTA_NUM];// 预投点
	INT							m_nBidden[X_ERA_ATTA_NUM];// 已投点
	INT							m_nOgnAtt[X_ERA_ATTA_NUM];// 自身成长点
	INT							m_nOverplus;			  // 当前可投点数
	INT							m_nInternalInjury;		//内伤值
	INT							m_TempAttEquipAdd[ERA_End];

	GUIStatic*					m_pStcToughnes;
	GUIStatic*					m_pStcToughnesValue;

	GUIStatic*				    m_pStcAttHP;     //血属性窗口控件
	GUIStatic*				    m_pStcAttHPFont; //血值字体显示控件
	ActiveProgress*		        m_pProPlayerHP;  //血显示条 

	GUIStatic*				    m_pStcAttMP;     //蓝属性窗口控件
	GUIStatic*				    m_pStcAttMPFont; //蓝值字体显示控件
	ActiveProgress*		        m_pProPlayerMP;  //蓝显示条 

	GUIPushButton*				m_pPbnShowHead;		//显示头盔
	GUIPushButton*				m_pPbnShowPiFeng;	//显示披风

	tagDisplaySet				m_curDisplaySet;              // 当前的装备显示设置

	bool						m_bDontHaveToSentEvent;		// 是否需要发送切换装备模式事件

	// vip
	GUIStatic*					m_pStcSilverVIP;
	GUIStatic*					m_pStcSilverVIPLeftTime;
	GUIStatic*					m_pStcGoldVIP;
	GUIStatic*					m_pStcGoldVIPLeftTime;
	GUIStatic*					m_pStcPlatinumVIP;
	GUIStatic*					m_pStcPlatinumVIPLeftTime;

};
