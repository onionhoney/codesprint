console.log("here");
$(function () {
    console.log("ready");
    $(document).scroll(function () {
        var $nav = $(".navbar-default");
        $nav.toggleClass('scrolled', $(this).scrollTop() > $nav.height());
    });
});
