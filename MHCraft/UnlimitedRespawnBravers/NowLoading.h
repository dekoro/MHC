#ifndef NOW_LOADING
#define NOW_LOADING

/*

DXライブラリの場合読み込んでるデータの数が取得できるので「授業でのパズル」
のようにTextureLodaerやSoundLoderを用意する必要はないと思う。

このNowLoading関数を非同期に入ってから使うと読み込んでいるアセットの数を
ゲージのようなテクスチャーであわわしてくれる。

注：3Dモデルの場合読み込んでる数をゲージで表現するが、読み込むモデルのデータ量
によってゲージの進み具合がバラバラになってしまう。
例えばマップとプレイヤーだと明らかに読み込むデータ量が違う

*/

//引数：ロード画面に使う画像のパス
void NowLoading(const char* filePath);

#endif