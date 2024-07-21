const char MAIN_page [] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset = "UTF - 8" >
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
  	h1 {
  		text-align: center;
  		text-transform: uppercase;
  		color: #4CAF50;
	}
    img.center {
    	display: auto;
    	margin-left: auto;
    	margin-right: auto;
	}
    h4 {
  		text-align: center;
  		text-transform: uppercase;
  		color: #4CAF50;
	}
	p {
  		text-indent: 20px;
  		text-align: justify;
  		letter-spacing: 2px;
	}

    body {
      text-align: left;
      font-family: "Trebuchet MS", Arial;
      margin-left:centre;
      margin-right:auto;
    }
    .slider {
      width: 400px;
    }
}
  </style>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
</head>
<body>
  <h1>Giao Dien HVAC</h1>
  <h4>WebServer</h4>
  <p>Set Point Nhiet Do: <span id="servoPos0"></span> (Dung de bat coil nong lanh)</p>
  <input type="range" min="0" max="50" class="slider" id="servoSlider0" onchange="servo(this.value)"/>
  <script>
    var slider0 = document.getElementById("servoSlider0");
    var servoP0 = document.getElementById("servoPos0");
    servoP0.innerHTML = slider0.value;
    slider0.oninput = function() {
      slider0.value = this.value;
      servoP0.innerHTML = this.value;
    }
    $.ajaxSetup({timeout:1000});
    function servo(pos) {
      $.get("/?value=" + pos + "&");
      {Connection: close};
    }
  </script>
  <p>Set Point Do am: <span id="servoPos1"></span> (Dung de tu dong bat quat)</p>
  <input type="range" min="50" max="100" class="slider" id="servoSlider1" onchange="servo(this.value)"/>
  <script>
    var slider1 = document.getElementById("servoSlider1");
    var servoP1 = document.getElementById("servoPos1");
    servoP1.innerHTML = slider1.value;
    slider1.oninput = function() {
      slider1.value = this.value;
      servoP1.innerHTML = this.value;
    }
    $.ajaxSetup({timeout:1000});
    function servo(pos) {
      $.get("/?value=" + pos + "&");
      {Connection: close};
    }
  </script>
 
  <p>Nhiet Do: <span id="nhietdos"></span> do C <img src="https://congnghedoluong.com/wp-content/uploads/2020/03/11-427x400.png" alt="Nhietdo" width="200" height="150"></p>

  <p>Do am: <span id="doams"></span>%  <img src="https://cdn-icons-png.freepik.com/512/4148/4148388.png" alt="Doam" width="200" height="150"></p>
  <img src="https://quatviet.net/wp-content/uploads/2020/04/icon-quatviet-net.jpg"alt="Quat" width="200" height="150">
  <p>Quat 1: <span id="servoPos2"></span> (Trong phong) </p>
  <input type="range" min="0" max="100" class="slider" id="servoSlider2" onchange="servo(this.value)"/>
  <script>
    var slider2 = document.getElementById("servoSlider2");
    slider2.value = 0;
    var servoP2 = document.getElementById("servoPos2");
    servoP2.innerHTML = slider2.value;
    slider2.oninput = function() {
      slider2.value = this.value;
      servoP2.innerHTML = this.value;
    }
    $.ajaxSetup({timeout:1000});
    function servo(pos) {
      $.get("/?value=" + pos + "&");
      {Connection: close};
    }
  </script>  
  <p>Quat 2: <span id="servoPos3"></span> (Ngoai hanh lang)</p>
  <input type="range" min="0" max="100" class="slider" id="servoSlider3" onchange="servo(this.value)"/>
  <script>
    var slider3 = document.getElementById("servoSlider3");
    slider3.value = 0;
    var servoP3 = document.getElementById("servoPos3");
    servoP3.innerHTML = slider3.value;
    slider3.oninput = function() {
      slider3.value = this.value;
      servoP3.innerHTML = this.value;
    }
    $.ajaxSetup({timeout:1000});
    function servo(pos) {
      $.get("/?value=" + pos + "&");
      {Connection: close};
    }
  </script> 
  <script>

  setInterval(function(){
    getnhietdo();
    getdoam();
    setdoam();
    setnhietdo();
    nhanquat1();
    nhanquat2();
    hamamve();
    hamnhietve();
    vequat1();
    vequat2();
  },400);
  function getnhietdo(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("nhietdos").innerHTML =
            this.responseText;
       }
    };
    xhttp.open("GET","nhietdo",true);
    xhttp.send();
  }
  function getdoam(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("doams").innerHTML =
            this.responseText;
       }
    };
    xhttp.open("GET","doam",true);
    xhttp.send();
  }
  function setdoam(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
           document.getElementById("servoPos1").innerHTML=
           this.responseText;
           slider1.value = servoP1.innerHTML;           
      }
    };
    xhttp.open("GET","setpointdoam",true);
    xhttp.send();
  }
  function setnhietdo(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
           document.getElementById("servoPos0").innerHTML=
           this.responseText;
           slider0.value = servoP0.innerHTML;
      }
    };
    xhttp.open("GET","setpointnhietdo",true);
    xhttp.send();
  }
  function hamnhietve(){
      var getnhiet = "E"+document.getElementById("servoSlider0").value+"F";
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET","/input0?input0="+getnhiet,true);
      xhttp.send();

  }
  function hamamve(){
      var getam = "G"+document.getElementById("servoSlider1").value+"H";
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET","/input1?input1="+getam,true);
      xhttp.send();
  }
  function nhanquat1(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
           document.getElementById("servoPos2").innerHTML=
           this.responseText;
           slider2.value = servoP2.innerHTML;           
      }
    };
    xhttp.open("GET","datquat1",true);
    xhttp.send();
  }
  function nhanquat2(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
           document.getElementById("servoPos3").innerHTML=
           this.responseText;
           slider3.value = servoP3.innerHTML;           
      }
    };
    xhttp.open("GET","datquat2",true);
    xhttp.send();
  }
  function vequat1(){
      var quat1 = "I"+document.getElementById("servoSlider2").value+"K";
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET","/vequat1?vequat1="+quat1,true);
      xhttp.send();

  }
  function vequat2(){
      var quat2 = "L"+document.getElementById("servoSlider3").value+"M";
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET","/vequat2?vequat2="+quat2,true);
      xhttp.send();

  }
</script>
</body>
</html>

)=====";