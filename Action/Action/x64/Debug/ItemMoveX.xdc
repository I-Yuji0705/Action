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
<member name="M:ItemMoveX.#ctor(Sound*,Collision*,Item*,ItemHit*)" decl="false" source="c:\users\student\desktop\action\action\action\itemmovex.cpp" line="4">
<summary>
<para>コンストラクタ</para>
<para>音を管理するクラスと接触を判定するクラス、接触後の処理を行うクラスのポインタを追加で収得する</para>
<para>引数:</para>
<param name="sound"><para>sound:壁に接触した際に鳴らす音を管理するクラスのポインタ</para></param>
<param name="collision"><para>collision:移動する先に衝突するObjectがあるかを調べるクラスのポインタ</para></param>
<param name="itemhit"><para>itemhit:接触時に位置調整などの処理を行うクラスのポインタ</para></param>
</summary>
</member>
<member name="M:ItemMoveX.MoveX(System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\itemmovex.cpp" line="18">
<summary>
<para>Y軸の移動処理</para>
<para>移動しようとしている数字を受け取り、移動先に他のObjectに接触するかを調べる</para>
<para>移動先にObjectない場合:xに数値を加算し、移動する</para>
<para>移動先にObjectある場合:接触処理を行う</para>
<para>引数:</para>
<param name="num"><para>num:X軸に加算しようとしている値</para></param>
</summary>
</member>
<member name="M:ItemMoveX.Do" decl="false" source="c:\users\student\desktop\action\action\action\itemmovex.cpp" line="49">
<summary>
<para>行動処理</para>
<para>item_の向きから移動先を決め、X軸の移動処理を行う</para>
</summary>
</member>
</members>
</doc>