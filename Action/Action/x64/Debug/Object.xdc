<?xml version="1.0"?><doc>
<members>
<member name="M:Object.#ctor(System.Single,System.Single,System.Single,System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="6">
<summary>
<para>コンストラクタ</para>
<para>オブジェクトの左上のX座標とY座標、横幅と縦幅を設定する</para>
<para>また、初期位置を保存する</para>
<param name="x"><para>x:Objectの左上のX座標</para></param>
<param name="y"><para>y:Objectの左上のY座標</para></param>
<param name="height"><para>height:Objectの左から右までの横幅</para></param>
<param name="width"><para>width:Objectの上から下までの縦幅</para></param>
</summary>
</member>
<member name="M:Object.Finalize" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="21">
<summary>
<para>終了処理</para>
<para>メモリ上の画像を削除する</para>
</summary>
</member>
<member name="M:Object.Left" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="29">
<summary>
<para>オブジェクトの左端のｘ座標を返す</para>
<returns>
<para>オブジェクトの左端のｘ座標</para>
</returns>
</summary>
</member>
<member name="M:Object.Right" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="39">
<summary>
<para>オブジェクトの右端のｘ座標を返す</para>
<returns>
<para>オブジェクトの右端のｘ座標</para>
</returns>
</summary>
</member>
<member name="M:Object.Top" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="49">
<summary>
<para>オブジェクトの上辺のｙ座標を返す</para>
<returns>
<para>オブジェクトの上辺のｙ座標</para>
</returns>
</summary>
</member>
<member name="M:Object.Base" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="59">
<summary>
<para>オブジェクトの下辺のｙ座標を返す</para>
<returns>
<para>オブジェクトの下辺のｙ座標</para>
</returns>
</summary>
</member>
<member name="M:Object.Center_X" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="69">
<summary>
<para>オブジェクトの中心のX座標を返す</para>
<returns>
<para>オブジェクトの中心のX座標</para>
</returns>
</summary>
</member>
<member name="M:Object.GetWidth" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="79">
<summary>
<para>オブジェクトの横幅を返す</para>
<returns>
<para>オブジェクトの横幅</para>
</returns>
</summary>
</member>
<member name="M:Object.GetHeight" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="89">
<summary>
<para>オブジェクトの縦幅を返す</para>
<returns>
<para>オブジェクトの縦幅</para>
</returns>
</summary>
</member>
<member name="M:Object.Set(System.Single,System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="99">
<summary>
<para>オブジェクトを指定した座標に設定する</para>
<param name="x"><para>x:設定するObjectの左上のX座標</para></param>
<param name="y"><para>y:設定するObjectの左上のY座標</para></param>
</summary>
</member>
<member name="M:Object.Set(System.Single,System.Single,System.Single,System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="109">
<summary>
<para>オブジェクトを指定した座標に設定する</para>
<para>追加でオブジェクトの縦幅、横幅を設定する</para>
<param name="x"><para>x:設定するObjectの左上のX座標</para></param>
<param name="y"><para>y:設定するObjectの左上のY座標</para></param>
<param name="height"><para>height:Objectの左から右までの横幅</para></param>
<param name="width"><para>width:Objectの上から下までの縦幅</para></param>
</summary>
</member>
<member name="M:Object.CanPushed(System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="123">
<summary>
<para>押されようとしている数字から、自分が押されることのできる数字を返す</para>
<para>デフォルトだと常に0を返す</para>
<param name="num"><para>num:現在の位置から動かそうとしている座標への差</para></param>
<returns>
<para>numに対して、実際にこのObjectを動かせる距離</para>
</returns>
</summary>
</member>
<member name="M:Object.CanPicked(Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="135">
<summary>
<para>Objectに持たれるかを返す</para>
<para>デフォルトだと常にfalseを返す</para>
<param name="object"><para>object:自分を持つObject</para></param>
<returns>
<para>true:自分を持つことができる</para>
<para>false:自分を持つことができない</para>
</returns>
</summary>
</member>
<member name="M:Object.CanPutted" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="148">
<summary>
<para>今Objectが置かれることができるかを返す</para>
<para>デフォルトだと常にfalseを返す</para>
<returns>
<para>true:自分を持つことができる</para>
<para>false:自分を持つことができない</para>
</returns>
</summary>
</member>
<member name="M:Object.CanThrew" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="160">
<summary>
<para>今Objectが投げられることができるかを返す</para>
<para>デフォルトだと常にfalseを返す</para>
<returns>
<para>true:自分投げることができる</para>
<para>false:自分を投げることができない</para>
</returns>
</summary>
</member>
<member name="M:Object.Retry" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="172">
<summary>
<para>リトライ処理</para>
<para>初期位置に座標を設定する</para>
</summary>
</member>
<member name="M:Object.CanClear" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="180">
<summary>
<para>今クリアできるかを返す</para>
<para>デフォルトだと常にfalseを返す</para>
<returns>
<para>true:自分投げることができる</para>
<para>false:自分を投げることができない</para>
</returns>
</summary>
</member>
</members>
</doc>