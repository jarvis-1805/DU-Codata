var i = 1;

function displayNextTable() {
  var div = document.createElement("div");
  var br = document.createElement("br");
  var randomColor = Math.floor(Math.random()*16777215).toString(16);
  i++;
  if (i < 11) {
    for (let j = 1; j < 11; j++) {
      div.innerHTML += "\t" + i * j;
    }
    div.style.textAlign = "center";
    div.style.fontSize = 10 * i + "px";
    div.style.color = "#" + randomColor;
    document.getElementById("container").appendChild(div);
    document.getElementById("container").appendChild(br);
  } else {
    clearInterval(interval);
  }
}

var interval = document.addEventListener("DOMContentLoaded", () => {
  setInterval(displayNextTable, 5000);
})