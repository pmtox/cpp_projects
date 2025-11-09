const canvas = document.getElementById("myCanvas");
const ctx = canvas.getContext("2d");

let x = 0;
let y = 200;
let dx = 2; // speed

function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height); // clear old frame

    ctx.beginPath();
    ctx.moveTo(0, 200);
    ctx.lineTo(x, y);
    ctx.strokeStyle = "lime";
    ctx.lineWidth = 3;
    ctx.stroke();

    x += dx;

    // reset when it reaches end
    if (x > canvas.width) x = 0;

    requestAnimationFrame(draw); // keep animating
}

draw();
