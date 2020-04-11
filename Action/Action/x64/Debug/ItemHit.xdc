<?xml version="1.0"?><doc>
<members>
<member name="M:ItemHit.#ctor(Collision*,Item*)" decl="false" source="c:\users\yu-rei\music\action\action\action\itemhit.cpp" line="4">
<summary>
<para>コンストラクタ</para>
<para>操作するitemのポインタを追加で受け取る</para>
<param name="item"><para>item:操作するitemのポインタ</para></param>
</summary>
</member>
<member name="M:ItemHit.HitObjects(System.Int32,System.Single)" decl="false" source="c:\users\yu-rei\music\action\action\action\itemhit.cpp" line="13">
<summary>
<para>接触処理</para>
<para>item_のstateを変更した後、引数で受け取ったintの数値によってX軸かY軸に受け取ったfloatの数値分加算する</para>
<param name="check"><para>check:Collision::HitCheckXやCollision::HitCheckX、Collision::MapCheckの戻り値の一つであるint型の数値</para></param>
<param name="distance"><para>distance:Collision::HitCheckXやCollision::HitCheckX、Collision::MapCheckの戻り値の一つであるfloat型の数値</para></param>
</summary>
</member>
</members>
</doc>