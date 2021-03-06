<?php

$pizza  = "<!DOCTYPE html PUBLIC *\"*-//W3C//DTD XHTML 1.0 Transitional//EN*\"* *\"*http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd*\"*>
<html xmlns=*\"*http://www.w3.org/1999/xhtml*\"*>
<head>
<meta http-equiv=*\"*Content-Type*\"* content=*\"*text/html; charset=UTF-8*\"* />
<title>Calathea Smart Plug</title> 
<meta name=*\"*viewport*\"* content=*\"*width=device-width, initial-scale=0.55*\"* />  
<style>



body{

  background: repeating-radial-gradient(circle at bottom left, #fedc00 0, #fedc00 5.5555555556%, #fcb712 0, #fcb712 11.1111111111%, #f7921e 0, #f7921e 16.6666666667%, #e87f24 0, #e87f24 22.2222222222%, #dd6227 0, #dd6227 27.7777777778%, #dc4c27 0, #dc4c27 33.3333333333%, #ca3435 0, #ca3435 38.8888888889%, #b82841 0, #b82841 44.4444444444%, #953751 0, #953751 50%, #364c88 0, #364c88 55.5555555556%, #16599d 0, #16599d 61.1111111111%, #02609e 0, #02609e 66.6666666667%, #0073a9 0, #0073a9 72.2222222222%, #008aa4 0, #008aa4 77.7777777778%, #239a87 0, #239a87 83.3333333333%, #7cba6d 0, #7cba6d 88.8888888889%, #becc2f 0, #becc2f 94.4444444444%, #e0d81d 0, #e0d81d 100%), repeating-radial-gradient(circle at bottom right, #fedc00 0, #fedc00 5.5555555556%, #fcb712 0, #fcb712 11.1111111111%, #f7921e 0, #f7921e 16.6666666667%, #e87f24 0, #e87f24 22.2222222222%, #dd6227 0, #dd6227 27.7777777778%, #dc4c27 0, #dc4c27 33.3333333333%, #ca3435 0, #ca3435 38.8888888889%, #b82841 0, #b82841 44.4444444444%, #953751 0, #953751 50%, #364c88 0, #364c88 55.5555555556%, #16599d 0, #16599d 61.1111111111%, #02609e 0, #02609e 66.6666666667%, #0073a9 0, #0073a9 72.2222222222%, #008aa4 0, #008aa4 77.7777777778%, #239a87 0, #239a87 83.3333333333%, #7cba6d 0, #7cba6d 88.8888888889%, #becc2f 0, #becc2f 94.4444444444%, #e0d81d 0, #e0d81d 100%);
  background-blend-mode: overlay;
  height: 100vh;
	text-align:center;
	padding:10%;
	font-family:*\"*Lucida Console*\"*, Monaco, monospace;
	
	
}


#plugwrap {
 border-radius: 100px;
  background: #FFF;
  padding: 20px;
  width: 550px;
  height: 100px; 
  box-shadow: 5px 5px 10px 1px #030;
  margin-left:auto;
 margin-right:auto;

}
.box {
	display:block;
	border-radius: 100px;
	width:200px;
    height:80px;
    text-align:center;
    padding:10px;
	background-color:#CFF0C3;
		
}
.right {
	 float: right;
	 
}
.left{ 
       float: left;
}

.button {  border: none; color: white; padding: 20px; border-radius:50px; height:40px; display:block; font-size:35px; cursor:pointer;}	

.round {
	border-radius:45px;
	height:45px;
	width:45px;
	background-color:#CFF0C3;
}
.off{
	background-color:#005493;}
.on{
	background-color:#0096FF;}
h1{
	font-size: 4vw;
	text-shadow: 1px 1px 2px #fff, 1px 1px 2px #ccc;
}

.button55 {
	text-decoration: none;	
	font-size:15px;
	border-radius:20px;
	height:20px;
	width:20px;
	background-color:#FFF;
	text-align:center;
	float:left;
	padding:10px;
	cursor:pointer;
	display:block;
}
.status{
 display:block;
 float: left;
 margin-right:10px;
 margin-top:10px;
 width:290px;
}

input {
	display:block;
	margin:10px;
	float: left;
	border-radius:10px;
	font-size:16px;
	background-color:white;
	border:none;
	padding:5px;

}
#advanced {
	margin-top:50px;
	padding:10px;
	width:600px;
	margin-left:auto;
	margin-right:auto;
	background-color:#CCC;
	height:170px;
    border-radius:25px;
	opacity:70%;

    	
}
.pad{
	padding-top: 5px;
	padding-right: 5px;
	padding-bottom: 0px;
	padding-left: 15px;
}
table,td, th{
	border-collapse: collapse;
 border:none;
 padding:0px;
}
#gear{
	display:block;
	float:left;
	width:100px;
	font-size:50px;
	cursor:pointer;
}
#gear:hover{
	color:#909;}
.hide{visibility:hidden;}
.show{visibility:visible;}
</style>
</head>

<body>
<h1> Calathea Smart Plug Status </h1>
<div id=*\"*plugwrap*\"*>
<div class=*\"*box left*\"*><div onclick=*\"*OnButton1()*\"* class=*\"*button off*\"* id=*\"*button1*\"*> OFF <div id=*\"*round1*\"* class=*\"*round left*\"*></div> </div></div><div onclick=*\"*gearButt()*\"* id=*\"*gear*\"*>⚙</div>
<div class=*\"*box right*\"*><div onclick=*\"*OnButton2()*\"* id=*\"*button2*\"* class=*\"*button off*\"*> ON<div class=*\"*round left*\"*></div> </div></div>
</div>
<div class=*\"*hide*\"* id=*\"*advanced*\"*>
<table width=*\"*322*\"* height=*\"*169*\"* border=*\"*1*\"*>
  <tr>
    <td><div class=*\"*status*\"* id=*\"*status1*\"*><input type=*\"*text*\"* value=*\"*http://192.168.0.107/1/on*\"* id=*\"*myInput1*\"*><div class=*\"*button55*\"* onClick=*\"*On1()*\"*> 🔗 </div></div>
</td>
    <td><div class=*\"*status*\"* id=*\"*status2*\"*><input type=*\"*text*\"* value=*\"*http://192.168.0.107/2/on*\"* id=*\"*myInput2*\"*><div class=*\"*button55*\"* onClick=*\"*On2()*\"*> 🔗 </div></div>
</td>
  </tr>
  <tr>
    <td><div class=*\"*status*\"* id=*\"*status3*\"*><input type=*\"*text*\"* value=*\"*http://192.168.0.107/1/off*\"* id=*\"*myInput3*\"*><div class=*\"*button55*\"* onClick=*\"*Off1()*\"*> 🔗 </div></div>
</td>
    <td><div class=*\"*status*\"* id=*\"*status4*\"*><input type=*\"*text*\"* value=*\"*http://192.168.0.107/2/off*\"* id=*\"*myInput4*\"*><div class=*\"*button55*\"* onClick=*\"*Off2()*\"*> 🔗 </div></div>
</td>
  </tr>
  </table>

</div>

<script>
const button1=document.getElementById(*\"*button1*\"*);
const button2=document.getElementById(*\"*button2*\"*);
function OnButton1() { 
fetch(*\"*http://192.168.0.107/1/on*\"*);  
 button1.classList.remove('off');
 button1.classList.add('on');
 button1.innerHTML = 'ON<div class=*\"*round right*\"*></div>';
 setTimeout(function(){ location.reload(true); }, 1000);
 
};

function OffButton1() { 
fetch(*\"*http://192.168.0.107/1/off*\"*);  
 button1.classList.remove('on');
 button1.classList.add('off');
 button1.innerHTML = 'OFF<div class=*\"*round left*\"*></div>';
 setTimeout(function(){ location.reload(true); }, 1000);
 
};
function OnButton2() { 
fetch(*\"*http://192.168.0.107/2/on*\"*);  
 button2.classList.remove('off');
 button2.classList.add('on');
 button2.innerHTML = 'ON<div class=*\"*round right*\"*></div>';
 setTimeout(function(){ location.reload(true); }, 1000);
 
};

function OffButton2() { 
fetch(*\"*http://192.168.0.107/2/off*\"*);  
 button2.classList.remove('on');
 button2.classList.add('off');
 button2.innerHTML = 'OFF<div class=*\"*round left*\"*></div>';
 setTimeout(function(){ location.reload(true); }, 1000);
 
};
//// SHow and hide settings /////
const advn=document.getElementById(*\"*advanced*\"*);
function gearButt() { 
 advn.classList.remove('hide');
 advn.classList.add('show');
}



///// FOr copying URLS /////
  const statusB1=document.getElementById(*\"*status1*\"*);
  const statusB2=document.getElementById(*\"*status2*\"*);
  const statusB3=document.getElementById(*\"*status3*\"*);
  const statusB4=document.getElementById(*\"*status4*\"*);
   function On1() {
  /* Get the text field */
  var copyText = document.getElementById(*\"*myInput1*\"*);

  /* Select the text field */
  copyText.select();
  copyText.setSelectionRange(0, 99999); /*For mobile devices*/

  /* Copy the text inside the text field */
  document.execCommand(*\"*copy*\"*);

  /* Alert the copied text */
statusB1.innerHTML = '<div class=*\"*pad*\"*>Copied Link to clipboard </div></div>';


} 

   function On2() {
  /* Get the text field */
  var copyText = document.getElementById(*\"*myInput2*\"*);

  /* Select the text field */
  copyText.select();
  copyText.setSelectionRange(0, 99999); /*For mobile devices*/

  /* Copy the text inside the text field */
  document.execCommand(*\"*copy*\"*);

  /* Alert the copied text */
statusB2.innerHTML = '<div class=*\"*pad*\"*>Copied Link to clipboard </div></div>';


} 

   function Off1() {
  /* Get the text field */
  var copyText = document.getElementById(*\"*myInput3*\"*);

  /* Select the text field */
  copyText.select();
  copyText.setSelectionRange(0, 99999); /*For mobile devices*/

  /* Copy the text inside the text field */
  document.execCommand(*\"*copy*\"*);

  /* Alert the copied text */
statusB3.innerHTML = '<div class=*\"*pad*\"*>Copied Link to clipboard </div></div>';


} 

   function Off2() {
  /* Get the text field */
  var copyText = document.getElementById(*\"*myInput4*\"*);

  /* Select the text field */
  copyText.select();
  copyText.setSelectionRange(0, 99999); /*For mobile devices*/

  /* Copy the text inside the text field */
  document.execCommand(*\"*copy*\"*);

  /* Alert the copied text */
statusB4.innerHTML = '<div class=*\"*pad*\"*>Copied Link to clipboard </div></div>';


} 

</script>

</body>
</html>

";

$pieces = explode("\n",htmlspecialchars($pizza));

foreach($pieces as $value){
    echo "client.println(\"" . $value . "\");" .  "</br>";
   }
?>

