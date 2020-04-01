<?xml version="1.0"?><doc>
<members>
<member name="M:Collision.MapDistance(Object!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="14">
<summary>
<para>対象のObjectが画面端まで接触するまで動ける数値を返す</para>
<para>引数:</para>
<param name="player"><para>player:移動するObjectのポインタ</para></param>
<param name="check"><para>check:MapCheck内のcheck変数</para></param>
<para>戻り値:</para>
<returns>
<para>Objectがステージ左端または右端まに接触するまで動ける数値</para>
</returns>
</summary>
</member>
<member name="M:Collision.Check(System.Single,System.Single,System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="26">
<summary>
<para>
指定した右上の座標と左下の座標を対角線とする四角形の中に、指定したObjectが接触しているかを返す
</para>
<para>引数:</para>
<param name="x1"><para>x1:調べる範囲の左上のX座標</para></param>
<param name="y1"><para>y1:調べる範囲の左上のY座標</para></param>
<param name="x2"><para>x2:調べる範囲の右下のX座標</para></param>
<param name="y2"><para>y2:調べる範囲の右下のY座標</para></param>
<param name="object"><para>object:対象のObjectのポインタ</para></param>
<returns>
<para>戻り値:</para>
<para>true:Objectが接触する</para>
<para>false:Objectが接触しない</para>
</returns>
</summary>
</member>
<member name="M:Collision.Check(System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*,Object!System.Runtime.CompilerServices.IsConst*)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="44">
<summary>
<para>
対象のオブジェクトが指定した座標上に出る場合、指定したObjectに接触するかを返す
</para>
<para>引数:</para>
<param name="x"><para>x:対象のObjectが移動するX座標</para></param>
<param name="y"><para>y:対象のObjectが移動するY座標</para></param>
<param name="player"><para>player:対象のObjectのポインタ</para></param>
<param name="object"><para>object:調べるObjectのポインタ</para></param>
<returns>
<para>戻り値:</para>
<para>true:Objectが接触する</para>
<para>false:Objectが接触しない</para>
</returns>
</summary>
</member>
<member name="M:Collision.#ctor(std.vector&lt;Object**,std.allocator&lt;Object**&gt;&gt;*)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="62">
<summary>
Stageのポインタの収得
</summary>
</member>
<member name="M:Collision.Initialize" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="66">
<summary>
<para>初期化処理</para>
<para>Stageのポインタから、ステージ右端と左端のTerrainの収得</para>
</summary>
</member>
<member name="M:Collision.ObjectDistance(Object!System.Runtime.CompilerServices.IsConst*,Object!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="72">
<summary>
<para>接触する二つのオブジェクトが接触するまで移動するObjectが動ける数値</para>
<para>引数:</para>
<param name="target"><para>target:playerが接触するObjectのポインタ</para></param>
<param name="player"><para>player:移動するObjectのポインタ</para></param>
<param name="check"><para>check:HitCheckXまたはHitCheckY内のcheck変数</para></param>
<returns>
<para>戻り値:</para>
<para>二つのオブジェクトが接触するまでplayerが動ける数値</para></returns>
</summary>
</member>
<member name="M:Collision.Check(System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="84">
<summary>
<para>
対象のオブジェクトが指定した座標上に出る場合、指定したObjectに接触するかを返す
</para>
<para>引数:</para>
<param name="x"><para>x:対象のObjectが移動するX座標</para></param>
<param name="y"><para>y:対象のObjectが移動するY座標</para></param>
<param name="player"><para>player:対象のObjectのポインタ</para></param>
<para>戻り値:</para>
<returns>
<para>true:Objectが接触する</para>
<para>false:Objectが接触しない</para>
</returns>
</summary>
</member>
<member name="M:Collision.MapCheck(System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="true" source="c:\users\student\desktop\action\action\action\collision.h" line="102">
<summary>
<para>指定したX地点に移動した場合、ステージの外に出るかどうか、</para>
<para>出る場合、現在の位置から接触するまで動ける数値を返す</para>
<para>引数:</para>
<param name="num"><para>num:移動しようとしているX地点</para></param>
<param name="player"><para>player:移動するObjectのポインタ</para></param>
<para>戻り値:</para>
<returns>
<para>int:Objectがステージ左端または右端に接触するか</para>
<para>0:接触しない</para>
<para>1:右端に接触する</para>
<para>2:左端に接触する</para>
<para>float:接触する場合、接触するまで動ける数値</para>
<para>999.0f:接触しない</para>
<para>999.0f以外:接触するまで動ける数値</para>
</returns>
</summary>
</member>
<member name="M:Object.#ctor(System.Single,System.Single,System.Single,System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="12">
<summary>
<para>コンストラクタ</para>
<para>オブジェクトの左上のX座標とY座標、横幅と縦幅を設定する</para>
<para>また、初期位置を保存する</para>
<para>引数:</para>
<param name="x"><para>x:Objectの左上のX座標</para></param>
<param name="y"><para>y:Objectの左上のY座標</para></param>
<param name="height"><para>height:Objectの左から右までの横幅</para></param>
<param name="width"><para>width:Objectの上から下までの縦幅</para></param>
</summary>
</member>
<member name="M:Object.Finalize" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="28">
<summary>
<para>終了処理</para>
<para>メモリ上の画像を削除する</para>
</summary>
</member>
<member name="M:Object.Left" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="36">
<summary>
<para>オブジェクトの左端のｘ座標を返す</para>
<para>戻り値:</para>
<returns>
<para>オブジェクトの左端のｘ座標</para>
</returns>
</summary>
</member>
<member name="M:Object.Right" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="47">
<summary>
<para>オブジェクトの右端のｘ座標を返す</para>
<para>戻り値:</para>
<returns>
<para>オブジェクトの右端のｘ座標</para>
</returns>
</summary>
</member>
<member name="M:Object.Top" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="58">
<summary>
<para>オブジェクトの上辺のｙ座標を返す</para>
<para>戻り値:</para>
<returns>
<para>オブジェクトの上辺のｙ座標</para>
</returns>
</summary>
</member>
<member name="M:Object.Base" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="69">
<summary>
<para>オブジェクトの下辺のｙ座標を返す</para>
<para>戻り値:</para>
<returns>
<para>オブジェクトの下辺のｙ座標</para>
</returns>
</summary>
</member>
<member name="M:Object.Center_X" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="80">
<summary>
<para>オブジェクトの中心のX座標を返す</para>
<para>戻り値:</para>
<returns>
<para>オブジェクトの中心のX座標</para>
</returns>
</summary>
</member>
<member name="M:Object.GetWidth" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="91">
<summary>
<para>オブジェクトの横幅を返す</para>
<para>戻り値:</para>
<returns>
<para>オブジェクトの横幅</para>
</returns>
</summary>
</member>
<member name="M:Object.GetHeight" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="102">
<summary>
<para>オブジェクトの縦幅を返す</para>
<para>戻り値:</para>
<returns>
<para>オブジェクトの縦幅</para>
</returns>
</summary>
</member>
<member name="M:Object.Set(System.Single,System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="113">
<summary>
<para>オブジェクトを指定した座標に設定する</para>
<para>引数:</para>
<param name="x"><para>x:設定するObjectの左上のX座標</para></param>
<param name="y"><para>y:設定するObjectの左上のY座標</para></param>
</summary>
</member>
<member name="M:Object.Set(System.Single,System.Single,System.Single,System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="124">
<summary>
<para>オブジェクトを指定した座標に設定する</para>
<para>追加でオブジェクトの縦幅、横幅を設定する</para>
<para>引数:</para>
<param name="x"><para>x:設定するObjectの左上のX座標</para></param>
<param name="y"><para>y:設定するObjectの左上のY座標</para></param>
<param name="height"><para>height:Objectの左から右までの横幅</para></param>
<param name="width"><para>width:Objectの上から下までの縦幅</para></param>
</summary>
</member>
<member name="M:Object.CanPushed(System.Single)" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="147">
<summary>
<para>押されようとしている数字から、自分が押されることのできる数字を返す</para>
<para>デフォルトだと常に0を返す</para>
<para>引数:</para>
<param name="num"><para>num:現在の位置から動かそうとしている座標への差</para></param>
<para>戻り値:</para>
<returns>
<para>numに対して、実際にこのObjectを動かせる距離</para>
</returns>
</summary>
</member>
<member name="M:Object.CanPicked(Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="161">
<summary>
<para>Objectに持たれるかを返す</para>
<para>デフォルトだと常にfalseを返す</para>
<para>引数:</para>
<param name="object"><para>object:自分を持つObject</para></param>
<para>戻り値:</para>
<returns>
<para>true:自分を持つことができる</para>
<para>false:自分を持つことができない</para>
</returns>
</summary>
</member>
<member name="M:Object.CanPutted" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="176">
<summary>
<para>今Objectが置かれることができるかを返す</para>
<para>デフォルトだと常にfalseを返す</para>
<para>戻り値:</para>
<returns>
<para>true:自分を持つことができる</para>
<para>false:自分を持つことができない</para>
</returns>
</summary>
</member>
<member name="M:Object.CanThrew" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="189">
<summary>
<para>今Objectが投げられることができるかを返す</para>
<para>デフォルトだと常にfalseを返す</para>
<para>戻り値:</para>
<returns>
<para>true:自分投げることができる</para>
<para>false:自分を投げることができない</para>
</returns>
</summary>
</member>
<member name="M:Object.Retry" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="202">
<summary>
<para>リトライ処理</para>
<para>初期位置に座標を設定する</para>
</summary>
</member>
<member name="M:Object.CanClear" decl="false" source="c:\users\student\desktop\action\action\action\object.cpp" line="210">
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