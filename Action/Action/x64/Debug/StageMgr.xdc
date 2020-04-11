<?xml version="1.0"?><doc>
<members>
<member name="M:StageMgr.#ctor(Keyboard*,Sound*,IGameStateChanger*)" decl="false" source="c:\users\yu-rei\music\action\action\action\stagemgr.cpp" line="13">
<summary>
<para>コンストラクタ</para>
<para>キャラクターに渡すKeyboardクラス、Soundクラス、IGameStateChangerクラスを受け取る</para>
<para>ゲームのステージを生成する</para>
<param name="keyboard"><para>Playerの操作に使用するクラスのポインタ</para></param>
<param name="sound"><para></para>ObjectからSEを発生させるクラス</param>
<param name="statechanger"><para>GameのStateを変更するクラス</para></param>
</summary>
</member>
<member name="M:StageMgr.CreateStage(Keyboard*,Sound*,IGameStateChanger*,Collision*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\yu-rei\music\action\action\action\stagemgr.cpp" line="30">
<summary>
<para>ステージの生成処理</para>
<para>引数で渡されたステージ名のテキストファイルから、ステージ情報を読み込み、ステージを生成する</para>
<para>この関数を使用する場合、CreateStageData関数は</para>
<param name="keyboard"><para>Playerの操作に使用するクラスのポインタ</para></param>
<param name="sound"><para></para>ObjectからSEを発生させるクラス</param>
<param name="statechanger"><para>GameのStateを変更するクラス</para></param>
<param name="collision"><para>Objectの接触判定を担当するクラス</para></param>
<param name="stagename"><para>読み込むテキストファイルの名前</para></param>
</summary>
</member>
<member name="M:StageMgr.CreateStageData(Keyboard*,Sound*,IGameStateChanger*,Collision*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\yu-rei\music\action\action\action\stagemgr.cpp" line="69">
<summary>
<para>ステージの生成処理</para>
<para>CreateStageとは違い、プログラム文から生成したステージ情報をテキストファイルに出力する</para>
<param name="keyboard"><para>Playerの操作に使用するクラスのポインタ</para></param>
<param name="sound"><para></para>ObjectからSEを発生させるクラス</param>
<param name="statechanger"><para>GameのStateを変更するクラス</para></param>
<param name="collision"><para>Objectの接触判定を担当するクラス</para></param>
<param name="stagename"><para>出力するテキストファイルの名前</para></param>
</summary>
</member>
<member name="M:StageMgr.Initialize" decl="false" source="c:\users\yu-rei\music\action\action\action\stagemgr.cpp" line="127">
<summary>
<para>初期化処理</para>
<para>ステージ上のObjectとカメラの初期化処理を行う</para>
</summary>
</member>
<member name="M:StageMgr.Draw" decl="false" source="c:\users\yu-rei\music\action\action\action\stagemgr.cpp" line="139">
<summary>
<para>描写処理</para>
<para>ステージ上のObjectの描写処理を行う</para>
</summary>
</member>
<member name="M:StageMgr.Update" decl="false" source="c:\users\yu-rei\music\action\action\action\stagemgr.cpp" line="151">
<summary>
<para>更新処理</para>
<para>ステージ上のObjectの更新処理を行う</para>
</summary>
</member>
<member name="M:StageMgr.Finalize" decl="false" source="c:\users\yu-rei\music\action\action\action\stagemgr.cpp" line="162">
<summary>
<para>終了処理</para>
<para>ステージ上のObjectの終了処理を行う</para>
</summary>
</member>
<member name="M:StageMgr.Retry" decl="false" source="c:\users\yu-rei\music\action\action\action\stagemgr.cpp" line="172">
<summary>
<para>リトライ処理処理</para>
<para>ステージ上のObjectのリトライ処理を行う</para>
</summary>
</member>
</members>
</doc>