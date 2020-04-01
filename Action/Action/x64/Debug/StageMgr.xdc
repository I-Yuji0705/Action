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
<member name="M:StageMgr.#ctor(Keyboard*,Sound*,IGameStateChanger*)" decl="false" source="c:\users\student\desktop\action\action\action\stagemgr.cpp" line="13">
<summary>
<para>コンストラクタ</para>
<para>キャラクターに渡すKeyboardクラス、Soundクラス、IGameStateChangerクラスを受け取る</para>
<para>ゲームのステージを生成する</para>
<para>引数:</para>
<param name="keyboard"><para>Playerの操作に使用するクラスのポインタ</para></param>
<param name="sound"><para></para>ObjectからSEを発生させるクラス</param>
<param name="statechanger"><para>GameのStateを変更するクラス</para></param>
</summary>
</member>
<member name="M:StageMgr.CreateStage(Keyboard*,Sound*,IGameStateChanger*,Collision*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\stagemgr.cpp" line="31">
<summary>
<para>ステージの生成処理</para>
<para>引数で渡されたステージ名のテキストファイルから、ステージ情報を読み込み、ステージを生成する</para>
<para>引数:</para>
<param name="keyboard"><para>Playerの操作に使用するクラスのポインタ</para></param>
<param name="sound"><para></para>ObjectからSEを発生させるクラス</param>
<param name="statechanger"><para>GameのStateを変更するクラス</para></param>
<param name="collision"><para>Objectの接触判定を担当するクラス</para></param>
<param name="stagename"><para>読み込むテキストファイルの名前</para></param>
</summary>
</member>
<member name="M:StageMgr.CreateStageDeta(Keyboard*,Sound*,IGameStateChanger*,Collision*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\stagemgr.cpp" line="70">
<summary>
<para>ステージの生成処理</para>
<para>CreateStageとは違い、プログラム文から生成したステージ情報をテキストファイルに出力する</para>
<para>引数:</para>
<param name="keyboard"><para>Playerの操作に使用するクラスのポインタ</para></param>
<param name="sound"><para></para>ObjectからSEを発生させるクラス</param>
<param name="statechanger"><para>GameのStateを変更するクラス</para></param>
<param name="collision"><para>Objectの接触判定を担当するクラス</para></param>
<param name="stagename"><para>出力するテキストファイルの名前</para></param>
</summary>
</member>
<member name="M:StageMgr.Initialize" decl="false" source="c:\users\student\desktop\action\action\action\stagemgr.cpp" line="127">
<summary>
<para>初期化処理</para>
<para>ステージ上のObjectとカメラの初期化処理を行う</para>
</summary>
</member>
<member name="M:StageMgr.Draw" decl="false" source="c:\users\student\desktop\action\action\action\stagemgr.cpp" line="139">
<summary>
<para>描写処理</para>
<para>ステージ上のObjectの描写処理を行う</para>
</summary>
</member>
<member name="M:StageMgr.Update" decl="false" source="c:\users\student\desktop\action\action\action\stagemgr.cpp" line="151">
<summary>
<para>更新処理</para>
<para>ステージ上のObjectの更新処理を行う</para>
</summary>
</member>
<member name="M:StageMgr.Finalize" decl="false" source="c:\users\student\desktop\action\action\action\stagemgr.cpp" line="162">
<summary>
<para>終了処理</para>
<para>ステージ上のObjectの終了処理を行う</para>
</summary>
</member>
<member name="M:StageMgr.Retry" decl="false" source="c:\users\student\desktop\action\action\action\stagemgr.cpp" line="172">
<summary>
<para>リトライ処理処理</para>
<para>ステージ上のObjectのリトライ処理を行う</para>
</summary>
</member>
</members>
</doc>