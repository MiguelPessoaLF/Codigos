setTimeout(() => 
{
    document.getElementById("animacao-inicial").classList.add("fade-out");

    setTimeout(() => 
        {
        document.getElementById("animacao-inicial").style.display = "none";
        document.querySelector(".all").style.display = "block";

        document.body.classList.remove("loading");
    }, 1000);
}, 3000);