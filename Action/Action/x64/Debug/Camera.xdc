<?xml version="1.0"?><doc>
<members>
<member name="M:Camera.#ctor(std.vector&lt;Object**,std.allocator&lt;Object**&gt;&gt;*,Collision*)" decl="false" source="c:\users\yu-rei\music\action\action\action\camera.cpp" line="6">
<summary>
<para>コンストラクタ</para>
<para>描写するステージとCpllisionクラスのポインタの取得</para>
<para>state:描写するステージのポインタ</para>
<para>collision:プレイヤーとステージ右端、左端オブジェクトのポインタを貰う</para>
</summary>
</member>
<member name="M:Camera.Initialize" decl="false" source="c:\users\yu-rei\music\action\action\action\camera.cpp" line="17">
<summary>
<para>初期化処理</para>
<para>ステージの右端、左端、画面の中央に描写するPlayerのポインタの取得</para>
</summary>
</member>
<member name="M:Camera.Update" decl="false" source="c:\users\yu-rei\music\action\action\action\camera.cpp" line="27">
<summary>
<para>更新処理</para>
<para>playerがステージ右端、左端にいる場合を除いて、画面の中央に描写するように全体を動かす</para>
</summary>
</member>
</members>
</doc>