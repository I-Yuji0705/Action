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
<member name="M:Collision.#ctor(std.vector&lt;Object**,std.allocator&lt;Object**&gt;&gt;*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="7">
<summary>
Stageのポインタの収得
</summary>
</member>
<member name="M:Collision.Initialize" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="15">
<summary>
<para>初期化処理</para>
<para>Stageのポインタから、ステージ右端と左端のTerrainの収得</para>
</summary>
</member>
<member name="M:Collision.Check(System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="31">
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
<member name="M:Collision.Check(System.Single,System.Single,System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="53">
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
<member name="M:Collision.ObjectDistance(Object!System.Runtime.CompilerServices.IsConst*,Object!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="79">
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
<member name="M:Collision.MapDistance(Object!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="112">
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
<member name="M:Collision.Check(System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="138">
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
<member name="M:Collision.MapCheck(System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="164">
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
<member name="M:Collision.PointCheck(System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="190">
<summary>
<para>引数の座標地点にObjectがあるかどうか、あった場合はy座標からどの程度の高さかを返す</para>
<para>あった場合はy座標からどの程度の高さかを返す</para>
<para>引数:</para>
<param name="x"><para>x:調べる座標のX座標</para></param>
<param name="y"><para>y:調べる座標のY座標</para></param>
<param name="player"><para>player:移動するObjectのポインタ</para></param>
<para>戻り値:</para>
<returns>
<para>Objectが存在した場合、yからどの程度の高さか</para>
<para>0:接触したObjectが存在しなかった</para>
<para>0以外:接触したObjectのy地点からの高さ</para>
</returns>
</summary>
</member>
<member name="M:Collision.AreaFullCheck(Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="221">
<summary>
<para>選択したObjectの内部すべてに他のObjectが存在するかを返す関数</para>
<para>引数:</para>
<param name="area"><para>area:調べる対象Objectのポインタ</para></param>
<para>戻り値:</para>
<returns>
<para>true:area内部全てが他のOjbectで満たされている</para>
<para>false:area内部全てが他のOjbectで満たされていない</para>
</returns>
</summary>
</member>
<member name="M:Collision.AreaCheck(Object*,System.Single,System.Single,System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="255">
<summary>
<para>指定した右上の座標と左下の座標を対角線とする四角形の中に存在する他のObject一つを返す</para>
<para>引数:</para>
<param name="target"><para>target:戻り値の格納先</para></param>
<param name="x1"><para>x1:調べる範囲の左上のX座標</para></param>
<param name="y1"><para>y1:調べる範囲の左上のY座標</para></param>
<param name="x2"><para>x2:調べる範囲の右下のX座標</para></param>
<param name="y2"><para>y2:調べる範囲の右下のY座標</para></param>
<param name="player"><para>player:候補から外すObjectのポインタ</para></param>
<para>戻り値:</para>
<returns>
<para>nullptr:</para>
<para>指定した範囲内にObjectが存在しない</para>
<para>nullptr以外:</para>
<para>指定した範囲の中にに存在し、</para>
<para>playerに近かったObjectのポインタ</para>
</returns>
</summary>
</member>
<member name="M:Collision.GetMapLeft(Object*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="286">
<summary>ステージの左端にある地形を返す
<para>引数:</para>
<param name="target">target:戻り値の格納先</param>
<para>戻り値:</para>
<returns>
<para>ステージ右端のTerrainのポインタ</para>
</returns>
</summary>
</member>
<member name="M:Collision.GetMapRight(Object*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="299">
<summary>ステージの左端にある地形を返す
<para>引数:</para>
<param name="target"><para>target:戻り値の格納先</para></param>
<para>戻り値:</para>
<returns>
<para>ステージ右端のTerrainのポインタ</para>
</returns>
</summary>
</member>
<member name="M:Collision.GetPlayer" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="312">
<summary>ステージ上にあるPlayer全てを返す
<para>戻り値:</para>
<returns>
<para>ステージ上にあるPlayer全て</para>
</returns>
</summary>
</member>
<member name="M:Collision.HitCheckX(System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="328">
<summary>
<para>対象のObjectのX軸に数値を追加した結果、他のObjectに接触するか、</para>
<para>した場合にはどの部分に接触したか、接触したObject、</para>
<para>接触したObjectのうち、一番近いObjectと接触するまで対象のObjectが動ける数値を返す</para>
<para>引数:</para>
<param name="num"><para>num:対象のObjectのY座標に追加する予定の数値</para></param>
<param name="player"><para>player:対象のObjectのポインタ</para></param>
<para>戻り値:</para>
<returns>
<para>int:Objectに接触したか、した場合はどの部分に接触したか</para>
<para>0:接触しない</para>
<para>1:objectの左側に接触</para>
<para>2:objectの右側に接触</para>
<para>float:numに対して、実際にplayerがX軸に追加できる値</para>
<para>std::vector:接触した全てのObjectのポインタ</para>
</returns>
</summary>
</member>
<member name="M:Collision.HitCheckY(System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="366">
<summary>
<para>対象のObjectのY軸に数値を追加した結果、他のObjectに接触するか、</para>
<para>した場合にはどの部分に接触したか、接触したObject、</para>
<para>接触したObjectのうち、一番近いObjectと接触するまで対象のObjectが動ける数値を返す</para>
<para>引数:</para>
<param name="num"><para>num:対象のObjectのY座標に追加する予定の数値</para></param>
<param name="player"><para>player:対象のObjectのポインタ</para></param>
<para>戻り値:</para>
<returns>
<para>int:Objectに接触したか、した場合はどの部分に接触したか</para>
<para>0:接触しない</para>
<para>3:objectの上側に接触</para>
<para>4:objectの下側に接触</para>
<para>float:numに対して、実際にplayerがY軸に追加できる値</para>
<para>std::vector:接触した全てのObjectのポインタ</para>
</returns>
</summary>
</member>
<member name="M:Collision.AlignAdhesionObjects(std.vector&lt;Object**,std.allocator&lt;Object**&gt;&gt;,Object!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="403">
<summary>
<para>Objectの動的配列から、対象のObjectに接触しているObjectの動的配列と</para>
<para>接触しているObjectから、接触していないObjectのうち、一番近いObjectまでの差を返す</para>
<para>引数:</para>
<param name="objects"><para>objects:調べるObjectのポインタの動的配列</para></param>
<param name="player"><para>player:接触しているか調べるObjectのポインタ</para></param>
<param name="check"><para>check:HitCheckX及びHitCheckYのintで返されるint型変数</para></param>
<para>戻り値:</para>
<returns>
<para>std::vector:接触ししている全てのObjectのポインタ</para>
<para>float:playerが一番近いObjectに接触するまで動ける数値</para>
</returns>
</summary>
</member>
</members>
</doc>