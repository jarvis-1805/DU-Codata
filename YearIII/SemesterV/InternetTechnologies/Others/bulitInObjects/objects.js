/* JavaScript Built-in Objects */

/* Window Object */

window.addEventListener("DOMContentLoaded", (event) => {
    var msg  = "<h2>browser window</h2><p>width: " + window.innerWidth + " </p>";
    msg += "<p>height: " + window.innerHeight + "</p>";
    msg += "<h2>history</h2><p>items : " + window.history.length + "</p>";
    msg += "<h2>screen</h2><p>width: " + window.screen.width + "</p> " ;
    msg += "<p>height : " + window.screen.height + "</p>";
    var el =  document.getElementById("info");
    el.innerHTML = msg;
    alert("Current page: " + window.location);
});



/* Document Object */

window.addEventListener("DOMContentLoaded", (event) => {
    var  msg = "<br><hr><br><p><b>Page Title: </b>" + document.title + "<br/>" ;
    msg += "<b>Page Address: </b>" + document.URL+ "<br />";
    msg += " <b>Last Modified: </b>" + document.lastModified + "</p>";
    var el = document.getElementById("footer");
    el.innerHTML = msg;
});
