<?xml version="1.0"?><doc>
<members>
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
<param name="x"><para>x:対象のObjectが移動するX座標</para></param>
<param name="y"><para>y:対象のObjectが移動するY座標</para></param>
<param name="player"><para>player:対象のObjectのポインタ</para></param>
<param name="object"><para>object:調べるObjectのポインタ</para></param>
<returns>
<para>true:Objectが接触する</para>
<para>false:Objectが接触しない</para>
</returns>
</summary>
</member>
<member name="M:Collision.Check(System.Single,System.Single,System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="51">
<summary>
<para>
指定した右上の座標と左下の座標を対角線とする四角形の中に、指定したObjectが接触しているかを返す
</para>
<param name="x1"><para>x1:調べる範囲の左上のX座標</para></param>
<param name="y1"><para>y1:調べる範囲の左上のY座標</para></param>
<param name="x2"><para>x2:調べる範囲の右下のX座標</para></param>
<param name="y2"><para>y2:調べる範囲の右下のY座標</para></param>
<param name="object"><para>object:対象のObjectのポインタ</para></param>
<returns>
<para>true:Objectが接触する</para>
<para>false:Objectが接触しない</para>
</returns>
</summary>
</member>
<member name="M:Collision.ObjectDistance(Object!System.Runtime.CompilerServices.IsConst*,Object!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="75">
<summary>
<para>接触する二つのオブジェクトが接触するまで移動するObjectが動ける数値</para>
<param name="target"><para>target:playerが接触するObjectのポインタ</para></param>
<param name="player"><para>player:移動するObjectのポインタ</para></param>
<param name="check"><para>check:HitCheckXまたはHitCheckY内のcheck変数</para></param>
<returns>
<para>二つのオブジェクトが接触するまでplayerが動ける数値</para>
</returns>
</summary>
</member>
<member name="M:Collision.MapDistance(Object!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="107">
<summary>
<para>対象のObjectが画面端まで接触するまで動ける数値を返す</para>
<param name="player"><para>player:移動するObjectのポインタ</para></param>
<param name="check"><para>check:MapCheck内のcheck変数</para></param>
<returns>
<para>Objectがステージ左端または右端まに接触するまで動ける数値</para>
</returns>
</summary>
</member>
<member name="M:Collision.Check(System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="131">
<summary>
<para>
対象のオブジェクトが指定した座標上に出る場合、指定したObjectに接触するかを返す
</para>
<param name="x"><para>x:対象のObjectが移動するX座標</para></param>
<param name="y"><para>y:対象のObjectが移動するY座標</para></param>
<param name="player"><para>player:対象のObjectのポインタ</para></param>
<returns>
<para>true:Objectが接触する</para>
<para>false:Objectが接触しない</para>
</returns>
</summary>
</member>
<member name="M:Collision.MapCheck(System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="155">
<summary>
<para>指定したX地点に移動した場合、ステージの外に出るかどうか、</para>
<para>出る場合、現在の位置から接触するまで動ける数値を返す</para>
<param name="num"><para>num:移動しようとしているX地点</para></param>
<param name="player"><para>player:移動するObjectのポインタ</para></param>
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
<member name="M:Collision.PointCheck(System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="179">
<summary>
<para>引数の座標地点にObjectがあるかどうか、あった場合はy座標からどの程度の高さかを返す</para>
<para>あった場合はy座標からどの程度の高さかを返す</para>
<param name="x"><para>x:調べる座標のX座標</para></param>
<param name="y"><para>y:調べる座標のY座標</para></param>
<param name="player"><para>player:移動するObjectのポインタ</para></param>
<returns>
<para>Objectが存在した場合、yからどの程度の高さか</para>
<para>0:接触したObjectが存在しなかった</para>
<para>0以外:接触したObjectのy地点からの高さ</para>
</returns>
</summary>
</member>
<member name="M:Collision.AreaFullCheck(Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="208">
<summary>
<para>選択したObjectの内部すべてに他のObjectが存在するかを返す関数</para>
<param name="area"><para>area:調べる対象Objectのポインタ</para></param>
<returns>
<para>true:area内部全てが他のOjbectで満たされている</para>
<para>false:area内部全てが他のOjbectで満たされていない</para>
</returns>
</summary>
</member>
<member name="M:Collision.AreaCheck(Object*,System.Single,System.Single,System.Single,System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="240">
<summary>
<para>指定した右上の座標と左下の座標を対角線とする四角形の中に存在する他のObject一つを返す</para>
<param name="target"><para>target:戻り値の格納先</para></param>
<param name="x1"><para>x1:調べる範囲の左上のX座標</para></param>
<param name="y1"><para>y1:調べる範囲の左上のY座標</para></param>
<param name="x2"><para>x2:調べる範囲の右下のX座標</para></param>
<param name="y2"><para>y2:調べる範囲の右下のY座標</para></param>
<param name="player"><para>player:候補から外すObjectのポインタ</para></param>
<returns>
<para>nullptr:</para>
<para>指定した範囲内にObjectが存在しない</para>
<para>nullptr以外:</para>
<para>指定した範囲の中にに存在し、</para>
<para>playerに近かったObjectのポインタ</para>
</returns>
</summary>
</member>
<member name="M:Collision.GetMapLeft(Object*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="269">
<summary>ステージの左端にある地形を返す
<param name="target">target:戻り値の格納先</param>
<returns>
<para>ステージ右端のTerrainのポインタ</para>
</returns>
</summary>
</member>
<member name="M:Collision.GetMapRight(Object*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="280">
<summary>ステージの左端にある地形を返す
<param name="target"><para>target:戻り値の格納先</para></param>
<returns>
<para>ステージ右端のTerrainのポインタ</para>
</returns>
</summary>
</member>
<member name="M:Collision.GetPlayer" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="291">
<summary>ステージ上にあるPlayer全てを返す
<returns>
<para>ステージ上にあるPlayer全て</para>
</returns>
</summary>
</member>
<member name="M:Collision.HitCheckX(System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="306">
<summary>
<para>対象のObjectのX軸に数値を追加した結果、他のObjectに接触するか、</para>
<para>した場合にはどの部分に接触したか、接触したObject、</para>
<para>接触したObjectのうち、一番近いObjectと接触するまで対象のObjectが動ける数値を返す</para>
<param name="num"><para>num:対象のObjectのY座標に追加する予定の数値</para></param>
<param name="player"><para>player:対象のObjectのポインタ</para></param>
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
<member name="M:Collision.HitCheckY(System.Single,Object!System.Runtime.CompilerServices.IsConst*)" decl="false" source="c:\users\student\desktop\action\action\action\collision.cpp" line="340">
<summary>
<para>対象のObjectのY軸に数値を追加した結果、他のObjectに接触するか、</para>
<para>した場合にはどの部分に接触したか、接触したObject、</para>
<para>接触したObjectのうち、一番近いObjectと接触するまで対象のObjectが動ける数値を返す</para>
<param name="num"><para>num:対象のObjectのY座標に追加する予定の数値</para></param>
<param name="player"><para>player:対象のObjectのポインタ</para></param>
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
</members>
</doc>