
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE HTML><html>
  <head>
  
 <title>ESP-Riders Mecanum M.A.X.</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body { font-family: Times;
      text-align: center; 
      margin:1px auto; 
      padding-top: 30px; 
      width:auto; 
      user-select: none;  
      background-color: #ffAA00;}
      
      
      .button{
        padding: 0px 2px;
        font-size: 40px;
        font-family: appaji ambarisha darbha;
        background-color: white;
        margin: 5px;
        color: black;
        border: 2px solid black;
        width: 60px;
        height: 60px;
        display: inline;
        text-align: center;
        border-radius: 15%;
             } 

      .button0 {}
      .button1 { width: 70px;
        height: 70px;
        display: inline;
        text-align: center;}
       .button2 {}       
       .button3 { width: 70px;
        height: 70px;
        display: inline;
        text-align: center;}       
       .button4 { width: 70px;
        height: 70px;
        display: inline;
        text-align: center;}       
       .button5 {}       
       .button6 { width: 70px;
        height: 70px;
        display: inline;
        text-align: center;}       
       .button7 {}       
       .button8 {border-radius: 50%;}
       .button9 {border-radius: 50%;} 
           
      .button:hover {
        background-color: white;
         color: grey;
                    }
                    
      .button:active {
        background-color: #007399;
        color: white;
        box-shadow: 2 1px #ff0045;
        transform: translateY(x);
                    }
      
      .action_btn {
        width: 150px;
        margin: 0 auto;
        display: inline;}

.slidecontainer {
  width: 100%;
}

.slider {
  -webkit-appearance: none;
  width: 100%;
  height: 50px;
  background: #000000;
  outline: none;
  opacity: 1.0;
  -webkit-transition: .2s;
  transition: opacity .2s;
}

.slider:hover {
  opacity: 1;
}

.slider::-webkit-slider-thumb {
  -webkit-appearance: none;
  appearance: none;
  width: 50px;
  height: 50px;
  background: #AAAAAA;
  cursor: pointer;
}

.slider::-moz-range-thumb {
  width: 25px;
  height: 25px;
  background: #ffffff;
  cursor: pointer;
}
  
  </style>
      
  </head>
  <body>
    <h1>ESP-RIDER WebRocket</h1>
    <h1>MECANUM M.A.X. 4X4</h1>
    
<div class="buttons">
<div class="action_btn">

    
    <p><button class="button button0" id="button0" onmousedown="toggle('A');" ontouchstart="toggle('A');" onmouseup="toggle('off');" ontouchend="toggle('off')">&#8662</button>
     <button class="button button1" id="button1" onmousedown="toggle('B');" ontouchstart="toggle('B');" onmouseup="toggle('off');" ontouchend="toggle('off')">&#8657</button>
    <button class="button button2" id="button2" onmousedown="toggle('C');" ontouchstart="toggle('C');" onmouseup="toggle('off');" ontouchend="toggle('off');">&#8663</button><P>
    
    <p><button class="button button3" id="button3" onmousedown="toggle('D');" ontouchstart="toggle('D');"  onmouseup="toggle('off');" ontouchend="toggle('off');">&#8656</button>    
    <button class="button button4" id="button4" onmousedown="toggle('E');" ontouchstart="toggle('E');" onmouseup="toggle('off');" ontouchend="toggle('off');" >&#8658</button></p>
   
    <p><button class="button button5" id="button5" onmousedown="toggle('F');" ontouchstart="toggle('F');" onmouseup="toggle('off');" ontouchend="toggle('off');">&#8665</button>
    <button class="button button6" id="button6" onmousedown="toggle('G');" ontouchstart="toggle('G');" onmouseup="toggle('off');" ontouchend="toggle('off');">&#8659</button>    
    <button class="button button7" id="button7" onmousedown="toggle('H');" ontouchstart="toggle('H');" onmouseup="toggle('off');" ontouchend="toggle('off');">&#8664</button><p>
        

  <p><button class="button button8" id="button8" onmousedown="toggle('I');" ontouchstart="toggle('I');"  onmouseup="toggle('off');" ontouchend="toggle('off');">&#8630</button>    
    <button class="button button9" id="button9" onmousedown="toggle('J');" ontouchstart="toggle('J');" onmouseup="toggle('off');" ontouchend="toggle('off');" >&#8631</button></p>

             
     
     
             </div>

        </div>

  

<script>

var gateway = `ws://${window.location.hostname}/ws`;
var websocket;

window.addEventListener('load', onload);
window.addEventListener('open', onopen);

function onload(event) {
   console.log("initwebSocket");
   initWebSocket();
}

function onopen(event) {
       console.log('Connection opened');
   }

function toggle(x) {
     console.log(x);
     websocket.send("GET /" + x);
   }

function initWebSocket() {
    console.log('Trying to open a WebSocket connection…');
    websocket = new WebSocket(gateway);
    websocket.onopen = onOpen;
    websocket.onclose = onClose;
    websocket.onmessage = onMessage;
}

function onOpen(event) {
       console.log('Connection really really opened');
   }

function onClose(event) {
    console.log('Connection closed');
    setTimeout(initWebSocket, 2000);
}

function onMessage(event) {
    console.log(event.data);
    var myObj = (event.data);
    document.getElementById("myRange").value = myObj;
  }

/*
var slider = document.getElementById("myRange");
slider.oninput = function() {
  pos = slider.value;
  speed(pos);
}

function speed(pos) {
    console.log(pos);
    websocket.send("GET /Pos?value="+ pos + "&");
    // var xhr = new XMLHttpRequest();
    // xhr.open("GET", "/Pos?value="+ pos , true);
    // xhr.send();
   }
*/
   
  </script>
  </body>
</html>
)=====";
