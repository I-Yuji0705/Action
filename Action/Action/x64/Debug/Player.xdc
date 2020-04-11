<?xml version="1.0"?><doc>
<members>
<member name="M:Player.#ctor(Keyboard*,Sound*,IGameStateChanger*,Collision*,System.Single,System.Single,System.Single,System.Single)" decl="false" source="c:\users\yu-rei\music\action\action\action\player.cpp" line="10">
<summary>
<para>コンストラクタ</para>
<para>描写する画像の設定、当たった後の処理を行うクラス、行動を管理するクラスの生成</para>
<param name="sound"><para>動作時に音を発生させるクラス</para></param>
<param name="collision"><para>動作時や動作確認時に接触判定を調べる</para></param>
</summary>
</member>
<member name="M:Player.Action" decl="false" source="c:\users\yu-rei\music\action\action\action\player.cpp" line="30">
<summary>
<para>プレイヤーのアクションの管理</para>
<para>プレイヤーのキー入力とそれに対応するPlayerActionを行う</para>
</summary>
</member>
<member name="M:Player.Initialize" decl="false" source="c:\users\yu-rei\music\action\action\action\player.cpp" line="41">
<summary>
<para>初期化処理</para>
</summary>
</member>
<member name="M:Player.Update" decl="false" source="c:\users\yu-rei\music\action\action\action\player.cpp" line="51">
<summary>
<para>更新処理</para>
<para>Playerのstateがクリア状態の時のみ、Dance処理を行う</para>
</summary>
</member>
<member name="M:Player.Draw" decl="false" source="c:\users\yu-rei\music\action\action\action\player.cpp" line="66">
<summary>
<para>描写処理</para>
<para>Playerの向きによって、描写する画像を反転する</para>
</summary>
</member>
<member name="M:Player.Clear" decl="false" source="c:\users\yu-rei\music\action\action\action\player.cpp" line="75">
<summary>
<para>クリア処理</para>
<para>クリア条件を満たした際に、一度だけ呼ばれる関数</para>
</summary>
</member>
<member name="M:Player.Retry" decl="false" source="c:\users\yu-rei\music\action\action\action\player.cpp" line="84">
<summary>
<para>リトライ処理</para>
<para>Objectのリトライ処理に加え、初期化を行う</para>
</summary>
</member>
<member name="M:Player.CanClear" decl="false" source="c:\users\yu-rei\music\action\action\action\player.cpp" line="93">
<summary>
<para>今クリアできるかを返す</para>
<returns>
<para>true:自分投げることができる</para>
<para>false:自分を投げることができない</para>
</returns>
</summary>
</member>
</members>
</doc>