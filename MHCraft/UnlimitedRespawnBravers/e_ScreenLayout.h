#ifndef E_SCREEN_LAYOUT
#define E_SCREEN_LAYOUT

//プレイヤー数に応じて画面を増やすときのenum
enum e_ScreenLayout
{
	e_Single,//1Playerモード画面
	e_Double,//2Playerモード画面
	e_Triple,//3Plaerモード画面
	e_Quad,//4Playerモード画面
};

//e_ScreenLayoutがe_Doubl以上のときにPostEffectが「何Ｐの画面なのか」の情報
enum e_ScreenNumber
{
	e_First,//1Pの画面
	e_Second,//2Pの画面
	e_Third,//3Pの画面
	e_Fourth,//4Pの画面
};

#endif
