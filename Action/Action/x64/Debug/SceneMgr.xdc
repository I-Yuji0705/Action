<?xml version="1.0"?><doc>
<members>
<member name="M:SceneMgr.#ctor(Keyboard*,Sound*)" decl="false" source="c:\users\yu-rei\music\action\action\action\scenemgr.cpp" line="8">
<summary>
<para>コンストラクタ</para>
<para>Scene内で使用するキーボードクラスと音を発生させるクラスを取得する</para>
<para>追加で、最初のSceneをTitleに設定する</para>
<param name="keyboard"><para>キーが押されているか確認するクラス</para></param>
<param name="sound"><para>BGMやSEなどの音を発生させるクラス</para></param>
</summary>
</member>
<member name="M:SceneMgr.Initialize" decl="false" source="c:\users\yu-rei\music\action\action\action\scenemgr.cpp" line="24">
<summary>
<para>初期化処理</para>
<para>Sceneの初期化処理を行う</para>
</summary>
</member>
<member name="M:SceneMgr.Finalize" decl="false" source="c:\users\yu-rei\music\action\action\action\scenemgr.cpp" line="32">
<summary>
<para>終了処理</para>
<para>Sceneの終了処理を行う</para>
</summary>
</member>
<member name="M:SceneMgr.Update" decl="false" source="c:\users\yu-rei\music\action\action\action\scenemgr.cpp" line="41">
<summary>
<para>更新処理</para>
<para>Sceneの変更要請がない場合、Sceneの更新処理を行う</para>
<para>Sceneの変更要請があった場合、画面を暗くし始める</para>
</summary>
</member>
<member name="M:SceneMgr.Draw" decl="false" source="c:\users\yu-rei\music\action\action\action\scenemgr.cpp" line="69">
<summary>
<para>描写処理</para>
<para>Sceneの描写処理を行う</para>
</summary>
</member>
<member name="M:SceneMgr.ChangeScene(Scene)" decl="false" source="c:\users\yu-rei\music\action\action\action\scenemgr.cpp" line="77">
<summary>
<para>シーンの変更処理</para>
<para>次のシーンをセットし、描写範囲を設定しなおす</para>
</summary>
</member>
<member name="M:SceneMgr.BlackOutScene" decl="false" source="c:\users\yu-rei\music\action\action\action\scenemgr.cpp" line="86">
<summary>
<para>シーンの暗転処理</para>
<para>描写範囲を狭めることで画面を暗くする</para>
<para>描写範囲を無くした後、シーンの変更処理を行い、Stateを暗転の状態から明るくする状態に変更する</para>
</summary>
</member>
<member name="M:SceneMgr.LightingScene" decl="false" source="c:\users\yu-rei\music\action\action\action\scenemgr.cpp" line="117">
<summary>
<para>シーンの明るくする処理</para>
<para>描写範囲を広げることで画面を明るくする</para>
<para>描写範囲を画面まで広げた後、Scene毎のBGMを再生し、Stateを通常時に変更する</para>
</summary>
</member>
<member name="M:SceneMgr.SetDepictionScreen(System.Int32,System.Int32,System.Int32,System.Int32)" decl="false" source="c:\users\yu-rei\music\action\action\action\scenemgr.cpp" line="132">
<summary>
<para>シーンの描写範囲の変更処理</para>
<para>描写する範囲の左上のX座標とY座標、右下のX座標とY座標を引数として受け取る</para>
<para>シーンの描写範囲を変数に保存した後、受け取った座標を対角線とする四角形を描写範囲として設定する</para>
<param name="x1"><para>x1:描写する範囲の左上のX座標</para></param>
<param name="y1"><para>y1:描写する範囲の左上のY座標</para></param>
<param name="x2"><para>x2:描写する範囲の右下のX座標</para></param>
<param name="y2"><para>y2:描写する範囲の右下のX座標</para></param>
</summary>
</member>
</members>
</doc>