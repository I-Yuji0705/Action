<?xml version="1.0"?><doc>
<members>
<member name="M:Collision.MapDistance(Object!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="14">
<summary>
<para>対象のObjectが画面端まで接触するまで動ける数値を返す</para>
<para>引数:</para>
<param name="player"><para>player:移動するObjectのポインタ</para></param>
<param name="check"><para>check:MapCheck内のcheck変数</para></param>
<para>戻り値:</para>
<returns>
<para>Objectがステージ左端または右端まに接触するまで動ける数値</para>
</returns>
</summary>
</member>
<member name="M:Collision.Check(System.Single,System.Single,System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="26">
<summary>
<para>
指定した右上の座標と左下の座標を対角線とする四角形の中に、指定したObjectが接触しているかを返す
</para>
<para>引数:</para>
<param name="x1"><para>x1:調べる範囲の左上のX座標</para></param>
<param name="y1"><para>y1:調べる範囲の左上のY座標</para></param>
<param name="x2"><para>x2:調べる範囲の右下のX座標</para></param>
<param name="y2"><para>y2:調べる範囲の右下のY座標</para></param>
<param name="object"><para>object:対象のObjectのポインタ</para></param>
<returns>
<para>戻り値:</para>
<para>true:Objectが接触する</para>
<para>false:Objectが接触しない</para>
</returns>
</summary>
</member>
<member name="M:Collision.Check(System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*,Object!System.Runtime.CompilerServices.IsConst*)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="44">
<summary>
<para>
対象のオブジェクトが指定した座標上に出る場合、指定したObjectに接触するかを返す
</para>
<para>引数:</para>
<param name="x"><para>x:対象のObjectが移動するX座標</para></param>
<param name="y"><para>y:対象のObjectが移動するY座標</para></param>
<param name="player"><para>player:対象のObjectのポインタ</para></param>
<param name="object"><para>object:調べるObjectのポインタ</para></param>
<returns>
<para>戻り値:</para>
<para>true:Objectが接触する</para>
<para>false:Objectが接触しない</para>
</returns>
</summary>
</member>
<member name="M:Collision.#ctor(std.vector&lt;Object**,std.allocator&lt;Object**&gt;&gt;*)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="62">
<summary>
Stageのポインタの収得
</summary>
</member>
<member name="M:Collision.Initialize" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="66">
<summary>
<para>初期化処理</para>
<para>Stageのポインタから、ステージ右端と左端のTerrainの収得</para>
</summary>
</member>
<member name="M:Collision.ObjectDistance(Object!System.Runtime.CompilerServices.IsConst*,Object!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="72">
<summary>
<para>接触する二つのオブジェクトが接触するまで移動するObjectが動ける数値</para>
<para>引数:</para>
<param name="target"><para>target:playerが接触するObjectのポインタ</para></param>
<param name="player"><para>player:移動するObjectのポインタ</para></param>
<param name="check"><para>check:HitCheckXまたはHitCheckY内のcheck変数</para></param>
<returns>
<para>戻り値:</para>
<para>二つのオブジェクトが接触するまでplayerが動ける数値</para></returns>
</summary>
</member>
<member name="M:Collision.Check(System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="84">
<summary>
<para>
対象のオブジェクトが指定した座標上に出る場合、指定したObjectに接触するかを返す
</para>
<para>引数:</para>
<param name="x"><para>x:対象のObjectが移動するX座標</para></param>
<param name="y"><para>y:対象のObjectが移動するY座標</para></param>
<param name="player"><para>player:対象のObjectのポインタ</para></param>
<para>戻り値:</para>
<returns>
<para>true:Objectが接触する</para>
<para>false:Objectが接触しない</para>
</returns>
</summary>
</member>
<member name="M:Collision.MapCheck(System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="102">
<summary>
<para>指定したX地点に移動した場合、ステージの外に出るかどうか、</para>
<para>出る場合、現在の位置から接触するまで動ける数値を返す</para>
<para>引数:</para>
<param name="num"><para>num:移動しようとしているX地点</para></param>
<param name="player"><para>player:移動するObjectのポインタ</para></param>
<para>戻り値:</para>
<returns>
<para>int:Objectがステージ左端または右端に接触するか</para>
<para>0:接触しない</para>
<para>1:右端に接触する</para>
<para>2:左端に接触する</para>
<para>float:接触する場合、接触するまで動ける数値</para>
<para>999.0f:接触しない</para>
<para>999.0f以外:接触するまで動ける数値</para>
</returns>
</summary>
</member>
<member name="M:SceneMgr.#ctor(Keyboard*,Sound*)" decl="false" source="c:\users\student\desktop\action\action\action\scenemgr.cpp" line="8">
<summary>
<para>コンストラクタ</para>
<para>Scene内で使用するキーボードクラスと音を発生させるクラスを取得する</para>
<para>追加で、最初のSceneをTitleに設定する</para>
<para>引数:</para>
<param name="keyboard"><para>キーが押されているか確認するクラス</para></param>
<param name="sound"><para>BGMやSEなどの音を発生させるクラス</para></param>
</summary>
</member>
<member name="M:SceneMgr.Initialize" decl="false" source="c:\users\student\desktop\action\action\action\scenemgr.cpp" line="25">
<summary>
<para>初期化処理</para>
<para>Sceneの初期化処理を行う</para>
</summary>
</member>
<member name="M:SceneMgr.Finalize" decl="false" source="c:\users\student\desktop\action\action\action\scenemgr.cpp" line="33">
<summary>
<para>終了処理</para>
<para>Sceneの終了処理を行う</para>
</summary>
</member>
<member name="M:SceneMgr.Update" decl="false" source="c:\users\student\desktop\action\action\action\scenemgr.cpp" line="42">
<summary>
<para>更新処理</para>
<para>Sceneの変更要請がない場合、Sceneの更新処理を行う</para>
<para>Sceneの変更要請があった場合、画面を暗くし始める</para>
</summary>
</member>
<member name="M:SceneMgr.Draw" decl="false" source="c:\users\student\desktop\action\action\action\scenemgr.cpp" line="70">
<summary>
<para>描写処理</para>
<para>Sceneの描写処理を行う</para>
</summary>
</member>
<member name="M:SceneMgr.ChangeScene(Scene)" decl="false" source="c:\users\student\desktop\action\action\action\scenemgr.cpp" line="80">
<summary>
<para>シーンの変更処理</para>
<para>次のシーンをセットし、描写範囲を設定しなおす</para>
</summary>
</member>
<member name="M:SceneMgr.BlackOutScene" decl="false" source="c:\users\student\desktop\action\action\action\scenemgr.cpp" line="89">
<summary>
<para>シーンの暗転処理</para>
<para>描写範囲を狭めることで画面を暗くする</para>
<para>描写範囲を無くした後、シーンの変更処理を行い、Stateを暗転の状態から明るくする状態に変更する</para>
</summary>
</member>
<member name="M:SceneMgr.LightingScene" decl="false" source="c:\users\student\desktop\action\action\action\scenemgr.cpp" line="120">
<summary>
<para>シーンの明るくする処理</para>
<para>描写範囲を広げることで画面を明るくする</para>
<para>描写範囲を画面まで広げた後、Scene毎のBGMを再生し、Stateを通常時に変更する</para>
</summary>
</member>
<member name="M:SceneMgr.SetDepictionScreen(System.Int32,System.Int32,System.Int32,System.Int32)" decl="false" source="c:\users\student\desktop\action\action\action\scenemgr.cpp" line="135">
<summary>
<para>シーンの描写範囲の変更処理</para>
<para>描写する範囲の左上のX座標とY座標、右下のX座標とY座標を引数として受け取る</para>
<para>シーンの描写範囲を変数に保存した後、受け取った座標を対角線とする四角形を描写範囲として設定する</para>
<para>引数:</para>
<param name="x1"><para>x1:描写する範囲の左上のX座標</para></param>
<param name="y1"><para>y1:描写する範囲の左上のY座標</para></param>
<param name="x2"><para>x2:描写する範囲の右下のX座標</para></param>
<param name="y2"><para>y2:描写する範囲の右下のX座標</para></param>
</summary>
</member>
</members>
</doc>