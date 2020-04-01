<?xml version="1.0"?><doc>
<members>
<member name="M:PlayerMoveY.#ctor(Keyboard*,Sound*,Collision*,Player*,PlayerHit*)" decl="false" source="c:\users\student\desktop\action\action\action\playermovey.cpp" line="6">
<summary>
<para>コンストラクタ</para>
<para>キーが押されているか確認するKeyboardクラス、動作時に音を発生させるクラス、移動先に他のObjectがないか確認するクラス、接触処理を行うクラスを追加で取得する</para>
<param name="keyboard"><para>キーが押されているか確認するクラス</para></param>
<param name="sound"><para>動作時に音を発生させるクラス</para></param>
<param name="collision"><para>拾う範囲に他のObjectがないか確認するクラス</para></param>
<param name="playerhit"><para>Playerの接触処理を行うクラス</para></param>
</summary>
</member>
<member name="M:PlayerMoveY.Do" decl="false" source="c:\users\student\desktop\action\action\action\playermovey.cpp" line="21">
<summary>
<para>行動処理</para>
<para>上キーを押した場合、ジャンプする</para>
<para>押していない場合、または重力よりも上に上がる力がない場合、下に落下する</para>
</summary>
</member>
<member name="M:PlayerMoveY.MoveY(System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\playermovey.cpp" line="43">
<summary>
<para>Y軸の移動処理</para>
<para>移動しようとしている数字を受け取り、移動先に他のObjectに接触するかを調べる</para>
<para>移動先またはPlayerが持っているObject以外にObjectがない場合:yに数値を加算し、空中に移動する</para>
<para>移動先またはPlayerが持っているObject以外ににObjectがあった場合:接触処理を行う</para>
<para>PlayerがObjectを持っている場合、そのObjectも同様にPlayer以外と接触するかを調べる</para>
<param name="num"><para>num:X軸に加算しようとしている値</para></param>
</summary>
</member>
</members>
</doc>