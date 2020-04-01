<?xml version="1.0"?><doc>
<members>
<member name="M:ItemMoveX.#ctor(Sound*,Collision*,Item*,ItemHit*)" decl="false" source="c:\users\student\desktop\action\action\action\itemmovex.cpp" line="4">
<summary>
<para>コンストラクタ</para>
<para>音を管理するクラスと接触を判定するクラス、接触後の処理を行うクラスのポインタを追加で収得する</para>
<param name="sound"><para>sound:壁に接触した際に鳴らす音を管理するクラスのポインタ</para></param>
<param name="collision"><para>collision:移動する先に衝突するObjectがあるかを調べるクラスのポインタ</para></param>
<param name="itemhit"><para>itemhit:接触時に位置調整などの処理を行うクラスのポインタ</para></param>
</summary>
</member>
<member name="M:ItemMoveX.MoveX(System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\itemmovex.cpp" line="17">
<summary>
<para>Y軸の移動処理</para>
<para>移動しようとしている数字を受け取り、移動先に他のObjectに接触するかを調べる</para>
<para>移動先にObjectない場合:xに数値を加算し、移動する</para>
<para>移動先にObjectある場合:接触処理を行う</para>
<param name="num"><para>num:X軸に加算しようとしている値</para></param>
</summary>
</member>
<member name="M:ItemMoveX.Do" decl="false" source="c:\users\student\desktop\action\action\action\itemmovex.cpp" line="47">
<summary>
<para>行動処理</para>
<para>item_の向きから移動先を決め、X軸の移動処理を行う</para>
</summary>
</member>
</members>
</doc>