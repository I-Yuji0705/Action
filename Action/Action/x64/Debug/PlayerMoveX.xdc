<?xml version="1.0"?><doc>
<members>
<member name="M:PlayerMoveX.#ctor(Keyboard*,Sound*,Collision*,Player*,PlayerHit*)" decl="false" source="c:\users\student\desktop\action\action\action\playermovex.cpp" line="9">
<summary>
<para>コンストラクタ</para>
<para>キーが押されているか確認するKeyboardクラス、動作時に音を発生させるクラス、移動先に他のObjectがないか確認するクラス、接触処理を行うクラスを追加で取得する</para>
<param name="keyboard"><para>キーが押されているか確認するクラス</para></param>
<param name="sound"><para>動作時に音を発生させるクラス</para></param>
<param name="collision"><para>拾う範囲に他のObjectがないか確認するクラス</para></param>
<param name="playerhit"><para>Playerの接触処理を行うクラス</para></param>
</summary>
</member>
<member name="M:PlayerMoveX.Do" decl="false" source="c:\users\student\desktop\action\action\action\playermovex.cpp" line="25">
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
<param name="num"><para>num:X軸に加算しようとしている値</para></param>
</summary>
</member>
<member name="M:PlayerMoveX.Push(System.Single,std.vector&lt;Object**,std.allocator&lt;Object**&gt;&gt;,System.Int32)" decl="false" source="c:\users\student\desktop\action\action\action\playermovex.cpp" line="99">
<summary>
<para>Playerの押す処理</para>
<para>地面にいるときにのみ、押す動作を開始する</para>
<para>渡された動的配列のから、Playerに密着しているObjectと、</para>
<para>Playerに密着していないObjectの内、Playerから近いObjectとの差を得する</para>
<para>PlayerがObjectを持っている場合、同様に密着しているObjectと密着していないObjectとの差を取得する</para>
<para>密着しているObjectに、渡されたfloatの値に対して、どの程度動けるかを取得する</para>
<para>収得した値のうち、一番小さい値でPlayerに密着しているObject全てを押す</para>
<para>実際に押せたかどうかを戻り値にする</para>
<param name="num"><para>num:X軸に加算しようとしている値</para></param>
<param name="target"><para>target:押そうとしている対象のObjectのポインタ全て</para></param>
<param name="check"><para>check:Collision::HitCheckXでのint型の戻り値、押そうとしている方向を確認する</para></param>
</summary>
</member>
<member name="M:PlayerMoveX.AlignAdhesionObjects(std.vector&lt;Object**,std.allocator&lt;Object**&gt;&gt;,Object!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="false" source="c:\users\student\desktop\action\action\action\playermovex.cpp" line="149">
<summary>
<para>Objectの動的配列から、対象のObjectに接触しているObjectの動的配列と</para>
<para>接触しているObjectから、接触していないObjectのうち、一番近いObjectまでの差を返す</para>
<para>引数:</para>
<param name="objects"><para>objects:調べるObjectのポインタの動的配列</para></param>
<param name="player"><para>player:接触しているか調べるObjectのポインタ</para></param>
<param name="check"><para>check:HitCheckX及びHitCheckYのintで返されるint型変数</para></param>
<para>戻り値:</para>
<returns>
<para>std::vector:接触ししている全てのObjectのポインタ</para>
<para>float:playerが一番近いObjectに接触するまで動ける数値</para>
</returns>
</summary>
</member>
</members>
</doc>