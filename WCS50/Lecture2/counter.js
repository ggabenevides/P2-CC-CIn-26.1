let counter = 0;

function count(){
    counter++;
    document.querySelector('h1').innerHTML = counter;
}

document.addEventListener('DOMContentLoaded', function(){
    document.querySelector('button').onclick = count; //only run function count when button is clicked - functional programming
    setInterval(count, 1000)
});