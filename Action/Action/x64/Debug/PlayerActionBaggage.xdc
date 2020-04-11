<?xml version="1.0"?><doc>
<members>
<member name="M:PlayerActionBaggage.#ctor(Keyboard*,Sound*,Collision*,Player*)" decl="false" source="c:\users\yu-rei\music\action\action\action\playeractionbaggage.cpp" line="5">
<summary>
<para>コンストラクタ</para>
<para>キーが押されているか確認するKeyboardクラス、拾う範囲に他のObjectがないか確認するクラス、行動時の音を管理するクラスを追加で取得する</para>
<param name="keyboard"><para>キーが押されているか確認するクラス</para></param>
<param name="sound"><para>動作時に音を発生させるクラス</para></param>
<param name="collision"><para>拾う範囲に他のObjectがないか確認するクラス</para></param>
</summary>
</member>
<member name="M:PlayerActionBaggage.Do" decl="false" source="c:\users\yu-rei\music\action\action\action\playeractionbaggage.cpp" line="17">
<summary>
<para>行動処理</para>
<para>押されたキーと、PlayerがObjectを持っているかどうかによって行動が変わる</para>
<para>Spaceキーを押した時、PlayerがObjectを持っていた場合:Throw処理</para>
<para>Spaceキーを押した時、PlayerがObjectを持っていない場合:Pick処理</para>
<para>下キーを押したとき、PlayerがObjectを持っていた場合:Put処理</para>
</summary>
</member>
<member name="M:PlayerActionBaggage.Pick" decl="false" source="c:\users\yu-rei\music\action\action\action\playeractionbaggage.cpp" line="37">
<summary>
<para>拾う行動処理</para>
<para>player_の位置と向きから拾う範囲を設定し、その範囲内にObjectがあった場合、そのObjectに対して拾えるかを確認する</para>
<para>拾える場合、player_のcarryonの値をそのObjectに更新し、そのObjectに拾われた時の動作を行わせる</para>
</summary>
</member>
<member name="M:PlayerActionBaggage.Throw" decl="false" source="c:\users\yu-rei\music\action\action\action\playeractionbaggage.cpp" line="70">
<summary>
<para>投げる行動処理</para>
<para>carryonに対して投げられるかを確認する</para>
<para>投げられる場合、player_のcarryonの値をnullptrに更新し、そのObjectに投げられた時の動作を行わせる</para>
</summary>
</member>
<member name="M:PlayerActionBaggage.Put" decl="false" source="c:\users\yu-rei\music\action\action\action\playeractionbaggage.cpp" line="85">
<summary>
<para>置く行動処理</para>
<para>carryonに対して置けるかを確認する</para>
<para>置ける場合、player_のcarryonの値をnullptrに更新し、そのObjectに置かれた時の動作を行わせる</para>
</summary>
</member>
</members>
</doc>