function updateTime()
{
    var time = new Date();
    var hour = time.getHours();
    var min = time.getMinutes();
    var sec = time.getSeconds();
    var timeStr = hour.toString().padStart(2, '0') + ":" + min.toString().padStart(2, '0') + ':' + sec.toString().padStart(2, '0');

    document.getElementById("t").innerHTML = timeStr;

    var greeting = document.getElementById("greeting")

    if (hour >= 20 || hour <= 4)
    {
        greeting.innerHTML = "晚上好"
    }
    else if (hour > 4 && hour < 10)
    {
        greeting.innerHTML = "早上好"
    }
    else if (hour >= 10 && hour <15)
    {
        greeting.innerHTML = "中午好"
    }
    else
    {
        greeting.innerHTML = "下午好"
    }
}

window.onload = updateTime
setInterval(updateTime, 1000);

function updateZmd()
{
    var speed = 1.0

    var obj = document.getElementById("zmd")
    var left = obj.offsetLeft;
    obj.style.left = left - speed + "px";

    if (obj.offsetLeft <= -obj.offsetWidth)
    {
        obj.style.left = document.body.clientWidth + "px";
    }

    console.log(document.body.offsetWidth)
}

setInterval(updateZmd, 1);