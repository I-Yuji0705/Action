<?xml version="1.0"?><doc>
<members>
<member name="M:Title.#ctor(Keyboard*,Sound*,ISceneChanger*)" decl="false" source="c:\users\student\desktop\action\action\action\title.cpp" line="8">
<summary>
<para>コンストラクタ</para>
<para>追加で、タイトルに表示する画像と最初に表示する字幕の生成を行う</para>
</summary>
</member>
<member name="M:Title.Initialize" decl="false" source="c:\users\student\desktop\action\action\action\title.cpp" line="18">
<summary>
<para>初期化処理</para>
<para>字幕の初期化処理を行う</para>
</summary>
</member>
<member name="M:Title.Update" decl="false" source="c:\users\student\desktop\action\action\action\title.cpp" line="26">
<summary>
<para>更新処理</para>
<para>字幕の更新処理を行う</para>
<para>nextstateが変更されていた場合、nextstateによって処理を行う</para>
</summary>
</member>
<member name="M:Title.Draw" decl="false" source="c:\users\student\desktop\action\action\action\title.cpp" line="63">
<summary>
<para>描写処理</para>
<para>タイトルと字幕の描写処理を行う</para>
</summary>
</member>
<member name="M:Title.Finalize" decl="false" source="c:\users\student\desktop\action\action\action\title.cpp" line="73">
<summary>
<para>終了処理</para>
<para>メモリ上のタイトルの画像を削除し、字幕の終了処理を行う</para>
</summary>
</member>
<member name="M:Title.ChangeState(TitleState)" decl="false" source="c:\users\student\desktop\action\action\action\title.cpp" line="82">
<summary>
<para>Stateの変更処理</para>
<para>nextstate_を引数の値に変更する</para>
<para>引数:</para>
<param name="state"><para>nextstate_にCopyする値</para></param>
</summary>
</member>
</members>
</doc>