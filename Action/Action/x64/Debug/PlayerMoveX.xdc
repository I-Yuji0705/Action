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
<member name="M:PlayerMoveX.#ctor(Keyboard*,Sound*,Collision*,Player*,PlayerHit*)" decl="false" source="c:\users\student\desktop\action\action\action\playermovex.cpp" line="9">
<summary>
<para>コンストラクタ</para>
<para>キーが押されているか確認するKeyboardクラス、動作時に音を発生させるクラス、移動先に他のObjectがないか確認するクラス、接触処理を行うクラスを追加で取得する</para>
<para>引数:</para>
<param name="keyboard"><para>キーが押されているか確認するクラス</para></param>
<param name="sound"><para>動作時に音を発生させるクラス</para></param>
<param name="collision"><para>拾う範囲に他のObjectがないか確認するクラス</para></param>
<param name="playerhit"><para>Playerの接触処理を行うクラス</para></param>
</summary>
</member>
<member name="M:PlayerMoveX.Do" decl="false" source="c:\users\student\desktop\action\action\action\playermovex.cpp" line="26">
<summary>
<para>行動処理</para>
<para>キーボードの左右キーの入力状態を確認し、移動を行う。</para>
<para>左キーのみを押している場合は、左移動する。</para>
<para>右キーのみを押している場合は、右移動する。</para>
</summary>
</member>
<member name="M:PlayerMoveX.MoveX(System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\playermovex.cpp" line="44">
<summary>
<para>X軸の移動処理</para>
<para>移動しようとしている数字を受け取り、移動先に他のObjectに接触するかを調べる</para>
<para>移動先にObjectない場合:xに数値を加算し、移動する</para>
<para>移動先にObjectある場合:対象のObjectを押し、少しも押せなかったら接触処理を行う</para>
<para>PlayerがObjectを持っている場合、そのObjectも同様に接触するかを調べる</para>
<para>引数:</para>
<param name="num"><para>num:X軸に加算しようとしている値</para></param>
</summary>
</member>
<member name="M:PlayerMoveX.Push(System.Single,std.vector&lt;Object**,std.allocator&lt;Object**&gt;&gt;,System.Int32)" decl="false" source="c:\users\student\desktop\action\action\action\playermovex.cpp" line="96">
<summary>
<para>Playerの押す処理</para>
<para>返された値のうち、一番小さい</para>
<para>地面にいるときにのみ、押す動作を開始する</para>
<para>渡された動的配列のから、Playerに密着しているObjectと、</para>
<para>Playerに密着していないObjectの内、Playerから近いObjectとの差を得する</para>
<para>PlayerがObjectを持っている場合、同様に密着しているObjectと密着していないObjectとの差を取得する</para>
<para>密着しているObjectに、渡されたfloatの値に対して、どの程度動けるかを取得する</para>
<para>収得した値のうち、一番小さい値でPlayerに密着しているObject全てを押す</para>
<para>実際に押せたかどうかを戻り値にする</para>
<para>引数:</para>
<param name="num"><para>num:X軸に加算しようとしている値</para></param>
<param name="target"><para>target:押そうとしている対象のObjectのポインタ全て</para></param>
<param name="check"><para>check:Collision::HitCheckXでのint型の戻り値、押そうとしている方向を確認する</para></param>
<returns>
<para>true:少しでも押すことができた</para>
<para>false:少しも押せなかった</para>
</returns>
</summary>
</member>
</members>
</doc>