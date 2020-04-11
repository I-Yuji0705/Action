<?xml version="1.0"?><doc>
<members>
<member name="M:PlayerHit.#ctor(Collision*,Player*)" decl="false" source="c:\users\yu-rei\music\action\action\action\playerhit.cpp" line="4">
<summary>
<para>コンストラクタ</para>
<para>追加で、操作するPlayerのポインタを取得する</para>
<param name="player"><para>player:操作する対象のPlayerクラスのポインタ</para></param>
</summary>
</member>
<member name="M:PlayerHit.HitObjects(System.Int32,System.Single)" decl="false" source="c:\users\yu-rei\music\action\action\action\playerhit.cpp" line="13">
<summary>
<para>接触処理</para>
<para>引数で受け取ったintの数値によってX軸かY軸に受け取ったfloatの数値分加算し、player_のstateを変更する</para>
<para>intの数字が4の時、angleも変更する</para>
<param name="check"><para>check:Collision::HitCheckXやCollision::HitCheckX、Collision::MapCheckの戻り値の一つであるint型の数値</para></param>
<param name="distance"><para>distance:Collision::HitCheckXやCollision::HitCheckX、Collision::MapCheckの戻り値の一つであるfloat型の数値</para></param>
</summary>
</member>
</members>
</doc>