$(document).ready(function () {
    var flag = false;
    $("button#nonveg").click(function () {
        if ( flag == false ) {
            flag = true;
            $("h2").text("Non-Veg Menu");
            $("button#nonveg").text("Veg Menu");
            $f = $(".menu-list .replace-eggs").detach();
            $(".menu-list .breakfast").append("<li class='breakfast-eggs'>Egg Curry</li>")
            $(".menu-list .dinner").append("<li class='dinner-eggs'>Egg Curry</li>")
        } else if ( flag == true) {
            flag = false;
            $("h2").text("Veg Menu");
            $("button#nonveg").text("Non-Veg Menu");
            $(".breakfast-eggs").replaceWith($f[0]);
            $(".dinner-eggs").replaceWith($f[1]);
        }
    });
})