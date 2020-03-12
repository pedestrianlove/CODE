<!DOCTYPE HTML>

<html>
<head>
	<meta charset="UTF-8">
	<title>u105021226's Website</title>
</head>


<body>
	<h3>u105021226 的HTML5網頁</h3>
	<hr />
	<font size=3 color="blue"><a href="http://www.math.nthu.edu.tw/">數學系</a> 純數組 李智修 </font> <br />
	<img src="https://learn.math.nthu.edu.tw/math172/user/pix.php/654/f1.jpg"> <br />
	<hr />
	<p>
		興趣<font color="#999999">(以清單條列)</font>
		<ul type="circle">
			<li>聽音樂</li>
			<li>玩LF2</li>
	</p>
	<p>
		本學期有修:
		<table border=3 color="grey">
			<tr>
					<td>1</td>	<td>管理學</td>
			</tr>
			<tr>
					<td>2</td>	<td>離散數</td>
			</tr>
			<tr>
					<td>3</td>	<td>程式設計二</td>
			</tr>
		</table>
	</p>
	<p>	Print 100 times "Welcome to MATH" <br />
		<?php
			for ($i=0; $i<100; $i++)
				printf ("<p>%3d&nbsp;&nbsp;<font color=\"red\">Welcome to MATH</font></p>", $i+1);
		?>
	</p>
</body>


</html>
