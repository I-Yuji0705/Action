<?xml version="1.0"?><doc>
<members>
<member name="M:Item.#ctor(Sound*,Collision*,System.Single,System.Single,System.Single,System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="13">
<summary>
<para>コンストラクタ</para>
<para>描写する画像の設定、当たった後の処理を行うクラス、行動を管理するクラスの生成</para>
<param name="sound"><para>動作時に音を発生させるクラス</para></param>
<param name="collision"><para>動作時や動作確認時に接触判定を調べる</para></param>
</summary>
</member>
<member name="M:Item.Initialize" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="32">
<summary>
<para>初期化処理</para>
<para>自分を持っているPlayerのポインタをnullptrにする</para>
</summary>
</member>
<member name="M:Item.Update" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="42">
<summary>
<para>更新処理</para>
<para>Itemの状態によってで行う行動を変える</para>
</summary>
</member>
<member name="M:Item.Draw" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="63">
<summary>
<para>描写処理</para>
<para>Itemの向きによって、描写する画像を反転する</para>
</summary>
</member>
<member name="M:Item.CanPicked(Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="72">
<summary>
<para>Objectに持たれるかを返す</para>
<para>Objectの頭上に自身を置くことができるかを調べ、返す</para>
<param name="object"><para>object:自分を持つObject</para></param>
<returns>
<para>true:自分を持つことができる</para>
<para>false:自分を持つことができない</para>
</returns>
</summary>
</member>
<member name="M:Item.Picked(Object*)" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="89">
<summary>
<para>Objectに持たれた始める際の処理</para>
<para>自分のstateを変更し、持たれる対象をポインタに保存し、自分の位置を変更する</para>
<param name="object"><para>object:自分を持つObject</para></param>
</summary>
</member>
<member name="M:Item.CanPutted" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="100">
<summary>
<para>carrier_に置かれることができるかを返す</para>
<para>Objectの頭上に自身を置くことができるかを調べ、返す</para>
<returns>
<para>true:自分を持つことができる</para>
<para>false:自分を持つことができない</para>
</returns>
</summary>
</member>
<member name="M:Item.Putted" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="132">
<summary>
<para>Objectに持たれた始める際の処理</para>
<para>stateと持たれる対象をポインタに保存し、自分の位置を変更する</para>
<param name="object"><para>object:自分を持つObject</para></param>
</summary>
</member>
<member name="M:Item.CanThrew" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="141">
<summary>
<para>carrier_に投げられる際、投げれるかを返す</para>
<para>Itemのvector_から投げる際に自分がいる位置に他のObjectがないか調べる</para>
<returns>
<para>true:自分投げることができる</para>
<para>false:自分を投げることができない</para>
</returns>
</summary>
</member>
<member name="M:Item.Threw" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="173">
<summary>
<para>投げられる際の処理</para>
<para>自分の位置を変更する</para>
</summary>
</member>
<member name="M:Item.Retry" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="181">
<summary>
<para>リトライ処理</para>
<para>自分の位置を最初の位置に戻し、初期化処理を行う</para>
</summary>
</member>
<member name="M:Item.CanPushed(System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="190">
<summary>
<para>押されようとしている数字から、自分が押されることのできる数字を返す</para>
<para>ステージ端に移動してしまう場合、その差の数字を返す</para>
<para>自分が押される分数字を半分にした後、移動先にObjectがあった場合そのObjectのCapushedを再帰させ、一番小さい数字を返す</para>
<param name="num"><para>num:現在の位置から動かそうとしている座標への差</para></param>
<returns>
<para>numに対して、実際にこのObjectを動かせる距離</para>
</returns>
</summary>
</member>
<member name="M:Item.Pushed(System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\item.cpp" line="225">
<summary>
<para>引数で受け取った数字分座標を移動する</para>
<para>移動先に他のObjectがあった場合、そのObjectもPushedを使い、再帰させる</para>
<param name="num"><para>num:現在の位置から動かそうとしている座標への差</para></param>
</summary>
</member>
</members>
</doc>