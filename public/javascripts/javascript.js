//  
// Ukrit Fongsomboon 
// Kobori4268@gmail.com 
// 
var usertemp;
var userhum;
var usertime;
get_setting();
Get_data();

setInterval(function(){
  Get_data();
},1000*10);

setInterval(function(){
  get_setting();
},1000*15);


function get_setting(){
 var socket = io.connect();
 socket.on('get_setting', function (data) {
   usertemp   = data.user_temp;
   userhum    = data.user_hum;
   usertime   = data.time;
   // console.log("time update :"+data.time+"/"+"temp:"+data.user_temp+"/"+"hum:"+data.user_hum);

   var text   = document.getElementById("textupdate"); 
   text.innerHTML ="Update : "+  data.time; 


   var slider = document.getElementById("myRange");
   var output = document.getElementById("demo");
   slider.value = usertemp;
   output.innerHTML = slider.value;
   slider.oninput = function() {
    output.innerHTML = this.value;
  }  

  var slider1 = document.getElementById("myRange1");
  var output1 = document.getElementById("demo1");
  slider1.value = userhum;
  output1.innerHTML = slider1.value;
  slider1.oninput = function() {
    output1.innerHTML = this.value;
  }  
});
}

var slider = document.getElementById("myRange");
var output = document.getElementById("demo");
output.innerHTML = slider.value;
slider.oninput = function() {
  output.innerHTML = this.value;
}  

var slider1 = document.getElementById("myRange1");
var output1 = document.getElementById("demo1");
output1.innerHTML = slider1.value;
slider1.oninput = function() {
  output1.innerHTML = this.value;
}  

function Get_data(){
  var socket = io.connect();
  socket.on('temp_realtime_data',function(data){
 //    console.log(data.tempareture+" "+data.tempareture2+" "+data.tempareture3+" "+data.tempareture4+" "+data.tempareture5+" "+data.tempareture6);
 $(document).ready(function(){
  $(".tmp").text(data.tempareture5);
  $(".tmp2").text(data.tempareture);
  $(".tmp3").text(data.tempareture3);
  $(".tmp4").text(data.tempareture6);
  $(".tmp5").text(data.tempareture2);
  $(".tmp6").text(data.tempareture4);
});
});
}

    //   $(".tmp").text(data.tempareture5);
    //   $(".tmp2").text(data.temperature);
    //   $(".tmp3").text(data.temperature3);
    //   $(".tmp4").text(data.temperature6);
    //   $(".tmp5").text(data.temperature2);

    function send_data(){
      var socket = io.connect();
      socket.emit('Recive-data-web', { user_temp: slider.value,user_hum:slider1.value});
    // socket.emit('Recive-data-web', { user_temp:25,user_hum:33});
    var text   = document.getElementById("textupdate"); 
    socket.on('recive_timeupdate',function(time){
      var text   = document.getElementById("textupdate"); 
      text.innerHTML ="Update : "+ time.time; 
    });
    // get_setting();
    // text.innerHTML ="Update : "+  data.time; 
  }








