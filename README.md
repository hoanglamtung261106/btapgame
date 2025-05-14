<h1> BIRD DASH: Bài tập game môn lập trình nâng cao</h1>
<p align="center"><img src="https://github.com/hoanglamtung261106/btapgame/blob/main/image/font/bird_dash.png">

<h2> I. Giới thiệu tác giả:</h2>
<ul>
<li><b>Tên:</b> Hoàng Lâm Tùng</li>
<li><b>Lớp:</b> K69I-CS1</li>
<li><b>MSSV:</b> 24021661</li>
</ul>

<h2>
 II. Tổng quan về trò chơi "BIRD DASH"
</h2>
<ul>
 <li><b>Video Demo Game:</b> <a href="https://www.youtube.com/watch?v=SjYX6dI5WYo">Click here</a>
 <li><b>Thể loại:</b> Vô hạn</li>
 <li><b>Ngôn ngữ lập trình ra game:</b> C++ kết hợp với SDL2</li>
 <li>Trò chơi có 2 mức độ: dễ và khó</li>
 <li><b>Nhân vật:</b> <p align="center"><img src="https://github.com/hoanglamtung261106/btapgame/blob/main/image/frame/frame-1.png" width=100></p>
 <li><b>Tóm tắt:</b> Người chơi sẽ phải điều khiển nhân vật sao cho nhân vật không được chạm vào bề dọc của ống (chạm bề ngang thì không bị thua). Điều khiển bằng keyboard UP, nếu càng giữ chim càng bay (giống như gamemode ship hoặc wave của Geometry Dash)</li>
</ul>

<h2> III.Những điểm nổi bật trong game</h2>
<h3>Mức độ dễ</h3>
Mức độ này không có tính năng nổi bật. Và tất nhiên, chim đi qua mỗi pipe thì sẽ tăng 1 điểm.
<h3>Những loại portal mà chim đi qua (chỉ có ở mức độ khó)</h3>
<b>Có 5 loại cổng có trong game:</b>
<ul>
<li> <b>Gravity up portal</b><p align="center"><img src="https://github.com/hoanglamtung261106/btapgame/blob/main/image/portal/up_portal.png" width=100> </p>
Khi con chim vào cổng này, kể cả chim xuôi hay ngược, con chim trở thành chim ngược, và trọng lực nằm ở phía trên.</li>
<li> <b>Gravity down portal</b><p align="center"><img src="https://github.com/hoanglamtung261106/btapgame/blob/main/image/portal/down_portal.png" width=100> </p>
Khi con chim vào cổng này, kể cả chim xuôi hay ngược, con chim trở thành chim xuôi, và trọng lực nằm ở phía dưới.</li>
<li> <b>Gravity changed portal</b><p align="center"><img src="https://github.com/hoanglamtung261106/btapgame/blob/main/image/portal/down_or_up_portal.png" width=100> </p>
Khi con chim vào cổng này, con chim sẽ bị đảo trọng lực.</li>
<li> <b>Mini portal</b><p align="center"><img src="https://github.com/hoanglamtung261106/btapgame/blob/main/image/portal/mini_portal.png" width=100> </p>
Khi con chim vào cổng này, kể cả chim size thường hay mini, con chim trở thành chim mini, và bay vút hơn so với chim size thường.</li>
<li> <b>Normal size portal</b><p align="center"><img src="https://github.com/hoanglamtung261106/btapgame/blob/main/image/portal/big_portal.png" width=100> </p>
Khi con chim vào cổng này, kể cả chim size thường hay mini, con chim trở thành chim size thường.</li>
</ul>

<h3>Âm thanh</h3>
<ul>
 <li> <b> Nhạc nền cho menu và settings: </b> <b>Running Away</b>
 <li> Trong lúc chơi, không có nhạc nên, chỉ có sound effects</li>
 <li> Ở <b>Settings</b> có 2 buttons mute hoặc unmute cho cả nhạc nền menu và sound effects. Người chơi ấn button đó sẽ chuyển sang trạng thái ngược lại</li>
</ul>

<h3>Cách tạm dừng game</h3>
Người chơi có thể ấn phím ESC hoặc click chuột trái vào pause button, khi đó game sẽ tạm dừng

<h3>Quà (chỉ có trong mức độ khó)</h3>
Có 4 quà hình giống nhau nhưng chức năng khác nhau<p align="center"><img src="https://github.com/hoanglamtung261106/btapgame/blob/main/image/gift.png"></p>
<ul>
 <li> <b>+5</b>: Có hiệu lực trong 30 giây. Khi đi qua mỗi pipe, điểm cộng thêm 5.</li>
 <li> <b>Shield</b>: Có hiệu lực trong 30 giây. Shield sẽ kết thúc khi hết 30 giây hoặc chim va chạm với pipe.</li>
 <li> <b>+10đ 1 lần:</b> Khi chim gặp quà này thì điểm sẽ cộng thêm 10.
 <li> <b>-10đ 1 lần:</b> Khi chim gặp quà này thì điểm sẽ trừ đi 10. Nếu điểm âm thì set thành 0.
</ul>

<h3>Cách tính điểm (chỉ nói đến ở mức độ khó)</h3>
<ul>
 <li>Bình thường, khi chim đi qua 1 pipe, điểm sẽ cộng thêm 1.</li>
 <li>Khi quà <b>+5</b> có hiệu lực, điểm sẽ cộng thêm 5 khi chim đi qua mỗi pipe.</li>
 <li>Khi chim ăn quà <b>+10đ 1 lần</b>, điểm sẽ cộng thêm 10.</li>
 <li>Khi chim ăn quà <b>-10đ 1 lần</b>, điểm sẽ trừ đi 10. Nếu điểm âm thì set thành 0.</li>
</ul>

<h2>IV. Tài liệu tham khảo</h2>
<ul>
 <li> Code mẫu tham khảo trên <a href="https://lazyfoo.net/tutorials/SDL/index.php"> Lazy Foo</a> và <a href="https://github.com/chauttm/advprogram/tree/master"> Code mẫu do giảng viên cung cấp</a></li>
 <li> Background thì nhờ Chat GPT vẽ</li>
 <li> Ảnh con chim và pipe được lấy từ <a href="https://opengameart.org/">Opengameart</a></li>
 <li> Các portals được lấy từ <a href="https://geometry-dash.fandom.com/wiki/Portals">GD wiki</a></li>
 <li> Các ảnh khác được lấy từ <a href="https://www.pngwing.com/en/free-png-zmfgs/download">PNGWING</a>, <a href="https://uxwing.com/pause-button-red-icon/">UXWING</a> và <a href="https://vi.pngtree.com/">PNGTREE
 <li> Nhạc nền menu được lấy từ <a href="https://github.com/chauttm/gameProject/blob/main/09_sound_and_music/assets/RunningAway.mp3">GITHUB tham khảo do cô Châu cung cấp</a>
 <li> Sound effects được lấy từ <a href="https://dev.azure.com/">dev.azure.com</a> và <a href="https://www.101soundboards.com">101soundboards</a>
 <li> Font được gõ từ <a href="https://gdcolon.com/gdfont"> GD Font</a> rồi tải xuống thành file ảnh đuôi .png</li>
</ul></h2>
