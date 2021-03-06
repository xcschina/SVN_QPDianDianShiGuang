#ifndef _CARD_MANAGER3_PIZI_H_
#define _CARD_MANAGER3_PIZI_H_

#include "gr_card.h"
#include "LVideo.h"

//////////////////////////////////////////////////////////////////////////
class CardStyle_SiChuan3_PiZi
{
public:
	CardStyle_SiChuan3_PiZi();
	~CardStyle_SiChuan3_PiZi();

	void        SortCard(CardVec& vce);//对牌按大到小排序;
	void        SortCardLaiziFront(CardVec& vce);//癞子放前面;
	void        SortCardLaiziInsert(CardVec& vce);//癞子替换掉;

	void        EarseCard(CardVec& des,CardVec& src);//删除des中属于src的牌;
	void		CheckCardStyle(CardVec const& src,CardStyleNumberVec& style,bool last, BYTE currCardStyle = 0);//检查所有符合牌型;
	bool		CheckCardStyle(CardVec const& src,BYTE style,BYTE& cardNumber);//以某种牌型来检查当前的牌;
	int			CanBig(DWORD dsCount,BYTE dsStyle,BYTE dsNumber,CardStyleNumberVec& style);

	void		GetSingleDoubleThreeFour(CardVec const& vec,CardVec& single,CardVec& duizi,CardVec& three,CardVec& four);
	void		GetJokeNumber2(CardVec const& vec,CardVec& joke,CardVec& number2,CardVec& other);
	void		GetLaizi(CardVec const& vec,CardVec& laizi,CardVec& other);
	void		GetBombLaiziJokeNumber2(CardVec const& vec,CardVec& bomb,CardVec& laizi,CardVec& joke,CardVec& number2,CardVec& other);
	bool		CheckContinuous(std::vector<BYTE>& vec);
	
	bool        HasRocket(CardVec const& vec);
	bool		Has2Count4Bomb(CardVec const& vec);
	bool        CheckHasBomb(CardVec const& Src, Lint* nBombCard = NULL);//查看手牌中是否有炸弹;

	int			GetCardScore(CardVec& vec);
	bool        IsBiZhua(CardVec const& vec);	//是否是必抓牌
	bool        IsBiDao(CardVec const& vec);	//判断是否是必倒牌

private:

	bool        IsRocket(CardVec const& vec,CardVec const& laizi, BYTE& cardType);	//是否是双王;
	bool        IsSuperRocket(CardVec const& vec,CardVec const& laizi, BYTE& cardType);	//是否是双王(重炸）;
	bool        IsDouble(CardVec const& vec,CardVec const& laizi,BYTE& cardType);		//对子;
	bool        IsBomb1(CardVec const& vec,CardVec const& laizi,BYTE& cardType);		//纯软炸弹;
	bool        IsBomb2(CardVec const& vec,CardVec const& laizi,BYTE& cardType);		//纯硬炸弹;
	bool        IsBomb3(CardVec const& vec,CardVec const& laizi,BYTE& cardType);		//软炸弹;
	bool		IsSuperBomb(CardVec const& vec,CardVec const& laizi,BYTE& cardNumber);
	bool		IsDoubleBomb(CardVec const& vec,CardVec const& laizi,BYTE& cardType);	//重炸（3333，4444)
	bool        IsBombToSingle(CardVec const& vec,CardVec const& laizi,BYTE& cardType);	//四带单;
	bool        IsBombToDouble(CardVec const& vec,CardVec const& laizi,BYTE& cardType);	//四带对;
	bool        IsThree(CardVec const& vec,CardVec const& laizi,BYTE& cardType);		//三个;
	bool        IsThreeToSingle(CardVec const& vec,CardVec const& laizi,BYTE& cardType);//三带单;
	bool		IsThreeToDouble(CardVec const& vec,CardVec const& laizi,BYTE& cardType);//三带对;
	bool        IsThreeList(CardVec const& vec,CardVec const& laizi,BYTE& cardType);		//飞机;
	bool        IsThreeListToSingle(CardVec const& vec,CardVec const& laizi,BYTE& cardType);//飞机带单;
	bool		IsThreeListToDouble(CardVec const& vec,CardVec const& laizi,BYTE& cardType);//飞机带对;
	bool        IsSingleList(CardVec const& vec,CardVec const& laizi,BYTE& cardType);//是否是单顺;
	bool        IsDoubleList(CardVec const& vec,CardVec const& laizi,BYTE& cardType);//是否是双顺;

public:
	static CardStyle_SiChuan3_PiZi* Instance();
};

///////////////////////////////////////////////////////////////////////////
//发牌的类;
class CardDeal_SiChuan3_PiZi
{
public:
	CardDeal_SiChuan3_PiZi();
	~CardDeal_SiChuan3_PiZi();

	void		ClearLaizi();
	void		SetLaizi(BYTE bCardNumber);
	void		DealCard(CardVec * receivers, Lint receiversLength, CardValue* changeCard = NULL, Lint nChangeLength = 0);
	void        GetLeftCard(CardVec& leftCard);
	void        SS(Lint nCardPos, Lint nColor, Lint nNumber);         // 调牌辅助函数;
	void        TiaoPai(CardValue tiaopai[], Lint nLenth);                                            // 调牌函数;

private:
	void		RandCard();
	void        RandCard_15cards();

private:
	Card		m_oCard[CARD_COUNT_DDZ + 1];
	CardVec		m_pCard;

	Lint		m_nSize;
};


////////////////////////////////////////////////////////////////////////////////////////////
class CardHelp_SiChuan3_PiZi
{
public:
	CardHelp_SiChuan3_PiZi();
	~CardHelp_SiChuan3_PiZi();

	//提示;
	std::vector<std::vector<Lint>> HelpMe(Lint cardMode, Lint cardType, Lint cardCount, CardVec& handcard, std::vector<Lint>& m_curHelpUnusable, bool baojing);


	void	CheckOne(Lint cardType,CardVec& o,CardVec& t,CardVec& th, CardVec& f,std::vector<std::vector<Lint>>& ret,bool baojing);
	void	CheckTwo(Lint cardType,CardVec& o,CardVec& t,CardVec& th, CardVec& f, std::vector<std::vector<Lint>>& ret);
	void	CheckThreeToTwo(Lint cardType,CardVec& o,CardVec& t,CardVec& th, CardVec& f, std::vector<std::vector<Lint>>& ret);
	void	CheckThreeFlyToTwo(Lint cardType,CardVec& o,CardVec& t,CardVec& th, CardVec& f,CardVec& handcard,Lint count, std::vector<std::vector<Lint>>& ret);
	void	CheckOneList(Lint cardType,CardVec& o,CardVec& t,CardVec& th, CardVec& f,Lint count, std::vector<std::vector<Lint>>& ret);
	void	CheckTwoList(Lint cardType,CardVec& o,CardVec& t,CardVec& th, CardVec& f,Lint count, std::vector<std::vector<Lint>>& ret);
	void    CheckThreeToOne(Lint cardType,CardVec& o,CardVec& t,CardVec& th, CardVec& f, std::vector<std::vector<Lint>>& ret);
	void    CheckFourToTwo(Lint cardType,CardVec& o,CardVec& t,CardVec& th, CardVec& f, std::vector<std::vector<Lint>>& ret);
	void    CheckThree(Lint cardType,CardVec& o,CardVec& t,CardVec& th, CardVec& f, std::vector<std::vector<Lint>>& ret);
	void    CheckThreeList(Lint cardType,CardVec& o,CardVec& t,CardVec& th, CardVec& f,CardVec& handcard,Lint count, std::vector<std::vector<Lint>>& ret);
	void    CheckThreeFlyToSingle(Lint cardType,CardVec& o,CardVec& t,CardVec& th, CardVec& f,CardVec& handcard,Lint count, std::vector<std::vector<Lint>>& ret);
};
#endif