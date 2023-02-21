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
	//무기
	곤봉,
	구리검,
	철제단검,
	철제장검,
	양손철검,
	미스릴검,
	동방도,
	은사의검,
	무신의검,
	발키리의검,

	//방어구
	가죽갑옷,
	쇠사슬갑옷,
	철갑옷,
	미스릴갑옷,
	실크갑옷,

	//아이템
	쾌유환,
	폭탄,
	인형,
	찻잔,
	책,
	시집,
	정령의반지,
	유니콘뿔피리,
	악마의펜던트,
	비너스목걸이,
	칠흑의비늘,
	고양이의눈,
	드래곤의이빨,
	인어의눈물,
	은색모피,
	유혹의향수,
	축복의빵가루,
	귀부인의반지,
	극락조의알,
	명장의붓,
	얼음의조각,
	무적의반지,
	왕가의비파,
	케이크,
	생선조개,//??
	고기요리,//??
	요정의꿀,

	//의류
	평상복,
	하복,
	동복,
	목면드레스,
	실크드레스,
	가죽드레스,
	가시드레스,
	경국의로브,
	빈칸,
	악마의드레스,
	용의레오타드,

	//교육
	자연과학,
	시문학,
	신학,
	군사학,
	검술,
	격투술,
	마법,
	예법,
	미술,
	무용,

	//아르바이트
	집안일,
	아이보기,
	여관,
	농장,
	레스토랑,
	나무꾼,
	미용실,
	미장이,
	사냥꾼,
	묘지기,
	가정교사,
	주점,
	어둠의주점,
	어둠의전당,

	//휴식
	무사수행_동부산림지대,
	자유행동,
	바캉스,
	간호,
	요양,
	감시,

	//상점가
	무기점,
	의류점,
	잡화점,
	병원,

	//수호신
	태양신_솔,
	달신_더문,
	화성신_마르스,
	수성신_머큐리,
	목성신_주피터,
	금성신_비너스,
	토성신_새턴,
	천왕성신_우라누스,
	해왕성신_넵튠,
	명왕성신_하데스,

	//무사수행
	서부사막지대,
	남부폭포지대,
	북부빙산지대,

	//상태
	불량상태,
	질병상태,
	연애상태,

	//떠돌이행상인
	고대의우유,
	풍유환

};

enum class StatusName
{
	Null = -1,
	
	체력,
	근력,
	지능,
	기품,
	색기,
	도덕성,
	신앙,
	업보,
	감수성,
	스트레스,

	전사평가,
	전투기술,
	공격력,
	방어력,

	마법평가,
	마법기술,
	마력,
	항마력,

	사교평가,
	예의범절,
	예술,
	화술,

	가사평가,
	요리,
	청소세탁,
	성품,

	신장,
	체중,
	가슴,
	허리,
	엉덩이,

	인맥,

	모성,
	왕자관계,
	아버지관계,
	집사관계,
	몬스터살육수,
	교육및알바횟수,
	마왕이벤트횟수,
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
	염소자리,
	물병자리,
	물고기자리,
	양자리,
	황소자리,
	쌍둥이자리,
	게자리,
	사자자리,
	처녀자리,
	천칭자리,
	전갈자리,
	사수자리
};

enum class PatronGod
{
	Null = -1,
	태양신_솔 = 87,
	달신_더문,
	화성신_마르스,
	수성신_머큐리,
	목성신_주피터,
	금성신_비너스,
	토성신_새턴,
	천왕성신_우라누스,
	해왕성신_넵튠,
	명왕성신_하데스,
};

enum class Diet
{
	무리하지_않는다,
	어쨌든_튼튼하게,
	얌전한_아이로,
	다이어트_시킨다
};