$(document).ready(function(){
    $("#toggle-btn").click(function(){
        var temp = document.getElementById("left-sidebar");
        temp.setAttribute("class","active");
        var content = document.getElementById("content");
        console.log(content);
        $("#content").removeClass('col-lg-12');
        content.setAttribute("class","content");
        content.setAttribute("class","col-lg-9");
        console.log(content);
        $("#toggle-btn").hide();
        $("#toggle-btn-close").show();
    });
})
$(document).ready(function(){
    $("#toggle-btn-close").click(function(){
        var  sidebar = document.getElementById("left-sidebar");
        $("#left-sidebar").removeClass('active');
        sidebar.setAttribute("class", "col-lg-3");
        sidebar.setAttribute("class", "left-sidebar")
        console.log(sidebar);
        var content = document.getElementById("content");
        $("#content").removeClass('col-lg-9');
        content.setAttribute("class","content");
        content.setAttribute("class","col-lg-12");
        console.log(content);
        $("#toggle-btn").show();
        $("#toggle-btn-close").hide();
    });
})
