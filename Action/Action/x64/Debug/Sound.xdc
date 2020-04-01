<?xml version="1.0"?><doc>
<members>
<member name="M:Sound.#ctor" decl="false" source="c:\users\student\desktop\action\action\action\sound.cpp" line="6">
<summary>
<para>コンストラクタ</para>
<para>プログラム中で使用するBGMとSEの設定とSEの音量調整</para>
<para>現在鳴らしているBGMを無しにする</para>
</summary>
</member>
<member name="M:Sound.RegulationSeVolume(Se_Name,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\sound.cpp" line="32">
<summary>
<para>音量の調整</para>
<para>引数で受け取ったObjectが出す音量の調整を行う</para>
<para>対象のObjectが画面外にいる時、離れているほど音は小さくなる</para>
<param name="sename"><para>sename:鳴らそうとしているSEの列挙子</para></param>
<param name="num"><para>object:音を鳴らそうとしているObject</para></param>
<returns>
<para>鳴らす音量(0～255)</para>
</returns>
</summary>
</member>
<member name="M:Sound.PlayBgm(BGM_Name)" decl="false" source="c:\users\student\desktop\action\action\action\sound.cpp" line="58">
<summary>
<para>BGMの再生</para>
<para>引数で受け取ったBGMを再生し、再生しているBGMの列挙子を更新する</para>
<para>引数で受け取った列挙子が現在鳴らしているBGMの場合、何もしない</para>
<param name="bgmname"><para>bgmname:鳴らそうとしているBGMの列挙子</para></param>
</summary>
</member>
<member name="M:Sound.PlaySe(Se_Name)" decl="false" source="c:\users\student\desktop\action\action\action\sound.cpp" line="73">
<summary>
<para>SEの再生</para>
<para>引数で受け取ったSEを再生する</para>
<param name="sename"><para>sename:鳴らそうとしているseの列挙子</para></param>
</summary>
</member>
<member name="M:Sound.PlaySe(Se_Name,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\sound.cpp" line="86">
<summary>
<para>SEの再生</para>
<para>引数で受け取ったSEを再生する</para>
<param name="sename"><para>sename:鳴らそうとしているseの列挙子</para></param>
</summary>
</member>
<member name="M:Sound.StopBgm" decl="false" source="c:\users\student\desktop\action\action\action\sound.cpp" line="100">
<summary>
<para>BGMの停止</para>
<para>現在BGMを鳴らしている場合、停止させる</para>
</summary>
</member>
<member name="M:Sound.StopSe" decl="false" source="c:\users\student\desktop\action\action\action\sound.cpp" line="111">
<summary>
<para>SEの停止</para>
<para>現在鳴らしているSEを全て止める</para>
</summary>
</member>
<member name="M:Sound.Finalize" decl="false" source="c:\users\student\desktop\action\action\action\sound.cpp" line="122">
<summary>
<para>終了処理</para>
<para>メモリ上にあるBGMの情報を削除する</para>
</summary>
</member>
</members>
</doc>