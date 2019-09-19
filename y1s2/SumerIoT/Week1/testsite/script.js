$(document).ready(function () {
    // 10583a2072274ea59aef9b68becc2c46
var url;
var authcode;

function attatchAuth(){
    authcode =$("#auth").val();
    url = "http://iot.nortcele.win:8080/"+authcode+"/";
};

$("#b_auth").click(function() {
    attatchAuth();
    alert(authcode);
    alert(url);
});    




$("#V1").click(function() {
  $.getJSON( url+"get/V1", function( data ) {
    alert(data);
  });
});

var newText = $("#txt_setv1").val();
$("#b_setv1").click(function() {
    alert($("#txt_setv1").val());
  $.getJSON( url+"update/V1?value="+$("#txt_setv1").val(), function( data ) {
    alert(newText);
  });
});

$("#b_refresh").click(function() {
  $.getJSON( url+"get/V22", function( data ) {
    $("#data_temp").html(data + " C");
  });
  $.getJSON( url+"get/V23", function( data ) {
    $("#data_hum").html(data + " %");
  });
  $.getJSON( url+"get/V27", function( data ) {
    $("#data_lgt").html(data + " lux");
  });

  alert("data refreshed");
});

});
