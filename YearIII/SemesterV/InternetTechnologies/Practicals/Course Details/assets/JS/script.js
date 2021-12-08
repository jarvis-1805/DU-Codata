$(document).ready(function() {
  $("#show-table").click(function() {
    $(".paper-details table").toggle(1000);
  });
  $("#redesign").click(function() {
    $("#redesign").toggle(100);
    $("body").css({
      "background-color":"black",
      "color":"white",
      "font-family":"'Courier New', Courier, monospace",
      "background":"linear-gradient(-45deg, #7873f5, #ec77ab, #537895, #09203f)",
	    "background-size":"100% 200%",
	    "animation":"gradient 10s ease infinite"
    });
    $(".container").css({
      "padding":"50px",
      "padding-top":"5px"
    });
    $(".container h1").css({
      "text-align":"center",
      "border":"2px solid white",
      "padding":"2px"
    });
    $("table, th, td").css("border", "1px solid white");
    $("h2").css({
      "text-decoration":"underline"
    });
  });
});