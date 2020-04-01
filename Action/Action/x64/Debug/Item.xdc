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
<member name="M:Item.#ctor(Sound*,Collision*,System.Single,System.Single,System.Single,System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="13">
<summary>
<para>コンストラクタ</para>
<para>描写する画像の設定、当たった後の処理を行うクラス、行動を管理するクラスの生成</para>
<para>引数:</para>
<param name="sound"><para>動作時に音を発生させるクラス</para></param>
<param name="collision"><para>動作時や動作確認時に接触判定を調べる</para></param>
</summary>
</member>
<member name="M:Item.Initialize" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="33">
<summary>
<para>初期化処理</para>
<para>自分を持っているPlayerのポインタをnullptrにする</para>
</summary>
</member>
<member name="M:Item.Update" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="43">
<summary>
<para>更新処理</para>
<para>Itemの状態によってで行う行動を変える</para>
</summary>
</member>
<member name="M:Item.Draw" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="64">
<summary>
<para>描写処理</para>
<para>Itemの向きによって、描写する画像を反転する</para>
</summary>
</member>
<member name="M:Item.CanPicked(Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="73">
<summary>
<para>Objectに持たれるかを返す</para>
<para>Objectの頭上に自身を置くことができるかを調べ、返す</para>
<para>引数:</para>
<param name="object"><para>object:自分を持つObject</para></param>
<para>戻り値:</para>
<returns>
<para>true:自分を持つことができる</para>
<para>false:自分を持つことができない</para>
</returns>
</summary>
</member>
<member name="M:Item.Picked(Object*)" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="92">
<summary>
<para>Objectに持たれた始める際の処理</para>
<para>自分のstateを変更し、持たれる対象をポインタに保存し、自分の位置を変更する</para>
<para>引数:</para>
<param name="object"><para>object:自分を持つObject</para></param>
</summary>
</member>
<member name="M:Item.CanPutted" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="104">
<summary>
<para>carrier_に置かれることができるかを返す</para>
<para>Objectの頭上に自身を置くことができるかを調べ、返す</para>
<para>戻り値:</para>
<returns>
<para>true:自分を持つことができる</para>
<para>false:自分を持つことができない</para>
</returns>
</summary>
</member>
<member name="M:Item.Putted" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="137">
<summary>
<para>Objectに持たれた始める際の処理</para>
<para>stateと持たれる対象をポインタに保存し、自分の位置を変更する</para>
<para>引数:</para>
<param name="object"><para>object:自分を持つObject</para></param>
</summary>
</member>
<member name="M:Item.CanThrew" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="147">
<summary>
<para>carrier_に投げられる際、投げれるかを返す</para>
<para>Itemのvector_から投げる際に自分がいる位置に他のObjectがないか調べる</para>
<para>戻り値:</para>
<returns>
<para>true:自分投げることができる</para>
<para>false:自分を投げることができない</para>
</returns>
</summary>
</member>
<member name="M:Item.Threw" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="180">
<summary>
<para>投げられる際の処理</para>
<para>自分の位置を変更する</para>
</summary>
</member>
<member name="M:Item.Retry" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="188">
<summary>
<para>リトライ処理</para>
<para>自分の位置を最初の位置に戻し、初期化処理を行う</para>
</summary>
</member>
<member name="M:Item.CanPushed(System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="197">
<summary>
<para>押されようとしている数字から、自分が押されることのできる数字を返す</para>
<para>ステージ端に移動してしまう場合、その差の数字を返す</para>
<para>自分が押される分数字を半分にした後、移動先にObjectがあった場合そのObjectのCapushedを再帰させ、一番小さい数字を返す</para>
<para>引数:</para>
<param name="num"><para>num:現在の位置から動かそうとしている座標への差</para></param>
<para>戻り値:</para>
<returns>
<para>numに対して、実際にこのObjectを動かせる距離</para>
</returns>
</summary>
</member>
<member name="M:Item.Pushed(System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="234">
<summary>
<para>引数で受け取った数字分座標を移動する</para>
<para>移動先に他のObjectがあった場合、そのObjectもPushedを使い、再帰させる</para>
<para>引数:</para>
<param name="num"><para>num:現在の位置から動かそうとしている座標への差</para></param>
</summary>
</member>
</members>
</doc>