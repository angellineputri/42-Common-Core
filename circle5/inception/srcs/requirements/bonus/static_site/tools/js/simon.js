const buttons = ["red", "blue", "green", "yellow"];
let sequence = [];
let playerSequence = [];
let level = 0;

const levelDisplay = document.getElementById("level");
const startButton = document.getElementById("start");

function playSequence() {
    let i = 0;
    const interval = setInterval(() => {
        const btn = document.getElementById(sequence[i]);
        btn.classList.add("active");
        setTimeout(() => btn.classList.remove("active"), 400);
        i++;
        if (i >= sequence.length) clearInterval(interval);
    }, 600);
}

function nextLevel() {
    level++;
    levelDisplay.textContent = "Level: " + level;
    sequence.push(buttons[Math.floor(Math.random() * buttons.length)]);
    playerSequence = [];
    playSequence();
}

function handleClick(color) {
    const btn = document.getElementById(color);
    btn.classList.add("active");
    setTimeout(() => btn.classList.remove("active"), 300);

    playerSequence.push(color);
    const index = playerSequence.length - 1;
    if (playerSequence[index] !== sequence[index]) {
        alert("Game Over! You reached level " + level);
        sequence = [];
        level = 0;
        levelDisplay.textContent = "Level: 0";
        return;
    }
    if (playerSequence.length === sequence.length) {
        setTimeout(nextLevel, 800);
    }
}

buttons.forEach(color => {
    const btn = document.getElementById(color);

    btn.addEventListener("click", () => handleClick(color));
    
    btn.addEventListener("mouseenter", () => btn.classList.add("pulse"));
    btn.addEventListener("mouseleave", () => btn.classList.remove("pulse"));
});

startButton.addEventListener("click", nextLevel);
